/*************************************************************************
	> File Name: shiyaner.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年04月01日 星期六 12时52分26秒
 ************************************************************************/

#include "stdio.h"
#include<stdlib.h>
#include<math.h>
#define n 4
/**
 * 顺序消去法
 */
void shunxuxiaoqu(float a[n][n],float h[n]){
    int i,j,k;
    float x[n];
    float temp1,temp2;
    for(k=0; k<n-1;k++){
        for(i=k+1;i<n;i++){
            temp1 = a[i][k]/a[k][k];
            h[i] -= h[k]*temp1;
            for(j=k+1;j<n;j++){
                a[i][j] -= a[k][j]*temp1;
            }
        }
    }
    x[n-1]=h[n-1]/a[n-1][n-1];
    for(i=n-2;i>-1;i--){
        temp2 = 0;
        for(j=i+1;j<n;j++){
            temp2 += a[i][j]*x[j];
        }
        //回代求解
        x[i]=(h[i]-temp2)/a[i][i];
      //  printf("xi:%f--%f---%f----%f------\n",x[i],h[i],temp2,a[i][i]);
    }
   // cout<<"方程的解为："<<endl;
    printf("方程的解为：\n");
    for(i=0;i<n;i++){
       // cout<<x[i]<<setprecision(4)<<endl;
       printf("%f\n",x[i]);
    }
}

//列主元消去法
void liezhuyuan(float a[n][n],float b[n]){
    float m[n][n];
	float x[n];
        int k,i,j,l;
	float max;
	float p;
	for(k=0;k<n-1;k++)
	{
		max=a[k][k];
		l=k;
        for(i=k+1;i<n;i++)//选主元
		{
			if(fabs(a[i][k])>fabs(max))
			{
				max=a[i][k]; 
				l=i;
			}
		}
		if(fabs(max)*100000<1)
			printf("det a=0\n");
        else{
			if(l!=k)//交换行
			{
				p=b[l];b[l]=b[k];b[k]=p;
				for(j=0;j<n;j++)
				{
					p=a[l][j];
					a[l][j]=a[k][j];
					a[k][j]=p;
				}
			}
			for(i=k+1;i<n;i++)//消元计算，将方程组约化为三角形方程组
			{
				m[i][k]=a[i][k]/a[k][k];
				for(j=k+1;j<n;j++)
				{
					a[i][j]-=m[i][k]*a[k][j];
				}
				b[i]-=m[i][k]*b[k];
			}
		}
	}
        if(fabs(a[n-1][n-1])*100000<1)
		   printf("det a=0\n");
    	else{
		//回代求解
		x[n-1]=b[n-1]/a[n-1][n-1];
		for(i=n-2;i>=0;i--)
		{
			x[i]=b[i];
			for(j=i+1;j<n;j++)
			{
			x[i]-=a[i][j]*x[j];
			}
			x[i]/=a[i][i];
		}
	}
	//输出方程组的解
	for(i=0;i<n;i++)
	{
	    printf("%f\n",x[i]);
	}
}




int main(){
    float a1[n][n]={{1.1348,3.8326,1.1651,3.4017},
	            {0.5301,1.7875,2.5330,1.5435},
	            {3.4129,4.9317,8.7643,1.3142},
                {1.2371,4.9998,10.6721,0.0147}};
	float b1[n]={9.5342,6.3941,18.4231,16.9237};
    printf("\n");
    printf("顺序消去法：\n");
    shunxuxiaoqu(a1,b1);
    printf("\n");
    float a2[n][n]={{1.1348,3.8326,1.1651,3.4017},
                	{0.5301,1.7875,2.5330,1.5435},
                	{3.4129,4.9317,8.7643,1.3142},
                	{1.2371,4.9998,10.6721,0.0147}};
	float b2[n]={9.5342,6.3941,18.4231,16.9237};
    printf("列主元消去法：\n");
    liezhuyuan(a2,b2);

    return 0;
}

