class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> dp(nums.size(),0);
        int sum = nums[0];
        int maxi = nums[0];

        for(int i = 1 ; i < nums.size();i++){
            if(sum > 0){
                sum = nums[i] + sum;
            }
            else sum = nums[i];
            maxi = max(maxi,sum);
        }
        return maxi;
    }
};