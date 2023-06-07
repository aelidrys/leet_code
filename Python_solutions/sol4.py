class Solution(object):
    def reverseVowels(self, s):
        i , j = 0 , len(s) - 1
        str1 = "aeiouAEIOU"
        s = list(s)
        while i < j:
            if s[i] in str1 and s[j] in str1:
                c1 = s[i]
                s[i] = s[j]
                s[j] = c1
                i += 1
                j -= 1
            elif s[i] not in str1:
                i += 1
            else:
                j -= 1
        return "".join(s)

sol = Solution()

print(sol.reverseVowels("ayohhhhhdb"))