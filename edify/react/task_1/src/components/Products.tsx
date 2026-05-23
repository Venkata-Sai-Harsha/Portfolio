// ProductList.tsx

// import React from "react";

interface Product {
  id: number;
  brand: string;
  name: string;
  price: number;
  originalPrice: number;
  discount: string;
  rating: number;
  reviews: string;
  imageUrl: string;
}

const products: Product[] = [
  {
    id: 1,
    brand: "Powerlook",
    name: "Men Checked Casual Shirt",
    price: 971,
    originalPrice: 1799,
    discount: "46% OFF",
    rating: 4,
    reviews: "889",
    imageUrl: "https://assets.myntassets.com/f_webp,dpr_1.5,q_60,w_210,c_limit,fl_progressive/assets/images/30203386/2024/JULY/13/9AIXZvWO_b05a69e224b94c9a894c4563ee8bf776.jpg"
  },
  {
    id: 2,
    brand: "Mast & Harbour",
    name: "Printed Pure Cotton Shirt",
    price: 674,
    originalPrice: 2499,
    discount: "73% OFF",
    rating: 3.7,
    reviews: "10",
    imageUrl: "https://assets.myntassets.com/f_webp,dpr_1.5,q_60,w_210,c_limit,fl_progressive/assets/images/32156759/2025/2/11/5e3f6de1-90d5-4a37-bb2d-0b6f31a6ca1d1739254746751-Mast--Harbour-Men-Shirts-7361739254746242-1.jpg"
  },
  {
    id: 3,
    brand: "The Indian Garage Co",
    name: "Regular Fit Casual Shirt",
    price: 507,
    originalPrice: 1749,
    discount: "71% OFF",
    rating: 4.3,
    reviews: "6.4k",
    imageUrl: "https://assets.myntassets.com/f_webp,dpr_1.5,q_60,w_210,c_limit,fl_progressive/assets/images/2024/JULY/31/ZsgAZHVX_c54469e10bb54d00a7714a1b364a04bd.jpg"
  },
  {
    id: 4,
    brand: "Mast & Harbour",
    name: "Opaque Cotton Casual Shirt",
    price: 791,
    originalPrice: 2399,
    discount: "67% OFF",
    rating: 4.4,
    reviews: "1.7k",
    imageUrl: "https://assets.myntassets.com/f_webp,dpr_1.5,q_60,w_210,c_limit,fl_progressive/assets/images/17357496/2022/3/16/8cb8a784-eb4b-43ed-a92c-9fb3180150661647425390596-The-Indian-Garage-Co-Men-Shirts-8551647425390053-1.jpg"
  },
  {
    id: 5,
    brand: "Campus Sutra",
    name: "Spread Collar Casual Shirt",
    price: 759,
    originalPrice: 1899,
    discount: "60% OFF",
    rating: 4.4,
    reviews: "13.3k",
    imageUrl: "https://assets.myntassets.com/f_webp,dpr_1.5,q_60,w_210,c_limit,fl_progressive/assets/images/28219632/2024/3/12/2f53aaab-40e1-4c5b-8148-6ad150e5f4341710256687634CampusSutraMenClassicOpaqueCheckedCasualShirt2.jpg"
  }
];
const Products: React.FC = () => {
  return (
    <div className="p-8">
      <div className="grid grid-cols-1 sm:grid-cols-2 md:grid-cols-3 lg:grid-cols-5 gap-5">
        {products.map((product) => (
          <div key={product.id} className="bg-white rounded-lg shadow-md overflow-hidden">
            <img src={product.imageUrl} alt={product.name} className="w-full h-72 object-cover" />
            <div className="p-4">
              <div className="flex items-center space-x-1 text-green-600 font-semibold">
                <span>{product.rating}</span>
                <span className="text-sm text-gray-600">★ | {product.reviews}</span>
              </div>
              <h2 className="mt-1 font-bold text-gray-800">{product.brand}</h2>
              <p className="text-sm text-gray-600">{product.name}</p>
              <div className="mt-2 text-sm">
                <span className="font-bold text-gray-800">Rs. {product.price}</span>{' '}
                <span className="line-through text-gray-400">Rs. {product.originalPrice}</span>{' '}
                <span className="text-orange-600">{product.discount}</span>
              </div>
            </div>
          </div>
        ))}
      </div>
    </div>
  );
};

export default Products;
