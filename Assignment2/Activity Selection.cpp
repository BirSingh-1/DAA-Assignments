 #include<iostream>
 #include<vector>
 using namespace std;
 int main(){
 	vector<int>a={1,2,3,4,5,6};
    vector<int>s{1,3,0,5,8,5};
    vector<int>f={2,4,5,7,9,9};
    vector<int>A;
    A.push_back(a[0]);
    int k=0;
    for(int m=1;m<a.size();m++){
        if(s[m]>=f[k]){
            A.push_back(a[m]);
            k=m;
        }
    }
   for(int i=0;i<A.size();i++){
       cout<<A[i]<<endl;
   }
 }
