import java.util.*; 
class FractionalKnapsack{
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter total no. of items: ");
        int n=sc.nextInt();
        System.out.print("Enter total weight of: ");
        int w=sc.nextInt();
        int val[] = new int[n];
        int weight[] = new int[n];
        int i,j,a=0,b=0,c=0,result=0;
        for(i=0;i<n;i++){
            System.out.print("Enter values for obj"+(i+1)+" : ");
            val[i]=sc.nextInt();
            System.out.print("Enter weight for obj"+(i+1)+" : ");
            weight[i]=sc.nextInt();
        }
        int frac[] = new int[n];
        for(i=0;i<n;i++){
            frac[i] = val[i]/weight[i];
        }
        for(i=0;i<n-1;i++){
            for(j=i+1;j<n;j++){
                if(frac[i]<frac[j]){
                    a = frac[i];
                    frac[i] = frac[j];
                    frac[j] = a;
                    b = val[i];
                    val[i] = val[j];
                    val[j] = b;
                    c = weight[i];
                    weight[i] = weight[j];
                    weight[j] = c;
                }
            }
        }
        // System.out.print("\nObjects are:   ");
        // for(i=0;i<n;i++){
        //     System.out.print("obj"+(i+1)+"\t");
        // }
        // System.out.print("\nValues are:    ");
        // for(i=0;i<n;i++){
        //     System.out.print(val[i]+"\t");
        // }
        // System.out.print("\nWeights are:   ");
        // for(i=0;i<n;i++){
        //     System.out.print(weight[i]+"\t");
        // }
        // System.out.print("\nFractions are: ");
        // for(i=0;i<n;i++){
        //     System.out.print(frac[i]+"\t");
        // }
        for(i=0;i<n;i++){
            if(w > weight[i]){
                w = w - weight[i];
                result = result + val[i];
            }
            else{
                result = result + ((w * val[i])/weight[i]);
            }
        }
        System.out.println("\nResult is: "+result);
    }
}