from sys import argv
import csv
import cs50

# Performs usage check
if len(argv) != 2:
    print("usage error, missing csv file")
    exit()

# Opens the database file
db = cs50.SQL(f"sqlite:///students.db")

with open(argv[1], "r") as students:

    reader = csv.DictReader(students)

    for row in reader:

        # Splits name into an array of either 2 or 3 strs.
        names = row["name"].split()

        # Middle presence check
        if (len(names) == 3):
            middleName = names[1]
            lastName = names[2]
        else:
            middleName = None
            lastName = names[1]

        # Adds data to Database
        db.execute("INSERT INTO students(first, middle, last, house, birth) VALUES(?, ?, ?, ?, ?)",
                   names[0], middleName, lastName, row["house"], row["birth"])
