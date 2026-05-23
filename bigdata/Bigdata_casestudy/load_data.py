import pandas as pd
from pymongo import MongoClient

# Load data from Excel
passengers_df = pd.read_excel('airlines_data.xlsx', sheet_name='Passengers')
flights_df = pd.read_excel('airlines_data.xlsx', sheet_name='Flights')
bookings_df = pd.read_excel('airlines_data.xlsx', sheet_name='Bookings')

# Connect to MongoDB
client = MongoClient('mongodb://localhost:27017/')
db = client['airlines_db']

# Insert data into collections
db['passengers'].insert_many(passengers_df.to_dict('records'))
db['flights'].insert_many(flights_df.to_dict('records'))
db['bookings'].insert_many(bookings_df.to_dict('records'))

print("Data loaded into MongoDB.")
