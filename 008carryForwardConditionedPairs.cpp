// Array
// Carry Forward

#include <iostream>
using namespace std;

// Given a string, Calculate number of pairs of (i, j) such that a[i] == 'a' and a[j] == 'g'
//      |g|s|a|g|d|a|a|e|g|a|

int main() {
    int n = 10;
    char arr[] = {'g','s','a','g','d','a','a','e','g','a'};
    int ans = 0;
    int cG = 0;
    for(int i=n-1; i>=0; i--){
        if(arr[i]=='g'){
            cG++;
        }
        if(arr[i]=='a'){
            ans += cG;
        }
    }
    cout<<ans;

    return 0;
}