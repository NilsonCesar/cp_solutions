t = int(input())
ans = False

def is_bit_set(numero, i):
  return (numero & (1 << i)) != 0

def desliga_i_bit(numero, i):
   return numero & ~(1 << i)

def solve(numero, s, c):
   global ans
#    print(numero, s, c)
   if numero == 0:
        ans = True
   for i in range(c):
      if is_bit_set(numero, i):
         temp = desliga_i_bit(numero, i)
         if temp > 0 and is_bit_set(s, temp - 1):
            continue
         solve(temp, s, c)

while t > 0:
    t -= 1
    ans = False
    c = int(input())
    mix = 2 ** c - 1
    s = input()[::-1]
    if s[0] == '1':
       print('No')
       continue
    s = int(s, 2)
    solve(mix, s, c)
    if ans:
       print('Yes')
    else:
       print('No')