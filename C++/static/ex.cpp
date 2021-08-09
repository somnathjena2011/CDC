#include <iostream>
class Test
{
public:
    void fun();
};
static void Test::fun()   
{
    std::cout<<"fun() is staticn";
}
int main()
{
    Test::fun();   
    return 0;
}