// Binary Search
// Array
// Sliding Window

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Find pairs of elements from the vector whose absolute difference is equal to k and print those pairs.

int pairDifference(vector<int> arr, int n, int k){
    sort(arr.begin(), arr.end());
    int s = 0, e = 0;
    while(s<=e){
        if(abs(arr[s]-arr[e])<k){
            e++;
        }
        else if(abs(arr[s]-arr[e])==k){
            cout<<"("<<arr[s]<<", "<<arr[e]<<"), ";
            s++;
            e++;
        }
        else if(abs(arr[s]-arr[e])>k){
            s++;
        }
        if(e==n){
            break;
        }
    }
}

int main(){
    int n;
    int k;
    cin>>n >>k;
    vector<int> arr;
    for(int i=1;i<=n;i++){
        int temp;
        cin>> temp;
        arr.push_back(temp);
    }
    return pairDifference(arr, n, k);

}