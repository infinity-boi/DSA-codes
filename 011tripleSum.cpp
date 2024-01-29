// Binary Search
// Sliding Window 
// Two Pointers

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Threesome : Find triplets having sum equal to k;

// Brute : O(N^3)

// O(NlogN+N^2) = O(N^2)

// My way:
// int triplesum(vector<int> arr, int n, int k){
//     // sort(arr.begin(), arr.end());
//     int s = 0,  m =1, e = 2;
//     while(s<=n-3){
//         if(abs(arr[s]+arr[m]+arr[e])<=k){
//             cout<<"("<<arr[s]<<", "<<arr[m]<<", "<<arr[e]<<") , ";
//         }
//         if(m==e-1){
//             e++;
//         }
//         else if(s==m-1){
//             m++;
//         }
//         else{
//             s++;
//         }     
//     }
// }

int triplesum(vector<int> arr, int n, int k){
    sort(arr.begin(), arr.end());
    for(int i=0; i<n-2; i++){
        int s = i+1, e = n-1;
        while(s<e){
            if(arr[s]+arr[i]+arr[e]<k){
                s++;
            }
            else if(arr[s]+arr[i]+arr[e]==k){
                cout<<"("<<arr[i]<<", "<<arr[s]<<", "<<arr[e]<<")"<<endl;
                s++;
                e--;
            }
            else if(arr[s]+arr[i]+arr[e]>k){
                e--;
            }
        }
    }
}

int main(){
    // int n = 8;
    // int k = 11;
    // vector<int> arr = {2,1,1,4,6,3,8,7};
    int n;
    int k;
    cin>>n >>k;
    vector<int> arr;
    for(int i=1;i<=n;i++){
        int temp;
        cin>> temp;
        arr.push_back(temp);
    }
    return triplesum(arr, n, k);
}