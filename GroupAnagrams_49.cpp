//Given an array of strings strs, group the anagrams together. You can return the answer in any order.

#include <vector>
#include <unordered_map>

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::unordered_map<string, int> groupMap;
        std::vector<std::vector<string>> outList;

        int c = 0;
        for (int i = 0; i < strs.size(); ++i){
            std::string s = strs[i];
            std::sort(s.begin(), s.end());

            if (groupMap.count(s) < 1){
                groupMap[s] = c;
                std::vector<string> newVec = {strs[i]};
                outList.push_back(newVec);
                c++;
            }

            else{
                int n = groupMap[s];
                outList[n].push_back(strs[i]);
            }
        }

    return outList;
    }
};