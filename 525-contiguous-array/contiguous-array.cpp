class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> mp;
        mp[0] = -1;
        int n = nums.size();
        int sum = 0;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                sum += -1;
            } else {
                sum += nums[i];
            }
            if (mp.find(sum) != mp.end()) {
                ans = max(ans, i - mp[sum]);

            } else {
                mp[sum] = i;
            }
        }
        return ans;
    }
};