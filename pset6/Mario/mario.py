from cs50 import get_int


def printChar(char):
    print(char, end='')


height = 0
while height < 1 or height > 8:
    height = get_int("Height: ")

for i in range(height):
    for j in range(height - (i + 1)):
        printChar(" ")

    for j in range(i + 1):
        printChar("#")

    for j in range(2):
        printChar(" ")

    for j in range(i + 1):
        printChar("#")

    print()
