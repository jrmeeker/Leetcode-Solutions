#Given a string s, return true if it is a palindrome, or false otherwise.

class Solution:
    def isPalindrome(self, s: str) -> bool:
        letters = ''
        for ch in s:
            if ch.isalnum():
                letters += ch

        letters = letters.lower()
        return letters == letters[::-1]