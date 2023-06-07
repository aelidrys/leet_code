class Solution(object):
    def kidsWithCandies(self, candies, extraCandies):
        i = 0
        len1 = len(candies)
        arry = [False] * len1
        n_max = max(candies)
        print(n_max)
        while i < len1:
            if candies[i] + extraCandies >= n_max:
                arry[i] = True
            else:
                arry[i] = False
            i += 1
        return arry

sol = Solution()

print(sol.kidsWithCandies([1,2,5,8,0,6], 2))
