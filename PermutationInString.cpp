/*Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.
In other words, return true if one of s1's permutations is the substring of s2.*/

#include <unordered_map>

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size())
            return false;

        int l = 0, wSize = s1.size();
        std::unordered_map<char, int> map1, map2;

        for(int i = 0; i < s1.size(); ++i)
            map1[s1[i]]++;

        for(int i = 0; i < s1.size(); ++i)
            map2[s2[i]]++;

        if (map1 == map2)
            return true;

        for(int r = wSize; r < s2.size(); ++r){
            map2[s2[r]]++;
            map2[s2[l]]--;
            if(map2[s2[l]] <= 0)
                map2.erase(s2[l]);
            l++;

            if(map1 == map2)
                return true;
        }

        return false;
    }
};