// https://leetcode.com/problems/k-closest-points-to-origin/

// Sorting
// Heap

#include <bits/stdc++.h>
using namespace std;


vector<vector<int>> kClosestUsingSorting(vector<vector<int>>& points, int k) {
    vector<pair<int, int>> dist;
    for(int i=0; i<points.size(); i++){
        int d = points[i][0]*points[i][0] + points[i][1]*points[i][1];
        dist.push_back({i, d});
    }
    sort(dist.begin(), dist.end(), [](auto &a, auto&b){
        return a.second<b.second;
    });
    vector<vector<int>> ans;
    for(int i=0; i<k; i++){
        ans.push_back(points[dist[i].first]);
    }
    return ans; 
}

vector<vector<int>> kClosestUsingHeap(vector<vector<int>>& points, int k) {
    priority_queue<pair<int, vector<int>>, vector<pair<int, vector<int>>>, greater<pair<int, vector<int>>>> pq;
    for(auto p: points){
        int d = p[0]*p[0] + p[1]*p[1];
        pq.push(make_pair(d, p));
    }
    vector<vector<int>> ans;
    for(int i=0; i<k; i++){
        ans.push_back(pq.top().second);
        pq.pop();
    }
    return ans;
}

int main(){
    int n;
    cin>>n;
    vector<vector<int>> points;
    for(int i=0; i<n; i++){
        int x, y;
        cin>> x>> y;
        points.push_back({x, y});
    }
    int k;
    cin>> k;
    vector<vector<int>> ans = kClosestUsingSorting(points, k);
    for(int i=0; i<ans.size(); i++){
        cout<< ans[i][0]<< " "<< ans[i][1]<< endl;
    }
    return 0;
    
}