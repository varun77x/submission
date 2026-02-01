class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> dp(nums.size(),0);
        dp[0] = nums[0];

        for(int i = 1 ; i < nums.size();i++){
            if(dp[i-1] > 0){
                dp[i] = nums[i] + dp[i-1];
            }
            else dp[i] = nums[i];
        }
        int maxi = -10001;
        for(int num:dp){
            maxi = max(maxi,num);
        }

        return maxi;
    }
};