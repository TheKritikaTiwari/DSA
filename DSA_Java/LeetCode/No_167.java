import java.util.*;
class Solution {
    public int[] twoSum(int[] numbers, int target) {
        int result[] =new int [2];
        HashMap<Integer,Integer> map=new HashMap<Integer,Integer>();
        for(int i=0;i<numbers.length;i++){
            int diff=target-numbers[i];
            if(map.containsKey(diff)){
                result[0] = map.get(diff)+1;
                result[1] = i+1;
                break;
            }
            map.put(numbers[i],i);
        }
        return result;
    }
}