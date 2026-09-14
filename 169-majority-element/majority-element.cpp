class Solution {
public:

    int majorityElement(vector<int>& nums) {
        // vector<int>:
        // Used to store a dynamic array of integers.
        // vector is part of the C++ STL (Standard Template Library).
        //
        // vector<int>& nums:
        // '&' means nums is passed by reference.
        // This avoids creating a copy of the entire array.
        // Therefore, it saves extra memory.
        //
        // nums is the input array containing n integers.


        int candidate = 0;
        // 'int' is used because the array contains integer values.
        //
        // candidate stores the element that is currently considered
        // to be the possible majority element.
        //
        // We initialize it with 0.
        // This is only an initial value; it will be replaced when
        // count becomes 0.


        int count = 0;
        // count represents the current "vote balance" of candidate.
        //
        // If we see the same element as candidate:
        //     count increases.
        //
        // If we see a different element:
        //     count decreases.
        //
        // This is the main idea of the Boyer-Moore Majority Vote Algorithm.


        for (int num : nums) {
            // Range-based for loop.
            //
            // 'for' is used to visit every element of the array.
            //
            // 'int num' stores the current element.
            //
            // ': nums' means take each element from nums one by one.
            //
            // Example:
            // nums = [2, 2, 1]
            //
            // num will become:
            // 2 → 2 → 1
            //
            // This avoids manually using an index such as nums[i].


            if (count == 0) {
                // If count becomes 0, the previous candidate has
                // completely lost its vote advantage.
                //
                // Therefore, we choose the current element as
                // the new candidate.


                candidate = num;
                // Store the current element as our new candidate.
            }


            if (num == candidate) {
                // Check whether the current element is the same
                // as our current candidate.
                //
                // '==' is the equality comparison operator.


                count++;
                // Same element → candidate gets one vote.
                //
                // '++' increases count by 1.
            }


            else {
                // The current element is different from candidate.
                //
                // Instead of maintaining a frequency table,
                // Boyer-Moore cancels one vote of the candidate.


                count--;
                // Different element → cancel one vote.
                //
                // '--' decreases count by 1.
            }
        }


        return candidate;
        // Return the final candidate.
        //
        // The problem guarantees that a majority element always exists.
        // Therefore, after all cancellations, candidate will be
        // the majority element.
    }
};