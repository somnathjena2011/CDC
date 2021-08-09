#include<bits/stdc++.h>
using namespace std;
int main()
{
	#define INDIA true
	#ifdef INDIA
		cout<<"India\n";
	#endif
	#ifndef PAKISTAN
		cout<<"Pakistan\n";
	#endif
	#define PAKISTAN false
	#ifdef PAKISTAN
		#undef PAKISTAN
		cout<<"Pakistan2\n";
	#endif
	#ifndef PAKISTAN
		cout<<"Pakistan3\n";
	#endif
	#define gfg 7
	#if gfg > 200
		#undef gfg
		#define gfg 200
	#elif gfg < 50
		#undef gfg
		#define gfg 50
	#else
		#undef gfg
		#define gfg 100
	#endif
	cout<<gfg<<'\n';
	return 0;
}