// https://www.geeksforgeeks.org/bucket-sort-2/

// sorting

#include <iostream>
#include <vector>
using namespace std;

// Insertion sort function to sort individual buckets
void insertionSort(vector<float>& bucket) {
    for (int i = 1; i < bucket.size(); ++i) {
        float key = bucket[i];
        int j = i - 1;
        while (j >= 0 && bucket[j] > key) {
            bucket[j + 1] = bucket[j];
            j--;
        }
        bucket[j + 1] = key;
    }
}

// Function to sort arr[] of size n using bucket sort
void bucketSort(float arr[], int n) {
    // 1) Create n empty buckets
    vector<float> b[n];

    // 2) Put array elements in different buckets
    for (int i = 0; i < n; i++) {
        int bi = n * arr[i];
        b[bi].push_back(arr[i]);
    }

    // 3) Sort individual buckets using insertion sort
    for (int i = 0; i < n; i++) {
        insertionSort(b[i]);
    }

    // 4) Concatenate all buckets into arr[]
    int index = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < b[i].size(); j++) {
            arr[index++] = b[i][j];
        }
    }
}

// Driver program to test above function
int main() {
    float arr[] = {0.897, 0.565, 0.656, 0.1234, 0.665, 0.3434};
    int n = sizeof(arr) / sizeof(arr[0]);
    bucketSort(arr, n);

    cout << "Sorted array is \n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}


// #include <bits/stdc++.h>
// using namespace std;

// class Student{
//     public :
//         int marks;
//         string name;
//         int roll;
// };

// void bucketSort(vector<Student> nums, int n){
//     vector<vector<Student>> bucket(361);
//     int ind;
//     for(int i=0; i<n; i++){
//         ind = nums[i].marks;
//         bucket[ind].push_back(nums[i]);
//     }
//     ind = 0;
//     for (int i = 360; i>=0; i++){
//         for (int j = 0; j < bucket[i].size(); j++)
//             nums[ind++] = bucket[i][j];
//     }
    
// }


// int main(){
//     int n;
//     cin>> n;
//     vector<Student> stud;
//     for(int i=0; i<n; i++){
//         string name;
//         cin>> name;
//         int x;
//         cin>>x;
//         int roll;
//         cin>> roll;
//         Student S;
//         S.marks = x;
//         S.name = name;
//         S.roll = roll;
//         stud.push_back(S);
//     }
//     bucketSort(stud, n);
// }