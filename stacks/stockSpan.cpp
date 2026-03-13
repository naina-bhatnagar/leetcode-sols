#include <iostream>
#include <stack>

using namespace std;

class StockSpanner {
public:
    stack <pair<int,int>> curr;

    StockSpanner() {}
    
    int next(int price) {
        int span = 1;

        while(!curr.empty() && curr.top().first <= price){
            span += curr.top().second;
            curr.pop();
        }
        
        curr.push({price,span});
        return span;
    }
};

int main(){
    
    return 0;
}