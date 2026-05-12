a, p, j = map(int, input().split())
plays = []

while True:
    try: 
        play = int(input())
        plays.append(play)
    except EOFError:
        break

levels = [p] * (a + 1)
player = 1
has_loser = False

for play in plays:
    levels[play] -= 1
    if (levels[play] + 1 == 2  and levels[play + 1] == 1):
        print(player)
        has_loser = True
        break
    if (levels[play] == 0):
        print(player)
        has_loser = True
        break

    player = (player + 1) % j

if not has_loser:
    print(-1)