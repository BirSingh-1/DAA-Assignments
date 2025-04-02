#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    string s1="stone";
    string s2="longest";
    int m=s1.size();
    int n=s2.size();
    int k[m+1][n+1];
    for(int i=0;i<=m;i++){
        for(int j=0;j<=n;j++){
            if(i==0 || j==0){
                k[i][j]=0;
            }
            else{
                if(s1[i-1]==s2[j-1]){
                    k[i][j]=1+k[i-1][j-1];
                }
                else{
                    k[i][j]=max(k[i][j-1],k[i-1][j]);
                }
            }
        }
    }
    cout<<k[m][n]<<endl;
    string op="";
    int i=m;
    int j=n;
    
    while(i>0 && j>0){
        if(s1[i-1]==s2[j-1]){
            op+=s1[i-1];
            i--;
            j--;
        }
        else if(k[i-1][j]>k[i][j-1]){
            i--;
        }
        else{
            j--;
        }
    }
    reverse(op.begin(),op.end());
    cout<<op;
}
