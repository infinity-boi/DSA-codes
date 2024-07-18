#include <bits/stdc++.h>
using namespace std;
// slidin window, precomputation

long long countSubarrays(vector<int>& nums, int minK, int maxK) {
    int n = nums.size();
    int cumi = n-1, cuma = n-1;
    int s = 0, e = 0;
    int ans = 0;
    int nextma[n], nextmi[n];
    nextma[n-1] = n;
    nextmi[n-1] = n;
    for(int i=n-2; i>=0; i--){
        nextma[i] = cuma;
        nextmi[i] = cumi;
        if(nums[i]>nums[cuma]) cuma = i;
        if(nums[i]<nums[cumi]) cumi = i;
    }
    cuma = 0, cumi = 0;
    while(e<n){
        if(nums[e]>=nums[cuma]) cuma = e;
        if(nums[e]<=nums[cumi]) cumi = e;
        while(nums[cuma]==maxK && nums[cumi]==minK && s<=e){
            if(nums[nextma[s]]==maxK && nums[nextmi[s]]==minK) ans+= e-s+1;
            else ans+=1;
            if(nums[s]>nums[cuma]) cuma = nextma[s];
            if(nums[s]<nums[cumi]) cumi = nextmi[s];
            s++;
        }
        e++;
    }
    return ans;
}
    
int main(){
    vector<int> nums = {1,1,1,1};
    int minK = 1;
    int maxK = 1;
    long long ans = countSubarrays(nums, minK, maxK);
    cout << "Number of subarrays with fixed bound (minK, maxK): ";
    cout<< ans;
    return 0;
    
}