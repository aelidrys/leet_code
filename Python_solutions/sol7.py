
class Solution(object):
    def compress(self, s):
        i = 0
        len_s = len(s)
        list1 = []
        while i < len_s:
            k = 0
            c = s[i]
            while i < len_s and s[i] == c:
                i += 1
                k += 1
            list2 = list(str(k))
            if k > 1:
                list1.extend([c] + list2)
            else:
                list1.append(c)

        s1 = "".join(list1)
        i = 0
        list_len = len(list1)
        while i < list_len:
            s[i] = s1[i]
            i += 1
        return list_len

sol = Solution()
s = ["a","a","b","b","b","a","a","a","a","c","c","c"]
res = sol.compress(s)
print(s[:res])