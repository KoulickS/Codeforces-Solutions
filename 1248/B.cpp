#include<bits/stdc++.h>
using namespace std;
// #include <boost/multiprecision/cpp_int.hpp> 
// using namespace boost::multiprecision;
#define boost ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long int
//#define for(i,n) for(ll i=0;i<n;i++)
#define pb push_back
#define mp make_pair
 
//ALWAYS USE ll DATA TYPE FOR INTEGER(FASTER THAN INTEGER) && DOUBLE FOR DECIMAL VALUES.. 
int main() {
    
   
      boost;
      ll n; cin>>n;
      ll arr[n];
      for(int i=0;i<n;i++)
      cin>>arr[i];
      sort(arr,arr+n,greater<int>());
      ll x=0,y=0;
      ll k;
      ll res=0;
      if(n%2==0)
      {
            k=n/2;
            for(ll i=0;i<k;i++)
            x+=arr[i];
            for(ll j=k;j<n;j++)
            y+=arr[j];
            
            res = x*x + y*y;
            
      }
      else
      {     // max min max min max....
            k=n/2;
            for(ll i=0;i<=k;i++)
            x+=arr[i];
            for(ll j=k+1;j<n;j++)
            y+=arr[j];
            
            res= x*x + y*y;
            
      }
      cout<<res<<"\n";
      
      
    return 0;
}