class Solution {
public:
    // memoization
    unordered_map<int,int> mp;
    int solve(int sum,int n,vector<int>& coins){
        if(mp.count(sum)){
            return mp[sum];
        }
        if(sum == 0){
            return mp[sum] = 1;
        }
        else if(sum < 0){
            return mp[sum] = INT_MAX;
        }
        int temp;
        int curr_mini = INT_MAX;
        for(int i = 0; i<n ; i++){
            temp = solve(sum-coins[i],n,coins);
            if(temp < curr_mini){
                curr_mini = temp;
            }
        }
        if(curr_mini == INT_MAX){
            return mp[sum] = INT_MAX;
        }
        return mp[sum] = curr_mini + 1;
    }
    int coinChange(vector<int>& coins, int amount) {
        int temp = solve(amount,coins.size(),coins);
        return (temp==INT_MAX?-1:temp-1);
    }
};