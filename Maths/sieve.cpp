#include<bits/stdc++.h>
using namespace std;
//O(nlog(logn))
vector<int> sieve(int A) {
    int prime[A+1];
    int i,j;
    for(i=0;i<=A;i++)
    prime[i]=1;
    prime[0]=prime[1]=0;
    for(i=2;i*i<=A;i++)
    {
        if(prime[i])
        {
            for(j=2;j*i<=A;j++)
            prime[j*i]=0;
        }
    }
    vector<int> primes;
    for(i=0;i<=A;i++)
    {
        if(prime[i])
        primes.push_back(i);
    }
    return primes;
}
int main()
{
	int n;
	cin>>n;
	vector<int> primes=sieve(n);
	for(auto p:primes)
		cout<<p<<' ';
	cout<<'\n';
	return 0;
}