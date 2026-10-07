class Solution {
    public int[] nextGreaterElement(int[] nums1, int[] nums2) {
        HashMap<Integer, Integer> mp = new HashMap<>();
        int m = nums1.length;
        int n = nums2.length;
        int[] ans = new int[m];
        Arrays.fill(ans, 0);
        Deque<Integer> st = new ArrayDeque<>();

        for (int i = 0; i < m; i++) {
            mp.put(nums1[i], i);
        }

        for (int i = n - 1; i >= 0; i--) {
            while (!st.isEmpty() && st.peek() <= nums2[i]) {
                st.pop();
            }
            if (mp.containsKey(nums2[i])) {
                if (!st.isEmpty() && st.peek() > nums2[i]) {
                    ans[mp.get(nums2[i])] = st.peek();

                } else {
                    ans[mp.get(nums2[i])] = -1;

                }
            }
            st.push(nums2[i]);
        }
        return ans;
    }
}