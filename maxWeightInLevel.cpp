#include <bits/stdc++.h>
using namespace std;

// Level Weight = (Sum of Node Weight)/ (Total Nodes)

int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0; i<n; i++){
        cin>> a[i];
    }
    //IN : n = 6, a[] = {10, 8, 20, 6, 9, 17}
    //OUT : Maximum Weighted level is 3 with weight 28
    float mx = INT_MIN;
    int mlvl = 1;
    for(int i=1; i<n+1; i=i*2+1){
        int j=i/2;
        float cur = 0;
        int count = i-j; 
        while(j<i && j<n){
            cur+= a[j];
            j++;
        }
        cur = cur/count;
        if(cur>mx){
            mlvl++;
            mx = cur;
        }
    }
    cout<<"Maximum Weighted level is "<< mlvl<< " with weight "<< mx;
    return 0;
}