#include <cctype>
#include <algorithm>
#include <string>

//Given a string s, return true if it is a palindrome, or false otherwise.

class Solution {
public:
    bool isPalindrome(string s) {
        std::string letters;
        for(auto ch:s){
            if (std::isalnum(ch)){
                letters += tolower(ch);
            }
        }
        std::string revLetters = letters;
        std::reverse(revLetters.begin(), revLetters.end());
        return letters == revLetters;
    }
};