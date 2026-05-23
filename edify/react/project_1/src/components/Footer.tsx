
function Footer() {

    return (
        <footer className="bg-gray-900 text-gray-300 px-6 py-8">
            <div className="max-w-7xl mx-auto grid grid-cols-1 sm:grid-cols-2 md:grid-cols-4 gap-8">
                <div>
                    <h3 className="text-white text-lg font-semibold mb-4">Company</h3>
                    <ul>
                        <li className="mb-2 hover:text-white"><a href="#">About Us</a></li>
                        <li className="mb-2 hover:text-white"><a href="#">Careers</a></li>
                        <li className="mb-2 hover:text-white"><a href="#">Blog</a></li>
                    </ul>
                </div>
                <div>
                    <h3 className="text-white text-lg font-semibold mb-4">Support</h3>
                    <ul>
                        <li className="mb-2 hover:text-white"><a href="#">Help Center</a></li>
                        <li className="mb-2 hover:text-white"><a href="#">Contact Us</a></li>
                        <li className="mb-2 hover:text-white"><a href="#">FAQ</a></li>
                    </ul>
                </div>
                <div>
                    <h3 className="text-white text-lg font-semibold mb-4">Legal</h3>
                    <ul>
                        <li className="mb-2 hover:text-white"><a href="#">Privacy Policy</a></li>
                        <li className="mb-2 hover:text-white"><a href="#">Terms of Service</a></li>
                        <li className="mb-2 hover:text-white"><a href="#">Cookie Policy</a></li>
                    </ul>
                </div>
                <div>
                    <h3 className="text-white text-lg font-semibold mb-4">Stay Connected</h3>
                    <p className="mb-2">Subscribe to our newsletter</p>
                    <form className="flex">
                        <input
                            type="email"
                            placeholder="Email"
                            className="w-full px-3 py-2 rounded-l-md bg-gray-800 text-white focus:outline-none"
                        />
                        <button
                            type="submit"
                            className="bg-blue-600 px-4 py-2 rounded-r-md text-white hover:bg-blue-700"
                        >
                            Subscribe
                        </button>
                    </form>
                </div>
            </div>

            <div className="mt-8 border-t border-gray-700 pt-6 text-center text-sm text-gray-400">
                © {new Date().getFullYear()} Your Company. All rights reserved.
            </div>
        </footer>
    )
}

export default Footer;