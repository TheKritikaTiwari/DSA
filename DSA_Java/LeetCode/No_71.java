class Solution {
    public String simplifyPath(String path) {
        Stack<String> stack = new Stack<String>();
        Set<String> set = new HashSet<String>(Arrays.asList("..",".",""));
        for(String dir: path.split("/")){
            if(!set.contains(dir)){
                stack.push(dir);
            }
            else if(dir.equals("..") && !stack.isEmpty()){
                stack.pop();
            }
            
        }
        StringBuilder stb = new StringBuilder();
        //String s;
        for(String s: stack){
            stb= stb.append("/").append(s);
        }
        //return "a";
        return (stb.length()>0?  stb.toString() :  "/");
    }
}