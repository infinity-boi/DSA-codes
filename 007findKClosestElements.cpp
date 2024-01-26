// https://leetcode.com/problems/find-k-closest-elements/
// Binary Search
// Two Pointer
// Sliding Window

#include <iostream>
#include <vector>
using namespace std;

// Given a sorted integer array arr, two integers k and x, return the k closest integers to x in the array. The result should also be sorted in ascending order.

// An integer a is closer to x than an integer b if:

// |a - x| < |b - x|, or
// |a - x| == |b - x| and a < b
 

// Example 1:

// Input: arr = [1,2,3,4,5], k = 4, x = 3
// Output: [1,2,3,4]
// Example 2:

// Input: arr = [1,2,3,4,5], k = 4, x = -1
// Output: [1,2,3,4]

vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int left = 0, right = arr.size()-k;
        while(left< right){
            int mid = (left +right) /2;
            if(x- arr[mid] > arr[mid+k] - x)  left = mid+1;
            else {
                right = mid;
            }
        }
        return vector<int>(arr.begin() + left, arr.begin()+left+k);
    }

int main(){
    int n;
    cin>> n;
    vector<int> arr;
    while(n--){
        int in;
        cin>> in;
        arr.push_back(x);
    }
    int k;
    cin>> k;
    int x;
    cin>> x;
    vector<int> ans = findClosestElements(arr, k, x);
    for(auto i : ans) cout<<i<<" ";
    return 0;
}