#include<bits/stdc++.h>
#include<string.h>
#define ll long long int
#define fio ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;
void solve(){
    ll T=1;
    cin>>T;
    while(T--){
        string se;
		cin>>se;
		ll vec[26]; ll i;
		for(i=0;i<26;i++) vec[i]=0; ll cou=1;
	    for(i=1;i<se.length();i++){
			if(se[i]==se[i-1]){
				cou++; continue;}
			if(cou%2==1)
			 vec[se[i-1]-'a']=1;cou=1;}
		if(cou%2==1)
		 vec[se[se.length()-1]-'a']=1;
		for(i=0;i<26;i++)
		if(vec[i]==1)
		cout<<(char)('a'+i);

		cout<<endl;
    }
}
int main()
{
    solve();
}