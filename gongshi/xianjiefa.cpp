/*************************************************************************
	> File Name: xianjiefa.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年03月14日 星期二 16时18分30秒
 ************************************************************************/

#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
double f(double);                                             //函数声明
double xpoint(double,double);                                 //函数声明
double root(double,double);                                   //函数声明

int main( )
{
    double x1,x2,f1,f2,x;
    do
    { cout<< "input x1,x2:";
    cin >> x1 >> x2;
    f1=f(x1);
    f2=f(x2);
    } while(f1*f2 >= 0);
    x = root(x1,x2);
    cout << setiosflags(ios::fixed) << setprecision(6);       //指定输出7位小数
    cout << "A root of equation is " << x << endl;
    return 0;
}


double f(double x)                                       //定义f函数
{ double y;
y = x * x *x + 2*x*x + 10 * x -20;
return y;
}

double xpoint(double x1,double x2)                       //定义spoint 函数,求出弦与 x 轴的交点
{ double y;
y = ( x1 * f(x2) - x2 * f(x1))/(f(x2) - f(x1));          //在 xpoint 函数中调用 f 函数
return y;
}

double root(double x1,double x2)                         //定义 root 函数，求近似根
{
    double x,y,y1;
    y1 = f(x1);
    do
    { x = xpoint(x1,x2);                               //在 root 函数中调用 xpoint 函数
      cout<<setprecision(10)<<x<<endl;
       y = f(x);                                            //在 root 函数中调用 f 函数
    if(y*y1 > 0)
    { y1 = y;
    x1 = x;
    }
    else
        x2 = x;
    }while(fabs(y)>= 0.000001);
    return x;
}

