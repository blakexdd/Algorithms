# python3
from random import randint
import sys
import numpy as np

class Solver:
	def __init__(self, s):
		self.s = s
		self.m1 = 20000124533
		self.m2 = 10000127909
		self.x = 4
		self.h1 = np.zeros(len(self.s))
		self.h2 = np.zeros(len(self.s))
		self.pows = np.zeros(len(self.s))
		self.pows[0] = 1

		for i in range(1, len(self.s)):
			self.h1[i] = (self.x * self.h1[i - 1] + ord(self.s[i - 1])) % self.m1
			self.h2[i] = (self.x * self.h2[i - 1] + ord(self.s[i - 1])) % self.m2
			self.pows[i] = self.pows[i - 1] * self.x

	def ask(self, a, b, l):
		firstHashH1 = (self.h1[a + l] - self.h1[a] * self.pows[l]) % self.m1
		secondHashH1 = (self.h1[b + l] - self.h1[b] * self.pows[l]) % self.m1
		firstHashH2 = (self.h2[a + l] - self.h2[a] * self.pows[l]) % self.m2
		secondHashH2 = (self.h2[b + l] - self.h2[b] * self.pows[l]) % self.m2

		return firstHashH1 == secondHashH1 and firstHashH2 == secondHashH2

s = sys.stdin.readline()
q = int(sys.stdin.readline())
solver = Solver(s)
for i in range(q):
	a, b, l = map(int, sys.stdin.readline().split())
	print("Yes" if solver.ask(a, b, l) else "No")
