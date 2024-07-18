class Solution {
    
    // a: input array
    // n: size of array
    // Function to find equilibrium point in the array.
    public static int equilibriumPoint(long arr[], int n) {

        // Your code here
        long totalSum=0;
        for(int i=0;i<n;i++){
            totalSum+=arr[i];
        }
        long leftSum=0;
        for(int i=0;i<n;i++){
            totalSum-=arr[i];
            if(totalSum==leftSum){ 
                return i+1;
            }
            leftSum+=arr[i];
        }
        return -1;
    }
}
