import cs50

cCardStr = str(cs50.get_int("Number: "))


def checksum(string):
    digits = list(map(int, string))
    odd_sum = sum(digits[-1::-2])
    even_sum = sum([sum(divmod(2 * d, 10)) for d in digits[-2::-2]])
    return (odd_sum + even_sum) % 10


def verify(string):
    return (checksum(string) == 0)


if not verify(cCardStr):
    print("INVALID")
    exit()

isAmex = False
isMastercard = False
isVisa = False
first2Digits = int(cCardStr[:2])

if first2Digits == 34 or first2Digits == 37:
    isAmex = True
if first2Digits >= 51 and first2Digits <= 55:
    isMastercard = True
if first2Digits >= 40 and first2Digits <= 49:
    isVisa = True

if (isAmex):
    print("AMEX")
if (isMastercard):
    print("MASTERCARD")
if (isVisa):
    print("VISA")
else:
    print("INVALID")
