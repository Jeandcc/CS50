text = input("Text: ")

countletters = 0
countwords = 0
countsentences = 0

if text[0].isalpha:
    countwords += 1

for i in range(len(text)):
    if text[i].isalpha():
        countletters += 1
    if (text[i].isspace() or text[i] == '"') and (i+1 < len(text) and text[i+1].isalpha()):
        countwords += 1
    if text[i] == '.' or text[i] == '!' or text[i] == '?':
        countsentences += 1

factor = 100 / countwords
L = countletters * factor
S = countsentences * factor

index = 0.0588 * L - 0.296 * S - 15.8

if index < 1:
    print("Before Grade 1")
elif index >= 16:
    print("Grade 16+")
else:
    print(f"Grade {round(index)}")
