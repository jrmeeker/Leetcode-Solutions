/*Given an array of integers nums which is sorted in ascending order, and an integer target, 
write a function to search target in nums. If target exists, then return its index. Otherwise, return -1.
You must write an algorithm with O(log n) runtime complexity.*/

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
};