# CS50 Problem Set Solutions


## PSET 1
A set of exercises aimed at getting the student familiar with the C programming language.
1. [Hello](https://github.com/Jeandcc/CS50/blob/master/pset1/hello/hello.c): Simple program whose objective is to output the phrase "Hello X", where "X" is defined through user input.
2. [Mario.c](https://github.com/Jeandcc/CS50/blob/master/pset1/mario/mario.c): Program whose objective is to output a symmetric pyramid of size n, where "n" is an integer greater than 1 and less than or equal to 8, provided by the user.
```
$ ./mario
Height: 4
   #  #
  ##  ##
 ###  ###
####  ####
```

## PSET 2
A set of exercises aimed at familiarization with Functions, Arrays, Command Line Arguments, Variables, and Scopes.
1. [Readability](https://github.com/Jeandcc/CS50/blob/master/pset2/Readability/readability.c): Program focused on determining the level of readability of a text excerpt, using the Coleman-Liau Index to output what (U.S.) grade level is needed to understand the text.
```
$ ./readability
Text: Harry Potter was a highly unusual boy in many ways. For one thing, he hated the summer holidays more than any other time of year. For another, he really wanted to do his homework but was forced to do it in secret, in the dead of the night. And he also happened to be a wizard.
Grade 5
```
3. [Caesar](https://github.com/Jeandcc/CS50/blob/master/pset2/Caesar/caesar.c): Program that encrypts messages using Caesar’s cipher, per the below.
```
$ ./caesar 13
plaintext:  HELLO
ciphertext: URYYB
```
4. [Substitution](https://github.com/Jeandcc/CS50/blob/master/pset2/Substitution/substitution.c): Program that implements a substitution cipher, per the below.
```
$ ./substitution JTREKYAVOGDXPSNCUIZLFBMWHQ
plaintext:  HELLO
ciphertext: VKXXN
```

## PSET 3
A set of exercises that works with the concepts of algorithms, especially those of sorting. The main topics were Linear Search, Binary Search, Bubble Sort, Selection Sort, Insertion Sort, Recursion, and Merge Sort.
1. [Plurarity](https://github.com/Jeandcc/CS50/blob/master/pset3/plurarity/plurality.c): Program that runs a plurality election, per the below.
```
$ ./plurality Alice Bob Charlie
Number of voters: 4
Vote: Alice
Vote: Bob
Vote: Charlie
Vote: Alice
Alice

```
2. [Tideman](https://github.com/Jeandcc/CS50/blob/master/pset3/tideman/tideman.c): Program that runs a Tideman election, per the below:
```
./tideman Alice Bob Charlie
Number of voters: 5
Rank 1: Alice
Rank 2: Charlie
Rank 3: Bob

Rank 1: Alice
Rank 2: Charlie
Rank 3: Bob

Rank 1: Bob
Rank 2: Charlie
Rank 3: Alice

Rank 1: Bob
Rank 2: Charlie
Rank 3: Alice

Rank 1: Charlie
Rank 2: Alice
Rank 3: Bob

Charlie
```

## PSET 4
Set of exercises that provided a better understanding of lower-level subjects such as Pointers, Memory Allocation, Call Stacks, and File Pointers.
1. [Filter](https://github.com/Jeandcc/CS50/blob/master/pset4/filter/filter/helpers.c): Program that applies 1 of 4 types of filters (Grayscale, Blur, Edges, Reflect) to a given BMP image. 
```
$ ./filter -r image.bmp reflected.bmp
```
2. [Recover](https://github.com/Jeandcc/CS50/blob/master/pset4/recover/recover.c): Program that recovers JPEGs from a forensic image, per the below.
```
$ ./recover card.raw
```

## PSET 5
Set of exercises that further refined the understandings about algorithms and data structures, such as Singly-Linked Lists, Hash Tables, and Tries.
1. [Speller](https://github.com/Jeandcc/CS50/blob/master/pset5/speller/dictionary.c): A program that spell-checks a file, a la the below, using a hash table:
```
$ ./speller texts/lalaland.txt
MISSPELLED WORDS

[...]
AHHHHHHHHHHHHHHHHHHHHHHHHHHHT
[...]
Shangri
[...]
fianc
[...]
Sebastian's
[...]
```

## PSET 6
Set of exercises focused on getting students started with the programming language Python.
1. [Hello](https://github.com/Jeandcc/CS50/blob/master/pset6/Hello/hello.py): Recreation of a previously performed exercise when using C as the language. 
2. [Mario](https://github.com/Jeandcc/CS50/blob/master/pset6/Mario/mario.py): Recreation of a previously performed exercise when using C as the language. 
3. [Credit](https://github.com/Jeandcc/CS50/blob/master/pset6/Credit/credit.py): Recreation of a previously performed exercise when using C as the language. 
4. [Readability](https://github.com/Jeandcc/CS50/blob/master/pset6/Redability/readability.py): Recreation of a previously performed exercise when using C as the language. 
5. [Dna](https://github.com/Jeandcc/CS50/blob/master/pset6/DNA/dna.py): Program that identifies a person based on their DNA, per the below.
```
$ python dna.py databases/large.csv sequences/5.txt
Lavender
```

## PSET 7
Set of exercises focused on providing a basic understanding of SQL databases and the most common operations performed on such databases.
1. [Movies](https://github.com/Jeandcc/CS50/tree/master/pset7/movies): Set of database queries, aiming to answer the questions posed by the exercise [here](https://cs50.harvard.edu/x/2020/psets/7/movies/#specification). 
2. Program that [imports](https://github.com/Jeandcc/CS50/blob/master/pset7/houses/import.py) student data into a database, and then [produces class rosters](https://github.com/Jeandcc/CS50/blob/master/pset7/houses/roster.py). Example:
```
$ python import.py characters.csv
$ python roster.py Gryffindor

Lavender Brown, born 1979
Colin Creevey, born 1981
Seamus Finnigan, born 1979
Hermione Jean Granger, born 1979
Neville Longbottom, born 1980
Parvati Patil, born 1979
Harry James Potter, born 1980
Dean Thomas, born 1980
Romilda Vane, born 1981
Ginevra Molly Weasley, born 1981
Ronald Bilius Weasley, born 1980
```
