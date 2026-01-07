class Solution {
public:

    int max_sum(vector<int>& nums,int l ,int r){
        int prev_by_one = 0, prev_by_two = 0, curr =0;
        for(int i = l ; i <= r ; i++ ){

            int skip = prev_by_one;
            int take = nums[i] + prev_by_two;

            curr = max(skip,take);

            prev_by_two = prev_by_one;
            prev_by_one = curr;
  
        }

        return curr;
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1){
            return nums[0];
        }

        return max(max_sum(nums,0,n-2), max_sum(nums,1,n-1));
        
    }
};