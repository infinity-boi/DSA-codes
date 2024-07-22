// https://www.spoj.com/problems/PRATA/
// binary search
#include <bits/stdc++.h>
using namespace std;

bool check(int tmid, int p, int l, vector<int> &ranks){
    int curp = 0;
    for(int i=0; i<l; i++){
        int time = ranks[i];
        int j =2;
        while(time<=tmid){
            curp++;
            time+= ranks[i]*j;
            j++;
        }
        if(curp>=p){
            return true;
        }
    }
    return false;
}

int timeTaken(int &p, int &l, vector<int> &ranks){
    sort(ranks.begin(), ranks.end());
    int tmin = 1;
    int tmax = ranks[l-1]*p*(p+1)/2;
    int ans = 0;
    while(tmin<=tmax){
        int tmid = (tmin+tmax)/2;
        if(check(tmid, p, l, ranks)){
            ans = tmid;
            tmax= tmid-1;
        }
        else{
            tmin= tmid+1;
        }
    }
    return ans;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int p, l;
        cin>> p>> l;
        vector<int> ranks;
        for(int i=0; i<l; i++){
            int x;
            cin>> x;
            ranks.push_back(x);
        } 
        int ans = timeTaken(p, l, ranks);
        cout<< ans<< endl;
    }
    return 0;
    
}
