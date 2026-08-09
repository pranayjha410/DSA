class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();

        int maxLen =1;
        int start =0;

        for(int i=1;i<n;i++){
            //for even pal

            int left = i-1;
            int right = i;

            while(left >=0 && right<n && s[left] == s[right]){
                if(right - left +1 > maxLen){
                    maxLen = right-left+1;
                    start = left;
                }
                left--;
                right++;
            }

            //for odd

            left = i-1;
            right = i+1;

            
            while(left >=0 && right<n && s[left] == s[right]){
                if(right - left +1 > maxLen){
                    maxLen = right-left+1;
                    start = left;
                }
                left--;
                right++;
            }


        }
        return s.substr(start,maxLen);
    }
};