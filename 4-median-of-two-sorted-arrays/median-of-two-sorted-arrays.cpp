class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        
        int i = 0, j = 0;
        int prev = 0, curr = 0;

        for (int k = 0; k <= (n + m) / 2; k++) {
            prev = curr;

            if (i < n && (j >= m || nums1[i] <= nums2[j])) {
                curr = nums1[i++];
            } else {
                curr = nums2[j++];
            }
        }

        if ((n + m) % 2 == 0) {
            return (prev + curr) / 2.0;
        }

        return curr;
    }
};