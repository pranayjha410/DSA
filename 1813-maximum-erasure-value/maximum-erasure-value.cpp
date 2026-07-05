class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_set<int>st;
        int sum=0,ans=0;
        int left=0,right=0;
        int n=nums.size();

        while(right<n){
            sum += nums[right];

            while(st.find(nums[right]) != st.end()){
                sum -=nums[left];
                st.erase(nums[left]);
                left++;
            }

            ans = max(ans,sum);
            st.insert(nums[right]);
            right++;

        }
        return ans;
    }
};