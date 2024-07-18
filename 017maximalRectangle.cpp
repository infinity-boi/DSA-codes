// https://leetcode.com/problems/maximal-rectangle/
// stack, dp

#include <bits/stdc++.h>
using namespace std;

// Given a rows x cols binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.


// Example 1:


// Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
// Output: 6
// Explanation: The maximal rectangle is shown in the above picture.
// Example 2:

// Input: matrix = [["0"]]
// Output: 0
// Example 3:

// Input: matrix = [["1"]]
// Output: 1
 

// Constraints:

// rows == matrix.length
// cols == matrix[i].length
// 1 <= row, cols <= 200
// matrix[i][j] is '0' or '1'. 

int largestRectangle(vector<vector<int>> &arr, int j, int m){
    stack<int> st;
    int leftsm[m], rightsm[m];
    int curLargest = 0;
    for(int i=0; i<m; i++){
        while(!st.empty() && arr[j][st.top()] >= arr[j][i]){
            st.pop();
        }
        if(st.empty()) leftsm[i] = 0;
        else{
            leftsm[i] = st.top() + 1;
        }
        st.push(i);
    }
    while(!st.empty()) st.pop();
    for(int i = m-1; i>=0; i--){
        while(!st.empty() && arr[j][st.top()]>= arr[j][i]){
            st.pop();
        }
        if(st.empty()) rightsm[i] = m-1;
        else{
            rightsm[i] = st.top() - 1;
        }
        st.push(i);
        curLargest = max(curLargest, (rightsm[i]-leftsm[i]+1)* arr[j][i]);
    }
    return curLargest;
}
int maximalRectangle(vector<vector<char>>& matrix) {
    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<int>> arr(n, vector<int>(m, 0));
    int maximalRectangleArea= 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(i==0 || matrix[i][j]=='0') arr[i][j] = matrix[i][j] - '0';
            else{
                arr[i][j] = matrix[i][j] - '0' + arr[i-1][j];
            }
        }
        int curLargest = largestRectangle(arr, i, m);
        maximalRectangleArea = max(maximalRectangleArea, curLargest); 
    }
    return maximalRectangleArea;
}


int main(){
    // TODO
}