#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long int
#define ll long long int
#define mp make_pair
#define pb push_back
#define mod 1000000007
#define mem memset
#define ff first
#define ss second
#define loop0(i,n) for(i=0;i<n;i++)
#define loop1(i,n) for(i=1;i<=n;i++)
#define rloop0(i,n) for(i=n-1;i>=0;i--)
#define rloop1(i,n) for(i=n;i>0;i--)
#define sloop0(i,n,s) for(i=0;i<n;i+=s)
int main()
{
	int t,n,k,i,j,x;
	int p,q;
	cin>>t;
	int num;
	loop1(x,t)
	{
		cin>>n>>k;
		set<int> a;
		loop0(i,n)
		{
			cin>>p;
			a.insert(p);
		}
		vector<int> v;
		for(auto el:a)
			v.pb(el);
		int s=0;
		n=v.size();
		if(n==1)
		{
			float ann=(float)(k-1)/k;
			printf("Case #%d: %.6f\n",x,ann);
			//cout<<"Case #"<<x<<": "<<ann<<'\n';
			continue;
		}
		vector<int> diff;
		for(i=1;i<n;i++)
			diff.pb(v[i]-v[i-1]-1);
		sort(diff.begin(),diff.end());
		n=diff.size();
		int diff1=diff[n-1];
		int diff2=diff[n-2];
		p=(diff1+1)/2;
		q=(diff2+1)/2;
		if(diff1>1 && (diff1>p+q))
			num=diff1;
		else
			num=p+q;
		n=v.size();
		if(v[0]!=1&&v[n-1]!=k)
		{
			if((v[0]-1)+(k-v[n-1])>num)
				num=(v[0]-1)+(k-v[n-1]);
		}
		else if(v[0]!=1)
		{
			if(v[0]-1>num)
				num=v[0]-1;
			if((v[0]-1)+p>num)
				num=v[0]-1+p;
			if(diff1>num)
				num=diff1;
		}
		else if(v[n-1]!=k)
		{
			if(k-v[n-1]>num)
				num=k-v[n-1];
			if((k-v[n-1]+p)>num)
				num=k-v[n-1]+p;
			if(diff1>num)
				num=diff1;
		}
		float ans=(float)num/k;
		printf("Case #%d: %.6f\n",x,ans);
		//cout<<"Case #"<<x<<": "<<ans<<'\n';
	}
	return 0;
}