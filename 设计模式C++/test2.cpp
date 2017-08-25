#include "stdio.h"
class Interface
{
	public:
		Interface(){}
		~Interface(){}
		virtual void Function()=0;
};
class DoInterface1:public Interface
{
	public:
		DoInterface1()
		{
			
		}
		~DoInterface1()
		{
			
		}
		void Function()
		{
			printf("Do Function1 \n");
		}
};
class DoInterface2:public Interface
{
	public:
		DoInterface2()
		{
			
		}
		~DoInterface2()
		{
			
		}
		void Function()
		{
			printf("Do Function2 \n");
		}
};
class Factory
{
	public:
		Factory(){}
		~Factory(){}
	virtual Interface *Function()=0;
};
class DoFactory1:public Factory
{
	public:
		DoFactory1(){}
		~DoFactory1(){}
		 Interface *Function()
		{
			return new DoInterface1;
		}
};
int main(int argc,char **agrv)
{
  	printf("工厂模式 \n");
	Factory * p1=new DoFactory1();
    Interface *p2 = p1->Function();
	p2->Function();
	delete p2;
	delete p1;
	return 0;
}
