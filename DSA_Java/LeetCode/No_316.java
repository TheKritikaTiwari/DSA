class Solution {
    public String removeDuplicateLetters(String s) {
        int[] count =new int[26];
        boolean[] visited =new boolean[26];
        Stack<Character> stack = new Stack<Character>();
        for(char c:s.toCharArray()){
            count[c - 'a']++;
        }
        for(int i=0;i<26;i++){
            System.out.print(count[i]+" ");
        }
        System.out.println();
        
        for(int i=0;i<26;i++){
            System.out.print(visited[i]+" ");
        }
        for(char c : s.toCharArray()){
            System.out.println(stack);
            count[c - 'a']--;
            if(visited[c - 'a']) continue;
            while(!stack.isEmpty() && c<stack.peek() && count[stack.peek()- 'a']>0){
                visited[stack.pop() - 'a'] = false;
            }
            stack.push(c);
            visited[c - 'a'] =  true;
        }
        StringBuilder stb = new StringBuilder();
        //String s;
        for(char c: stack){
            stb.append(c);
        }
        return stb.toString();

        // Stack<String> stack = new Stack<String>();
        // int i;
        // String ch[] = s.toCharArray();
        // Arrays.sort(ch);   
        // for(i=0;i<ch.length;i++)
        // {
        //     if(!stack.contains(ch[i])){
        //         stack.push(ch[i]);
        //     }
        //     else{
        //         stack.pop();
        //     }
        // }
        // StringBuilder stb = new StringBuilder();
        // //String s;
        // for(String s: stack){
        //     stb= stb.append(s);
        // }
        // return stb.toString();
    }
}