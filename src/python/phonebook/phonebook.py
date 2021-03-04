import csv

## Open csv file in append mode and write to it using the csv library ##
with open("phonebook.csv", "a") as file:    # Use this syntax to automatically file.close()
  name = input("Enter name: ")
  number = input("Enter number: ")
  
  writer = csv.writer(file)   # Wrap file to start writing to it
  writer.writerow([name, number])
