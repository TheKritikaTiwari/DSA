class Solution {
    public int maxSubarraySumCircular(int[] nums) {
        int maxSum = kadane(nums);
        if(maxSum<0) return maxSum;
        int totalSum = 0;
        for(int n: nums){
            totalSum += n;
        }
        int negatedArr[] = new int[nums.length];
        for(int i=0;i<nums.length;i++){
            negatedArr[i] = -(nums[i]);
        }
        int minSum = kadane(negatedArr);
        int circularSumArr = Math.max(maxSum,totalSum+minSum);
        return circularSumArr;
    }
    public int kadane(int[] nums){
        int result = nums[0];
        int sum=nums[0];
        for(int i=1;i<nums.length;i++){
            sum=Math.max(nums[i],sum+nums[i]);
            result=Math.max(sum,result);
        }
        return result;
    }
}