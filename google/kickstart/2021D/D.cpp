#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
ll construct(ll* t,ll* a,ll as,ll ae,ll ti)
{
	if(as==ae)
		return t[ti]=a[as];
	ll m=as+(ae-as)/2;
	t[ti]=construct(t,a,as,m,2*ti+1)+construct(t,a,m+1,ae,2*ti+2);
	return t[ti];
}
ll getSumUtil(ll* t,ll qs,ll qe,ll as,ll ae,ll ti)
{
	if(as>=qs&&ae<=qe)
		return t[ti];
	if(as>qe||ae<qs)
		return 0;
	ll m=as+(ae-as)/2;
	return getSumUtil(t,qs,qe,as,m,2*ti+1)+getSumUtil(t,qs,qe,m+1,ae,2*ti+2);
}
ll getSum(ll* t,ll qs,ll qe,ll n)
{
	if(qs>qe || qs<0 || qe>=n)
		return LONG_MIN;
	return getSumUtil(t,qs,qe,0,n-1,0);
}
void updateUtil(ll* t,ll as,ll ae,ll ai,ll d,ll ti)
{
	if(ai<as||ai>ae)
		return;
	t[ti]+=d;
	if(as!=ae)
	{
		ll m=as+(ae-as)/2;
		updateUtil(t,as,m,ai,d,2*ti+1);
		updateUtil(t,m+1,ae,ai,d,2*ti+2);
	}
}
void update(ll* t,ll* a,ll i,ll nv,ll n)
{
	if(i<0||i>=n)return;
	ll d=nv-a[i];
	a[i]=nv;
	updateUtil(t,0,n-1,i,d,0);
}
ll power(ll x,ll p)
{
	ll n=x;ll ans=1;
	while(p)
	{
		if(p&1)
			ans*=n;
		n*=n;
		p>>=1;
	}
	return ans;
}
ll v(ll x,ll s,ll p)
{
	ll y=power(x,s);
	ll z=power(x%p,s);
	ll a=y-z;
	ll ans=0;
	if(!a)
		return 0;
	while(a%p==0)
	{
		++ans;
		a/=p;
	}
	return ans;
}
ll a[100005],v1[100005],v2[100005],v3[100005],v4[100005];
ll t1[150000],t2[150000],t3[150000],t4[150000];
int main()
{
	ll tests,x,y,n,q,p,pos,val,s,l,r,i;
	cin>>tests;
	for(x=1;x<=tests;x++)
	{
		cin>>n>>q>>p;
		ll z=(ll)ceil(log2(n));
		for(i=0;i<n;i++)
		{
			cin>>a[i];
			v1[i]=v(a[i],1,p);
			v2[i]=v(a[i],2,p);
			v3[i]=v(a[i],3,p);
			v4[i]=v(a[i],4,p);
		}
		construct(t1,v1,0,n-1,0);
		construct(t2,v2,0,n-1,0);
		construct(t3,v3,0,n-1,0);
		construct(t4,v4,0,n-1,0);
		vector<ll> ans;
		for(i=0;i<q;i++)
		{
			cin>>y;
			if(y==1)
				cin>>pos>>val;
			else
				cin>>s>>l>>r;
			pos--;
			l--;r--;
			if(y==1)
			{
				update(t1,v1,pos,v(val,1,p),n);
				update(t2,v2,pos,v(val,2,p),n);
				update(t3,v3,pos,v(val,3,p),n);
				update(t4,v4,pos,v(val,4,p),n);
			}
			else
			{
				if(s==1)
					ans.push_back(getSum(t1,l,r,n));
				else if(s==2)
					ans.push_back(getSum(t2,l,r,n));
				else if(s==3)
					ans.push_back(getSum(t3,l,r,n));
				else
					ans.push_back(getSum(t4,l,r,n));
			}
		}
		cout<<"Case #"<<x<<": ";
		for(ll el:ans)
			cout<<el<<' ';
		cout<<'\n';
	}
	return 0;
}