// https://leetcode.com/problems/single-element-in-a-sorted-array/
// Binary Search
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> nums;
    for(int i=0; i<n; i++){
        int x;
        cin>> x;
        nums.push_back(x);
    }
    cout<< singleNonDuplicate(nums);
    return 0;
    
}

int singleNonDuplicate(vector<int>& nums) {
    int n = nums.size();
    if(n==1) return nums[0];
    if(nums[0]!=nums[1]){
        return nums[0];
    }
    if(nums[n-1]!= nums[n-2]){
        return nums[n-1];
    }
    int s = 1, e = n-2;
    while(s<=e){
        int mid = (s+e)/2;
        if(nums[mid] != nums[mid-1] && nums[mid] != nums[mid+1]){
            return nums[mid];
        }
        else if((mid%2==0 && nums[mid]==nums[mid+1]) || (mid%2==1 && nums[mid]==nums[mid-1])){
            s = mid+1;;
        }
        else{
            e = mid -1;
        }
    }
    return -1;
}