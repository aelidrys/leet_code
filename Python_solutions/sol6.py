# import numpy as np
#     arry1 = nums.remove(x)
#     np.prod(nums)

from functools import reduce

def prud1(nums, nums1, i):
    x = nums[i]
    nums.remove(x)
    print(nums)
    prod = reduce(lambda x, y: x * y, nums)
    nums1.append(prod)
    return prod

class Solution(object):
    def productExceptSelf(self, nums):
        len_a = len(nums)
        prod = reduce(lambda x, y: x * y, nums)
        nums1 = []
        i = 0
        while i < len_a:
            # print(nums[i])
            prud1(nums,nums1,i)
            i += 1
        return nums

sol = Solution()

print(sol.productExceptSelf([1,2,3,4]))


# my_array = [2, 2, 5, 4]