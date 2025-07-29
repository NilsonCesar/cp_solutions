import sys

def main_io(s=""):
    if s:
        try:
            sys.stdin = open(f"{s}.in", "r")
            sys.stdout = open(f"{s}.out", "w")
        except IOError as e:
            print(f"Erro ao abrir arquivos: {e}", file=sys.stderr)
            sys.exit(1)

def solve():
    try:
        line = sys.stdin.readline()
        if not line: return
        n, m = map(int, line.split())
    except (IOError, ValueError):
        return

    a = []
    idx = 0
    for _ in range(n):
        try:
            start, end = map(int, sys.stdin.readline().split())
            a.append((start, end, idx))
            idx += 1
        except (IOError, ValueError):
            continue

    a.sort()

    if not a or a[0][0] != 1:
        print("NO")
        return

    ans = []
    k = 0            
    j = 1              
    b = -1             

    while k < len(a):
        if j > m:
            break

        if a[k][0] > j:
            if b == -1:
                j = -1 
                break
            
            ans.append(a[b][2])
            j = a[b][1] + 1
            b = -1
            continue

        elif a[k][0] <= j <= a[k][1]:
            if b == -1 or a[k][1] > a[b][1]:
                b = k
        
        k += 1

    if b != -1:
        if j <= m:
            if a[b][0] <= j and a[b][1] >= j:
                ans.append(a[b][2])
                j = a[b][1] + 1

    if j > m:
        print("YES")
        print(len(ans))
        print(' '.join(str(idx + 1) for idx in ans))
    else:
        print("NO")

if __name__ == "__main__":
    main_io()
    solve()