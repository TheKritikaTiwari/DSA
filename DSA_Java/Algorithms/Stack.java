import java.util.Scanner;
class StackOp{
    int arr[] =  new int[100];
    int size,top;
     StackOp(){
        top=-1;
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the size: ");
        size = sc.nextInt();
    }
    public void push(int val){
        if(top==size-1){
            System.out.println("Stack is in Overflow");
        }
        top++;
        arr[top]=val;
        System.out.println("Element pushed !!");
    } 
    public int pop(){
        if(top==-1){
            return -404;
        }
        int temp = arr[top];
        top--;
        return temp; 
         
    }
    public int peek(){
        return this.arr[this.top];
    }
    public boolean isEmpty(){
        if(top==-1) 
        {
            return true;
        } else return false;
    }
    public void show(){
        if(top==-1){
            System.out.println("Stack is empty");
        }
        else{
            System.out.print("Stack elelment:");
            for(int i=0;i<=top;i++){
                System.out.print(arr[i]+" ");
            }
            System.out.println();
        }
        
    }
}
public class Stack{
    public static void main(String args[]){
        StackOp obj = new StackOp();
        Scanner sc = new Scanner(System.in);
        while(true){
            System.out.println("1. PUSH");
            System.out.println("2. POP");
            System.out.println("3. PEEK");
            System.out.println("4. STACK EMPTY");
            System.out.println("5. SHOW");
            System.out.println("0 EXIT");
            System.out.print("Enter your choice: ");
            int ch = sc.nextInt();
            if(ch==0){
                break;
            }
            else if(ch==1){
                System.out.print("Enter stack element: ");
                int val = sc.nextInt();
                obj.push(val);
            }
            else if(ch==2){
                int temp=obj.pop();
                if(temp==-404){
                    System.out.println("Stack is in Underflow");
                }
                else{
                    System.out.println("Element popped: "+temp);
                }
            }
            else if(ch==3){
                System.out.println("Peek element is: "+obj.peek());
            }
            else if(ch==4){    
                System.out.println("Stack Empty:" + obj.isEmpty());
            }
            else if(ch==5){
                obj.show();
            }
        }
    }
}