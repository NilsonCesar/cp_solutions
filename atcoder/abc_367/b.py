x = input()

while True:
    if x[-1] == "0":
        x = x[:-1]
    elif x[-1] == ".":
        x = x[:-1]
        break
    else:
        break

print(x)