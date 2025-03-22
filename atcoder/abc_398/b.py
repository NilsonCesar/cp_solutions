a = map(int, input().split())
cards = dict()
three = False
two = False
for c in a:
    v = cards.setdefault(c, 0)
    cards[c] = v + 1

for c in cards:
    if cards[c] >= 3 and not three:
        three = True
    elif cards[c] >= 2 and not two:
        two = True

print('Yes' if two and three else 'No')
