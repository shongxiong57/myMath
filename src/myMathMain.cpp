/*
 * myMathMain.cpp
 *
 *  Created on: Apr 5, 2017
 *      Author: Shong Xiong
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <time.h>

#include "mathfunctions.h"

/*
 * Program weaknesses/bugs
 * -Program can only handle positive integers
 * -Limitations:
 * --secondNum*thirdNum < firstNum
 * --Cannot compute equations resulting in a value beyond 65536 (2^16)
 * Yet to implement a function to track execution time of functions
 */

using namespace std;

void print_clock(int&,int);

int execution_time;

int main(){
	int firstNum = 5, secondNum = 3, thirdNum = 1;


/*
	cout << "Enter first number." << "\n";
	cin >> firstNum;

	cout << "Enter second number." << "\n";
	cin >> secondNum;

	cout << "Enter third number." << "\n";
	cin >> thirdNum;
*/
	//Recursive function calls
	cout << "---- Recursive Functions ----" << endl;
	cout << firstNum << " + " << secondNum << " = " << add(firstNum, secondNum) << endl;
	cout << firstNum << " - " << secondNum << " = " << sub(firstNum, secondNum) << endl;
	cout << firstNum << " * " << secondNum << " = " << multiply(firstNum, secondNum) << endl;
	cout << firstNum << " / " << secondNum << " = " << quotient(firstNum, secondNum) << endl;
	cout << firstNum << " % " << secondNum << " = " << remains(firstNum, secondNum) << endl;
	cout << firstNum << " ^ " << secondNum << " = " << power(firstNum, secondNum) << endl;
	cout << firstNum << " gcd " << secondNum << " = " << gcd(firstNum, secondNum) << endl;
	//Iterative function calls
	cout << "---- Iterative Functions ----" << endl;
	cout << firstNum << " + " << secondNum << " = " << myplus(firstNum, secondNum) << endl;
	cout << firstNum << " - " << secondNum << " = " << myminus(firstNum, secondNum) << endl;
	cout << firstNum << " * " << secondNum << " = " << times(firstNum, secondNum) << endl;
	cout << firstNum << " / " << secondNum << " = " << divide(firstNum, secondNum) << endl;
	cout << firstNum << " % " << secondNum << " = " << modulo(firstNum, secondNum) << endl;
	cout << firstNum << " ^ " << secondNum << " = " << exp(firstNum, secondNum) << endl;
	cout << firstNum << " euclid " << secondNum << " = " << euclid(firstNum, secondNum) << endl;

	//x + ( y / z ) % x
	//( x - y * z )4 / ( x + y )
	cout << "x + ( y / z ) % x = " << recur_eq1(firstNum,secondNum,thirdNum) << endl;
	cout << "( x - y * z )^4 / ( x + y ) = " << recur_eq2(firstNum,secondNum,thirdNum) << endl;
	cout << "x + ( y / z ) % x = " << iter_eq1(firstNum,secondNum,thirdNum) << endl;
	cout << "( x - y * z )^4 / ( x + y ) = " << iter_eq2(firstNum,secondNum,thirdNum) << endl;
	return 0;
}

void print_clock(int &start_time, int stop_time){
	execution_time = stop_time - start_time;
	cout << "Execution time: " + execution_time << endl;
	start_time = stop_time;
};
