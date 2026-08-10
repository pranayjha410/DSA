class Solution {
public:
    int getSum(int num) {
        int sum = 0;
         while (num > 0) {
            int digit = num % 10;
            sum += digit * digit;
            num /= 10;
        }
        return sum;
    }
    
    bool isHappy(int n) {
        unordered_set<int> st;

        while (n != 1 && st.find(n) == st.end()) {
            st.insert(n);
            n = getSum(n);  //key pt-->override num... missing pt(confus)

            if(st.find(n) != st.end()){
                return false;
            }
        }
        return true;

        
    }
};