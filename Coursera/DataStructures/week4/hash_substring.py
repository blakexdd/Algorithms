# python3
#import numpy as np

def read_input():
    return (input().rstrip(), input().rstrip())

def print_occurrences(output):
    print(' '.join(map(str, output)))

def computeHash(s, m, p):
    ans = 0
    for c in reversed(s):
        ans = (ans * m + ord(c)) % p

    return ans

def get_occurrences(pattern, text):
    ans = []
    hashes = [0] * (len(text) - len(pattern) + 1)#np.zeros(len(text) - len(pattern) + 1)

    multiplier = 263
    prime = 1000000007

    pattern_hash = computeHash(pattern, multiplier, prime)
    hashes[len(text) - len(pattern)] = computeHash(text[len(text) - len(pattern):], multiplier, prime)
    y = 1

    for i in range(0, len(pattern)):
        y = (y * multiplier) % prime

    for i in range(len(text) - len(pattern) - 1, -1, -1):
        hashes[i] = (multiplier * hashes[i + 1] + ord(text[i]) - y * ord(text[i + len(pattern)])) % prime

    for i in range(0, len(text) - len(pattern) + 1):
        if hashes[i] == pattern_hash:
            if text[i:i + len(pattern)] == pattern:
                ans.append(i)

    return ans

if __name__ == '__main__':
    print_occurrences(get_occurrences(*read_input()))

