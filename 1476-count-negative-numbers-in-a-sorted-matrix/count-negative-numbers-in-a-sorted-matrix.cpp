class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int answer = 0;
        for(auto nums:grid){
            int left = 0;
            int right= nums.size() - 1;
            int mid;

            while(left <= right){
                mid = (left + right) / 2;
                if(nums[mid] >= 0){
                    left = mid+1;
                }
                else{
                    if(mid == 0 or nums[mid-1] >= 0){
                        answer += (nums.size() - mid); // because all the elements will be negative then starting from index 0 or i
                        break;
                    }
                    else{
                        right = mid - 1;
                    }
                }
            }
        }
        return answer;
    }
};