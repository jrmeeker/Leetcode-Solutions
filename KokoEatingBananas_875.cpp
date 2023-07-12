/*Koko loves to eat bananas. There are n piles of bananas, the ith pile has piles[i] bananas. 
The guards have gone and will come back in h hours.
Koko can decide her bananas-per-hour eating speed of k. Each hour, she chooses some pile of bananas 
and eats k bananas from that pile. If the pile has less than k bananas, she eats all of them instead 
and will not eat any more bananas during this hour.
Koko likes to eat slowly but still wants to finish eating all the bananas before the guards return.
Return the minimum integer k such that she can eat all the bananas within h hours.*/

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        std::vector<int>::iterator max = std::max_element(piles.begin(), piles.end());
        int hi = *max;
        int lo = 1, k = 0, t = 0;
        while(lo < hi){
            k = (hi + lo) / 2;
            t = 0;
            for(int i : piles)          
                t += ceil(i / (double)k);       
            if (t <= h)
                hi = k;
            else
                lo = k + 1;                
        }
        return hi;
    }
};