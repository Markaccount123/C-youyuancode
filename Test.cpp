#include<iostream>
using namespace std;

class Date;   // 前置声明 因为当他遇见class Date的时候是不知道是什么的，他只能往前去找，但又找不到，就会报错，
//所以提前给一个声明告诉他这个类在后面有
class Time 
{   
	friend class Date;   // 声明日期类为时间类的友元类，则在日期类中就直接访问Time类中的私有成员变量 
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
		, _t(hour,minute,second) //这里也可以不写，因为编译器会自动调用自定义的类型，但是你的自定义类型必须在定义的时候给缺省值
	{

	}
	void SetTimeOfDate(int hour, int minute, int second)  
	{   // 直接访问时间类私有的成员变量      
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
