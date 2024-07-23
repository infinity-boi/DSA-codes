// https://leetcode.com/problems/coin-change/

// Dynamic Programming, Memoization

#include <bits/stdc++.h>
using namespace std;


int solve(vector<int> &coins, int &amount, long long current, int num, int minCoins){
    if(current==amount){
        return num;
    }
    if(current>amount){
        return INT_MAX;
    }
    for(int i=0; i<coins.size(); i++){
        int curCoins = solve(coins, amount, current+coins[i], num+1, minCoins);
        minCoins = min(minCoins, curCoins);
    }
    return minCoins;
}
int coinChangeRecur(vector<int>& coins, int amount) {
    sort(coins.begin(), coins.end(), greater<int>());
    int minCoins = solve(coins, amount, 0L, 0, INT_MAX);
    return (minCoins == INT_MAX) ? -1 : minCoins;
}


int coinChange(vector<int>& coins, int amount) {
    int n = coins.size();
    sort(coins.begin(), coins.end());
    vector<int> dp(amount+1, amount+1);
    dp[0] = 0;
    for(int i=1; i<amount+1; i++){
        for(int coin: coins){
            if( i-coin >=0){
                dp[i] = min(dp[i], 1 + dp[i-coin]);
            }
        }
    }
    return (dp[amount]!=amount+1)? dp[amount] : -1;

}

int main(){
    int am, n;
    vector<int> coins;
    vector<int> dp;
    cin >> am >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        coins.push_back(x);
    }
    int ans = coinChange(coins, am);
    cout << ans;
    
}