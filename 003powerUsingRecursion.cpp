// Recursion

#include <iostream>
using namespace std;

int power(int a, int n){
    if(n==0) return 1;
    if(n%2==0){
        return power(a, n/2) * power(a, n/2);
    }
    else{
        return power(a, n/2) * power(a, n/2) * a;
    }
}

int main(){
    int n, a;
    cin>> a >>n;
    cout<< power(a, n);
    return 0;
}