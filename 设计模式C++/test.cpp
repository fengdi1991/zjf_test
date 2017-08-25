
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
class Context
{
	public:
		Context(Interface * Pstr)
		{this -> p_Interface = Pstr;}
		~Context(void)
		{delete this -> p_Interface;}
		void Function()
		{this->p_Interface->Function();}
	private:
		Interface *p_Interface;
};
int main(int agrc,char **agrv)
{
    printf("策略模式 \n");
    Context * pContext;
	pContext = new Context(new DoInterface1());
	pContext -> Function();
	delete pContext;
	pContext = new Context(new DoInterface2());
	pContext -> Function();
	delete pContext;
	printf("结束 \n");
	return 0;
}
