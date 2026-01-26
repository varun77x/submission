class Solution {
public:
    int numDecodings(string s) {
        int count = 0;
        int n = s.length();
        vector<int> dp(n, 0);
        dp[s.length() - 1] = (s[n - 1] == '0') ? 0 : 1;
        for (int i = n - 2; i >= 0; i--) {
            string runner = "";
            if (s[i] == '0') {
                continue;
            }
            int temp_sum = 0;
            for (int j = i; j < n; j++) {
                runner = runner + s[j];
                if (stoi(runner) > 26) {
                    break;
                } else {
                    if (j == n - 1) {
                        temp_sum += 1;
                    } else {
                        temp_sum += dp[j+1];
                    }
                }
            }
            dp[i] = temp_sum;
        }
        return dp[0];
    }
};