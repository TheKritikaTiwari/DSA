class Solution {
    public int maxArea(int[] height) {
        int start=0, end=height.length-1;
        int result=0, temp=0;
        while(start<end){
            temp=Math.min(height[start],height[end]);
            result=Math.max(result,temp*(end-start));
            if(height[start]<height[end]){
            start++;
            }
            else{
                end--;
            }
        }
        return result;
    }
}