class Solution(object):
    def reverseWords(self, s):
       word1 = s.split()
       word1.reverse()
       return " ".join(word1)

sol = Solution()

print(sol.reverseWords("hello guys salam aalikom"))
