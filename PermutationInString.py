'''Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.
In other words, return true if one of s1's permutations is the substring of s2.'''

class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        map1, map2 = dict(), dict()
        w_size = len(s1)
        l = 0

        if len(s1) > len(s2):
            return False

       #populate map1
        for i in range(len(s1)):
           map1[s1[i]] = 1 + map1.get(s1[i], 0)

        #populate map2 with initial values 
        for i in range(len(s1)):
            map2[s2[i]] = 1 + map2.get(s2[i], 0)

        if map1 == map2:
            return True

        #move window along s2, checking for matches
        for r in range(w_size, len(s2)):
            map2[s2[r]] = 1 + map2.get(s2[r], 0)
            map2[s2[l]] -= 1
            if map2[s2[l]] <= 0:
                del map2[s2[l]]
            l += 1
   
            if map1 == map2:
                return True
            
        return False