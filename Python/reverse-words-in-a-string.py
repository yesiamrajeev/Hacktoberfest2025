class Solution(object):
    def reverseWords(self, s):
       list = s.split()
       list.reverse()
       str2 = ' '.join(list)
       return str2