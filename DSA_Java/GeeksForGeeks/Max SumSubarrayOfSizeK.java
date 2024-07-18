class Solution{
    static long maximumSumSubarray(int K, ArrayList<Integer> Arr,int N){
        // code here
        long result = Integer.MIN_VALUE;
        long windowSum = 0;
        int left = 0;
        for(int right =0;right < Arr.size();right++){
            windowSum+=Arr.get(right);
            if((right-left)+1==K){
                result = Math.max(result,windowSum);
                windowSum-=Arr.get(left);
                left++;
            }
        }
        return result; 
    }
}