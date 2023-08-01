'''Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.

There is only one repeated number in nums, return this repeated number.

You must solve the problem without modifying the array nums and uses only constant extra space.'''

class Solution:
    def findDuplicate(self, nums: List[int]) -> int:

        fast, slow = 0, None
        while fast != slow:
            if slow == None:
                slow = 0
            slow, fast = nums[slow], nums[nums[fast]]

        slow = 0
        while slow != fast:
            slow, fast = nums[slow], nums[fast]

        return slow