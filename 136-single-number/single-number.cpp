class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int duplicate=0;
        for(auto num:nums){
            duplicate^=num;
        }
        return duplicate;
    }
};