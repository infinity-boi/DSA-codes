// https://leetcode.com/problems/single-number-ii/

// Bit Manipulations
#include <bits/stdc++.h>
using namespace std;

int singleNumber(vector<int>& nums) {
    int ans = 0;
    for(int i=0; i<32; i++){
        int bitcnt = 0;
        for(auto a: nums){
            if(a>>i & 1){
                bitcnt++;
            }
        }
        bitcnt = bitcnt%3;
        ans = ans | (bitcnt<<i);
    }
    return ans;
}


int main(){
    vector<int> nums = {0,1,0,1,0,1,99};
    cout<< singleNumber(nums);
    
}