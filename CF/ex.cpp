#include<bits/stdc++.h>
using namespace std;
int ex()
{
    int a=2;
    int b=3;
    return [](int a,int b){return a>b?a:b;}(a,b);
}
int main()
{
    int c=ex();
    return 0;
}