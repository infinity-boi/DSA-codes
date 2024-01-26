// Binary Search

#include <iostream>
using namespace std;

// Find the square root of x without builtin function
// Binary Search : Works for finding sqrt(n) but not sqrt(x), where x is a number. It only gives integer values of sqrt(n).
float squareRoot(int n, int p){
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
    float fans = ans;
    float inc = 0.1;
    for(int t= 1; t<=p; t++){
        while(fans*fans<=n){
            fans+= inc;
        }
        fans -= inc;
        inc = inc/ 10;
    }
    return fans;
}

int main(){
    int n; 
    cin>> n;
    int p;
    cin>> p;
    // Binary search method to find sqrt(n)
    float ans = squareRoot(n, p);
    cout<< ans<< endl;
    return 0;
}