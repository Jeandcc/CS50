from sys import argv
import csv

# Performs usage check
if len(argv) != 3:
    print("usage error, dna.py sequence.txt database.csv")
    exit()

# Opens the CSV file provided
with open(argv[1], "r") as dnaDatabase:
    dnaDbObj = csv.DictReader(dnaDatabase)
    matchesDict = {}

    # Opens the text file provided with the DNA sequence to be tested
    with open(argv[2], "r") as textFile:
        dnaSequence = textFile.read()

        # Loops through the Short Tandem Repeats (STRs) that the CSV looks for
        for sequence in dnaDbObj.fieldnames[1:]:

            lastFound = 0
            offset = 0
            foundIndexes = []

            # Goes through the DNA sequence looking for occurrences of a STR
            while dnaSequence.find(sequence, lastFound + offset) != -1:
                lastFound = dnaSequence.find(sequence, lastFound + offset)
                foundIndexes.append(lastFound)
                offset = len(sequence)

            # Iterates through the array of found indexes and computes the
            # largest sequences of repetitions
            currentSequence = 0
            biggestSequence = 0

            for i in range(len(foundIndexes)-1):
                # Checks if the indexes are in sequence given the length of the
                # STR.
                if foundIndexes[i+1] - foundIndexes[i] == len(sequence):
                    currentSequence += 1

                    # Updates the info about the biggest sequence
                    if currentSequence >= biggestSequence:
                        # The +1 accounts for the first STR of the current sequence
                        biggestSequence = currentSequence + 1

                # Resets the count to compute a (possible) new sequence
                else:
                    currentSequence = 0

            # Populates a dictionary with the most times a given STR occurs in sequence
            matchesDict[sequence] = biggestSequence

            # Fallback if only one STR was found in the DNA
            if len(foundIndexes) == 1:
                matchesDict[sequence] = 1

        def findAMatch(database, matchesDict):
            # Loops through each person in the database
            for person in database:

                isMatch = True

                for info in person:

                    # Disregards the name column
                    if info == "name":
                        continue

                    # Compares the amount of times a given STR occurs at most
                    # for a given person and the amount found in the DNA string
                    if int(person[info]) != matchesDict[info]:
                        isMatch = False
                        break

                # If no discrepancies were found, it's safe to assume that this
                # is the owner of the DNA
                if isMatch:
                    return person['name']

            # It will only reach this line if no one was a match for the DNA string
            return "No match"

        match = findAMatch(dnaDbObj, matchesDict)
        print(match)
