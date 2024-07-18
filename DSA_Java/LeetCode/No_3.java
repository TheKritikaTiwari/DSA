import java.util.*;
class Solution {
    public int lengthOfLongestSubstring(String s) {
        int result=0;
        Map<Character,Integer> set=new HashMap<>(); 
        int left =0;
        for(int right=0;right<s.length();right++){
            char currCharacter = s.charAt(right);
            if(set.containsKey(currCharacter)){
                left = Math.max(left,set.get(currCharacter) +1);
            }
            set.put(currCharacter,right);
            result = Math.max(result,right-left+1);

        }
        return result;
    }
}