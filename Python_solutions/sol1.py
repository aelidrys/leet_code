def is_divid(s1, div):
    b = 0
    s1_len = len(s1)
    div_len = len(div)
    while b < s1_len:
        c = 0
        while b < s1_len and c < div_len:
            if s1[b] != div[c]:
                return False
            b += 1
            c += 1
    if b == s1_len and c == div_len:
        return True
    return False

class Solution(object):
    def gcdOfStrings(self, str1, str2):
        i = 0
        divid = str2
        i = len(divid)
        while i >= 0:
            if is_divid(str1, divid) and is_divid(str2, divid):
                return divid
            else:
                divid = str2[0:i]
            i -= 1
        print(divid)
        return ""

sol1 = Solution()

print(sol1.gcdOfStrings("A", "AA"))