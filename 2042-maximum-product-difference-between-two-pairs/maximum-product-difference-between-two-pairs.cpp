class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        int n=nums.size();
        sort(nums.rbegin(),nums.rend());
        int w = nums[0];
        int x = nums[1];
        int y = nums[n-1];
        int z = nums[n-2];

        return ((w*x) - (y*z));
    }
};