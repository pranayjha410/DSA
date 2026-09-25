class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int n = nums.size();
        int count =0;
        int sum =0;
        mp[0] =1;
        for(int i=0;i<n;i++){
            sum += nums[i];
            
            // int rem = sum % k;
            int rem = ((sum%k)+k)%k;

            if(mp.find(rem) != mp.end()){
                count += mp[rem];
            }
            mp[rem]++;
        }
        return count;
    }
};