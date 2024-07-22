// Heap

#include <iostream>
#include <vector>
using namespace std;

class Heap{
    vector<int> maxheap;
    
    public:
    
    Heap(){
        maxheap.push_back(-1);
    }
    Heap(int cap){
        maxheap.reserve(cap+1);
        maxheap.push_back(-1);
    }

    int capacity(){
        return maxheap.size();
    }
    
    void push(int data){
        maxheap.push_back(data);
        int idx=maxheap.size()-1;
        while(idx>1 && maxheap[idx] > maxheap[idx/2]){
            swap(maxheap[idx],maxheap[idx/2]);
            idx /= 2;
        }
    }
    
    int top(){
        return maxheap[1];
    }

    void heapify(int idx){
        int l = 2*idx;
        int r = l+1;
        int mx = idx;
        if(l<maxheap.size() && maxheap[idx]< maxheap[l]){
            mx=l;
        }
        if(r<maxheap.size() && maxheap[mx]< maxheap[r]){
            mx=r;
        }
        if(mx!=idx){
            swap(maxheap[idx], maxheap[mx]);
            heapify(mx);
        }        
    }
    
    void pop(int idx){
        swap(maxheap[idx], maxheap[maxheap.size()-1]);
        maxheap.pop_back();
        heapify(idx);
    }

    void show();

    void heapsort();

};


void Heap::show(){
    int n = maxheap.size();
    for(int i=1; i<n; i++){
        cout<<" "<<maxheap[i];
    }
    cout<<endl;
}

void Heap::heapsort(){
    int n = capacity();
    for(int i=n/2; i>=1; i--){
        heapify(i);
    }
    for(int i=n-1; i>1; i++){
        swap(maxheap[0], maxheap[i]);
        heapify(0);
    }
}
int main(){
    int n;
    cin>> n;
    Heap hip(n);
    for(int i = 0; i<n; i++){
        int x;
        cin>>x;
        hip.push(x);
    }
    int max = hip.top();
    cout<<"Max is : "<<max<<endl;
    cout<<"Heapified array is : ";
    hip.show();
    cout<<"Sorted array is : ";
    hip.heapsort();
    cout<<" ";
    hip.show();
    return 0;
}