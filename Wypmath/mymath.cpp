/*
 * mymath.cpp
 *
 *  Created on: 2020年3月20日
 *      Author: hi
 */

#include<iostream>
#include"mymath.h"


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
