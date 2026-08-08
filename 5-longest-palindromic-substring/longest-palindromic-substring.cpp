class Solution {
public:
    bool isValid(string& temp) {
        int n = temp.size();
        int i = 0, j = n - 1;

        while (i < j) {
            if (temp[i] != temp[j]) {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    string longestPalindrome(string s) {
        int n = s.size();
        string ans = "";
        for (int i = 0; i < n; i++) {
            string temp = "";
            for (int j = i; j < n; j++) {
                temp += s[j];
                if (isValid(temp)) {
                    if (temp.size() >= ans.size()) {
                        ans = temp;
                    }
                }
            }
        }
        return ans;
    }
};