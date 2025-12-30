class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int vertical = grid.size() -1 ;
        int hz = 0;
        int n = grid[0].size();
        int ans = 0;

        while(hz < n and vertical >= 0){
            while(hz < n and grid[vertical][hz] >= 0){
                hz++;
                cout<<hz<<endl;
            }
            ans += (n-hz); // adding the count - counting from the end
            vertical--;
        }
        return ans;
    }
};