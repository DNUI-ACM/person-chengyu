# person-chengyu
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stddef.h>
struct	Vector{
	int* m_base;
	int  m_len;
	int  m_capacity;
};
typedef struct Vector vector;
typedef int Type;
void InitVector(vector* v){
	v->m_base=NULL;
	v->m_len=0;
	v->m_capacity=0;
}//初始化
void  destroyVector(vector * v){
	if(v->m_base!=NULL){
		free(v->m_base);	
	}
}//销毁
void   pushBackVector(vector* v,Type value){
	if(v->m_len<v->m_capacity){
		v->m_base[v->m_len]=value;
		v->m_len++; 
	}else {
		if(v->m_base==NULL){
			v->m_base=(Type*)malloc(sizeof(Type));
			if(v->m_base=NULL){
				printf("Error\n");
				return ;
			}
			v->m_capacity=1;
		}
		else{
			Type* new_base=(Type*)malloc(sizeof(Type)*v->m_capacity*2);
			if(new_base=NULL){
				printf("Error\n");
				return ;
			}
			memcpy(new_base,v->m_base,sizeof(Type)*(v->m_capacity));
			free(v->m_base);
			v->m_base=new_base;
			v->m_capacity*=2;
		}
		v->m_base[v->m_len]=value;
		v->m_len++;
	}
}//从数组后插入元素 
void popBackVector(vector* v){
		if(v->m_base=NULL){
			printf("Error\n");
			return ;
		}
		if(v->m_len==1){
			v->m_base=NULL;
			v->m_len=0;
			v->m_capacity=0;
		}else if(v->m_len-1==v->m_capacity/2){
			Type* new_base=(Type*)malloc(sizeof(Type)*v->m_len);
			if(new_base=NULL){
				printf("Error\n");
				return ;
			}
			memcpy(new_base,v->m_base,v->m_len);
			free(v->m_base);
			v->m_base=new_base;
			v->m_len--;
			v->m_capacity=v->m_len;	
		}
		else{
			v->m_len--;
		}		
	}//从数组后拿出元素 
	Type * getPos(vector * v , Type pos){
	if(pos >= v -> m_len){
		return NULL;
	}
	return v -> m_base + pos;
	}//数组位置的值 
	Type sizeVector(vector * v){
	return v -> m_len;
	}
	Type capacityVector(vector * v){
	return v -> m_capacity;
	}
/******************************************************/
