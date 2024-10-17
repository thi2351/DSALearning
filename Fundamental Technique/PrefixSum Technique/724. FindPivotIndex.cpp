class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefixSum(n,0);
        vector<int> postfixSum(n,0);
        for (int i = 1; i < n; i++) {
            prefixSum[i] = nums[i-1] + prefixSum[i-1];
        }
        for (int i = n - 2; i >= 0; i--) {
            postfixSum[i] = nums[i+1] + postfixSum[i+1];
        }
        for (int i = 0; i < n; i++) {
            if (prefixSum[i] == postfixSum[i]) {return i;}
        }
        return -1;
    }
};
