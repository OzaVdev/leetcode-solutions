class Solution {
public:
    int maxArea(vector<int>& height) {
        int result = 0;
        int left = 0;
        int right = height.size() - 1;

        while (left < right) {
            int min_height = min(height[left], height[right]);
            int area = (right - left) * min_height;
            result = max(result, area);

            if (min_height == height[left]) {
                left++;
            } else {
                right--;
            }
        }
        
        return result;
    }
};