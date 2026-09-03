class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.size();
        unordered_map<char,int>mp;
        int left=0,right=0;
    int maxFreq =1;
    int ans=1;
        while(right<n){
            mp[s[right]]++;

             maxFreq = max(maxFreq,mp[s[right]]);

             while(right-left+1 - maxFreq > k){
                mp[s[left]]--;
                left++;
             } 
             ans = max(ans,right-left+1);
             right++;
        }
        return ans;
    }
};