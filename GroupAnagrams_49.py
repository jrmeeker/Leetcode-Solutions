#Given an array of strings strs, group the anagrams together. You can return the answer in any order.

class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        group_map = dict()
        outlist = []
        
        i = 0
        for str in strs:
            s = ''.join(sorted(str))

            if s not in group_map:
                group_map[s] = i 
                outlist.append([str])
                i += 1
            else:
                n = group_map[s]
                outlist[n].append(str)
                
        return outlist