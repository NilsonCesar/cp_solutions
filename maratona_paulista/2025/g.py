s = input()

if ('B?-' in s or '?R-' in s or 'BR?' in s):
    print('S' if 'SP' in s else 'N')
elif ('S?' in s or '?P' in s):
    print('T')
else:
    print('N')