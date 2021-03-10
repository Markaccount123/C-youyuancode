#include<iostream>
using namespace std;

class Date;   // ǰ������ ��Ϊ��������class Date��ʱ���ǲ�֪����ʲô�ģ���ֻ����ǰȥ�ң������Ҳ������ͻᱨ��
//������ǰ��һ������������������ں�����
class Time 
{   
	friend class Date;   // ����������Ϊʱ�������Ԫ�࣬�����������о�ֱ�ӷ���Time���е�˽�г�Ա���� 
public:   
	//Time(int hour = 1, int minute = 1, int second = 1)
	Time(int hour, int minute, int second)       
		: _hour(hour)       
		, _minute(minute)       
		, _second(second)   
	{}  
private:   
	int _hour;   
	int _minute;   
	int _second; 
};

class Date 
{
public:  
	Date(int year = 1900, int month = 1, int day = 1, int hour = 0, int minute = 0, int second = 0)
		: _year(year)
		, _month(month)
		, _day(day)
		, _t(hour,minute,second) //����Ҳ���Բ�д����Ϊ���������Զ������Զ�������ͣ���������Զ������ͱ����ڶ����ʱ���ȱʡֵ
	{

	}
	void SetTimeOfDate(int hour, int minute, int second)  
	{   // ֱ�ӷ���ʱ����˽�еĳ�Ա����      
		_t._hour = hour;      
		_t._minute = minute;       
		_t._second = second;  
	}  
private:   
	int _year;
	int _month; 
	int _day;   
	Time _t;
};



class A 
{
private:    
	static int k;    
	int h; 
public:    
	class B   
	{
	public:        
		void foo(const A& a)        
		{
			cout << k << endl;//OK           
			cout << a.h << endl;//OK      
		}   
	}; 
};

int A::k = 1;
