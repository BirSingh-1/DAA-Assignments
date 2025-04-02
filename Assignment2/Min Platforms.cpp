#	RUN IT ON ONLINE COMPILER

#include<iostream>
#include<vector>
#include<algorithm>
 using namespace std;
 int main(){
    vector<int> a={900,940,950,1100,1500,1800};
    vector<int> d={910,1200,1120,1130,1900,2000};
    sort(a.begin(),a.end());
    sort(d.begin(),d.end());
    int needed=1;
    int i=0;
    int j=0;
    while(i<a.size() && j<a.size()){
        if(a[i]<d[j]){
            needed++;
            i++;
        }
        else if(a[i]>d[j]){
            needed--;
            j++;
        }
    }
    cout<<needed;
 }
