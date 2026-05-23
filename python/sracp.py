import asyncio
from playwright.async_api import async_playwright
import pandas as pd

username = 'brd-customer-hl_0f1e8134-zone-scraping_browser_amazon'
password = 'e4m9lkqu82ub'
auth = f'{username}:{password}'
host = 'brd.superproxy.io:9222'
browser_url = f'wss://{auth}@{host}'

async def scrape_amazon_bdata():
    async with async_playwright() as pw:
        try:
            print('connecting')
            # Launch new browser
            browser = await pw.chromium.connect_over_cdp(browser_url)
            print('connected')
            page = await browser.new_page()
            print('navigating')
            # Go to Amazon URL
            await page.goto('https://www.amazon.com/s?i=fashion&bbn=115958409011', timeout=600000)
            print('waiting for listings')
            await page.wait_for_selector('div.s-main-slot')
            print('data extraction in progress')
            # Extract information
            results = []
            listings = await page.query_selector_all('div.s-main-slot > div.s-result-item')
            print(f'Found {len(listings)} listings')
            for listing in listings:
                result = {}
                # Product name
                name_element = await listing.query_selector('h2 > a > span')
                result['product_name'] = await name_element.inner_text() if name_element else 'N/A'

                # Rating
                rating_element = await listing.query_selector('span[aria-label*="out of 5 stars"]')
                result['rating'] = await rating_element.get_attribute('aria-label') if rating_element else 'N/A'

                # Number of reviews
                reviews_element = await listing.query_selector('span[aria-label*="stars"] + span > a')
                result['number_of_reviews'] = await reviews_element.inner_text() if reviews_element else 'N/A'

                # Price
                price_element = await listing.query_selector('span.a-price > span.a-offscreen')
                result['price'] = await price_element.inner_text() if price_element else 'N/A'
                if result['product_name'] == 'N/A' and result['rating'] == 'N/A' and result['number_of_reviews'] == 'N/A' and result['price'] == 'N/A':
                    pass
                else:
                    results.append(result)
            # Close browser
            await browser.close()

            return results
        
        except Exception as e:
            print(f"An error occurred: {e}")
            return []

# Run the scraper and save results to a CSV file
if __name__ == "__main__":
    async def main():
        results = await scrape_amazon_bdata()
        if results:  # Ensure there are results before saving
            df = pd.DataFrame(results)
            df.to_csv('amazon_products_bdata_listings.csv', index=False)
        else:
            print("No results found.")
    
    asyncio.run(main())
