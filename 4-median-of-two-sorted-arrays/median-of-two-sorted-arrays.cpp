class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // Always binary search on the smaller array
        if (nums1.size() > nums2.size())
            return findMedianSortedArrays(nums2, nums1);

        int n = nums1.size();
        int m = nums2.size();

        int low = 0, high = n;

        while (low <= high) {
            int partition1 = low + (high - low) / 2;
            int partition2 = (n + m + 1) / 2 - partition1;

            int left1  = (partition1 == 0) ? INT_MIN : nums1[partition1 - 1];
            int right1 = (partition1 == n) ? INT_MAX : nums1[partition1];

            int left2  = (partition2 == 0) ? INT_MIN : nums2[partition2 - 1];
            int right2 = (partition2 == m) ? INT_MAX : nums2[partition2];

            // Correct partition
            if (left1 <= right2 && left2 <= right1) {

                // Odd total length
                if ((n + m) % 2 == 1)
                    return max(left1, left2);

                // Even total length
                return (max(left1, left2) + min(right1, right2)) / 2.0;
            }

            // Too many elements taken from nums1
            if (left1 > right2)
                high = partition1 - 1;

            // Too few elements taken from nums1
            else
                low = partition1 + 1;
        }

        return 0.0;
    }
};
// /*```cpp
// class Solution {
// public:
//     double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

//         /*
//             APPROACH:
//             ---------
//             We use Binary Search + Partition.

//             Goal:
//             Divide both arrays into LEFT and RIGHT parts such that:

//                 All elements in LEFT <= All elements in RIGHT

//             Example:

//                 nums1 = [1, 3, 8]
//                          LEFT | RIGHT

//                 nums2 = [7, 9, 10, 11]
//                          LEFT | RIGHT

//             We want the total number of elements on the LEFT side
//             to be half of the total elements.

//             Since we only need to find the correct partition,
//             we don't need to merge the arrays.

//             Time Complexity:
//                 O(log(min(n, m)))

//             Space Complexity:
//                 O(1)
//         */


//         // ---------------------------------------------------------
//         // STEP 1: Always binary search on the SMALLER array
//         // ---------------------------------------------------------
//         //
//         // This is important because our binary search will run
//         // between 0 and nums1.size().
//         //
//         // If nums1 is larger, swap the arrays.
//         //
//         // This guarantees:
//         //
//         //     nums1.size() <= nums2.size()
//         //
//         // Therefore complexity becomes:
//         //
//         //     O(log(min(n, m)))
//         //
//         if (nums1.size() > nums2.size())
//             return findMedianSortedArrays(nums2, nums1);


//         int n = nums1.size();
//         int m = nums2.size();


//         // ---------------------------------------------------------
//         // STEP 2: Binary Search on nums1
//         // ---------------------------------------------------------
//         //
//         // partition1 tells us how many elements we take from
//         // nums1 into the LEFT half.
//         //
//         // Example:
//         //
//         // nums1 = [1, 3, 8, 9]
//         //
//         // partition1 = 2
//         //
//         // means:
//         //
//         // [1, 3 | 8, 9]
//         //       ^
//         //    partition
//         //
//         int low = 0;
//         int high = n;


//         while (low <= high) {

//             // Number of elements taken from nums1
//             int partition1 = low + (high - low) / 2;


//             // -----------------------------------------------------
//             // STEP 3: Calculate partition2
//             // -----------------------------------------------------
//             //
//             // We want exactly half of all elements on the LEFT.
//             //
//             // Total elements = n + m
//             //
//             // Number of elements required on LEFT:
//             //
//             //       (n + m + 1) / 2
//             //
//             // So if partition1 elements come from nums1,
//             // the remaining elements must come from nums2.
//             //
//             //       partition2 =
//             //       (n + m + 1) / 2 - partition1
//             //
//             int partition2 = (n + m + 1) / 2 - partition1;


