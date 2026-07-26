class Solution {
public:
    int min(vector<int>& nums){
        int left =0,right=nums.size()-1;

        while(left<right){
            int mid = left+(right-left)/2;

            if(nums[mid] <= nums[right]){
                right = mid;
            }
            else{
                left = mid+1;
            }
        }
        return left;
    }
    int binary_search(int left,int right,int target, vector<int>&nums){
          while(left<=right){
            int mid = left+(right-left)/2;
            if(nums[mid] == target){
                return mid;
            }
            else if(nums[mid]>target){
                right = mid-1;
            }
            else{
                left = mid+1;
            }
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int min_el = min(nums);

        int ans = binary_search( 0, min_el -1, target,nums);
        int ans2 = binary_search(min_el, n-1, target,nums);

        if(ans != -1) return ans;
        else if(ans2 != -1) return ans2;
        else return -1;
    }
};