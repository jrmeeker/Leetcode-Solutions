'''You are given an m x n integer matrix matrix with the following two properties:

Each row is sorted in non-decreasing order.
The first integer of each row is greater than the last integer of the previous row.
Given an integer target, return true if target is in matrix or false otherwise.

You must write a solution in O(log(m * n)) time complexity.'''



class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
            
        def col_search(col, target):
            lo, hi = 0, len(col)
            m = (lo + hi) // 2
            if target < col[0]:
                return -1
            if len(col) == 1:
                return m
            while col[m] != target:
                prev_m = m
                if col[m] > target:
                    hi = m
                else:
                    lo = m
                m = (hi + lo) // 2
                if m == prev_m:
                    return m
            return m

        def search(nums, target):
            lo, hi = 0, len(nums)
            m = (lo + hi) // 2
            while nums[m] != target:
                prev_m = m
                if nums[m] > target:
                    hi = m
                else:
                    lo = m
                m = (hi + lo) // 2
                if m == prev_m:
                    return -1
            return m

        if target > matrix[-1][-1]:
            return False

        first_col = [i[0] for i in matrix]

        row = matrix[col_search(first_col, target)]
        ret = search(row, target)

        if ret < 0:
            return False
        return True