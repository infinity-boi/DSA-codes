// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

bool isPossible(vector<int> nums, int target, int k, int n){
    int port = 0;
    int csum = 0;
    for(int i=0; i<n; i++){
        
        if(csum < target){
            csum += nums[i];
        }
        else{
            csum = nums[i];
            port++;
        }
    }
     if(csum > target){
         port++;
     }
     return port>=k;
}

int maximizeCoins(vector<int> nums, int n, int k){
    int low = INT_MAX, high = 0;
    for(int i = 0; i<n; i++){
        if(nums[i]<low){
            low =nums[i];
        }
        high += nums[i];
    }
    high -= low;
    int ans;
    while(low <= high){
        int mid = (low+high)/2;
        if(isPossible(nums, mid, k, n)){
            low = mid+1;
            ans = mid;
        }
        else{
            high = mid-1;
        }
    }
    return ans;
}

int main() {
    vector<int> nums = {6, 8, 4, 2, 1, 7, 8, 2};
    int k= 3;
    int n= nums.size();
    int ans = maximizeCoins(nums, n, k);
    cout<< ans;

    return 0;
}