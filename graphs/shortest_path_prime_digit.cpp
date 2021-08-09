//given 2 4 digit primes, find shortest path from a to b
//such that at each step you change only one digit of the previous no
//and that number is also prime
#include<bits/stdc++.h>
using namespace std;
bool prime[10001];
void sieve(int n)
{
	int i,j;
	memset(prime,true,sizeof(prime));
	prime[0]=prime[1]=0;
	for(i=2;i*i<=n;i++)
	{
		if(prime[i])
		{
			for(j=i*i;j<=n;j+=i)
				prime[j]=false;
		}
	}
}
void findPrimes(vector<int>& v)
{
	sieve(10000);
	for(int i=1000;i<=9999;i++)
	{
		if(prime[i])
			v.push_back(i);
	}
}
bool compare(int a,int b)
{
	string p=to_string(a);
	string q=to_string(b);
	int c=0;
	for(int i=0;i<4;i++)
	{
		if(p[i]!=q[i])
			++c;
	}
	return (c==1);
}
int bfs(vector<int> adj[],int s,int d,int* visited,vector<int>& primes)
{
	if(s==d)
		return 0;
	queue<int> q;
	visited[s]=1;
	q.push(s);
	int ans=0;int u;
	while(!q.empty())
	{
		u=q.front();
		q.pop();
		for(int v:adj[u])
		{
			if(!visited[v])
			{
				visited[v]=visited[u]+1;
				q.push(v);
			}
			if(v==d)
				return visited[v]-1;
		}
	}
	return -1;
}
int main()
{
	int n1,n2;
	cin>>n1>>n2;
	vector<int> primes;
	findPrimes(primes);
	int n=primes.size();
	int i,j;
	vector<int> adj[n];
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(compare(primes[i],primes[j]))
			{
				adj[i].push_back(j);
				adj[j].push_back(i);
			}
		}
	}
	i=0,j=0;
	int k;
	for(k=0;k<primes.size();k++)
	{
		if(primes[k]==n1)
			i=k;
		if(primes[k]==n2)
			j=k;
	}
	int visited[n];
	for(k=0;k<n;k++)
		visited[k]=0;
	int ans=bfs(adj,i,j,visited,primes);
	cout<<ans<<'\n';
	return 0;
}