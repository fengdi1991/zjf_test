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
			printf("送花 \n");
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
			printf("送巧克力 \n");
		}
};
class Proxy:public Interface
{
	public:
		Proxy(Interface *Pstr){this->pInterface=Pstr;}
		~Proxy(){delete pInterface;}
		void Function(){this->pInterface->Function();}
	private:
		Interface *pInterface;
		
};

int main(int argc,char** argv)
{
	printf("代理模式\n");
	Proxy * CProxy=new Proxy(new DoInterface1());
    CProxy->Function();
	delete CProxy;
	return 0;
}

