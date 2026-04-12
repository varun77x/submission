class Solution {
public:
    vector<int> findDegrees(vector<vector<int>>& matrix) {
        vector<int> ans;
        int count;
        for(auto V:matrix){
            count = 0;
            for(auto E:V){
                if(E == 1){
                    count++;
                }
            }
            ans.push_back(count);
        }
        return ans;
    }
};