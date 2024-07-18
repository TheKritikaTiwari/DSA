import java.util.Scanner;
public class BruteForcePrime{
    public static void main(String args[]){
        Scanner sc= new Scanner(System.in);
        int first, last, s=0, temp;
        boolean flag = false;
        System.out.println("Enter first & last values: ");
        first = sc.nextInt();
        last = sc.nextInt();
        for(int i=first; i<=last; i++){
            if(i<0) temp = -(i);
            else temp = i;
            flag=true;
            if(temp < 2)  flag = false;
            for(int j=2; j<temp; j++){
                if(temp%j==0){
                    flag = false;
                    break;
                }
            }
            if(flag==true){
                System.out.print(i + " ");
                s=s+i;
            }
        }
        System.out.print("\n"+s);
    }
}