class Solution(object):
    def moveZeroes(self, nums):
        count_0 = nums.count(0)
        j = 0
        while j  < count_0:
            nums.remove(0)
            j += 1
        nums.extend([0 for i in range(count_0)])

sol = Solution()

nums = [1,0,2,0,4,5,0,2,0,1,0]
sol.moveZeroes(nums)
print(nums)