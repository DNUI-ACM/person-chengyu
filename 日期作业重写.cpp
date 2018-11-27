#include<cstdio>
#include<string.h>
#include<cmath>
#include<iostream>
#include<stdlib.h>
using namespace std;
class Date{
	public:
		Date(int year,int month,int day){
			if(year>=1980&&month>0&&month<13&&day<=GetmonthDay(year,month)){
				_year=year;
				_month=month;
				_day=day;
			}
			else{
				cout<<"日期非法"<<endl;
				_year=1980;
				_month=1;
				_day=1; 
			}
		}
		Date(const Date& d) //拷贝构造
       {
          _year = d._year;
          _month = d._month;
          _day = d._day;
       }
      void Display()       // 打印日期
      {
          cout << _year << "-" << _month << "-" << _day << endl;
      }
     ~Date()     //析构函数
      {
          //cout << "~Date()" << endl;
      }
      private: 
		bool IsLeapYear(int year){
			if(year%400==0||year%100!=0&&year%4==0)
				return true;
			else
				return false;	
		}
		int GetmonthDay(int year,int month){
			int montharr[13]={0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
			if(month==2&&IsLeapYear(year))
			montharr[2]=29;
			int day=montharr[month];
			return day;	
		}//判断日期的合法性	
		bool Dayisperiod(int year,int month,int day){
			if(year>2005&&year<2008)
				return true;
			else if(year==2005){
				if(month==1&&day>20)
					return true;
				else 
					return false;	
			}
			else if(year=2008){
				if(month==1&&day<20)
					return true;
				else 
					return false;	
			}	
		}
		public:
			Date operator + (int day){
				Date tmp=*this;
				int sumdays= tmp._day+day;
				while(sumdays>GetmonthDay(tmp._year,tmp._month)){
					sumdays-=GetmonthDay(tmp._year,tmp._month);
					tmp._month++;
					if(tmp._month>12){
						tmp._year++;
						tmp._month%=12;
					}
					else{
						tmp._year=sumdays;
					}
				}
				return tmp;	
			} 
			Date operator+=(int day){
				*this=operator+(day);
				return *this;
			}//
			Date operator - (int day){
        		 Date tmp = *this;
         	while (day >= tmp._day)
            {
            	day -= tmp._day;
        	if (tmp._month == 1)
             	{
                	tmp._year--;
                	tmp._month = 12;
             	}
             else
             	{
                	tmp._month--;
             	}
            tmp._day = GetmonthDay(tmp._year, tmp._month);
         	}
        	tmp._day -= day;
         	return tmp;
			}
			Date operator -=(int day){
				*this=operator-(day);
				return *this;
			}
	 private:
        int _year;
        int _month;
        int _day;
};
int main(){
	
}
