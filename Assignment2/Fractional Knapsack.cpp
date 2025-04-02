#include <iostream>
#include <algorithm>
using namespace std;
class item{
    public:
    int no;
    int profit;
    int wght;
};
bool compare(item a,item b){
    return a.profit/a.wght>b.profit/b.wght;
}
int main()
{
    item itm[]={{1,280,40},{2,100,10},{3,120,20},{4,120,24}};
    int n=sizeof(itm)/sizeof(itm[0]);
    sort(itm,itm+n,compare);
    
    cout << "Sorted items based on profit/weight ratio:\n";
    for (int i = 0; i < n; i++) {
        cout << "Item " << itm[i].no << " - Profit: " << itm[i].profit 
             << ", Weight: " << itm[i].wght << ", Ratio: " 
             << (double)itm[i].profit / itm[i].wght << endl;
    }
    
    double x[4]={0};
    int max=60;
    for(int i=0;i<n;i++){
        if(itm[i].wght<=max){
            x[i]=1;
            max=max-itm[i].wght;
        }
        else{
            x[i]=double(max)/itm[i].wght;
            break;
        }
    }
    
    for(int i=0;i<n;i++){
        cout<<itm[i].no<<": "<<x[i]<<endl;
    }
}
