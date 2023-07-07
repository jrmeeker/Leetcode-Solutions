#include <unordered_map>
#include <vector>

//Given an array of integers nums and an integer target, return 
//indices of the two numbers such that they add up to target.

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> nMap;
        std::vector<int> outVector = {-1, -1};
        int d = -1;

        int i = 0;
        for(auto num:nums){
            d = target - num;
            if (nMap.count(d)){
                outVector = {nMap[d], i};
                return outVector;
            }
            nMap[num] = i;
            ++i;
        }
        
        return outVector;
    }