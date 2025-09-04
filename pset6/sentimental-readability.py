from cs50 import get_string

text = get_string("Text: ")

sentences = float(text.count(".") + text.count("!") + text.count("?"))

words = float(0.0)
for word in text.split():
    words += 1

letters = float(0.0)
for char in text:
    if char.isalpha():
        letters += 1

l = (letters / words) * 100
s = (sentences / words) * 100

formula = round((0.0588 * l) - (0.296 * s) - 15.8)

if formula < 1:
    print("Before Grade 1")
elif formula >= 16:
    print("Grade 16+")
else:
    print(f"Grade {formula}")
