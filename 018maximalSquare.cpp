// https://leetcode.com/problems/maximal-square/
// Dynamic Programming
#include <bits/stdc++.h>
using namespace std;

int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.empty() || matrix[0].empty()){
            return 0;
        }
        int r = matrix.size();
        int c = matrix[0].size();
        vector<vector<int>> dp(r, vector<int> (c, 0));
        int mxside = 0;
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                if(matrix[i][j]=='1'){
                    if(i==0 || j==0){
                        dp[i][j]= 1;
                    }
                    else{
                        dp[i][j]= min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]})+1;
                    }
                    mxside = max(mxside, dp[i][j]);
                }
            }
        }
        return mxside*mxside;
    }


int main(){
    int n = 4;
    vector<vector<char>> matrix;
    matrix.push_back({'1','0','1','0','0'});
    matrix.push_back({'1','0','1','1','1'});
    matrix.push_back({'1','1','1','1','1'});
    matrix.push_back({'1','0','0','1','0'});
    
    int ans = maximalSquare(matrix);
    cout<< ans;
    return 0;
}