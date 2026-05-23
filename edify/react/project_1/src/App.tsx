import reactLogo from './assets/react.svg'
import viteLogo from '/vite.svg'
import './App.css';
import Home from './pages/Home';
import Navbar from './components/Navbar';
import Footer from './components/Footer';
import Products from './pages/Products';

function App() {

  return (
    <div>
      <Navbar/>
      
      {/* <Home /> */}
      <Products/>
      <Footer/>
    </div>
  )
}

export default App
