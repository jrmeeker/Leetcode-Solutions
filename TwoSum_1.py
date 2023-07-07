#Given an array of integers nums and an integer target, return indices of the 
#two numbers such that they add up to target.

class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        n_map = dict()
        for i, num in enumerate(nums):
            d = target - num 
            if d in n_map:
                return [n_map[d], i]
            n_map[num] = i