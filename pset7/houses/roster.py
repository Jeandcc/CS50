from sys import argv
import cs50

# Performs usage check
if len(argv) != 2:
    print("Usage error, missing house name")
    exit()

# Connects with DB
db = cs50.SQL(f"sqlite:///students.db")

# Queries the DB for the students in a given house
result = db.execute(
    f"SELECT * FROM students WHERE house='{argv[1]}' ORDER BY last, first")


for student in result:

    # Conditional formatting considering the existance or not of middle names
    if student["middle"]:
        name = f"{student['first']} {student['middle']} {student['last']}"
    else:
        name = f"{student['first']} {student['last']}"

    # Prints the results in the requested format
    print(
        f"{name}, born {student['birth']}")
