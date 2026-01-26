class Solution {
public:
    // int count = 0;
    unordered_map<int, int> mp;
    int sol(int index, string s, int n) {
        if (mp.count(index)) {
            return mp[index];
        }
        if (index == n) {
            return 1;
        }
        if (s[index] == '0') {
            return 0;
        }
        string runner = "";
        int total = 0;
        for (int i = index; i < n; i++) {

            runner = runner + s[i];
            if (stoi(runner) > 26) {
                break;
            } else {
                total = total + sol(i + 1, s, n);
            }
        }
        return mp[index] = total;
    }
    int numDecodings(string s) {
        int count = sol(0, s, s.length());
        return count;
    }
};