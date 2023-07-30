import os

"""
Code by longtqtqn
"""

MMOD = 1000000007
dp = list(range(200005))

s = input()
s = " " + s
rs = 0

for i in range(1, len(s)):
    dp[i] =(dp[i - 1] * 10 % MMOD + i * int(s[i]) % MMOD)
    rs = (rs + dp[i]) % MMOD

print(rs)
