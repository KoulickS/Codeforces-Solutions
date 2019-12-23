#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int q;
	cin>>q;
	int cnt;
	while(q>0)
	{
		int n;
		cin>>n;
		int a[(n*4)];
		for(int i=0;i<(n*4);i++)
		{
			cin>>a[i];
		}
		sort(a,a+(n*4));
		cnt=0;
		int k=a[0]*a[4*n-1];
		for(int i=0;i<4*n;i=i+2)
			if(a[i]*a[4*n-1-i]!=k||a[i]!=a[i+1])cnt++;
		if(cnt>0) cout<<"NO"<<endl;
		else cout<<"YES"<<endl;
		q--;
	}
	return 0;
}