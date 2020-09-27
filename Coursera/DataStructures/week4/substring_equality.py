# python3
from random import randint
import sys
import numpy as np

class Solver:
	def __init__(self, s):
		self.s = s
		self.m1 = 10 ** 9 + 7
		self.m2 = 10 ** 9 + 9
		self.x = randint(1, 10 ** 9)
		self.h1 = np.zeros(len(self.s))
		self.h2 = np.zeros(len(self.s))
		self.powsM1 = np.ones(len(self.s))
		self.powsM2 = np.ones(len(self.s))

		for i in range(1, len(self.s)):
			self.powsM1[i] = self.powsM1[i - 1] * self.x % self.m1
			self.powsM2[i] = self.powsM2[i - 1] * self.x % self.m2
			self.h1[i] = (self.h1[i - 1] + ord(self.s[i - 1]) * self.powsM1[i - 1]) % self.m1
			self.h2[i] = (self.h2[i - 1] + ord(self.s[i - 1]) * self.powsM2[i - 1]) % self.m2

	def ask(self, a, b, l):
		firstHashH1 = (self.h1[a + l] - self.h1[a]) / self.powsM1[a] % self.m1
		secondHashH1 = (self.h1[b + l] - self.h1[b]) / self.powsM1[b] % self.m1
		firstHashH2 = (self.h2[a + l] - self.h2[a]) / self.powsM1[a] % self.m2
		secondHashH2 = (self.h2[b + l] - self.h2[b]) / self.powsM1[b] % self.m2

		print( firstHashH1, " ", secondHashH1, " ",firstHashH2, " ", secondHashH2)

		return firstHashH1 == secondHashH1 and firstHashH2 == secondHashH2

s = sys.stdin.readline()
q = int(sys.stdin.readline())
solver = Solver(s)
for i in range(q):
	a, b, l = map(int, sys.stdin.readline().split())
	print("Yes" if solver.ask(a, b, l) else "No")
