#include "stdio.h"
class Observer//观察者接口
{
	public:
		Observer(){}
		~Observer(){}
		virtual void Updata()=0;//更新被观察者上送的信息
};
class  Observed //被观察者接口
{
	public:
		Observed(){}
		~Observed(){}
		virtual void Add(Observer *str)=0;//增加观察者接口
		virtual void Remove(Observer *str)=0;//移除观察者接口
		virtual void Notify(Observer *str)=0;//通知观察者 Observer *
};
class QianTai : public Observed//前台作为被观察者
{
	public:
		QianTai(){}
		~QianTai(){}
        void Add(Observer *str)
		{
			//将观察者加入到链表中
			count++;
			printf("将观察者加入到链表中 ");
			printf("count= %d \n",count);
		}
		void Remove(Observer *str)
		{
			//将观察者从链表中移除
			count--;
			printf("将观察者从链表中移除 \n");
			printf("count= %d \n",count);
		}
		void Notify(Observer *str)
		{
			for(int i=0 ;i<count;i++)
			{
            printf("目标出现，报告上级 \n");
            str->Updata();
			//将消息通知链表中的所有成员
			}
		}
		void Observed_Event(int stare)
		{
			m_stare = stare;
		}
	private:
		//1.观察者链表
        Observer *pObserver;
		int m_stare;
		int count;
};

class Staff1:public Observer //员工1 观察者
{
	public:
		Staff1(Observed *pStr){this->pObserved = pStr;}
		~Staff1(){delete pObserved;}
		void Updata()
		{
			printf("被发现的，开溜 \n");
		}
	private:
		Observed * pObserved;
};
class Staff2:public Observer
{
	public:
		Staff2(Observed *pStr){this->pObserved = pStr;}
		~Staff2(){delete pObserved;}
		void Updata()
		{
			printf("被发现的，开溜 \n");
		}
	private:
		Observed * pObserved;
};
int main(int argc,char** argv)
{
	printf("观察者模式 \n");
	Observed *p1= new QianTai();//创建被观察者
		
	
    Observer *N1= new Staff1(p1);//创建观察者
    Observer *N2= new Staff2(p1);
	Observer *N3= new Staff2(p1);

	p1->Add(N1);
	p1->Add(N2);
	p1->Add(N3);
	p1->Notify(N1);
	p1->Remove(N1);
	p1->Remove(N2);	
	p1->Notify(N1);
	delete N2;
	delete N1;
	delete p1;
	return 0;
}
