// Recursion

#include <iostream>
using namespace std;

int square(int a, int n){
    if(n==0) return 1;
    if(n%2==0){
        return square(a, n/2) * square(a, n/2);
    }
    else{
        return square(a, n/2) * square(a, n/2) * a;
    }
}

int main(){
    int n, a;
    cin>> a >>n;
    cout<< square(a, n);
    return 0;
}