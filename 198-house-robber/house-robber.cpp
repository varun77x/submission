class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(),0);
        dp[0] = nums[0];
        int n = nums.size();
        int maxi = 0;

        for(int i = 0;i<n;i++){
            int skip = (i==0?0:dp[i-1]); // dont take current but previous max
            int take = (((i==0 or i==1)?0:dp[i-2])) + nums[i]; // take current- meaning we cant take immediate previous(cause it would be adjacent) - basically -> dp[i-2] + nums[i]
            dp[i] = max(skip,take);
        }
        return dp[n-1];
    }
};