#include <bits/stdc++.h>
using namespace std;

int runningMedian(vector<int> stream, int i, int median, priority_queue<int, vector<int>, greater<int>> minHeap,
    priority_queue<int> maxHeap){
        if(stream[i]<median){
            maxHeap.push(stream[i]);
        }
        else{
            minHeap.push(stream[i]);
        }
        int x= maxHeap.size();
        int y= minHeap.size();
        if(abs(x-y)>1){
            if(x>y){
                int p = maxHeap.top();
                maxHeap.pop();
                minHeap.push(p);
            }
            else{
                maxHeap.push(minHeap.top());
                minHeap.pop();
            }
        }
        if(maxHeap.size()==minHeap.size()){
            median = maxHeap.top();
        }
        else if(maxHeap.size()> minHeap.size()){
            median = maxHeap.top();
        }
        else{
            median = minHeap.top();
        }
        return median;
    
}

int main(){
    int n;
    cin>> n;
    vector<int> stream;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    priority_queue<int> maxHeap;
    for(int i=0 ; i<n; i++){
        int x;
        cin>>x;
        stream.push_back(x);
    }
    int median = stream[0];
    cout<<median;
    maxHeap.push(stream[0]);
    for(int i=1 ; i<n; i++){
        int out = runningMedian(stream, i, median, minHeap, maxHeap);
        cout<< out<<endl;
    }
}