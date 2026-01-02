#include <iostream>
using namespace std;


//Buy Sell Stocks 
// given an array of stock prices on consequetive days, find the max profit...

int main(){
    int prices[15] = {244,4,6,32,6,441,8,4,5,6,9,1,2,25,8};
    int n = 15;

    int bestBuy = prices[0], maxPr = 0;
    for(int i=1;i<n;i++){
        if(prices[i]<bestBuy){
            bestBuy = prices[i];
        }
        maxPr = max(maxPr,prices[i]-bestBuy);
    }

    cout<<"Maximum Profit is: "<<maxPr<<endl;
    return 0;
}