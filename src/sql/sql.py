import sqlite3
import csv


sqliteConnection = sqlite3.connect('cars_mock.db')
create_vehicles_table_query = "CREATE TABLE vehicles (id INTEGER, model TEXT, year INTEGER, PRIMARY KEY (id))"
create_makes_table_query = "CREATE TABLE makes (vehicle_id INTEGER, make TEXT, FOREIGN KEY (vehicle_id) REFERENCES vehicles (id))"
cursor = sqliteConnection.cursor()
cursor.execute(create_vehicles_table_query)
cursor.execute(create_makes_table_query)

with open("MOCK_CAR_DATA.csv", "r") as file:
  reader = csv.DictReader(file)
  for row in reader:
    # Insert data into main table
    main_data_tuple = (row["model"], row["year"])
    cursor.execute("INSERT INTO vehicles (model, year) VALUES (?, ?)", main_data_tuple)     # ? = placeholder

    # Get latest id to insert into makes table
    cursor.execute("SELECT MAX(id) FROM vehicles")
    id = cursor.fetchone()[0]

    # Insert data into makes table
    makes_data_tuple = (id, row["make"])
    cursor.execute("INSERT INTO makes (vehicle_id, make) VALUES (?, ?)", sub_data_tuple)
  

sqliteConnection.commit()
# print("Database created and Successfully Connected to SQLite")

# sqlite_select_Query = "select sqlite_version();"
# cursor.execute(sqlite_select_Query)
# record = cursor.fetchall()
# print("SQLite Database Version is: ", record)
cursor.close()


if sqliteConnection:
  sqliteConnection.close()
  print("The SQLite connection is closed")