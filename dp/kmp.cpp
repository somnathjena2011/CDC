/*
T=text, P=pattern
prefix function
pre[i]=longest prefix of 0toi-1 which is also a 
suffix of 1 to i
TIME COMPLEXITY=>O(n)
*/
#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<climits>
#include<stdio.h>
#include<queue>
#include<list>
#include<stack>
#include<random>
#include<chrono>
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using namespace std;
#define COL 31
#define ROW 31
#define ll long long int
#define ull unsigned long long int
#define mp make_pair
#define pb push_back
#define mem memset
#define inf 1e18
#define mod 1000000007
#define ff first
#define ss second
int main()
{
	int n,m,i,j,k,q;
	string S,P;
	cin>>n>>m;
	cin>>S;
	cin>>P;
	int pre[m];
	pre[0]=0;
	k=0;
	for(i=1;i<m;i++)
	{
		while(k>0&&P[k]!=P[i])
			k=pre[k-1];
		if(P[k]==P[i])
			k++;
		pre[i]=k;
	}
	k=0;
	for(i=0;i<n;i++)
	{
		while(k>0&&P[k]!=S[i])
			k=pre[k-1];
		if(P[k]==S[i])
			k++;
		if(k==m)
		{
			cout<<S.substr(i-m+1,m)<<" at "<<i-m+1<<'\n';
			k=pre[k-1];
		}
	}
	return 0;
}