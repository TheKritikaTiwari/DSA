//User function Template for Java

//arr1,arr2 : the arrays
// n, m: size of arrays
class Solution
{
    //Function to return a list containing the union of the two arrays.
    public static ArrayList<Integer> findUnion(int arr1[], int arr2[], int n, int m)
    {
        // add your code here
        
        ArrayList<Integer> list = new ArrayList<Integer>();
        Set<Integer> set = new HashSet<Integer>();
        int i=0, j=0;
        while(i < n && j < m){
            if(arr1[i] < arr2[j]){
                if(!set.contains(arr1[i])){
                    list.add(arr1[i]);
                    set.add(arr1[i]);
                }
                i++;
                
            }
            else{
                if(!set.contains(arr2[j])){
                    list.add(arr2[j]);
                    set.add(arr2[j]);
                }
                j++;
            }
        }
        while(i < n){
            if(!set.contains(arr1[i])){
                    list.add(arr1[i]);
                    set.add(arr1[i]);
            }
            i++;
        }
        while(j < m){
            if(!set.contains(arr2[j])){
                    list.add(arr2[j]);
                    set.add(arr2[j]);
            }
            j++;
        }
        
        return list;
    }
}