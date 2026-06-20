class Solution {
public:
    vector<int> nearestSmallerRight(vector<int>& arr){
        int n=arr.size();
        stack<int>st;
        vector<int> ans;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[st.top()] >= arr[i]  ){
                st.pop();
            }
            if(!st.empty()){
                // ans.push_back(i); //mistake, pushing same(current elemtn)
                ans.push_back(st.top());
            }
            else{
                // ans.push_back(-1);
                ans.push_back(n); // last byond arr for right side
            }
            st.push(i);
        }
        
         reverse(ans.begin(),ans.end());
         return ans;
    }

     vector<int> nearestSmallerLeft(vector<int>& arr){
        int n=arr.size();
        stack<int>st;
        vector<int> ans;
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()] >= arr[i]  ){
                st.pop();
            }
            if(!st.empty() && arr[i] > arr[st.top()]){
                ans.push_back(st.top());
            }
            else{
                ans.push_back(-1);
            }
            st.push(i);
        }
        return ans;
    }
    int largestRectangleArea(vector<int>& arr) {
        vector<int>nsr =nearestSmallerRight(arr);
        vector<int> nsl =nearestSmallerLeft(arr);

        int n= arr.size();
        int area=0;
        for(int i=0;i<n;i++){
           int  width = nsr[i] - nsl[i] -1;
            area = max(area, arr[i]*width);
        }
        return area;
    }
};