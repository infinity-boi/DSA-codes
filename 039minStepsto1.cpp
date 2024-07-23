// https://www.naukri.com/code360/problems/min-steps-to-one-using-dp_920548?utm_source=youtube&utm_medium=affiliate&utm_campaign=Codestudio_AyushiSharma


#include <bits/stdc++.h>
using namespace std;

// greedy - gives wrong answer
int minStepsGreedy(int n){
    int steps = 0;
    while ( n > 1)
    {
        if (n % 3 == 0)
            n /= 3;    
        else if (n % 2 == 0)
            n /= 2;
        else
            n--;
        steps++;
    }
    return steps;
}


// recursive
int minStepsRecur(int n) 
{ 
    if(n==1)
    return 0;
    int a=INT_MAX, b=INT_MAX, c=INT_MAX;
    if(n%2==0) a=1+minStepsRecur(n/2);
    if(n%3==0) b=1+minStepsRecur(n/3);
    c=1+minStepsRecur(n-1);
    return min(a,min(b,c));
} 

// memoization
int solve(int n, int dp[]){
        if(n==1) return 0;
        
        if(dp[n]!=-1) return dp[n];
        
        int a=INT_MAX, b=INT_MAX, c=INT_MAX;
        if(n%2==0)
        a=1+solve(n/2, dp);
        if(n%3==0)
        b=1+solve(n/3, dp);
        c=1+solve(n-1, dp);
        
        dp[n] = min(a,min(b,c));
        return dp[n];
}
int minStepsMemo(int n) 
{ 
    int dp[1000];
    memset(dp,-1,sizeof(dp));
    return solve(n, dp);
}


// dynamic programming - bottom up
int minSteps(int n) 
{ 
    int dp[n+1];
    
    dp[0]=0, dp[1]=0, dp[2]=1, dp[3]=1;
    
    for(int i=4;i<=n;i++)
    {
         int a=INT_MAX, b=INT_MAX, c=INT_MAX;
         if(i%3==0)
         a=1+dp[i/3];
         if(i%2==0)
         b=1+dp[i/2];
         c=1+dp[i-1];
         dp[i] = min(a,min(b,c));
    }
    return dp[n];
} 

int main(){
    int t;
    cin>> t;
    while(t--){
        int n;
        cin>>n;
        cout<< minSteps(n)<< endl;  
    } 
    return 0;
}