// https://leetcode.com/problems/search-a-2d-matrix/
// Binary Search
// 2D Array
// Matrix

#include <iostream>
#include <vector>

using namespace std;

// You are given an m x n integer matrix matrix with the following two properties:

// Each row is sorted in non-decreasing order.
// The first integer of each row is greater than the last integer of the previous row.
// Given an integer target, return true if target is in matrix or false otherwise.

// You must write a solution in O(log(m * n)) time complexity.

 

// Example 1:
// Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
// Output: true

bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int i=0;
        int j=matrix[i].size()-1;
        if(j>99){
            
        }
        while(i<matrix.size() && j>=0 && j<matrix[i].size()){
            if(matrix[i][j]==target){
                return true;
            }
            else if(matrix[i][j]>target){
                j--;
            }else if(matrix[i][j]<target){
               i++;
            }
        }
        return false;
    }

int main(){
    int n, m;
    cin>> n>> m;
    vector<vector<int>> matrix(n);
    for(int i=0; i<n; i++){
        int x;
        for(int j=0; j<m; j++){
            cin>> x;
            matrix[i].push_back(x);
        }
    }
    int target;
    cin>>target;
    bool ans = searchMatrix(matrix, target);
    if(ans==true)
    cout<<"True";
    else cout<<"False";
    return 0;
}