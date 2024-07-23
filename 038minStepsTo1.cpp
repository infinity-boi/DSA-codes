// https://www.geeksforgeeks.org/minimum-step-reach-one/

// 

#include <bits/stdc++.h>
using namespace std;


//  structure represent one node in queue
struct data
{
    int val;
    int steps;
    data(int val, int steps) : val(val), steps(steps)
    {}
};
 
//  method returns minimum step to reach one
int minStepToReachOne(int n)
{
    queue<data> q;
    q.push(data(n, 0));
 
    set<int> st;
 
    //  loop until we reach to 1
    while (!q.empty())
    {
        data t = q.front();     
        q.pop();
         
        // if current data value is 1, return its
        // steps from n
        if (t.val == 1)
            return t.steps;
 
        //  check curr - 1, only if it not visited yet
        if (st.find(t.val - 1) == st.end())
        {
            q.push(data(t.val - 1, t.steps + 1));
            st.insert(t.val - 1);
        }

        //  loop from 2 to sqrt(value) for its divisors
        for (int i = 2; i*i <= t.val; i++)
        {
            // check divisor, only if it is not visited yet
            // if i is divisor of val, then val / i will
            // be its bigger divisor
            if (t.val % i == 0 && st.find(t.val / i) == st.end())
            {
                q.push(data(t.val / i, t.steps + 1));
                st.insert(t.val / i);
            }
        }
    }
}
 
//  Driver code to test above methods
int main()
{
    int n = 17;
    cout << minStepToReachOne(n) << endl; 
}