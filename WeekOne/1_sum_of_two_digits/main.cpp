/*
 * main.cpp
 *
 *  Created on: Aug 6, 2018
 *      Author: Besho
 */

#include <iostream>
#include <math.h>
using namespace std;

#define ValueOfNumber 0

int main ()
{
	auto ValueOfFirstNum = ValueOfNumber;
	auto ValueOfSecondNum = ValueOfNumber;

	cin >> ValueOfFirstNum;
	cin >> ValueOfSecondNum;

	cout << ValueOfFirstNum + ValueOfSecondNum;

	return 0;
}


