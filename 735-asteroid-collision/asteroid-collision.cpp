class Solution {
public:
    vector<int> asteroidCollision(vector<int>& arr) {
        int n = arr.size();
        stack<int> st;

        for (int i = 0; i < n; i++) {

            if (arr[i] > 0) {
                st.push(arr[i]);
            }

            if (arr[i] < 0) {

                while (!st.empty() &&
                       st.top() > 0 &&
                       st.top() < abs(arr[i])) {
                    st.pop();
                }

                if (!st.empty() && st.top() > abs(arr[i])) {
                    continue;
                }

                else if (!st.empty() && st.top() == abs(arr[i])) {
                    st.pop();
                    continue;
                }

                st.push(arr[i]);
            }
        }

        vector<int> ans;

        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};