// https://leetcode.com/problems/nth-magical-number/
// Binary Search
#include <bits/stdc++.h>
using namespace std;

int MOD = 1e9+7;

int divTermCount(int a, int b, int n, long long lcm, long long num){
    long long count =  num / a + num / b - num / lcm;
    if(count >= n) return 1;
    else return 0;
}

int nthMagicalNumber(int n, int a, int b) {
    long long low = 1L;
    long long high = (min(a*1L, b*1L) * (n*1L));
    long long mid;
    long long lcm = (a * b) / __gcd(a, b);
    long long ans = high;
    while (low <= high) {
        mid = (high + low) / 2;
        if(divTermCount(a, b, n, lcm, mid)){
            ans = mid;
            high = mid -1;
        }
        else
            low = mid + 1;
    }
    return ans % MOD;
}

int main(){
    int n, a, b;
    cin>>n>> a>> b;
    cout<< nthMagicalNumber(n, a, b);
    return 0;
}