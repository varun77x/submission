class Solution {
public:
    int characterReplacement(string s, int k) {
        // AABABABBA
        int n = s.length();
        int maxi = 0;
        int left = 0;
        int right = 0;
        unordered_map<char, int> mp;
        int curr = 0;

        while (right < n) {
            mp[s[right]]++;
            int temp = 0;
            for (auto& [key, value] : mp) {
                temp = max(temp, value);
            }
            if ((right - left + 1) - temp > k) {
                while ((right - left + 1) - temp > k and left < right) {
                    mp[s[left]]--;
                    left++;
                }
            } else
                maxi = max(maxi, right - left + 1);
            right++;
        }

        return maxi;
    }
};