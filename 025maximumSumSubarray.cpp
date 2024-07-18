// prefixsum
// slidingwindow

// okay
// https://www.geeksforgeeks.org/problems/max-sum-subarray-of-size-k5313/1

#include <bits/stdc++.h>
using namespace std;

// Given an array of integers Arr of size N and a number K. Return the maximum sum of a subarray of size K.

int maximumSumSubarray(int K, vector<int> &Arr , int N){
        // code here 
        int maxSum=0;
        for(int i=0; i<K; i++){
            maxSum+= Arr[i];
        }
        int curSum= maxSum;
        int st=0, ed=K-1;
        for(int i=K; i<N; i++){
            ed++;
            curSum -= Arr[st];
            curSum += Arr[ed];
            st++;
            if(curSum > maxSum){
                maxSum = curSum;
            }
        }
        return maxSum;
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
    int ans = maximumSumSubarray(k, v, n);
    cout<< ans;
    return 0;
}