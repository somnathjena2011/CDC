#include<iostream>
using std::cout;

namespace ns1{
	int age = 25;
	std::string name="Jeko";
}
namespace ns2{
	int age = 26;
}
namespace ns2{
	class Country{
	public:
		void display(std::string name)
		{
			std::cout<<name<<'\n';
		}
	};
}
namespace {
	int unique = 300;
}
namespace ns3 {
	int unique = 350;
}
void printUnique()
{
	cout<<unique<<'\n';
}

static int st=69;

int main()
{
	cout<<ns2::age<<'\n';
	cout<<ns1::name<<'\n';
	ns2::Country* country = new ns2::Country();
	country->display("India");
	ns2::age=30;
	cout<<ns2::age<<'\n';
	cout<<unique<<'\n';
	unique=70;
	cout<<unique<<'\n';
	int unique=21;
	cout<<unique<<'\n';
	printUnique();
	cout<<ns3::unique<<'\n';
	int age=35;
	cout<<age<<'\n';
	cout<<st<<'\n';
	st=79;
	cout<<st<<'\n';
	return 0;
}