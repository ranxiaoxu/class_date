#include<iostream>
#include<stdlib.h>
#include<assert.h>
using namespace std;
class Date
{
private:
	int _year;
	int _month;
	int _day;
public:
	Date(int year = 1990,int month = 1,int day = 1)
		:_year(year),
		_month(month),
		_day(day)
	{
		assert(year > 0);
		assert(month > 0 && month <13);
		assert(day > 0 && day <= GetRightDay() );
	}
	int GetRightDay()
	{
		int array[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
		int Rightday = array[_month-1];
		if((_year%400 == 0) || (_year%100 == 0 && _year%4 != 0)){
			if(_month == 2){
				Rightday = 29;
			}
		}
		return Rightday;
	}
	void print()
	{
		cout<<_year<<"-"<<_month<<"-"<<_day<<endl;
	}
	Date operator + (int time)
	{
		Date tmp = *this;
		if(time < 0)
		{
			tmp = tmp - (-time);
		}
		time += tmp._day;
		while(time > tmp.GetRightDay() ){
			time = time - tmp.GetRightDay();
			tmp._month += 1;
			if(tmp._month > 12){
				tmp._year += 1;
				tmp._month = 1;
			}
		}
		tmp._day = time;
		return tmp;
	}
	Date &operator += (int time)
	{
		*this = *this + time;
		return *this;
	}
	Date operator - (int time)
	{
		Date tmp = *this;
		time = tmp._day -time;
		while(time <= 0){
			tmp._month -= 1;	
			if(tmp._month == 0){
				tmp._year -= 1;
				tmp._month = 12;
			}
			time =  tmp.GetRightDay() + time;
		}
		tmp._day = time;
		return tmp;
	}
	Date &operator -= (int time)
	{
		*this = *this - time;
		return *this;
	}
	
	Date &operator ++ ()
	{
		*this = *this + 1;
		return *this;
	}
	Date operator ++ (int)
	{
		Date tmp = *this;
		*this = *this + 1;
		return tmp;
	}
	Date &operator -- ()
	{
		*this = *this - 1;
		return *this;
	}
	Date operator -- (int)
	{
		Date tmp = *this;
		*this = *this - 1;
		return tmp;
	}
	int operator - (const Date &d)
	{
		int ret = 0;
		Date tmp = d;
		while(1){
			if(_year == tmp._year && _month == tmp._month && _day == tmp._day){
				return ret;
		    }
			ret++;
		    ++tmp;
		}
	}
};
int main()
{
	menu();
	system("pause");
	return 0;
}