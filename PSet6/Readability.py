from cs50 import get_string

text = get_string("Text :")  # asking for text
array = text.split(" ")  # putting it in an array

words = 0
letters = 0
sentences = 0

for i in array:
    if len(i) != 1 or i == "I" or i.lower() != "the":  # counting the words
        words += 1

    for j in i:  # counting the letters by (isalpha) function
        if j.isalpha():
            letters += 1

    if ("." in i) or ("!" in i) or ("?" in i):  # counting senteces
        sentences += 1

L = letters / words * 100
S = sentences / words * 100
grade = round(0.0588 * L - 0.296 * S - 15.8)  # substitute in the formula

if grade < 16 and grade > 0:  # printing
    print("Grade " + str(grade))
elif grade < 1:
    print("Before Grade 1")
else:
    print("Grade 16+")
