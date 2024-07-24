// https://www.spoj.com/problems/BALIFE/

// load balancing

// 

#include <bits/stdc++.h>
using namespace std;

// bool isPossibl()


int stepsToRebalance(vector<int> cpu, int n){
    vector<int> ps;
    ps.push_back(cpu[0]);
    for (int i=1; i<n; i++) {
        int x = ps[i-1]+cpu[i];
        ps.push_back(x);
    }
    // for(int x : ps){
    //     cout<<x<<" ";
    // }
    // cout<<endl;
    if(ps[n-1]%n!=0){
        return -1;
    }
    int each = ps[n-1]/n;
    // cout<<each<<endl;
    int ans = INT_MIN;
    for(int i=0; i<n; i++){
        int steps = abs(ps[i] - each*(i+1)); 
        // cout<<steps<<" ";
        ans = max(steps, ans);
        // cout<<ans<<"  ";
    }
    // cout<<endl;
    return ans;
}

int main(){
    int n;
    do{
        vector<int> cpu;
        cin>>n;
        if(n==-1){
            return 0;
        }
        for(int i=0; i<n; i++){
            int p;
            cin>> p;
            cpu.push_back(p);
        }
        int ans = stepsToRebalance(cpu, n);
        cout<< ans<<endl;
    }
    while(n!=-1);

}