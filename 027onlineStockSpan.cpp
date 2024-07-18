// https://leetcode.com/problems/online-stock-span/

#include <bits/stdc++.h>
using namespace std;

// monotonic stack

class StockSpanner {
public:
    stack<int> st;
    stack<int> fq;
    StockSpanner() {
        
    }
    
    int next(int price) {
        if(st.empty()){
            st.push(price);
            fq.push(1);
            return 1;
        }
        else if(st.top() > price){
            st.push(price);
            fq.push(1);
            return 1;
        }
        else {
            int temp = 1;
            while(!st.empty() && st.top() <= price){
                st.pop();
                temp+= fq.top();
                fq.pop();
            }
            st.push(price);
            fq.push(temp);
            return temp;
        }
    }
};


int main(){
    StockSpanner* obj = new StockSpanner();
    int n = 5; // days
    while(n--){
        int price;
        cin>> price;
        int param = obj->next(price);
        cout<< param<<endl;
    }
    return 0;
}