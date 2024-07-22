// https://www.spoj.com/problems/EKO/
// binary search

#include <bits/stdc++.h>
using namespace std;

bool isPossible(vector<int> &tree, int &n, int &m, int &mid){
    int sum = 0;
    for(int i=0; i<n; i++){
        if(tree[i]>mid) sum += (tree[i]-mid);
        if(sum>=m){
            return true;
        }
    }
    return false;
}

int maximumHeight(vector<int> &tree, int &n, int &m){
    int lb= 1, ub= tree[n-1];
    int ans = 0;
    while(lb<=ub){
        int mid = (lb+ub)/2;
        if(isPossible(tree, n, m, mid)){
            ans = mid;
            lb = mid+1;
        }
        else{
            ub = mid-1;
        }
    }
    return ans;
}

int main(){
    int n, m;
    cin>>n>>m;

    vector<int> tree;
    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        tree.push_back(x);
    }
    sort(tree.begin(), tree.end());
    // if(m==0) return tree[n-1];
    cout<<maximumHeight(tree, n, m);
    return 0;
}