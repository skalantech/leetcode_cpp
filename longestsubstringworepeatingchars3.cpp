#include <string>
#include <vector>
#include <iostream>

using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int maxLength = 0;
        vector<int> charIndex(128, -1);
        int left = 0;

        for (int right = 0; right < n; right++) {
            if (charIndex[s[right]] >= left) {
                left = charIndex[s[right]] + 1;
            }
            charIndex[s[right]] = right;
            maxLength = max(maxLength, right - left + 1);
        }

        return maxLength;
    }
};

int main() {
    string s = "abcabcbb";
    string s1 = "bbbbb";
    string s2 = "pwwkew";
    Solution sol;
    int res = sol.lengthOfLongestSubstring(s);
    int res1 = sol.lengthOfLongestSubstring(s1);
    int res2 = sol.lengthOfLongestSubstring(s2);
    cout << res << ' ' << res1 << ' ' << res2 << '\n';
    return 0;
}