//             // -----------------------------------------------------
//             // STEP 4: Find the 4 important boundary elements
//             // -----------------------------------------------------
//             //
//             // We only care about the elements immediately around
//             // the partitions.
//             //
//             // nums1:
//             //
//             //      left1 | right1
//             //
//             // nums2:
//             //
//             //      left2 | right2
//             //
//             // Example:
//             //
//             // nums1 = [1, 3 | 8, 9]
//             //              ↑
//             //
//             // left1  = 3
//             // right1 = 8
//             //
//             // If partition is at the beginning/end of an array,
//             // one side doesn't exist.
//             //
//             // We use:
//             //
//             //      INT_MIN = -infinity
//             //      INT_MAX = +infinity
//             //
//             // This avoids special handling for boundaries.
//             //

//             int left1 =
//                 (partition1 == 0)
//                 ? INT_MIN
//                 : nums1[partition1 - 1];

//             int right1 =
//                 (partition1 == n)
//                 ? INT_MAX
//                 : nums1[partition1];


//             int left2 =
//                 (partition2 == 0)
//                 ? INT_MIN
//                 : nums2[partition2 - 1];

//             int right2 =
//                 (partition2 == m)
//                 ? INT_MAX
//                 : nums2[partition2];


//             // -----------------------------------------------------
//             // STEP 5: Check whether the partition is CORRECT
//             // -----------------------------------------------------
//             //
//             // We need:
//             //
//             //      left1 <= right2
//             //
//             // AND
//             //
//             //      left2 <= right1
//             //
//             // Why?
//             //
//             // We want every element on LEFT <= every element
//             // on RIGHT.
//             //
//             // Because both arrays are already sorted, we only
//             // need to check the two boundary conditions.
//             //
//             //       nums1: [ ... left1 | right1 ... ]
//             //       nums2: [ ... left2 | right2 ... ]
//             //
//             // If:
//             //
//             //       left1 <= right2
//             //       left2 <= right1
//             //
//             // then the partition is correct.
//             //
//             if (left1 <= right2 && left2 <= right1) {


//                 // -------------------------------------------------
//                 // STEP 6: Find the median
//                 // -------------------------------------------------
//                 //
//                 // CASE 1:
//                 // Total number of elements is ODD
//                 //
//                 // Example:
//                 //
//                 // [1, 3, 7, 8, 9]
//                 //          ↑
//                 //       median
//                 //
//                 // The median is the largest element on the LEFT.
//                 //
//                 if ((n + m) % 2 == 1)
//                     return max(left1, left2);


//                 // -------------------------------------------------
//                 // CASE 2:
//                 // Total number of elements is EVEN
//                 // -------------------------------------------------
//                 //
//                 // Example:
//                 //
//                 // [1, 3, 7, 8, 9, 10]
//                 //       ↑  ↑
//                 //
//                 // Median = (middle1 + middle2) / 2
//                 //
//                 // middle1 = largest element on LEFT
//                 // middle2 = smallest element on RIGHT
//                 //
//                 // Therefore:
//                 //
//                 //      max(left1, left2)
//                 //
//                 // and
//                 //
//                 //      min(right1, right2)
//                 //
//                 // are the two middle elements.
//                 //
//                 return (max(left1, left2) +
//                         min(right1, right2)) / 2.0;
//             }


//             // -----------------------------------------------------
//             // STEP 7: Partition is WRONG
//             // -----------------------------------------------------
//             //
//             // There are two possibilities.
//             //
//             // CASE 1:
//             //
//             //      left1 > right2
//             //
//             // This means we took TOO MANY elements from nums1
//             // into the LEFT half.
//             //
//             // So move partition1 to the LEFT.
//             //
//             if (left1 > right2) {
//                 high = partition1 - 1;
//             }


//             // CASE 2:
//             //
//             //      left2 > right1
//             //
//             // This means we took TOO FEW elements from nums1.
//             //
//             // Therefore we need to take MORE elements from nums1.
//             //
//             // Move partition1 to the RIGHT.
//             //
//             else {
//                 low = partition1 + 1;
//             }
//         }


//         // This should never be reached because a valid partition
//         // always exists for valid input.
//         return 0.0;
//     }
// };
// ```*/