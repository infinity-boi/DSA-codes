// https://leetcode.com/problems/maximum-score-from-removing-stones/
// Greedy
// Heap

#include <iostream>
#include <queue>
using namespace std;

int maximumScore(int a, int b, int c) {
    int score= 0;
    priority_queue<int> pq;
    pq.push(a);
    pq.push(b);
    pq.push(c);
    while(pq.size()>1){
        int one = pq.top(); pq.pop();
        int two = pq.top(); pq.pop();
        score +=1;
        one--;
        two--;
        if(one)
            pq.push(one);
        if(two)
            pq.push(two);
    }
    return score;
}

int main(){
    int a, b, c;
    cin>> a >> b >> c;
    cout<< maximumScore(a, b, c) << endl;
    return 0;
}