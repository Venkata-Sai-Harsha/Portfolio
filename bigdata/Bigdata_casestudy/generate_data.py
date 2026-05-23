import pandas as pd
import numpy as np
from faker import Faker

fake = Faker()

# Number of entries to generate
num_passengers = 1000
num_flights = 100
num_bookings = 10000

# Generate Passengers data
passengers_data = {
    "PassengerID": range(1, num_passengers + 1),
    "Name": [fake.name() for _ in range(num_passengers)],
    "Email": [fake.email() for _ in range(num_passengers)],
    "PhoneNumber": [fake.phone_number() for _ in range(num_passengers)],
    "FrequentFlyer": [fake.boolean(chance_of_getting_true=25) for _ in range(num_passengers)]
}
passengers_df = pd.DataFrame(passengers_data)

# Generate Flights data
flights_data = {
    "FlightID": range(1, num_flights + 1),
    "FlightNumber": [fake.bothify(text='??###') for _ in range(num_flights)],
    "Departure": [fake.city() for _ in range(num_flights)],
    "Destination": [fake.city() for _ in range(num_flights)],
    "Date": [fake.date_this_year() for _ in range(num_flights)]
}
flights_df = pd.DataFrame(flights_data)

# Generate Bookings data
bookings_data = {
    "BookingID": range(1, num_bookings + 1),
    "PassengerID": [fake.random_int(min=1, max=num_passengers) for _ in range(num_bookings)],
    "FlightID": [fake.random_int(min=1, max=num_flights) for _ in range(num_bookings)],
    "Fare": [fake.random_int(min=50, max=1000) for _ in range(num_bookings)],
    "Date": [fake.date_this_year() for _ in range(num_bookings)]
}
bookings_df = pd.DataFrame(bookings_data)

# Save to Excel
output_file = 'airlines_data.xlsx'
with pd.ExcelWriter(output_file) as writer:
    passengers_df.to_excel(writer, sheet_name='Passengers', index=False)
    flights_df.to_excel(writer, sheet_name='Flights', index=False)
    bookings_df.to_excel(writer, sheet_name='Bookings', index=False)

print(f"Datasets generated and saved to '{output_file}'.")
