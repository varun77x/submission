class Solution {
public:
    int maxProduct(vector<int>& nums) {

        int n = nums.size();

        long maxi = INT_MIN;
        long runner = 1;

        for (int i = 0; i < n; i++) {
            runner = runner * nums[i];
            maxi = max(maxi, runner);
            if(runner == 0) {
                runner = 1;
            }
        }
        runner = 1;
        for (int i = n - 1; i >= 0; i--) {
            runner = runner * nums[i];
            maxi = max(maxi, runner);
            if (runner == 0) {
                runner = 1;
            }
        }

        return int(maxi);
    }
};