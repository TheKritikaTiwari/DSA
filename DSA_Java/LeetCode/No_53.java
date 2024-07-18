class Solution {
    public int maxSubArray(int[] nums) {
        int result = nums[0];
        int temp=0;
        for(int i=0;i<nums.length;i++){
            // temp = nums[i];
            // for(int j=i+1;j<nums.length;j++){
            //     temp+=nums[j];
            //     result = Math.max(result,temp);
            // }
            temp = temp+nums[i];
            result = Math.max(result,temp);
            if(temp<0){
                temp=0;
            }
        }
        return result;
    }
}