#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> lastSeen(256, -1);

        int start = 0, ans = 0;

        for (int end = 0; end < s.size(); end++) {
            unsigned char c = s[end];

            if (lastSeen[c] >= start)
                start = lastSeen[c] + 1;

            lastSeen[c] = end;
            ans = max(ans, end - start + 1);
        }

        return ans;
    }
};
