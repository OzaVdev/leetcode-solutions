class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int ans = 0;

        while (left < right) {
            int h = height[left] < height[right] ? height[left] : height[right];
            int area = (right - left) * h;

            if (area > ans)
                ans = area;

            if (height[left] < height[right])
                ++left;
            else
                --right;
        }

        return ans;
    }
};