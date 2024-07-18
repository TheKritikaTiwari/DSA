import java.util.*;
class Solution {
    public long maximumSubarraySum(int[] nums, int k) {
        HashSet<Integer> set = new HashSet<Integer>();
        long result = 0;
        long sum=0;
        int left=0;
        for(int right=0;right<nums.length;right++){
            while(set.contains(nums[right])){
                set.remove(nums[left]);
                sum-=nums[left];
                left++;
            }
            set.add(nums[right]);
            sum+=nums[right];
            if(right-left+1 == k){
                result = Math.max(result,sum);
                set.remove(nums[left]);
                sum-=nums[left];
                left++;
            }
        }
        return result;
    }
}