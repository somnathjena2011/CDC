#include<bits/stdc++.h>
using namespace std;
class MinStack{
public:
	stack<int> s;
	int mini;
	MinStack(){
		mini=-1;
	}
	void push(int x)
	{
		if(s.empty())
		{
			s.push(x);
			mini=x;
		}
		else
		{
			if(x>=mini)
				s.push(x);
			else
			{
				s.push(x+(x-mini));
				mini=x;
			}
		}
	}
	void pop()
	{
		if(s.empty())
			return;
		if(s.top()<mini)
		{
			mini=mini+(mini-s.top());
			s.pop();
		}
		else
			s.pop();
	}
	int top()
	{
		if(s.empty())
			return -1;
		if(s.top()>=mini)
			return s.top();
		else
			return mini;
	}
	int getMin()
	{
		if(s.empty())
			return -1;
		return mini;
	}
};
int main()
{
	MinStack* s=new MinStack();
	int n,t,i,x;
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>t;
		switch(t)
		{
			case 0:
			cin>>x;
			s->push(x);
			break;
			case 1:
			s->pop();
			break;
			case 2:
			cout<<s->top()<<'\n';
			break;
			case 3:
			cout<<s->getMin()<<'\n';
			break;
		}
	}
	return 0;
}