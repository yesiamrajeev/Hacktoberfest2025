import random
class Solution(object):
    def sumZero(self, n):
        list =[]
        for i in range(1,n//2+1):
            list.append(i)
            list.append(-i)
        if(n%2!=0):
            list.append(0)
        return list

        