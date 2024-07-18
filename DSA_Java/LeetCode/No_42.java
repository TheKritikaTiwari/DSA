class Solution {
    public int trap(int[] height) {
        //4 2 0 3 2 5
       int water = 0;
       Stack<Integer> stack = new Stack<Integer>();
       for(int i=0;i<height.length;i++){
        while(!stack.isEmpty() && height[i]>height[stack.peek()]){
            int top = stack.pop();  //top = 2
            if(stack.isEmpty()){
                break;
            }
            
            int distance = i - stack.peek() -1; //
            int boundedHeight = Math.min(height[i],height[stack.peek()]) - height[top];
            water += distance * boundedHeight;
        }
        //stack = [0,1]
        stack.push(i);
       }  
       return water;
    }
}