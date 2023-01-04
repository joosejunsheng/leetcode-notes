## 53. Maximum Subarray
Can be solved using brute force (O(n^2)) solution to loop for all the possible subarrays and check for the max sum. (Time Limit Exceed)

O(n) solution:
At every step in the loop, we need to determine whether *IS IT WORTH TO INCLUDE PREVIOUS* step into our result / will the previous sum contribute to the maximum sum

### Testcase : [-5, 4, 18, -3, 10]
We set tempSum = nums[0];
We set maxSum = nums[0];

When we are at 4 (Position 1), we need to check if the previous -5 (Position 0) will contribute to our maximum sum and apparently it only make the sum smaller.
We check tempSum = max(nums[i], tempSum + nums[i]) and our temporary maximum (aka previous maximum sum) is now 4.
To get the maximum sum, we can get 4 by doing maxSum = max(maxSum, tempSum).

When we are at 18 (Position 2), we need to check if the previous temporary maximum 4 will contribute to our maximum sum. And yes it will.
We check tempSum = max(nums[i], tempSum + nums[i]) and our temporary maximum (aka previous maximum sum) is now 22.
To get the maximum sum, we can get 22 by doing maxSum = max(maxSum, tempSum).

When we are at -3 (Position 3), we need to check if the previous temporary maximum 22 will contribute to our maximum sum. And yes it will.
We check tempSum = max(nums[i], tempSum + nums[i]) and our temporary maximum (aka previous maximum sum) is now 19.
To get the maximum sum, we still get 22 by doing maxSum = max(maxSum, tempSum).

When we are at 10 (Position 4), we need to check if the previous temporary maximum 19 will contribute to our maximum sum. And yes it will.
We check tempSum = max(nums[i], tempSum + nums[i]) and our temporary maximum (aka previous maximum sum) is now 29.
To get the maximum sum, we get 29 by doing maxSum = max(maxSum, tempSum).

Ans: 29