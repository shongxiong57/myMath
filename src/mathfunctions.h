/*
 * mathfunctions.cpp
 *
 *  Created on: Apr 5, 2017
 *      Author: Shong Xiong
 *
 *      Recursive functions: add, sub, multiply, quotient, remains, power, gcd
 *		Iterative functions: plus, minus, times, divide, modulo, exp, euclid (for gcd).
 */

#include "mathbasic.h"

using namespace std;


/* ***********************************************************
 *
 * Recursive Math Functions:
 * add, sub, multiply, quotient, remains, power, gcd
 *
 * ***********************************************************
 */

int add(int x, int y) {
	if (equal0(y)) {
		return x;
	} else {
		return add(add1(x), sub1(y));
	}
}

int sub(int x, int y){
	if(equal0(y)) {
		return x;
	}
	else {
		return sub(sub1(x),sub1(y));
	}
}

int multiply(int x, int y){
	if(equal0(x)){
		return 0;
	}
	else {
		return add(multiply(sub1(x),y),y);
	}
}

int quotient(int x, int y){
	if(equal0(y)){
		cout << "Cannot divide by 0" << "\n";
		return 0;
	}
	else if(x <= 0 || x < y){
		return 0;
	}
	else {
		return add1(quotient(sub(x,y),y));
	}
}
int remains(int x, int y){
	if(x < y){
		return x;
	}
	else {
		return remains(sub(x,y),y);
	}

}
int power(int x, int y){
	if(y == 0)
		return 1;

	else
		return multiply(x,power(x,sub1(y)));

}
int gcd(int x, int y){
	if(x<y){
		return gcd(y,x);
	}
	else if(y == 0){
		return x;
	}
	else {
		return gcd(y,remains(x,y));
	}

}

int recur_eq1(int x, int y, int z){
	// x + ( y / z ) % x
	int temp1 = quotient(y,z);
	int temp2 = add(x,temp1);
	return remains(temp2,x);
}
int recur_eq2(int x, int y, int z){
	// ( x - y * z )^4 / ( x + y )
	int temp1 = multiply(y,z);
	int temp2 = sub(x,temp1);
	int temp3 = power(temp2,4);
	int temp4 = add(x,y);
	return quotient(temp3,temp4);
}

/* ***********************************************************
 *
 * Iterative Math Functions:
 * plus, minus, times, divide, modulo, exp, euclid (for gcd).
 *
 * ***********************************************************
 */

int myplus(int x, int y){
	while(y != 0){
		x = add1(x);
		y = sub1(y);
	}
	return x;
}
int myminus(int x, int y){
	while(y != 0){
		x = sub1(x);
		y = sub1(y);
	}
	return x;
}
int times(int x, int y){
	int ans = 0;
	while(y != 0){
		ans = myplus(ans,x);
		y = sub1(y);
	}
	return ans;
}
int divide(int x, int y){
	int ans = 0;
	while(x >= y){
		x = myminus(x,y);
		ans = add1(ans);
	}
	return ans;
}
int modulo(int x, int y){
	while(x >= y){
		x = myminus(x,y);
	}
	return x;
}
int exp(int x, int y){
	int ans = 1;
	while(y != 0){
		ans = times(ans,x);
		y = sub1(y);
	}
	return ans;
}
int euclid(int x, int y){
	if(x < y){ //swap x and y if true
		x = x+y;
		y = x-y;
		x = x-y;
	}
	int ans = y;
	while(modulo(x,y) != 0){
		ans = modulo(x,y);
		x = y;
		y = ans;
	}
	return ans;
}
int iter_eq1(int x, int y, int z){
	// x + ( y / z ) % x
	int temp1 = divide(y,z);
	int temp2 = myplus(x,temp1);
	return modulo(temp2,x);
}
int iter_eq2(int x, int y, int z){
	// ( x - y * z )^4 / ( x + y )
	int temp1 = times(y,z);
	int temp2 = myminus(x,temp1);
	int temp3 = exp(temp2,4);
	int temp4 = myplus(x,y);
	return divide(temp3,temp4);
}

