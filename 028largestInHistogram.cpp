#include <bits/stdc++.h>
using namespace std;

int largestRectangleArea(vector<int>& heights) {
        int n =heights.size();
        stack<int> st;
        int leftsm[n], rightsm[n];
        int maxArea = 0;
        for(int i=0; i<n ;i++)
        {
            while(!st.empty() && heights[st.top()]>= heights[i]) st.pop();
            if(st.empty()){
                leftsm[i] = 0;
            }
            else{
                leftsm[i] = st.top()+1;
            }
            st.push(i);
        }
        while(!st.empty()) st.pop();
        for(int i=n-1; i>=0; i--){
            while(!st.empty() && heights[st.top()]>=heights[i]) st.pop();
            if(st.empty()){
                rightsm[i] = n-1; 
            }
            else{
                rightsm[i] = st.top()-1;
            }
            st.push(i);
            maxArea = max(maxArea, (rightsm[i]-leftsm[i]+1)*heights[i]);
        }
        return maxArea;
    }

int main(){
    vector<int> heights = {2,1,5,6,2,3};
    int maxArea = largestRectangleArea(heights);
    cout<< maxArea;
    return 0;
    
}