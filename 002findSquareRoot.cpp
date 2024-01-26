#include <iostream>
using namespace std;

// Find the square root of x without builtin function
// Binary Search : Works for finding sqrt(n) but not sqrt(x), where x is a number. It only gives integer values of sqrt(n).
float squareRoot(int n){
    int s = 0;
    int e = n;
    int ans;
    while(s<=e){
        int mid = (s+e)/2;
        if(mid*mid>n){
            e = mid -1;
        }
        else if(mid*mid<=n){
            ans = mid;
            s = mid+1;
        }
    }
}

int main(){
    int n; 
    cin>> n;
    // Binary search method to find sqrt(n)
    float ans = squareRoot(n);
    cout<< ans<< endl;
    return 0;
}