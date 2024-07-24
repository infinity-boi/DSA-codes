// Greedy Algo

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// https://www.geeksforgeeks.org/problems/activity-selection-1587115620/1
int activitySelection(vector<int> start, vector<int> end, int n)
    {
        // Your code here
        vector<pair<int, int>> activities;
        for(int i=0; i<n; i++){
            activities.push_back({start[i], end[i]});
        }
        sort(activities.begin(), activities.end(), [](auto &a, auto &b){
            return a.second < b.second; 
        });
        int count = 1;
        int fin = activities[0].second;
        for(int i=1; i<n; i++){
            if(activities[i].first > fin){
                count++;
                fin = activities[i].second;
            }
        }
        return count;
    }


class Activity{
    public:
    int startTime;
    int endTime;
    string name;
    Activity(int st ,int et, string n) {
        startTime = st;
        endTime = et;
        name = n;
    }
};

bool compare(Activity a1, Activity a2){
    return (a1.endTime < a2.endTime);
}

int maxActivitiesPossible(vector<Activity> act, int n){
    sort(act.begin(), act.end(), compare);
    int count =1;
    int fin = act[0].endTime;
    for(int i=1; i<n; i++){
        if(act[i].startTime > fin){
            count++;
            fin = act[i].endTime;
        }
    }
    return count;
}

int main(){
    // 6 8 Yoga
    // 8 10 Breakfast
    // 9 13 Class
    // 11 12 chai 
    // 13 15 College 
    // 14 16 Sleep 
    // 16 18 Sports 
    // 17 19 Gym 
    int n;
    cin>> n;
    vector<Activity> activities;
    for(int i=0; i<n; i++){
        int startTime, endTime;
        string name;
        cin>> startTime >> endTime>> name;
        Activity activity = Activity(startTime, endTime, name);
        activities.push_back(activity);
    }
    int ans = maxActivitiesPossible(activities, n);
    cout<< ans;
    return 0;
}