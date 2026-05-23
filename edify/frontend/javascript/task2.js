var zepto=[
    {
        "id": 1,
        imageurl: "https://cdn.zeptonow.com/production/ik-seo/tr:w-400,ar-3000-3000,pr-true,f-auto,q-80/cms/product_variant/6b2be8eb-861b-44a6-8f83-f25580d19759/Mango-Alphonso-2-Pc.jpeg",
        product_name: "Mango Alphonso 2 Pc",
        quantity: "2 pc (350-400g)",
        price: "₹ 222"
    },
    {
        "id":2,
        imageurl:"https://cdn.zeptonow.com/production/ik-seo/tr:w-400,ar-2924-3000,pr-true,f-auto,q-80/cms/product_variant/3adc39a4-e8dc-4da5-84e8-872396a75bdc/Muskmelon.jpeg",
        product_name:"Muskmelon",
        quantity:"600 - 800 g",
        price:"₹ 43"
    },
    {
        "id":3,
        imageurl:"https://cdn.zeptonow.com/production/ik-seo/tr:w-400,ar-3000-3000,pr-true,f-auto,q-80/cms/product_variant/d684d49f-850e-4c4a-bed3-2f5ec4ba9c3c/Watermelon-Kiran-Tarbooj-.jpeg",
        product_name:"Watermelon",
        quantity:"1 pc (1.5 - 2 kg)",
        price:"₹ 60"
    },
    {
        "id":4,
        imageurl:"https://cdn.zeptonow.com/production/ik-seo/tr:w-400,ar-3000-3000,pr-true,f-auto,q-80/cms/product_variant/9c45acfa-024c-4400-b46e-098580358421/Mango-Banganapalli.jpeg",
        product_name:"Mango Banganapalli",
        quantity:"1Kg",
        price:"₹ 143"
    },
    {
        "id":5,
        imageurl:"https://cdn.zeptonow.com/production/ik-seo/tr:w-400,ar-450-330,pr-true,f-auto,q-80/inventory/product/50289a70-bf37-443c-8e6a-4ee60a84831a-51f152e5-b877-42a7-9692-a2c5412c86bc/Jack-Fruit-Bulbs.jpeg",
        product_name:"Jack Fruit Bulbs",
        quantity:"200g",
        price:"₹ 114"
    }

]

document.getElementById("image1").setAttribute("src", zepto[0].imageurl);
document.getElementById("product_name1").innerHTML = zepto[0].product_name;
document.getElementById("quantity1").innerHTML = zepto[0].quantity;
document.getElementById("price1").innerHTML = zepto[0].price;

document.getElementById("image2").setAttribute("src", zepto[1].imageurl);
document.getElementById("product_name2").innerHTML = zepto[1].product_name;
document.getElementById("quantity2").innerHTML = zepto[1].quantity;
document.getElementById("price2").innerHTML = zepto[1].price;

document.getElementById("image3").setAttribute("src", zepto[2].imageurl);
document.getElementById("product_name3").innerHTML = zepto[2].product_name;
document.getElementById("quantity3").innerHTML = zepto[2].quantity;
document.getElementById("price3").innerHTML = zepto[2].price;

document.getElementById("image4").setAttribute("src", zepto[3].imageurl);
document.getElementById("product_name4").innerHTML = zepto[3].product_name;
document.getElementById("quantity4").innerHTML = zepto[3].quantity;
document.getElementById("price4").innerHTML = zepto[3].price;

document.getElementById("image5").setAttribute("src", zepto[4].imageurl);
document.getElementById("product_name5").innerHTML = zepto[4].product_name;
document.getElementById("quantity5").innerHTML = zepto[4].quantity;
document.getElementById("price5").innerHTML = zepto[4].price;
