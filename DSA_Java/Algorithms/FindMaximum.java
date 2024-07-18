import java.util.*;
public class FindMaximum{
    public static void main(String args[]){
        ArrayList<Integer> list = new ArrayList<Integer>();
        Scanner sc = new Scanner(System.in);
        String str[] = sc.nextLine().split(" ");
        int i;
        for(i=0;i<str.length;i++){
            list.add(Integer.parseInt(str[i]));
        }
        int max1=Integer.MIN_VALUE, max2=Integer.MIN_VALUE, max3=Integer.MIN_VALUE;
        //for 1st maximum
        for(i=0;i<list.size();i++){
            if(max1<list.get(i)){
                max1=list.get(i);
            }
        }
        //for 2nd maximum
        for(i=0;i<list.size();i++){
            if(max2<list.get(i) && list.get(i)!=max1){
                max2=list.get(i);
            }
        }
        //for 3rd maximum
        for(i=0;i<list.size();i++){
            if(max3<list.get(i) && (list.get(i)!=max1 && list.get(i)!=max2)){
                max3=list.get(i);
            }
        }
        System.out.println(max1 + " " + max2 +" "+max3);
    }
}