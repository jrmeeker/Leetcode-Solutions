#Given a string s, find the length of the longest substring without repeating characters.

class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        max_l, max_mark, seen = 0, 0, dict()
        for i in range(len(s)):
            if s[i] in seen:
                max_mark = max(max_mark, seen[s[i]] + 1)
            seen[s[i]] = i
            max_l = max(max_l, 1 + i - max_mark)
        return max_l