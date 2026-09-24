class Solution {
public:
    void rotate(vector<int>& nums, int k) {
    if(nums.size()<=k)
    {
        k = k % nums.size();
        
    }
    int start = nums.size() - k ;
    reverse(nums.begin()+start,nums.begin()+start+k);
    vector<int> nums1;      
    for(int i = 0;i<k;i++)
      {
        int x = nums.back();
        nums.pop_back();
        nums1.push_back(x);
      }
    nums.insert(nums.begin(),nums1.begin(),nums1.end());
     
    }
};