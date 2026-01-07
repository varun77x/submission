class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1,0);
        if(n == 1){
            return nums[0];
        }

        for(int i = 1 ; i < n ; i++ ){
            int skip = dp[i-1];
            int take = nums[i];
            if(i-2 >= 0){
                take += dp[i-2];
            }
            dp[i] = max(skip,take);
        }
        int max_from_not_taking_the_first_element = dp[n-1];
        
        fill(dp.begin(),dp.end(),0);
        for(int i = 0 ; i < n-1 ; i++ ){
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
        int max_from_taking_the_first_element = dp[n-2];

        return max(max_from_not_taking_the_first_element,max_from_taking_the_first_element);
        
    }
};