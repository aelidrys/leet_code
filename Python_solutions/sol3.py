class Solution(object):
    def canPlaceFlowers(self, flowerbed, n):
        len1 = len(flowerbed)
        i = 0
        if len1 > 0 and flowerbed[i] == 0:
            if len1 == 1 or flowerbed[0] == 0 and flowerbed[1] == 0:
                n -= 1
                flowerbed[0] += 1
        while i < len1:
            x = i
            if i + 1 < len1 and flowerbed[i] == 0 and flowerbed[i+1] == 0:
                if i + 2 == len1 or flowerbed[i+2] == 0:
                    n -= 1
                    i += 2
            if x == i:
                i += 1
        if n > 0:
            return False
        return True

sol = Solution()

print(sol.canPlaceFlowers([1,0,0,0,1,0,0], 2))