# https://leetcode.com/problems/two-sum/
class Solution:
    def twoSum(self, nums, target: int):
        complement_table = {}
        for i, num in enumerate(nums):
            complement = target - num
            if complement in complement_table:
                return [complement_table[complement], i]
            complement_table[num] = i