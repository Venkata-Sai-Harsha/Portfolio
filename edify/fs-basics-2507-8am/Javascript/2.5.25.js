var busName = 'KSM Roadways';

var busType = 'Bharat Benz A/C Sleeper (2+1)';

var price = 1879;

var averageRating = 4.8;

var ratingCount = 1332;

var availableSeats = 28;

var availableSingleSeats = 9;

var isUserLoggedIn = true;

var isUserActive = true;

var isAccountSuspended = false;

var busName2 = 'Vikram Travels';

var busName3 = 'BSR Tours And Travels';

var busName4 = 'TVK Travels';

var busNames = ['KSM Roadways', 'Vikram Travels', 'BSR Tours And Travels', 'TVK Travels'];

console.log(busNames[3]);

busNames[3] = 'Royal Rich India - R No 208';

console.log(busNames);

var subjectMarks = [45, 89, 67, 34, 89, 45];

console.log(subjectMarks);

var busInfo = [
    ['name', 'KSM Roadways'],
    ['type', 'Bharat Benz A/C Sleeper (2+1)'],
    ['price', 1879],
    ['averageRating', 4.8]
];

console.log(busInfo[0][1]);

var busInfo = ['KSM Roadways', 'Bharat Benz A/C Sleeper (2+1)', 1879, 4.8, 28, 9];

var busInfo = {
    name: 'KSM Roadways',
    type: 'Bharat Benz A/C Sleeper (2+1)',
    price: 1879,
    avgRating: 4.8,
    availableSeats: 28,
    availableSingleSeats: 9,
    amenities: ['Water Bottle', 'Blankets', 'Charging Point', 'Reading Light', 'Pillow'],
    ratings: [
        {
            type: 5,
            percentage: 84
        },
        {
            type: 4,
            percentage: 12
        },
        {
            type: 3,
            percentage: 2
        },
        {
            type: 2,
            percentage: 1
        },
        {
            type: 1,
            percentage: 1
        }
    ]
};

console.log(busInfo['price']);

console.log(busInfo.ratings[0]['type'], busInfo.ratings[0]['percentage']);

console.log(busInfo.ratings[1]['type'], busInfo.ratings[1]['percentage']);

var buses = [
    {
        name: 'KSM Roadways',
        type: 'Bharat Benz A/C Sleeper (2+1)',
        price: 1879,
        avgRating: 4.8,
        availableSeats: 28,
        availableSingleSeats: 9,
        amenities: ['Water Bottle', 'Blankets', 'Charging Point', 'Reading Light', 'Pillow'],
        ratings: [
            {
                type: 5,
                percentage: 84
            },
            {
                type: 4,
                percentage: 12
            },
            {
                type: 3,
                percentage: 2
            },
            {
                type: 2,
                percentage: 1
            },
            {
                type: 1,
                percentage: 1
            }
        ]
    },
    {
        name: 'KSM Roadways',
        type: 'Bharat Benz A/C Sleeper (2+1)',
        price: 1879,
        avgRating: 4.8,
        availableSeats: 28,
        availableSingleSeats: 9,
        amenities: ['Water Bottle', 'Blankets', 'Charging Point', 'Reading Light', 'Pillow'],
        ratings: [
            {
                type: 5,
                percentage: 84
            },
            {
                type: 4,
                percentage: 12
            },
            {
                type: 3,
                percentage: 2
            },
            {
                type: 2,
                percentage: 1
            },
            {
                type: 1,
                percentage: 1
            }
        ]
    },
    {
        name: 'KSM Roadways',
        type: 'Bharat Benz A/C Sleeper (2+1)',
        price: 1879,
        avgRating: 4.8,
        availableSeats: 28,
        availableSingleSeats: 9,
        amenities: ['Water Bottle', 'Blankets', 'Charging Point', 'Reading Light', 'Pillow'],
        ratings: [
            {
                type: 5,
                percentage: 84
            },
            {
                type: 4,
                percentage: 12
            },
            {
                type: 3,
                percentage: 2
            },
            {
                type: 2,
                percentage: 1
            },
            {
                type: 1,
                percentage: 1
            }
        ]
    },
    {
        name: 'KSM Roadways',
        type: 'Bharat Benz A/C Sleeper (2+1)',
        price: 1879,
        avgRating: 4.8,
        availableSeats: 28,
        availableSingleSeats: 9,
        amenities: ['Water Bottle', 'Blankets', 'Charging Point', 'Reading Light', 'Pillow'],
        ratings: [
            {
                type: 5,
                percentage: 84
            },
            {
                type: 4,
                percentage: 12
            },
            {
                type: 3,
                percentage: 2
            },
            {
                type: 2,
                percentage: 1
            },
            {
                type: 1,
                percentage: 1
            }
        ]
    }
]

var vegetables = [
    {
        id: 1,
        imageUrl: 'https://cdn.zeptonow.com/production/ik-seo/tr:w-400,ar-3000-3000,pr-true,f-auto,q-80/cms/product_variant/708792d1-c428-41df-bf83-277e74a5b46d/Tomato-Local.jpeg',
        name: 'Tomato Local',
        quantity: 0.5,
        actualPrice: 43,
        discountedPrice: 23,
        discount: 46
    },
    {
        id: 2,
        imageUrl: 'https://cdn.zeptonow.com/production/ik-seo/tr:w-400,ar-3000-3000,pr-true,f-auto,q-80/cms/product_variant/708792d1-c428-41df-bf83-277e74a5b46d/Tomato-Local.jpeg',
        name: 'Tomato Local',
        quantity: 0.5,
        actualPrice: 43,
        discountedPrice: 23,
        discount: 46
    },
    {
        id: 3,
        imageUrl: 'https://cdn.zeptonow.com/production/ik-seo/tr:w-400,ar-3000-3000,pr-true,f-auto,q-80/cms/product_variant/708792d1-c428-41df-bf83-277e74a5b46d/Tomato-Local.jpeg',
        name: 'Tomato Local',
        quantity: 0.5,
        actualPrice: 43,
        discountedPrice: 23,
        discount: 46
    },
    {
        id: 4,
        imageUrl: 'https://cdn.zeptonow.com/production/ik-seo/tr:w-400,ar-3000-3000,pr-true,f-auto,q-80/cms/product_variant/708792d1-c428-41df-bf83-277e74a5b46d/Tomato-Local.jpeg',
        name: 'Tomato Local',
        quantity: 0.5,
        actualPrice: 43,
        discountedPrice: 23,
        discount: 46
    }
]

console.log(vegetables[0].imageUrl);

document.getElementById('grocery-image').src = vegetables[0].imageUrl;
document.getElementById('name').innerHTML = vegetables[0].name;
