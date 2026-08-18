class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
       int ans=0;
        unordered_set<int>st;
        for(int num:nums){
            st.insert(num);
        }
        int n= nums.size();

        for(auto it:st){
            if(st.find(it-1) == st.end()){
               int count =1;
              int  start = it;    //start pt

                while(st.find(start+1) != st.end()){
                    start++;
                    count++;
                }
                ans = max(count,ans);
            }
        }
        return ans;
    }
};