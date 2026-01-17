class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        int max_left = 0, max_right=0, maxLen = 1;

        for(int i = 0; i < n; i++) {
            // for odd length
            int left = i, right = i;
            while(left >= 0 && right < n && s[left] == s[right]) {
                if(right - left + 1 > maxLen) {
                    max_left = left;
                    max_right= right;
                    maxLen = right - left + 1;
                }
                left--; right++;
            }

            // even length
            left = i; right = i + 1;
            while(left >= 0 && right < n && s[left] == s[right]) {
                if(right - left + 1 > maxLen) {
                    max_left = left;
                    max_right= right;
                    maxLen = right - left + 1;
                }
                left--; right++;
            }
        }

        return s.substr(max_left,maxLen);
    }
};
