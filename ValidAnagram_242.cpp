//Given two strings s and t, return true if t is an anagram of s, and false otherwise.

#include <unordered_set>
#include <vector>

class Solution {
public:
    bool isAnagram(string s, string t) 
    {
        std:unordered_map<char, int> sMap, tMap;

        for(auto letter:s)
            sMap[letter]++;

        for(auto letter:t)
            tMap[letter]++;

        return (sMap == tMap);
    }
};