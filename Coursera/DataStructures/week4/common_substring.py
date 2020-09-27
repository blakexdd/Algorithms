# python3

import sys
from collections import namedtuple
import numpy as np

Answer = namedtuple('answer_type', 'i j len')

def compute_hash(s, t):
	m1 = 10 ** 9 + 7
	m2 = 10 ** 9 + 9
	x = 4
	h1 = np.zeros(len(s))
	h2 = np.zeros(len(t))

	for i in range(1, len(s)):
		h1[i] = (x * h1[i - 1] + ord(s[i - 1])) % m1

	for i in range(1, len(t)):
		h2[i] = (x * h2[i - 1] + ord(s[i - 1])) % m2

	return h1, h2

def solve(s, t):
	ans = Answer(0, 0, 0)
	x = 4
	h1, h2 = compute_hash(s, t)
	for i in range(min(len(s), len(t)) - 1, 0, -1):
		partial_hash1 = np.zeros(len(h1) - i + 1)
		partial_hash2 = np.zeros(len(h2) - i + 1)
		for j in range(1, len(partial_hash1), i):
			partial_hash1[j] = partial_hash1[j + i] - (x ** i) * partial_hash1[j]

		for j in range(1, len(partial_hash1), i):
			partial_hash2[j] = partial_hash2[j + i] - (x ** i) * partial_hash2[j]

		

	return ans

for line in sys.stdin.readlines():
	s, t = line.split()
	ans = solve(s, t)
	print(ans.i, ans.j, ans.len)
