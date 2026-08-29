class Solution {
public:
    int maxProductDifference(vector<int>& arr) {
        int n=arr.size();
        int high =INT_MIN;
        int sec_high =INT_MIN;
        int low =INT_MAX;
        int sec_low =INT_MAX;

        for(int i=0;i<n;i++){
            if(arr[i]>high){
                sec_high = high;
                high = arr[i];
            }
            else if(arr[i]>sec_high ){
                sec_high = arr[i];
            }
        }

        
        for(int i=0;i<n;i++){
            if(arr[i]<low){
                sec_low = low;
                low = arr[i];
            }
            else if(arr[i]<sec_low ){
                sec_low = arr[i];
            }
        }

        return ((high*sec_high) - (low*sec_low));
    }
};