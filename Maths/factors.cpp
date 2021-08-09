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
vector<int> allFactors(int A) {
    vector<int> small,large;
    int i;
    for(i=1;i*i<=A;i++)
    {
        if(A%i==0)
        {
            if(i*i==A)
            small.push_back(i);
            else
            {
                small.push_back(i);
                large.push_back(A/i);
            }
        }
    }
    for(auto it=large.rbegin();it!=large.rend();it++)
    small.push_back(*it);
    return small; 
}
int main()
{
	int n;
	cin>>n;
	vector<int> ans=allFactors(n);
	for(auto f:ans)
		cout<<f<<' ';
	cout<<'\n';
	return 0;
}