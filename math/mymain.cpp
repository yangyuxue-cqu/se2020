/*
 * mymain.cpp
 *
 *  Created on: 2020年3月20日
 *      Author: hi
 */


#include<iostream>
//#include"mymath.h"
#include<math.h>//仅对比精度用

using namespace std;

const double pi=3.1415926;

class Mymath{
private:
	double sign=-1;

public:
	 double mysin (double x);
	 double mycos (double x);
};


 double Mymath::mysin(double x){
	double a=x,sum=x;
	for(int i=3;a >= 0.00001;i=i+2){//用泰勒，误差大，因此当最后一项大于0.00001，就结束
		a=a*x*x/(i*(i-1));
		sum +=a*sign;
		sign=-sign;
	}
	return sum;
}

 double Mymath::mycos(double x){
	double a=1,sum=1;
	for(int i=2;a >= 0.00001;i=i+2){
		a=a*x*x/(i*(i-1));
		sum +=a*sign;
		sign=-sign;
	}
	return sum;
}


int main(){
	Mymath mymath;
	double x,y;
	cout<<"请输入角度：";
	cin>>x;

	y=x*pi/180;//角度转换为弧度
	cout<<"sin("<<x<<")的值为："<<mymath.mysin(y)<<endl;
	cout<<"cos("<<x<<")的值为："<<mymath.mycos(y)<<endl;

	//cout<<"======对比======"<<endl;
	//cout<<"sin("<<x<<")的数据库的值为："<<sin(y)<<endl;
	//cout<<"cos("<<x<<")的数据库的值为："<<cos(y)<<endl;

	return 0;
}

