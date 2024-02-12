// stack
// nearestsmallest
// nextsmaller
// array

#include <bits/stdc++.h>
using namespace std;

// Given an array return the array containing the next smaller elements for each element of the input array.

vector<int> nextSmaller(vector<int> v, int n){
    vector<int> ans(n, -1);
    stack<int> st;
    for(int i=0; i<n; i++){
        while(!st.empty() && v[i]<v[st.top()]){
            ans[st.top()] = v[i];
            st.pop();
        }
        st.push(i);
    }
    return ans; 
}

int main(){
    int n;
    cin>>n;
    // vector<int> arr = {4, 8, 2, 1, 6, 10, 5};
                       // 2, 2, 1, -1, 5, 5, -1 
    vector<int> v;
    for(int i=0; i<n; i++){
        int x;
        cin>> x;
        v.push_back(x);
    }
    vector<int> ans  = nextSmaller(v, n);
    for(int i=0; i<n; i++){
        cout<< ans[i]<< " ";
    }
}