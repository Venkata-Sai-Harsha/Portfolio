import React, { useState, useEffect } from 'react';
import axios from 'axios';
import './DealsPage.css';

const DealsPage = () => {
    const [deals, setDeals] = useState([]);
    const [loading, setLoading] = useState(true);
    const [error, setError] = useState(null);
    
    useEffect(() => {
        const fetchDeals = async () => {
            try {
                const { data } = await axios.get('http://localhost:5000/deals');
                setDeals(data);
                setLoading(false);
            } catch (error) {
                console.error('Error fetching deals:', error);
                setError(error);
                setLoading(false);
            }
        };
    
        fetchDeals();
    }, []);
    
    if (loading) {
        return <div>Loading...</div>;
    }

    if (error) {
        return <div>Error: {error.message}</div>;
    }

    return (
        <div className="deals">
            <h1>Deals</h1>
            <div className="deals-list">
                {deals.map((deal) => (
                    <div key={deal._id} className="deal">
                        <img src={deal.img} alt={deal.name} />
                        <div className="deal-details">
                            <a href={deal.url} target="_blank" rel="noreferrer">
                                <h2>{deal.name}</h2>
                            </a>
                            <p>{deal.source}</p>
                            <p>{deal.price}</p>
                        </div>
                    </div>
                ))}
            </div>
        </div>
    );
};

export default DealsPage;
