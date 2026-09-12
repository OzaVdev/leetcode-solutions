#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        array<int, 256> lastSeen;
        lastSeen.fill(-1);

        int start = 0, ans = 0;

        for (int i = 0; i < s.size(); ++i) {
            unsigned char c = s[i];

            if (lastSeen[c] >= start)
                start = lastSeen[c] + 1;

            lastSeen[c] = i;
            ans = max(ans, i - start + 1);
        }

        return ans;
    }
};