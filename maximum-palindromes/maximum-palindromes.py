#!/bin/python3

import os

"""
Code by longtqtqn
Using default template read/write of hackerrank
"""

abcInString = []

facMod = {}
facMod[0] = 1

MOD = 1000000007

def genFacMod():
    for i in range(1, 100001):
        facMod[i] = i * facMod[i - 1] % MOD
        

def initialize(s):
    genFacMod()
    abcCounts = [0] * 26
    for c in s:
        idx = ord(c) - ord('a')
        abcCounts[idx] += 1
        abcInString.append(abcCounts.copy())

class Solution:
    def __init__(self):
        self.counts = [0] * 26
    
    def ini(self, l, r):
        countsL = abcInString[l]
        countsR = abcInString[r]
        for i in range(len(countsL)):
            if countsL[i] == 0 or l == 0:
                self.counts[i] = countsR[i]
            else:
                self.counts[i] = countsR[i] - abcInString[l - 1][i]
        
    def solve(self):
        countOne  = 0
        sumGtOne  = 0
        listGtOne = []
        rs        = 1
        for i in self.counts:
            if i == 1:
                countOne += 1
            elif i != 0:
                sumGtOne += i//2
                listGtOne.append(i//2)
                if i % 2 == 1:
                    countOne += 1
        
        """
        Basic idea:
        [Input string s1    = aaaabbbbcccc]
        
        s2       = s1/2     = aabbcc
        lengSum  = leng(s2) = 6
        totalA   = aa       = 2
        Ca       = math.comb(lengSum, totalA)
        
        lengSum  = lengSum - totalA = 6 - 2 = 4
        totalB   = bb = 2
        Cb       = math.comb(lengSum, totalB)
        
        lengSum  = lengSum - totalB = 4 - 2 = 2
        totalC   = cc = 2
        Cc       = math.comb(lengSum, totalC)
        
    ==> output = Ca * Cb * Cc
        
        [Code]
        for i in listGtOne:
            rs *= math.comb(sumGtOne, i)
            sumGtOne -= i
        [end Code]
        Was optimized by the code below
        """
        sumF = facMod[sumGtOne]
        i1   = 1
        for i in listGtOne:
            i1 *= facMod[i] % MOD
        rs = sumF * pow(i1, -1, MOD) % MOD
        
        """
        Explain with example:
        
                math.comb(a, s)  * math.comb(b, s - a)  * math.comb(c, s - a - b)
            <=> [s! / a!*(s-a)!] * [(s-a)! /b!*(s-a-b)!]*[(s-a-b)!/c!*(s-a-b-c)!]
            <=> s!/(a! * b! * c!)
            
        """

        if countOne == 0:
            return rs;

        return rs * countOne
        
def answerQuery(l, r):
    so = Solution()    
    so.ini(l - 1, r - 1)

    return so.solve() % MOD

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    s = input()

    initialize(s)

    q = int(input().strip())

    for q_itr in range(q):
        first_multiple_input = input().rstrip().split()

        l = int(first_multiple_input[0])

        r = int(first_multiple_input[1])

        result = answerQuery(l, r)

        fptr.write(str(result) + '\n')

    fptr.close()
