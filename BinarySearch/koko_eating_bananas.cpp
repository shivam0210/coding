// Koko loves to eat bananas. There are n piles of bananas, the ith pile has piles[i] bananas. The guards have gone and will come back in h hours.
// Koko can decide her bananas-per-hour eating speed of k. Each hour, she chooses some pile of bananas and eats k bananas from that pile. If the pile has less than k bananas, she eats all of them instead and will not eat any more bananas during this hour.
// Koko likes to eat slowly but still wants to finish eating all the bananas before the guards return.
// Return the minimum integer k such that she can eat all the bananas within h hours.

#include<bits/stdc++.h>
using namespace std;

// 4, 11, 20, 23, 30
// find start and end = max_element in a pile.
// find the mid and check whether it can be completd in h hours
// return the possible k vlaue


bool is_possible(vector<int> piles, int h, int banana){
    int hours_taken = 0;
    for(int i=0; i<piles.size(); i++){
        hours_taken += ceil((float)piles[i]/banana);
    }
    
    return hours_taken <= h;
}



int minEatingSpeed(vector<int> piles, int h) {
    
    int start = 1;
    int end = *max_element(piles.begin(), piles.end());
    int mid, ans = -1;
    
    while(start<=end){
        mid = (start + end)/2;
        if(is_possible(piles, h, mid)){
            end = mid - 1;
            ans = mid;
        }
        else start = mid + 1;
    }

    return ans;
}
