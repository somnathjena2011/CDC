/*
100 diff types of caps numbered from 1 to 100
n persons each having a collection of a variable number of caps
One day all persons decide to go in a party wearing a cap
but to look unique they decided that none of them
will wear the same type of cap
Count total no of ways such that none of them is wearing
the same type of cap
1<=n<=10

BITMASKING:
->Suppose we have a collection of elements numbered 0 to N-1.
  if we want to represent a subset of this set
  we can encode it in a sequence of N bits(MASK)
->ith element belongs to the subset iff MASK[i]=1
  i.e. ith bit of the MASk is 1
->100000101 means subset consists of {0,2,8} elements
->For a set 2^N subsets are possible, hence 2^N masks possible

->Our main method is to assign a value to each mask(i.e. each subset)
  and caluclate values of new masks using precomputed mask values
->Usually target is the value of mask in which all bits are 1
  (i.e. subset consisting of all elements)
->To find value of subset X, we remove one element from X
  in all possible ways, add value corresponding to it to value
  of reduced subset X'
->Common operations/notations on masks:
  bit(i,mask)=> ith bit of mask = mask & (1<<i)
  count(mask)=> no of non-zero bits in mask
                int ans=0;
                while(mask>0)
                {
                	//N&(N-1) clears lowest 1 bit in N
                	//so while loop runs for the no of 1 bits in N times
					mask=mask&(mask-1);
					++ans;
                } 
  first(mask)=> lowest non-zero bit in mask
                to extract the number only with the lowest bit set
                do x& ~(x-1)
  set(i,mask)=> set the ith bit in mask=> mask= mask | (1<<i)
  check(i,mask)=>check the ith bit in the mask

SOLUTION TO THE PROBLEM:
-><=10 persons(say N persons)
  C caps
  Let i denote that we are considering caps from i to C
  Let mask indicate which persons are currently being considered
  count(i,mask) = count(i+1,mask) [the case when this cap 
  								  is not assigned to any person]
  	            + count(i+1,mask^(1<<j)) for all j such that jth bit 
  	                              is set in mask and ith cap
  	                              is in person j's list
  DP=> O(caps*N*2^N)
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
ll count(vector<vector<ll>>& dp,vector<ll> capsList[],ll cap,ll mask,ll caps,ll persons)
{
	//no persons left to assign a cap
	if(mask==0)
		return 1;
	//persons left to assign a cap, and all caps considered
	if(cap>caps)
		return 0;
	//if value has been precomputed return it
	if(dp[cap][mask]!=-1)
		return dp[cap][mask];
	//do not assign this cap to anyone
	ll ans=count(dp,capsList,cap+1,mask,caps,persons);
	ll i=0,j;
	//assign this cap to all persons whose bit in mask is 1
	//and capsList of cap contains it
	for(i=0;i<capsList[cap].size();i++)
	{
		j=capsList[cap][i];
		if((mask&(1ll<<j)))
			ans=(ans+count(dp,capsList,cap+1,mask^(1ll<<j),caps,persons))%mod;
	}
	return dp[cap][mask]=ans;
}
int main()
{
	ll n,m,i,j,c;
	cin>>n;
	vector<ll> capsList[101];
	for(i=0;i<n;i++)
	{
		cin>>m;
		for(j=0;j<m;j++)
		{
			cin>>c;
			capsList[c].push_back(i);
		}
	}
	vector<vector<ll>> dp(101,vector<ll>((1<<n),-1));
	ll ans=count(dp,capsList,1,((1<<n)-1),100,n);
	cout<<ans<<'\n';
}