s = input()
letters = {letter: True for letter in 'abcdefghijklmnopqrstuvwxyz'}

for c in s:
    letters[c] = False

for l in letters:
    if letters[l]:
        print(l)
        break