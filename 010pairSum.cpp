// Binary Search
// Sliding Window
// Two Pointers
// Hashing

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;

// Pair Sum = K
// N distinct elements

// Brute force : NestedLoop-> O(N^2)

// Efficient : Sorting-> O(NlogN) + BST-> O(NlogN)

int pairSum(vector<int> arr, int n, int k){
    sort(arr.begin(), arr.end());
    int s = 0, e = 0;
    while(s<=e){
        if(arr[s]+arr[e]<k){
            e++;
        }
        else if(arr[s]+arr[e]==k){
            cout<<"("<<arr[s]<<", "<<arr[e]<<"), ";
            s++;
            e++;
        }
        else if(arr[s]+arr[e]>k){
            s++;
        }
        if(e==n){
            break;
        }
    }
    return 0;
}

void pairSumUsingHashing(vector<int> arr, int n, int sum)
{
    // Store counts of all elements in map m
    unordered_map<int, int> m;
 
    // Traverse through all elements
    for (int i = 0; i < n; i++) {
 
        // Search if a pair can be formed with
        // arr[i].
        int rem = sum - arr[i];
        if (m.find(rem) != m.end()) {
            int count = m[rem];
            for (int j = 0; j < count; j++)
                cout << "(" << rem << ", " << arr[i] << ")"
                     << endl;
        }
        m[arr[i]]++;
    }
}

void pairSumUsingSet(vector<int> arr, int n, int k){
    unordered_set<int> s;
    for(int x: arr){
        if(s.count(k-x)){
            cout<<"("<<x<<", " <<(k-x)<<")"<<endl;
        }
        s.insert(x);
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
    // pairSumUsingSet(arr, n, k);
    // cout<<endl;
    return pairSum(arr, n, k);

}



