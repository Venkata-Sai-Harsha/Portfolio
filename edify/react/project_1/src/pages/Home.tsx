function Home() {

    return (
        <main>
            <section className="bg-gray-100 text-center py-16 px-6">
                <div className="max-w-4xl mx-auto">
                    <h2 className="text-4xl md:text-5xl font-bold mb-4">Your One-Stop Tech Shop</h2>
                    <p className="text-lg mb-6">Latest gadgets, best prices, and free delivery!</p>
                    <a href="#" className="bg-blue-600 text-white px-6 py-3 rounded hover:bg-blue-700 transition">Shop Now</a>
                </div>
            </section>

            <section className="py-12 px-6">
                <div className="max-w-7xl mx-auto">
                    <h3 className="text-2xl font-semibold mb-8">Featured Products</h3>
                    <div className="grid grid-cols-1 sm:grid-cols-2 md:grid-cols-4 gap-8">
                        <div className="bg-white shadow-md rounded-lg overflow-hidden">
                            <img src="https://via.placeholder.com/300x200?text=Headphones" alt="Product" className="w-full h-40 object-cover" />
                            <div className="p-4">
                                <h4 className="text-lg font-semibold">Wireless Headphones</h4>
                                <p className="text-blue-600 font-bold mt-2">₹2,999</p>
                            </div>
                        </div>
                        <div className="bg-white shadow-md rounded-lg overflow-hidden">
                            <img src="https://via.placeholder.com/300x200?text=Smart+Watch" alt="Product" className="w-full h-40 object-cover" />
                            <div className="p-4">
                                <h4 className="text-lg font-semibold">Smart Watch</h4>
                                <p className="text-blue-600 font-bold mt-2">₹4,499</p>
                            </div>
                        </div>
                        <div className="bg-white shadow-md rounded-lg overflow-hidden">
                            <img src="https://via.placeholder.com/300x200?text=Mouse" alt="Product" className="w-full h-40 object-cover" />
                            <div className="p-4">
                                <h4 className="text-lg font-semibold">Gaming Mouse</h4>
                                <p className="text-blue-600 font-bold mt-2">₹1,299</p>
                            </div>
                        </div>
                        <div className="bg-white shadow-md rounded-lg overflow-hidden">
                            <img src="https://via.placeholder.com/300x200?text=Speaker" alt="Product" className="w-full h-40 object-cover" />
                            <div className="p-4">
                                <h4 className="text-lg font-semibold">Bluetooth Speaker</h4>
                                <p className="text-blue-600 font-bold mt-2">₹1,999</p>
                            </div>
                        </div>
                    </div>
                </div>
            </section>
        </main>
    )

}

export default Home;