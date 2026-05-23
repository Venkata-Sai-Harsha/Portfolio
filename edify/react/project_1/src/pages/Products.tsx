function Products() {
    let products = [
        {
            id: 1,
            name: 'iPhone 16e 128 GB: Built for Apple Intelligence, A18 Chip, Supersized Battery Life, 48MP Fusion. Camera, 15.40 cm (6.1″) Super Retina XDR Display; Black',
            discount: 15,
            price: 59900,
            imageUrl: 'https://m.media-amazon.com/images/I/61FMZ9rSZUL._AC_UY545_FMwebp_QL65_.jpg',
            category: 'Mobiles',
            isProductInCart: false,
        },
        {
            id: 2,
            name: 'Apple iPhone 15 (128 GB) - Blue',
            discount: 14,
            price: 69900,
            imageUrl: 'https://m.media-amazon.com/images/I/71d7rfSl0wL._AC_UY545_FMwebp_QL65_.jpg',
            category: 'Mobiles',
            isProductInCart: false
        },
        {
            id: 3,
            name: 'Samsung Galaxy M05 (Mint Green, 4GB RAM, 64 GB Storage) | 50MP Dual Camera | Bigger 6.7" HD+ Display | 5000mAh Battery | 25W Fast Charging | 2 Gen OS Upgrade & 4 Year Security Update | Without Charger',
            discount: 35,
            price: 9999,
            imageUrl: 'https://m.media-amazon.com/images/I/81T3olLXpUL._AC_UY545_FMwebp_QL65_.jpg',
            category: 'Mobiles',
            isProductInCart: false
        },
        {
            id: 4,
            name: 'Xiaomi 14 CIVI (Shadow Black, 8GB RAM, 256GB Storage)',
            discount: 44,
            price: 54999,
            imageUrl: 'https://m.media-amazon.com/images/I/71x5XVC9UlL._AC_UY327_FMwebp_QL65_.jpg',
            category: 'Mobiles',
            isProductInCart: false
        },
        {
            id: 5,
            name: 'Samsung 7 kg, Fully-Automatic Top Load Washing Machine with Diamond Drum (WA70A4002GS/TL, Imperial Silver)',
            discount: 27,
            price: 21000,
            imageUrl: 'https://m.media-amazon.com/images/I/71a8akl5+LL._AC_UY327_FMwebp_QL65_.jpg',
            category: 'washing machine',
            isProductInCart: false
        },
        {
            id: 6,
            name: 'LG 7 Kg, 5 Star, Direct Drive Technology, Steam Wash, 6 Motion DD, Fully-Automatic Front Load Washing Machine (FHB1207Z2M, Allergy Care, In-Built Heater, Touch Panel',
            discount: 33,
            price: 44490,
            imageUrl: 'https://m.media-amazon.com/images/I/71XcZiTlQuL._AC_UY327_FMwebp_QL65_.jpg',
            category: 'washing machine',
            isProductInCart: false
        },
        {
            id: 7,
            name: 'Samsung 7 kg, 5 star, Semi-Automatic Washing Machine (WT70M3000UU/TL, Air Turbo Drying, LIGHT GRAY)',
            discount: 26,
            price: 14150,
            imageUrl: 'https://m.media-amazon.com/images/I/71DkvxIZpDL._AC_UY327_FMwebp_QL65_.jpg',
            category: 'washing machine',
            isProductInCart: false
        },
        {
            id: 8,
            name: 'Noise Vortex Plus 1.46 AMOLED Display, AoD, BT Calling, Sleek Metal Finish, 7 Days Battery Life, All New OS with 100+ Watch Faces & Health Suite (Black)',
            discount: 69,
            price: 6999,
            imageUrl: 'https://m.media-amazon.com/images/I/61QiBo-sPTL._AC_UY327_FMwebp_QL65_.jpg',
            category: 'smart watch',
            isProductInCart: false
        },
        {
            id: 9,
            name: 'boAt Wave Call 2 with 1.83" HD Display, Advanced BT Calling, Functional Crown, Cloud & Custom Watch Faces, Multiple Sports Modes, IP67, HR, Sleep & SPO₂ Monitor Smart',
            discount: 80,
            price: 6999,
            imageUrl: 'https://m.media-amazon.com/images/I/71rKSnY5XPL._AC_UY327_FMwebp_QL65_.jpg',
            category: 'smart watch',
            isProductInCart: false
        },
        {
            id: 10,
            name: 'HP Victus, 13th Gen Intel Core i5-13420H, NVIDIA RTX 2050 Gaming Laptop(Upgradable 16GB DDR4, 512GB SSD),144Hz, IPS, 300 nits, 15.6',
            discount: 18,
            price: 75142,
            imageUrl: 'https://m.media-amazon.com/images/I/71DL2Mt7i+L._AC_UY327_FMwebp_QL65_.jpg',
            category: 'laptop',
            isProductInCart: false
        },
        {
            id: 11,
            name: 'Apple MacBook Air Laptop: Apple M1 chip, 13.3-inch/33.74 cm Retina Display, 8GB RAM, 256GB SSD Storage, Backlit Keyboard, FaceTime HD Camera, Touch ID.',
            discount: 20,
            price: 74900,
            imageUrl: 'https://m.media-amazon.com/images/I/71jG+e7roXL._AC_UY327_FMwebp_QL65_.jpg',
            category: 'laptop',
            isProductInCart: false
        },
        {
            id: 12,
            name: 'Dell Vostro 15-3530 Laptop - 13th Gen Intel Core i5-1334U, 15.6" FHD 1920x1080, 8GB DDR4 RAM, 512GB, Intel UHD Graphics, Win 11 + Office H&S 2021, Carbon Black',
            discount: 18,
            price: 59528,
            imageUrl: 'https://m.media-amazon.com/images/I/61mIyqErSnL._AC_UY327_FMwebp_QL65_.jpg',
            category: 'laptop',
            isProductInCart: false
        },
        {
            id: 13,
            name: 'Acer[SmartChoice Aspire Lite 12thGen Intel Core i5-12450H Premium Laptop(Win11Home/16GB RAM/512GB SSD/IntelUHD Graphics',
            discount: 31,
            price: 66999,
            imageUrl: 'https://m.media-amazon.com/images/I/612TNOGY-1L._AC_UY327_FMwebp_QL65_.jpg',
            category: 'laptop',
            isProductInCart: false
        },
        {
            id: 14,
            name: 'Boult Q Over Ear Bluetooth Headphones with 70H Playtime, 40mm Bass Drivers, Zen™ ENC Mic, Type-C Fast Charging, 4 EQ Modes, BTv 5.4, AUX Option',
            discount: 67,
            price: 5999,
            imageUrl: 'https://m.media-amazon.com/images/I/71zfpkr4bYL._AC_UY327_FMwebp_QL65_.jpg',
            category: 'headphones',
            isProductInCart: false
        },
        {
            id: 15,
            name: 'Sony WH-CH520 Wireless Bluetooth Headphones On Ear with Mic, Up to 50Hrs Battery, Quick Charge, DSEE Upscale, Multipoint Connectivity, Voice Assistant',
            discount: 34,
            price: 5999,
            imageUrl: 'https://m.media-amazon.com/images/I/41JACWT-wWL._AC_UY327_FMwebp_QL65_.jpg',
            category: 'headphones',
            isProductInCart: false
        },
        {
            id: 16,
            name: 'boAt Rockerz 450, 15 HRS Battery, 40mm Drivers, Padded Ear Cushions, Integrated Controls, Dual Modes, On Ear Bluetooth Headphones, Wireless Headphone with Mic',
            discount: 65,
            price: 3990,
            imageUrl: 'https://m.media-amazon.com/images/I/51FNnHjzhQL._AC_UY327_FMwebp_QL65_.jpg',
            category: 'headphones',
            isProductInCart: false
        },
        {
            id: 17,
            name: 'OnePlus Pad Go 28.85Cm 2.4K 7:5 Ratio Readfit Eye Care LCD Display, Dolby Atmos Quad Speakers, 4G LTE(Calling) + Wi-Fi Connectivity Tablet, 8GB RAM 128 GB Storage',
            discount: 14,
            price: 21999,
            imageUrl: 'https://m.media-amazon.com/images/I/51Ouixhfs2L._AC_UY327_FMwebp_QL65_.jpg',
            category: 'tablet',
            isProductInCart: false
        },
        {
            id: 18,
            name: 'Apple iPad (10th Generation): with A14 Bionic chip, 27.69 cm (10.9″) Liquid Retina Display, 256GB, Wi-Fi 6, 12MP front/12MP Back Camera, Touch ID, All-Day Battery Life',
            discount: 30,
            price: 49900,
            imageUrl: 'https://m.media-amazon.com/images/I/61uA2UVnYWL._AC_UY327_FMwebp_QL65_.jpg',
            category: 'tablet',
            isProductInCart: false
        }
    ];

    let cart: any = [];

    const calculateDiscount = (price: number, discount: number) => {
        const discountedPrice = (price - (price * discount) / 100);
        return discountedPrice;
    };

    const addToCart = (productInfo: any) => {
        const index = cart.findIndex((product: any) => product.id === productInfo.id);
        if (index === -1) {
            cart.push({ ...productInfo, quantity: 1 });
            products = products.map((product: any) => {
                if (product.id === productInfo.id) {
                    return { ...product, isProductInCart: true };
                } else {
                    return product;
                }
            })
        } else {
           cart = cart.map((product: any) => {
            if (product.id === productInfo.id) {
                return { ...product, quantity: product.quantity + 1 };
            } else {
                return product;
            }
           }); 
        }
        console.log(products);
    };

    return (
        <div>
            <h1 className="text-center text-4xl font-medium my-4">Products</h1>

            <div id="products">
                {products.map((product: any, index: number) => (
                    <div id="product-info" className="flex justify-between mx-30 py-8 my-8 border-b border-gray-400">
                        <div className="w-1/5">
                            <img src={product.imageUrl} className="h-48" />
                        </div>
                        <div className="w-4/5">
                            <h1 className="text-xl font-medium my-3">{product.name} {index}</h1>
                            <h2><span className="text-xl font-semibold">{calculateDiscount(product.price, product.discount)}</span> <span className="me-2">M.R.P. <s>{product.price}</s></span><span>({product.discount}% off)</span></h2>
                            {product.isProductInCart ? (
                                <div>
                                    <div className="border-yellow-400 rounded-2xl border inline px-2 py-1 border-2 text-lg">
                                        <span className="mx-2">-</span>
                                        <span className="mx-2">5</span>
                                        <span className="mx-2">+</span>
                                    </div>
                                </div>
                            ) : (
                                <button className="bg-yellow-400 rounded-4xl px-3 py-2 font-medium mt-4" onClick={() => addToCart(product)}>Add to cart</button>
                            )}
                            
                            
                        </div>
                    </div>
                ))}
            </div>

        </div>
    )

}

export default Products;