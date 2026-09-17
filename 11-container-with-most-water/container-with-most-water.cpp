class Solution {
public:
    int maxArea(vector<int>& h) {
        int l = 0;
        int r = h.size() - 1;
        int ans = 0;

        while (l < r) {
            int height = h[l] < h[r] ? h[l] : h[r];
            int area = height * (r - l);

            if (area > ans)
                ans = area;

            if (h[l] < h[r]) {
                int x = h[l];
                while (++l < r && h[l] <= x);
            }
            else {
                int x = h[r];
                while (l < --r && h[r] <= x);
            }
        }

        return ans;
    }
};