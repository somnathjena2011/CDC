#include<dlfcn.h>
int main()
{
	void* handle=dlopen("hello.so",RTLD_LAZY);
	typedef void (*hello_t)();
	hello_t myHello = 0;
	myHello = (hello_t)dlsym(handle,"hello");
	myHello();
	dlclose(handle);
	return 0;
}