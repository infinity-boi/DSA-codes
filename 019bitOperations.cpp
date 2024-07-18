#include <iostream>

using namespace std;

int getbit(int n, int i){
    return (1 & (n >> i-1));
}

int setbit(int n, int i){
    return (n | (1<<i));
    
}

int clearbit(int n, int i){
    return  (n & ~(1<<i));
    
}

int countsetbit(int n, int i){
    int cnt=0;
    while(n){
        if(n&1){
            cnt++;
        }
        n>>=1;
    }
    return cnt;
}

int updatebit(int n, int i, int bit){
    if(getbit(n, i)==1){
        setbit(n,i);
    }
    else{
        clearbit(n, i);
    }
    return n;
}

int updatebitx(int n, int i, int bit){
    int count = 0;
    while(n){
        n = n & (n-1);
        count++;
    }
    return count;
}

int clearRangeofBits(int n, int i, int j){
    int mask1 = (~0)<<(i+1);
    int mask2 = 1<<j -1;
    return n & (mask1 | mask2);
}

int cleaerandreplace(int n, int i, int j, int m){
    n = clearRangeofBits(n, i, j);
    return n | (m<<j);
}


int main(){
    int n , i;
    cin>>n>>i;
    cout<<getbit(n, i)<<endl;
    cout<<setbit(n, i)<<endl;
    cout<<clearbit(n, i)<<endl;
    cout<<countsetbit(n, i)<<endl;
    cout<<updatebit(n, i, 0)<<endl;
    return 0;
}