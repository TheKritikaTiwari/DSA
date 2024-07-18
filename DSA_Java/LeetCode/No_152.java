class Solution {
    public int maxProduct(int[] nums) {
        int mxProduct=nums[0],mnProduct=nums[0],result=nums[0];
        for(int i=1;i<nums.length;i++){
            if(nums[i]<0){
                int temp = mxProduct;
                mxProduct = mnProduct;
                mnProduct = temp;
            }
            mxProduct = Math.max(nums[i],nums[i]*mxProduct);
            mnProduct = Math.min(nums[i],nums[i]*mnProduct);
            result = Math.max(result,mxProduct);
        }
        return result;
    }
}