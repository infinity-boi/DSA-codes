// Find a raised to the power of n using binary exponentiation
// Binary Exponentiation
// Bit Manipulation

#include <iostream>
using namespace std;

int power(int a, int n){
    int result = 1;
    while(n){
        if(n & 1){
            result *= a; 
        }
        n >>= 1;
        a *= a;
    }
    return result;
}

int main(){
    int n, a;
    cin>> a >>n;
    cout<< power(a, n);
    return 0;
}