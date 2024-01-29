// Two Pointer
// Sliding Window

#include <iostream>
#include <climits>
#include <algorithm>

using namespace std;

int minmaxSubarray(int A[], int n)
{
 
    // find maximum and minimum
    // values in the array
    int minValue = *min_element(A, A + n);
    int maxValue = *max_element(A, A + n);
 
    int pos_min = -1, pos_max = -1, ans = INT_MAX;
 
    // iterate over the array and set answer
    // to smallest difference between position
    // of maximum and position of minimum value
    for (int i = 0; i < n; i++) {
 
        // last occurrence of minValue
        if (A[i] == minValue)
            pos_min = i;
 
        // last occurrence of maxValue
        if (A[i] == maxValue)
            pos_max = i;
 
        if (pos_max != -1 and pos_min != -1)
            ans = min(ans, abs(pos_min - pos_max) + 1);
    }
    return ans;
}

int main(){
    int n;
    cin>> n;
    int A[n];
    for(int i=0; i<n; i++){
        cin>> A[i];
    }
    cout << minmaxSubarray(A, n);
    return 0;
}