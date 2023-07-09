int binSearch(vector<int>& nums, int target) {
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