/*************************************************************************
	> File Name: shiyansi.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年05月02日 星期二 13时10分06秒
 ************************************************************************/
#include"stdio.h"
#include"math.h"
#define N 5   

double X[N] = {0.4,0.55,0.8,0.9,1};							//函数表中x的值
double Y[N] = {0.41075,0.57815,0.88811,1.02652,1.17520};	//函数表中f(x)的值

double _X[N];		//原函数表x的值的备份
double _Y[N];		//原函数表y的值的备份

void Show_Function_Table();						//显示函数表函数
void Lagrange_Interpolation (double x);			//拉格朗日插值计算函数
void Newton_Interpolation(double x);			//牛顿插值计算函数

int main() {    
	printf("==============================实验4：插值问题==============================\n\n");
	printf("【函数表】\n");  

	//先显示函数表
	Show_Function_Table(); 
	
	printf("\n");    
	printf("【拉格朗日插值】：\n");  
	Lagrange_Interpolation (0.5);  
	Lagrange_Interpolation (0.7);  
	Lagrange_Interpolation (0.85); 

	printf("\n");

	printf("【牛顿插值】：\n"); 
	Newton_Interpolation(0.5);
	Newton_Interpolation(0.7);
	Newton_Interpolation(0.85);
        return 0;
}  

/*
*	显示函数表函数	
*/
void Show_Function_Table() {   
	int i;   
	printf("---------------------------------------------------------------------------\n");
	printf("  x    ");  
	for(i = 0;i < N;i++)    
		printf("   %0.2f    ",X[i]);  
	printf("\n---------------------------------------------------------------------------\n");
	printf("  f(x)  ");  
	for(i = 0;i < N;i++)    
		printf("%0.6f   ",Y[i]);  
	printf("\n---------------------------------------------------------------------------\n");
}  

/*
*	拉格朗日插值计算函数
*/
void Lagrange_Interpolation (double x) {   
	double p;				//累乘结果
	double y = 0;			//近似值
	int k,j;

	for(k = 0;k < N;k++)  {    
		p = 1;
		for(j = 0;j < N;j++)   {     
			if(j != k) {
				p = p * (x - X[j]) / (X[k] - X[j]);				//计算累乘结果
			}
		} 
		y = y + p * Y[k];				//计算拉格朗日插值    
	}    
	printf("当x=%.2f 时 :",x);  
	printf("      f(%.2f)=%f\n",x,y); 
} 

/*
*	牛顿插值计算函数
*/
void Newton_Interpolation(double x)  {    
	double t[N];
	double c;			//(x-x0)(x-x1)(x-x2)...(x-xn)
	double y1;			
	double y;			//近似值的最终值
	int i,k;  
	
	//把函数表的值取出来放到操作数组，保证函数表数组的值不受影响
	for(i = 0;i < N;i++)   {     
		_X[i] = X[i];    
		_Y[i] = Y[i];  
	}   
	y1 = _Y[0];			//先加上f(x0)的值
	y = 0;				//设为0，目标是存储近似值
	c = 1.0;    
	
	for(k = 1;k < N;k++)   {    
		for(i = k;i < N;i++) {
			t[i] = (_Y[i] - _Y[i-1]) / (_X[i] - _X[i-k]);			//计算差商
		}   	   
		c = c * (x - _X[k - 1]);   
		y1 = y1 +  t[k] * c;
		y = y1;    
		
		for(i = k;i < N;i++)    
			_Y[i] = t[i];											//覆盖前面的值，为了计算下一阶差商
	}   
	printf("当x=%.2f 时:",x);  
	printf("       f(%.2f)=%f\n",x,y); 
}  
