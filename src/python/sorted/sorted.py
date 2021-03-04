import csv

with open("./MOCK_DATA.csv", "r") as file:
  cars = {}
  reader = csv.DictReader(file)   # Use DictReader to read data in as a dictionary and take the columns into account

  for row in reader:
    if row['car'] not in cars:
      cars[row['car']] = 1
    cars[row['car']] += 1

  
for car in sorted(cars, key=lambda car: cars[car], reverse=True):   # Use a lambda function to sort by the count (values) instead of the brand (keys)
  print(car, cars[car])
