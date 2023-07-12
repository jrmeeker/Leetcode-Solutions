/*You are given an m x n integer matrix matrix with the following two properties:

Each row is sorted in non-decreasing order.
The first integer of each row is greater than the last integer of the previous row.
Given an integer target, return true if target is in matrix or false otherwise.

You must write a solution in O(log(m * n)) time complexity.*/

class Solution {
public:
    int search(vector<int>& nums, int target) {
            int midIndex = (int)(nums.size() / 2);
            int left = 0, right = nums.size() - 1;          
            while(left <= right){
                if(nums[midIndex] == target)
                    return midIndex;
                if(target < nums[midIndex])
                    right = midIndex - 1; 
                else
                    left = midIndex + 1;         
                midIndex = (int)((right + left) / 2);
            }
            return -1;
        }

    int colSearch(vector<int>& nums, int target) {
            if(nums.size() == 1)
                return 0;
            int left = 0, right = nums.size() - 1;  
            int midIndex = (int)((left + right) / 2);
            if (target < nums[left])
                return -1;
            if (target >= nums[right])
                return right;

            while(left <= right){
                cout << midIndex << endl;
                if (target == nums[midIndex])
                    return midIndex;
                if(target >= nums[midIndex] && target < nums[midIndex+1])
                    return midIndex;
                if(target < nums[midIndex])
                    right = midIndex - 1; 
                else
                    left = midIndex + 1;         
                midIndex = (int)((right + left) / 2);               
            }
            return -1;
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        std::vector<int> col0;
        for(auto v : matrix) //get first column of matrix
            col0.push_back(v[0]);
        int row = 0;
        if (col0.size() > 1){
            row = colSearch(col0, target);
        }     
        if (row >= 0){
            int col = search(matrix[row], target);
            return (col >= 0);
        }
        return false;
    }
};