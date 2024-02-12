#include <bits/stdc++.h>
using namespace std;

vector<int> previousSmaller(vector<int> v, int n){
    stack<int> s;
    vector<int> ans;
    ans.push_back(-1);
    s.push(v[0]);
    for (int i = 1; i < n; i++) {
        while(!s.empty() && s.top()>=v[i]){
            s.pop();
        }
        if(s.empty()){
            ans.push_back(-1); 
            s.push(v[i]); 
            continue;
        }
        if(v[i]> s.top()){
            ans.push_back(s.top());
            s.push(v[i]);
        }
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
    vector<int> ans  = previousSmaller(v, n);
    for(int i=0; i<n; i++){
        cout<< ans[i]<< " ";
    }
}