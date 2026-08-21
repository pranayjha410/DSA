class Solution {
public:
    vector<int> searchRange(vector<int>& arr, int target) {
        vector<int>ans{-1,-1};
        int left =0;
        int right = arr.size()-1;

            //lowwer bound
        while(left<=right){
            int mid = left +(right-left)/2;
            if(arr[mid] == target){
                ans[0] = mid;  //this might be last occ, look futhure
                right = mid-1;
            }
            else if(arr[mid] < target){
                left = mid+1;
            }
            else{
                right = mid-1;
            }
        }

        left = 0,right=arr.size()-1;
        while(left<=right){
            int mid = left+(right-left)/2;
            if(arr[mid] == target){
                ans[1] = mid; //this might be fisrt occ, look futhure
                left = mid+1;
            }
            else if(arr[mid]<target){
                left = mid+1;
            }
            else{
                right = mid-1;
            }
        }
        return ans;
    }
};