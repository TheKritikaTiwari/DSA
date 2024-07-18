class Solution{
    //Function to find the leaders in the array.
    static ArrayList<Integer> leaders(int arr[], int n){
        // Your code here
        ArrayList<Integer> result = new ArrayList<Integer>();
        boolean flag=true;
        for(int i=0;i<n-1;i++){
             flag=true;
            for(int j=i+1; j<n;j++){
                if(arr[i]<arr[j]){
                    flag=false;
                    break;
                }
            }
            if(flag==true){
                result.add(arr[i]);
            }
        }
        result.add(arr[n-1]);
        return result;
    }
}