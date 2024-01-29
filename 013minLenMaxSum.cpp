// Sliding Window
// Two Pointer

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Given an array find the smallest window size for which the sum of elements is k

int minLenMaxSum(vector<int> v, int n, int k){
    int winSize = INT_MAX;
    int ans = n;
    int l=0, r=0;
    int cur = v[0];
    while(r<n){
        if(cur < k){
            r++;
            if(r==n){
                break;
            }
            cur+=v[r];
            continue;
        }
        else if(cur == k){
            winSize = (r-l+1);
            ans = min(ans, winSize);
        }
        cur -= v[l];
        l++;
    }
    return ans;
}

int main(){
    // vector<int> v = {4, 2, 1, 6, 10, 3, 4};
    // int n = v.size();
    // int k = 7;
    int n;
    int k;
    cin>>n >>k;
    vector<int> arr;
    for(int i=1;i<=n;i++){
        int temp;
        cin>> temp;
        arr.push_back(temp);
    }
    return minLenMaxSum(arr, n, k);
}