#include<bits/stdc++.h>
using namespace std;
int xor1ton(int n)
{
	if(n%4==0)
		return n;
	else if(n%4==1)
		return 1;
	else if(n%4==2)
		return n+1;
	else
		return 0;
}
int check2power(int x)
{
	//first x is for 0
	//x & x-1 clears lowest 1bit, so if any 1 remains,
	//it will return 0
	return x&&(!(x&(x-1)));
}
int findXorSubsets(vector<int>& v)
{
	if(v.size()==1)
		return v[0];
	else
		return 0;
}
void swap(int* a,int* b)
{
	*a = *a ^ *b;//a^b
	*b = *a ^ *b;//(a^b)^b=a
	*a = *a ^ *b;//(a^b)^a=b
}
int flip(int n)
{
	int p=0;
	//find highest 1 bit
	for(int i=0;i<31;i++)
	{
		if(n&(1<<i))
			p=i;
	}
	int ans=((1<<(p+1))-1)-n;
	return ans;
}
int main()
{
	cout<<flip(23)<<'\n';
	int a=23;
	int b=77;
	swap(&a,&b);
	cout<<a<<' '<<b<<'\n';
	return 0;
}