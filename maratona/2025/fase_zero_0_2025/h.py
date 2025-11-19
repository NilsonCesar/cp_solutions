def build_palindrome(h_str, length):
    rev_h = h_str[::-1]
    if length % 2 != 0:
        return h_str + rev_h[1:]
    else:
        return h_str + rev_h

def solve():
    x = int(input())

    bin_half = bin(x)[2:]
    bin_len = len(bin_half)
    half_len = (bin_len + 1) // 2
    half_part = bin_half[:half_len]

    first_palindrome = build_palindrome(half_part, bin_len)
    first_n = int(first_palindrome, 2)

    if first_n <= x:
        print(first_n)
    else:
        half_n = int(half_part, 2)
        new_half_n = half_n - 1
        
        min_k_bit_val = 1 << (half_len - 1)

        if new_half_n < min_k_bit_val:
            print((1 << (bin_len - 1)) - 1)
        else:
            new_half_palindrome = bin(new_half_n)[2:]
            new_half_palindrome = new_half_palindrome.zfill(half_len) 
            second_palindrome = build_palindrome(new_half_palindrome, bin_len)
            print(int(second_palindrome, 2))

solve()