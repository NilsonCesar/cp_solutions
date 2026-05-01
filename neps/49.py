def main():
    n = int(input())
    f = input().split()

    fita = []
    loc_0 = []
    aux = []

    for i in range(n):
        if int(f[i]) == 0:
            loc_0.append(i)

    for i in range(n):
        if i in loc_0:
            fita.append(int(f[i]))
        else:
            for l in loc_0:
                aux.append(abs(l-i))
            fita.append(min(9, min(aux)))
            aux.clear()
    print(*fita)

if __name__ == "__main__":
    main()