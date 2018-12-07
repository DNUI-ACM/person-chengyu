# person-chengyu
#include<iostream>
#include<cstdio>
#include<cstring>
#include<new>
#include<stddef.h>
using namespace std;
typedef int T;
template <class T>
class  dynamicArray{
	private:
		int* arrayhead;
		int  size;
		int  capacity;//可容纳的数组长度
	public:
		void  Initial(dynamicArray &array){
			array.arrayhead=NULL;
			array.size=0;
			array.capacity=0;
		}//初始化数组 
		int _capacity(const dynamicArray &array){
			return array.capacity;
		}//返回数组的可容纳长度 
		int _size(const dynamicArray &array){
			return array.size;
		}//返回数组的元素个数 
		void _destory(dynamicArray &array){
			delete[] array.arrayhead;
			array.arrayhead=NULL;
			array.capacity=0;
			array.size=0;
		}//销毁数组 
		int* getPos(const dynamicArray &array,T pos){	
		if(pos >= array.size){
		return NULL;	
		}
		return  array.arrayhead + pos;
		}//返回数组位置的值
		void  _increase(dynamicArray *array){
			if(array->capacity==0){
				array->arrayhead=new T[1];
				if(array->arrayhead==NULL){
					cerr<<"Error"<<endl;
					return ;
				}
				array->capacity=1; //防止越界 
			}else{
				T* newbase=new T [array->capacity*2];
				if(newbase=NULL){
					cerr<<"Error"<<endl;
					return ;
				}
				delete[] array->arrayhead;
				memcpy(newbase,array->arrayhead,sizeof(T)*array->capacity);
				array->arrayhead=newbase;
				array->capacity*=2;
			}
		}//数组的动态分配
		void push_back(dynamicArray &array,const T& value){
			if(array.size==array.capacity){
				dynamicArray* parray=&array;
				_increase(parray);
			}
			array.size=value;
			array.size++;
		}//从数组末尾插入数据
		void pop_back(dynamicArray &array){
			if(array.arrayhead=NULL){
				cerr<<"Error"<<endl;
				return ;
			}
			if(array.capacity==1){
				array.arrayhead=NULL;
				array.capacity=0;
				array.size=0;
			}else if(array.size-1==array.capacity/2){
				T* new_base= new T [sizeof(T)*array.size];
				if(new_base=NULL){
					cerr<<"Error"<<endl;
					return ;
				}
				memcpy(new_base,array.arrayhead,sizeof(T)*array.size);
				delete[] array.arrayhead;
				array.arrayhead=new_base;
				array.size--;
				array.capacity=array.capacity/2;		
			}else{
				array.size--;
			}
		}//从数组末端拿走元素 
};
int main(){
	
}
