/*************************************************************************
	> File Name: shiyansan.cpp
	> Author: chenweizhe
	> Mail: 
	> Created Time: 2017年04月16日 星期日 19时08分40秒
 ************************************************************************/

#include <math.h>
#include <stdio.h>

void yakebi()
{
 double A[6][6] = {{4,-1,0,-1,0,0},
{-1,4,-1,0,-1,0},
{0,-1,4,-1,0,-1},
{-1,0,-1,4,-1,0},
{0,-1,0,-1,4,-1},
{0,0,-1,0,-1,4}};
 double b[6] = {0,5,-2,5,-2,6};;
 double x[6] = {0}; //第k+1次迭代的结果
 double xx[6] = {0}; //第k次迭代的结果
 int size = 6;
 int Max = 100;  //最大迭代次数
 double residual = 0.0;  //
 double sum = 0.0; 
 double dis = 0.0;
 double dif = 1.0;  //相邻迭代的结果差
 double eps = 1.0e-4; //迭代精度

 for(int k=1;(k<Max)&&(dif>eps);k++)
 {
  dif = 0.0;
  printf("\n第%d次迭代的结果：\n",k);
 
  for(int i=0;i<size;i++)
  {
   for(int j=0;j<size;j++)
   {
    if(i!=j)
    {
     sum +=A[i][j]*xx[j];
    }

   }
   x[i] = (b[i]-sum)/A[i][i];
   sum = 0.0; 

  } 
  residual=0.0;
  //计算相邻迭代的结果差
  for(int m=0;m<size;m++)
  {
   dis=fabs(x[m]-xx[m]);
   if(dis>residual)
    residual=dis;
  }
  dif=residual;
  //打印第k次的结果
  for(int i=0;i<size;i++)
  {
   printf("%12.8f ",x[i]);
   xx[i]=x[i];
  }
  printf("\n与上次计算结果的距离(2范数):%12.8f \n",dif);

 }
  printf("\n迭代计算的结果为：\n");
  for(int k=0;k<size;k++)
  {
   printf("%12.8f ",xx[k]);
  }
  printf("\n");
 
}

void gaosisaideer(){
 double A[6][6] = {{4,-1,0,-1,0,0},
                  {-1,4,-1,0,-1,0},
                  {0,-1,4,-1,0,-1},
                  {-1,0,-1,4,-1,0},
                  {0,-1,0,-1,4,-1},
                  {0,0,-1,0,-1,4}};
 double b[6] = {0,5,-2,5,-2,6};;
 double x[6] = {0}; //第k+1次迭代的结果
 double xx[5] = {0}; //第k次迭代的结果
 int size = 6;
 int Max = 100;  //最大迭代次数
 double residual = 0.0;  //
 double sum = 0.0; 
 double dis = 0.0;
 double dif = 1.0;  //相邻迭代的结果差
 double eps = 1.0e-4; //迭代精度
 
 for(int k=1;(k<Max)&&(dif>eps);k++){
  dif = 0.0;
  for(int i=0;i<size;i++){
   for(int j=0;j<size;j++){
    //与Jacobi迭代法唯一的区别就是sum的求法
    if(j<i)
    {
     sum +=A[i][j]*x[j];//本次的x[j]
    }
    if(j>i)
    {
     sum +=A[i][j]*xx[j];//上一次的x[j]
    }

   }
   x[i] = (b[i]-sum)/A[i][i];
   sum=0.0;

  } 
  residual=0.0;
  //计算相邻迭代的结果差
  for(int m=0;m<size;m++)
  {
   dis=fabs(x[m]-xx[m]);
   if(dis>residual)
    residual=dis;
  }
  dif=residual;

  //打印第k次的结果
  printf("\n第%d次迭代的结果：\n",k);
  for(int i=0;i<size;i++)
  {
   printf("%12.8f ",x[i]);
   xx[i]=x[i];
  }
  printf("\n与上次计算结果的距离(无穷范数):%12.8f \n",dif);
 }
 printf("\n迭代计算的结果为：\n");
 for(int k=0;k<size;k++)
 {
  printf("%12.8f ",xx[k]);
 }
 printf("\n");
 
}


int main(){
    printf("雅克比迭代法：\n");
    yakebi();
    printf("---------------------------------------------------------------------\n");
    printf("---------------------------------------------------------------------\n");
    printf("高斯赛德尔迭代法：\n");
    gaosisaideer();
    return 0;
}