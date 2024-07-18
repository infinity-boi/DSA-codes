// sliding window
// Deque
// Heap 
// Monotonic Queue
// https://leetcode.com/problems/sliding-window-maximum/

#include <bits/stdc++.h>
using namespace std;

// int maxElementInWindow(vector<int> v, int n, int k){
//     for(int i=0; i<n-k; i++){
//         for(int j=i; j<i+k; j++){
//              // find max
//         }
//     }
// }

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    deque<int> dq;
    vector<int> ans;
    int n =nums.size();
    for(int i=0; i<k; i++){
        while(!dq.empty() && nums[dq.back()] < nums[i]){
            dq.pop_back();
        }
        dq.push_back(i);
    }
    for(int i=k ; i<n; i++){
        ans.push_back(nums[dq.front()]);
        while(!dq.empty() && dq.front()<= i-k){
            dq.pop_front();
        }
        while(!dq.empty() && nums[i]>nums[dq.back()]){
            dq.pop_back();
        }
        dq.push_back(i);
    }
    ans.push_back(nums[dq.front()]);
    return ans;
}

int main(){
    int n;
    cin>>n;
    vector<int> v;
    for(int i=0; i<n; i++){
        int x;
        cin>> x;
        v.push_back(x);
    }
    int k;
    cin>> k;
    vector<int> ans = maxSlidingWindow(v, k);
    for(int x : ans){
        cout<< x <<" ";
    }
    return 0;
}