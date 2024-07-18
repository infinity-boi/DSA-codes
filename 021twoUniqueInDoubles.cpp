// https://leetcode.com/problems/single-number-iii/

#include <bits/stdc++.h>
using namespace std;

// Bit Manipulation

int getBit(int a, int k){
    return (a>> k) & 1;
}
vector<int> singleNumber(vector<int>& nums) {
    int axorb = 0;
    for(int num: nums){
        axorb ^= num;
    }
    int idx = 0;
    while(!getBit(axorb, idx)) idx++;
    int a = 0;
    for(int num: nums){
        if(getBit(num, idx)) a ^= num;
    }
    int b = axorb ^ a;
    return {a, b};
}

int main(){
    vector<int> nums = {1,2,1,3,2,5};
    vector<int> ans = singleNumber(nums);
    cout<< ans[0]<< " "<< ans[1];
    return 0;
    
}