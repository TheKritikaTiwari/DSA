import java.util.*;
public class BruteForceSubArray{
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        ArrayList<Integer> list = new ArrayList<Integer>();
        String arr[] = sc.nextLine().split(" ");
        int i,j,s=0;
        for(i=0; i<arr.length; i++){
            list.add(Integer.parseInt(arr[i]));
        }
        for(i=0;i<list.size()-1;i++){
            s=0;
            for(j=i;j<list.size();j++){
                System.out.print(list.get(j)+ " ");
                if(list.get(j)%2!=0){
                    s=s+list.get(j);
                }
            }
            System.out.println("=> "+s);
        }
        //System.out.print(list);
    }
}