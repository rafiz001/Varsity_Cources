//by rafiz
#include<iostream>
using namespace std;
int main(){
    int capasityLeft=5;
    int profit[5]={10,15,10,12,8};
    int quantity[5]={3,3,2,5,1};
    int knapsack[5]={0};
    int totalProfit=0;

    int profitPerUnit[5]={0};
    for(int i=0;i<5;i++)
    profitPerUnit[i]=profit[i]/quantity[i];

    for(int i=0;i<5;i++){ //buble sort (descending)
        for(int j=0;j<5-1;j++){
            if(profitPerUnit[j]<profitPerUnit[j+1]){
            swap(profitPerUnit[j],profitPerUnit[j+1]);
            swap(profit[j],profit[j+1]);
            swap(quantity[j],quantity[j+1]);}
        }
    }



    for(int i=0;i<5;i++){
        if(capasityLeft==0)break;

        int unitTaken=min(quantity[i],capasityLeft);
        totalProfit+=unitTaken*profitPerUnit[i];
        quantity[i]-=unitTaken;
        knapsack[i]+=unitTaken;
        capasityLeft-=unitTaken;
    }
    cout<< "Pre profit\t Knapsack\n";
    for(int i=0;i<5;i++){
        cout<<profit[i] <<"\t\t\t"<< knapsack[i]<< "\n";
    }
    cout<<"Total Profit: "<< totalProfit<<"\n";
}
