class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_set<int> m;
        int n = nums.size();
        int one;

        for(int i=0;i<n;i++){
            if(m.count(target-nums[i])){
                one = i;
                break;
            }
            m.insert(nums[i]);
        }
        for(int i = 0;i< n; i++){
            if(target - nums[one] == nums[i]) return{one,i};
        }
        return {-1,-1};
    }
};