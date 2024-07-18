// https://leetcode.com/problems/sliding-window-maximum/
// queue, sliding window, heap
#include <bits/stdc++.h>
using namespace std;

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
    ans.push_back(nums[dq.front()]);
    for(int i=k ; i<n; i++){
        if(!dq.empty() && dq.front()<= i-k){
            dq.pop_front();
        }
        while(!dq.empty() && nums[i]>nums[dq.back()]){
            dq.pop_back();
        }
        dq.push_back(i);
        ans.push_back(nums[dq.front()]);
    }
    return ans;
}


int main(){
    int n, k;
    cin>>n;
    vector<int> nums;
    while(n--){
        cin>> k;
        nums.push_back(k);
    }
    cin>> k;
    vector<int> ans = maxSlidingWindow(nums, k);
    for(int a: ans){
        cout<< a<< " ";
    }
    return 0;
}