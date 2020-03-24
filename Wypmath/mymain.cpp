/*
 * mymain.cpp
 *
 *  Created on: 2020年3月20日
 *      Author: hi
 */


#include<iostream>
#include"mymath.h"
#include<math.h>//仅对比精度用

using namespace std;

const double pi=3.1415926;

int main(){
	Mymath mymath;
	double x,y;
	cout<<"请输入角度：";
	cin>>x;

	y=x*pi/180;//角度转换为弧度
	cout<<"sin("<<x<<")的值为："<<mymath.mysin(y)<<endl;
	cout<<"cos("<<x<<")的值为："<<mymath.mycos(y)<<endl;

	cout<<"======对比======"<<endl;
	cout<<"sin("<<x<<")的数据库的值为："<<sin(y)<<endl;
	cout<<"cos("<<x<<")的数据库的值为："<<cos(y)<<endl;

	return 0;
}

