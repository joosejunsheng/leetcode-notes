class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        int maxSum = nums[0];
        int tempSum = nums[0];
        int n = nums.size();
        
        for(int i = 1; i < n; i++){
            tempSum = max(tempSum + nums[i], nums[i]);
            maxSum = max(maxSum, tempSum);

        }
        
        return maxSum;
    }
};