class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int sum_index;
        int n = coins.size();
        vector<int> dp(amount+1,-1);
        dp[0] = 0;

        for(int dp_index = 1 ; dp_index <= amount ; dp_index++){
            int minimum_sum = amount+1;
            for(int c_index = 0 ; c_index < n ; c_index++){
                sum_index = dp_index - coins[c_index];
                if(sum_index < 0 or dp[sum_index] == amount + 1) continue;
                if(minimum_sum > dp[sum_index]){
                    minimum_sum = dp[sum_index]  + 1;
                }
            }
            dp[dp_index] = minimum_sum;
        }
        return dp[amount]==amount+1?-1:dp[amount];
    }
};