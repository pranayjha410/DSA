class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int count =0;
        int sum=0;
        unordered_map<int,int>mp;
        mp[0] = 1;

        for(int i=0;i<n;i++){
            sum += nums[i];

            int left = sum-k;
            if(mp.find(left) != mp.end()){
                count += mp[left];
            }

            mp[sum]++;
        }
        return count;
    }
};