#Given two strings s and t, return true if t is an anagram of s, and false otherwise.

class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        s_map, t_map = dict(), dict()

        for letter in s:
            s_map[letter] = 1 + s_map.get(letter, 0)
        for letter in t:
            t_map[letter] = 1 + t_map.get(letter, 0)

        return s_map == t_map