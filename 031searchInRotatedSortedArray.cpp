// https://leetcode.com/problems/search-in-rotated-sorted-array/
// Binary Search

#include <bits/stdc++.h>
using namespace std;

int search(vector<int>& nums, int k) {
    int l = 0;
    int h = nums.size()-1;
    while(l<=h){
        int m = (l+h)/2;
        if(nums[m]==k) return m;
        else if(nums[m] >= nums[l]){
            if(nums[l]<=k && k<=nums[m]){
                h = m-1;
            }
            else{
                l = m+1;
            }
        }
        else{
            if(nums[m]<=k && k<=nums[h]){
                l = m+1;
            }
            else{
                h = m-1;
            }
        }
    }
    return -1;
}

int main(){
    int t;
    cin>> t;
    while(t--){
        int n, k;
        cin>> n;
        vector<int> nums;
        for(int i=0; i<n; i++){
            int x;
            cin>> x;
            nums.push_back(x);
        }
        cin>> k;
        cout<< search(nums, k)<<endl;
    }    
    return 0;
}

// 3
// 7
// 4 5 6 7 0 1 2
// 0
// 7
// 4 5 6 7 0 1 2
// 3
// 1
// 1
// 0