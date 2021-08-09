#include<bits/stdc++.h>
using namespace std;
auto f    =[](int i)->int {return i+3;};
auto sqr  =[](int i)->int {return i*i;};
auto twice=[](const function<int(int)>& f,int v){return f(f(v));};
auto comp =[](const function<int(int)>& f,const function<int(int)>& g,int v)
			{return f(g(v));}; 

int main()
{
	auto a=7,b=5,c=3;
	cout<<twice(f,a)<<' '<<comp(f,f,a)<<'\n';
	cout<<twice(sqr,b)<<' '<<comp(sqr,sqr,b)<<'\n';
	cout<<comp(sqr,f,c)<<' '<<comp(f,sqr,c)<<'\n';
	return 0;
}