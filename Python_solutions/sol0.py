class Solution(object):
    def mergeAlternately(self, word1, word2):
        word3 = ""
        i = 0
        len1 = len(word1)
        len2 = len(word2)
        while i < len1 and i < len2:
            word3 += word1[i]
            word3 += word2[i]
            i += 1
        while i < len1:
            word3 += word1[i]
            i += 1
        while i < len2:
            word3 += word2[i]
            i += 1
        return (word3)

sol1 = Solution()
print(sol1.mergeAlternately("aed", "blah"))