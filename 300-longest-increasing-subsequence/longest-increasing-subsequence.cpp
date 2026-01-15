class Solution {
public:
    int solve(vector<int>& nums, int index, int prev,vector<int>& dp) {
        if (index == nums.size()) {
            return 0;
        }
        int take = 0, skip = 0;
        if (nums[index] > prev) {
            if (dp[index] == -1) {
                take = solve(nums, index + 1, nums[index],dp) + 1;
                dp[index] = take;
            }
            take = dp[index];
        }
        skip = solve(nums, index + 1, prev,dp);
        return max(take, skip);
    }

    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);

        int ans = solve(nums, 0, INT_MIN,dp);
        return ans;
    }
};
