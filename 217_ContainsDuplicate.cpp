#include <iostream>
#include <unordered_set>
#include <vector>

//Given an integer array nums, return true if any value appears at least twice in the array, 
//and return false if every element is distinct.

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) 
    {
        std::unordered_set<int> numSet;

        for(auto num:nums){
            if(numSet.count(num))
                return true;
            numSet.insert(num);
        }

        return false;
    }
};