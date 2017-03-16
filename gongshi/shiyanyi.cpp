/*************************************************************************
	> File Name: shiyanyi.cpp
	> Author: Weizhe_Chen 
	> Mail: 
	> Created Time: 2017年03月15日 星期三 19时11分41秒
 ************************************************************************/

#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
double esp = 0.0005;

double f(double x){
   return exp(x)+10*x-2;
}

double diedaigongshi(double x){
    return  (2-exp(x))/10; 
}

double daoshugongshi(double x){
    return exp(x)+10;
}

/*
 *迭代法
 */
void diedaiOper(double x){
    int count = 0;
    double x1 = 0;
    do{
       x = x1;
       x1 = diedaigongshi(x);
       count++;
       cout<<"第"<<count<<"次计算结果为："<<x1<<endl;
    }while(fabs(x - x1)>esp); 
}

/**************二分法***************/
void erfenfa(double a,double b){
    double x;
    int count = 0;
    if(f(a)*f(b)>0){
        cout<<"在此区间内方程无根！！"<<endl;
    }
    while(fabs(b-a)>esp){
        x = (a+b)/2;
        if(f(x) == 0){
            cout<<"该方程的根为："<<x<<endl;
        }else {
            if(f(a)*f(x)<0){
               b = x;
            }else{
                a=x;
            }
        count++;
        cout<<"第"<<count<<"次运行的结果为："<<x<<endl;
    }
}
}


/**********牛顿法*********************/
void niudun(double x){
    int count=0;
    double x1 = x;
    do{
    
    x = x1;        
    double a = daoshugongshi(x);
    if(a == 0){
        cout<<"迭代终止"<<endl;
   
   }else{
        x1 = x - (f(x)/a);
        count++;
        cout<<"第"<<count<<"次计算结果为："<<x1<<endl;
      }
    }while(fabs(x - x1)>esp);
}


int main(){
    cout<<"牛顿法："<<endl;
    niudun(0);
    cout<<"----------------------";
    cout<<"二分法："<<endl;
    erfenfa(0,1.0);
    cout<<"----------------------";
    cout<<"迭代法："<<endl;
    diedaiOper(0);
    return 0;
}

