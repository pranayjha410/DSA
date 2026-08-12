class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n= nums.size();
        int largest = INT_MIN;
        int second_lar = INT_MIN;
        for(int i=0;i<n;i++){
            if(nums[i] > largest){
                second_lar = largest;
                largest = nums[i];
            }
            else if(nums[i]>=second_lar ){
                second_lar = nums[i];
            }
        }
         
        int ans =((largest-1) * (second_lar-1));
        return ans;
    }
};