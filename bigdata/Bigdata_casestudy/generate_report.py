from pymongo import MongoClient
from datetime import datetime
import json

# Connect to MongoDB
client = MongoClient('mongodb://localhost:27017/')
db = client['airlines_db']

# Current year
current_year = datetime.now().year

# Find frequent flyers
frequent_flyers = db['bookings'].aggregate([
    {"$group": {"_id": "$PassengerID", "count": {"$sum": 1}, "total_fare": {"$sum": "$Fare"}}},
    {"$match": {"count": {"$gt": 10}}}
])

# Generate report for each frequent flyer
reports = []
for flyer in frequent_flyers:
    passenger = db['passengers'].find_one({"PassengerID": flyer["_id"]} )
    total_fare_before_discount = flyer["total_fare"]
    total_fare_after_discount = total_fare_before_discount * 0.85

    report = {
        "Name": passenger["Name"],
        "Email": passenger["Email"],
        "Total Flights": flyer["count"],
        "Total Fare Before Discount": total_fare_before_discount,
        "Total Fare After Discount": total_fare_after_discount
    }
    reports.append(report)

# Save reports to a JSON file
with open('frequent_flyers_report.json', 'w') as json_file:
    json.dump(reports, json_file, indent=4)

print("Report generated and saved as 'frequent_flyers_report.json'.")
