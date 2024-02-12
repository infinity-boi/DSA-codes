#include <bits/stdc++.h>
using namespace std;

vector<int> tillLarger(vector<int> v, int n){
    stack<int> st;
    vector<int> ans;
    ans.push_back(1);
    st.push(0);
    for (int i = 1; i < n; i++) {
        while(!st.empty() && v[st.top()]<=v[i]){
            st.pop();
        }
        if(st.empty()){
            ans.push_back(i+1); 
        }
        else{
            ans.push_back(st.top()+1);
        }
        st.push(i);
    }
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
    vector<int> ans  = tillLarger(v, n);
    for(int i=0; i<n; i++){
        cout<< ans[i]<< " ";
    }
}