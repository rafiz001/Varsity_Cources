#include <iostream>
#include <climits>
using namespace std;

void merge(int A[], int p, int q, int r)
{
    int n1 = q - p + 1;
    int n2 = r - q;

    int L[n1 + 1], R[n2 + 1];

    for (int i = 0; i < n1; i++) L[i] = A[p + i];
    

    for (int j = 0; j < n2; j++) R[j] = A[q + j +1];


    L[n1] = INT_MAX; //2147483647
    R[n2] = INT_MAX;

    int i = 0;
    int j = 0;

    for (int k = p; k <= r; k++)
    {
        if (L[i] <= R[j])
        {
            A[k] = L[i];
            i++;
        }
        else
        {
            A[k] = R[j];
            j++;
        }
    }
}

void mergeSort(int A[],int p,int r){
if(p<r){
    int q=(p+r)/2;
    mergeSort(A,p,q);
    mergeSort(A,q+1,r);
    merge(A,p,q,r);

}
}

int main()
{
    int a[]={2,8,5,7};
    int n=4;

    mergeSort(a,0,n-1);

    for(int i=0;i<n;i++) cout<< a[i]<< " ";
    
    cout<<"\n";

    return 0;
}
