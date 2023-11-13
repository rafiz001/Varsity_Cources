public class QuickSort {
   
    public void swap(int array[],int i,int j){
        int temp=array[i];
        array[i]=array[j];
        array[j]=temp;
    }

    public void quickSort(int array[],int start,int end){
        if(end<=start) return;
            int pivot=partition(array,start,end);
            quickSort(array,start,pivot-1);
            quickSort(array,pivot+1,end);
        
    }
    public int partition(int array[],int start,int end){
        int pivot=array[end];
        int i=start-1;
        for(int j=start;j<=end-1;j++){
            if(array[j]<=pivot){
                i++;
                swap(array, i, j);
            }
        }
        i++;
        swap(array,i,end);
        return i;
    }
    public static void main(String[] args) {
        int array[]={3,7,8,5,2,1,9,5,4};
        QuickSort qs=new QuickSort();
        qs.quickSort(array,0,array.length-1);
        
        
        System.out.println("Sorted Array: ");
       for(int i=0;i<array.length-1;i++){
            System.out.print(array[i]+" ");
        }
        System.out.println("");
       
    }
}
