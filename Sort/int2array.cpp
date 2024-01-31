#include <iostream>
#include <math.h>
using namespace std;


int main()
{
    
    cout << "Enter number: ";
    int num;
    cin >> num;
    int n = ceil(log10(num));
    int digits[n];

    //converting integer to array
    for (int i = 0; i < n; i++)
    {
        int tempDigit = num % 10;
        digits[i]=tempDigit;
        num/=10;
    }

   //insertion sort:
        for (int  j = 1; j <n; j++)
    {
        int key=digits[j];
        int i=j-1;
        while (i>=0 && digits[i]<key){ //descending sort
            digits[i+1]=digits[i];
            i--;
        }
        digits[i+1]=key;
   
    }
    
//printing:

    for (int i = 0; i < n; i++)
    {
        cout<<" "<<digits[i];
    }
    cout<<"\n";
    

    return 0;
}