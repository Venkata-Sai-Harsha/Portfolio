import random
from datetime import datetime, timedelta
from pymongo import MongoClient
from collections import defaultdict

# Number of records
num_records = 1000
data = []

start_date = datetime(2023, 1, 1)
end_date = datetime(2023, 12, 31)

for user_id in range(1, num_records + 1):
    access_date = start_date + timedelta(
        days=random.randint(0, (end_date - start_date).days)
    )
    reading_duration = random.randint(1, 300)  # Duration in minutes
    data.append(
        (
            f"user_{user_id}",
            access_date.strftime("%Y-%m-%d"),
            reading_duration,
        )
    )

# Step 2: Store Data in MongoDB
client = MongoClient("mongodb://localhost:27017/")
db = client.newspaper_db
collection = db.reading_data

# Clear existing collection
collection.delete_many({})

# Insert generated data
for record in data:
    collection.insert_one(
        {
            "user_id": record[0],
            "access_date": record[1],
            "reading_duration": record[2],
        }
    )

# Mapper
def mapper():
    for record in collection.find():
        yield (record["reading_duration"], 1)

# Shuffle and Sort
def shuffle_and_sort(mapped_data):
    sorted_data = defaultdict(list)
    for key, value in mapped_data:
        sorted_data[key].append(value)
    return sorted_data

# Reducer
def reducer(sorted_data):
    min_duration = float("inf")
    max_duration = float("-inf")
    min_count = 0
    max_count = 0

    for duration, counts in sorted_data.items():
        count = sum(counts)
        if duration < min_duration:
            min_duration = duration
            min_count = count
        elif duration == min_duration:
            min_count += count

        if duration > max_duration:
            max_duration = duration
            max_count = count
        elif duration == max_duration:
            max_count += count

    return (min_duration, min_count), (max_duration, max_count)

# Execute mapper
mapped_data = list(mapper())

# Shuffle and sort the mapped data
sorted_data = shuffle_and_sort(mapped_data)

# Execute reducer
min_result, max_result = reducer(sorted_data)

# Output final result
print(f"Minimum duration of online reading: {min_result[0]} minutes with {min_result[1]} users")
print("\n")
print(f"Maximum duration of online reading: {max_result[0]} minutes with {max_result[1]} users")
