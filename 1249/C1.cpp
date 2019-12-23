#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int n,t,i,count=0,p,q=0,flug;
    cin>>t;
    while(t--){
            q=0;
            count=0;
        cin>>n;
        p=n;
        while(p!=0){
            p=p/3;
            count++;
        }
        //cout<<count<<" ";
        for(i=count;i>=0;i--){
            q+=pow(3,i);

        }
       // cout<<q<<endl;

        for(i=count;i>=0;i--){
            //cout<<q<<" ";
            if(q-pow(3,i)>=n) q-=pow(3,i);

        }

        cout<<q<<endl;


    }
}