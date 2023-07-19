//Given a string s, find the length of the longest substring without repeating characters.

#include <unordered_map>
#include <algorithm>

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxL = 0, mark = 0;
        std::unordered_map<char, int> seen;

        for (int i = 0; i < s.size(); ++i){
            if (seen.count(s[i]))
                mark = max(mark, seen[s[i]] + 1);
            seen[s[i]] = i;
            maxL = max(maxL, 1 + i - mark);
        }
        return maxL;
    } 
};

