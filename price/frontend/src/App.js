import React, { useState, useEffect } from "react";
import axios from "axios";
import { BrowserRouter as Router, Routes, Route, Navigate } from "react-router-dom";
import Header from "./components/Header";
import Login from "./components/Login";
import Forgot from "./components/Forgot";
import Signup from "./components/Signup";
import Home from "./components/Home";
import Subscription from './components/Subscription';
import DealsPage from './components/DealsPage'; // Import the DealsPage component
import "./App.css";

const URL = "http://localhost:5000";

function App() {
  const [showPriceHistory, setShowPriceHistory] = useState(false);
  const [priceHistory, setPriceHistory] = useState([]);
  const [searchTexts, setSearchTexts] = useState([]);
  const [newSearchText, setNewSearchText] = useState("");
  const [isAuthenticated, setIsAuthenticated] = useState(false);
  const [userName, setUserName] = useState("");

  useEffect(() => {
    fetchUniqueSearchTexts();
    checkAuthStatus();
  }, []);

  const checkAuthStatus = () => {
    const token = localStorage.getItem("token");
    const name = localStorage.getItem("userName");
    if (token && name) {
      setIsAuthenticated(true);
      setUserName(name);
    }
  };

  const fetchUniqueSearchTexts = async () => {
    try {
      const response = await axios.get(`${URL}/unique_search_texts`);
      const data = response.data;
      setSearchTexts(data);
    } catch (error) {
      console.error("Error fetching unique search texts:", error);
    }
  };

  const handleSearchTextClick = async (searchText) => {
    try {
      const response = await axios.get(`${URL}/results?search_text=${searchText}`);
      const data = response.data;
      setPriceHistory(data);
      setShowPriceHistory(true);
    } catch (error) {
      console.error("Error fetching price history:", error);
    }
  };

  const handlePriceHistoryClose = () => {
    setShowPriceHistory(false);
    setPriceHistory([]);
  };

  const handleNewSearchTextChange = (event) => {
    setNewSearchText(event.target.value);
  };

  const handleNewSearchTextSubmit = async (event) => {
    event.preventDefault();
    try {
      await axios.post(`${URL}/start-scraper`, {
        search_text: newSearchText,
        url: "https://amazon.in",
      });
      alert("Scraper started successfully. Please wait for 2-3 minutes.");
      setSearchTexts([...searchTexts, newSearchText]);
      setNewSearchText("");
    } catch (error) {
      alert("Error starting scraper:", error);
    }
  };

  const handleLoginSuccess = (token, name) => {
    localStorage.setItem("token", token);
    localStorage.setItem("userName", name);
    setIsAuthenticated(true);
    setUserName(name);
  };

  const handleSignupSuccess = (token, name) => {
    handleLoginSuccess(token, name);
  };

  const handleLogout = () => {
    localStorage.removeItem("token");
    localStorage.removeItem("userName");
    setIsAuthenticated(false);
    setUserName("");
  };

  return (
    <Router>
      <div className="main">
        <Header isAuthenticated={isAuthenticated} userName={userName} onLogout={handleLogout} />
        <Routes>
          <Route path="/" element={<Navigate to="/home" />} />
          <Route
            path="/home"
            element={
              <Home
                searchTexts={searchTexts}
                handleNewSearchTextSubmit={handleNewSearchTextSubmit}
                newSearchText={newSearchText}
                handleNewSearchTextChange={handleNewSearchTextChange}
                handleSearchTextClick={handleSearchTextClick}
                showPriceHistory={showPriceHistory}
                priceHistory={priceHistory}
                handlePriceHistoryClose={handlePriceHistoryClose}
              />
            }
          />
          <Route path="/login" element={<Login onLoginSuccess={handleLoginSuccess} />} />
          <Route path="/forgot" element={<Forgot />} />
          <Route path="/signup" element={<Signup onSignupSuccess={handleSignupSuccess} />} />
          <Route path="/subscribe" element={<Subscription />} />
          <Route path="/deals" element={<DealsPage />} /> 
        </Routes>
      </div>
    </Router>
  );
}

export default App;
