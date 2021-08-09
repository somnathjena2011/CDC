#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
	ll t,n,m,p,i,j,k,x;
	cin>>t;
	string s1,s2,s3;
	ll len,mini,minInd,minLen,minj;
	ll sum;
	ll ans=0;
	for(x=1;x<=t;x++)
	{
		cin>>n>>m>>p;
		string pref[n];
		set<string> forb;
		for(i=0;i<n;i++)
			cin>>pref[i];
		for(i=0;i<m;i++)
		{
			cin>>s1;
			forb.insert(s1);
		}
		ll ones[p]={0};
		ll zeros[p]={0};
		for(i=0;i<n;i++)
		{
			for(j=0;j<p;j++)
			{
				if(pref[i][j]=='1')
					++ones[j];
				else
					++zeros[j];
			}
		}
		pair<int,int> majo[p],mino[p];
		for(i=0;i<p;i++)
		{
			if(ones[i]>=zeros[i])
			{
				majo[i]={ones[i],1};
				mino[i]={zeros[i],0};
			}
			else
			{
				majo[i]={zeros[i],0};
				mino[i]={ones[i],1};
			}
		}
		s2="";ans=0;
		for(i=0;i<p;i++)
		{
			if(majo[i].second==1)
				s2.push_back('1');
			else
				s2.push_back('0');
			ans+=mino[i].first;
		}
		if(forb.find(s2)==forb.end())
			cout<<"Case #"<<x<<": "<<ans<<'\n';
		else
		{
			vector<set<pair<ll,ll>>> sets;
			pair<ll,ll> pen[p];
			for(i=0;i<p;i++)
				pen[i]={majo[i].first-mino[i].first,i};
			sort(pen,pen+p);
			ll seti[p]={0};
			vector<ll> sumi;
			sets.push_back(set<pair<ll,ll>>());
			sumi.push_back(0);
			i=1; len=1;
			vector<char> str(p);
			while(1)
			{
				mini=LONG_MAX;minInd=-1;minLen=LONG_MAX;minj=0;
				for(j=0;j<p;j++)
				{
					//cout<<"j="<<j<<" seti[j]="<<seti[j]<<" sum of seti[j]="<<sumi[seti[j]]<<" penalty="<<pen[j].first<<" real j="<<pen[j].second<<" mini="<<mini<<'\n';
					if(seti[j]>=0&&sumi[seti[j]]+pen[j].first<mini)
					{
						mini=sumi[seti[j]]+pen[j].first;
						minInd=seti[j];
						minLen=sets[seti[j]].size()+1;
						minj=j;
					}
					else if(seti[j]>=0&&sumi[seti[j]]+pen[j].first==mini&&sets[seti[j]].size()+1<minLen)
					{
						mini=sumi[seti[j]]+pen[j].first;
						minInd=seti[j];
						minLen=sets[seti[j]].size()+1;
						minj=j;
					}
				}
				//cout<<"minj="<<minj<<" minInd="<<minInd<<'\n';
				set<pair<ll,ll>> st;sum=0;
				for(auto pr:sets[minInd])
				{
					sum+=pr.first;
					st.insert(pr);
				}
				st.insert(pen[minj]);
				sum+=pen[minj].first;
				sets.push_back(st);
				sumi.push_back(sum);
				for(k=seti[minj]+1;k<sets.size();k++)
				{
					auto it=sets[k].rbegin();
					if(it->first>pen[minj].first)
						k++;
					else if(it->first<pen[minj].first)
					{
						seti[minj]=k;
						break;
					}
					else
					{
						if(it->second<pen[minj].second)
						{
							seti[minj]=k;
							break;
						}
						else
							k++;
					}
				}
				if(k==sets.size())
					seti[minj]=-1;
				for(j=0;j<p;j++)
				{
					str[j]=majo[j].second+'0';
				}
				for(auto pr:st)
				{
					str[pr.second]=mino[pr.second].second+'0';
				}
				s3="";
				for(j=0;j<p;j++)
					s3.push_back(str[j]);
				if(forb.find(s3)==forb.end())
				{
					ans=ans+sum;
					cout<<"Case #"<<x<<": "<<ans<<'\n';
					break;
				}
			}
		}
	}
	return 0;
}