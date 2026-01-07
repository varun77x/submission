class Solution {
public:

    int max_sum(vector<int>& nums,vector<int> dp,int l ,int r){
         for(int i = l ; i <= r ; i++ ){

            int skip = 0;
            if(i - 1 >= 0){
                skip = dp[i-1];
            }
            int take = nums[i];
            if(i-2 >= 0){
                take += dp[i-2];
            }
            dp[i] = max(skip,take);
            
        }

        return dp[r];
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1,0);
        if(n == 1){
            return nums[0];
        }

        return max(max_sum(nums,dp,0,n-2), max_sum(nums,dp,1,n-1));
        
    }
};