#include<bits/stdc++.h>
using namespace std;
void print(vector<vector<int>>& bracket,int i,int j,char name)
{
	if(i==j)
	{
		cout<<name;
		return;
	}
	cout<<'(';
	print(bracket,i,bracket[i][j],name);
	print(bracket,bracket[i][j]+1,j,name+bracket[i][j]-i+1);
	cout<<')';
}
int main()
{
	int n,i,j,k,l;
	cin>>n;//no of matrices
	//dimension of ith matrix is dim[i-1]*dim[i]
	int dim[n+1];
	for(i=0;i<=n;i++)
		cin>>dim[i];
	//min no of multiplications to multiply mati..matj
	vector<vector<int>> dp(n+1,vector<int>(n+1,0));
	//ith matrix after which optimal bracket
	vector<vector<int>> bracket(n+1,vector<int>(n+1,0));
	for(i=1;i<n;i++)
	{
		dp[i][i+1]=dim[i-1]*dim[i]*dim[i+1];
		bracket[i][i+1]=i;
		bracket[i][i]=i;
	}
	bracket[n][n]=n;
	int x,y,z,s,p;
	for(k=2;k<n;k++)
	{
		for(i=1;i<=n-k;i++)
		{
			j=i+k;
			dp[i][j]=INT_MAX;
			for(l=i;l<j;l++)
			{
				x=dim[i-1];
				y=dim[l];
				z=dim[j];
				if(dp[i][l]+dp[l+1][j]+x*y*z<dp[i][j])
				{
					dp[i][j]=dp[i][l]+dp[l+1][j]+x*y*z;
					bracket[i][j]=l;
				}
			}
		}
	}
	cout<<"Min multiplications="<<dp[1][n]<<'\n';
	print(bracket,1,n,'A');
	cout<<'\n';
	return 0;
}