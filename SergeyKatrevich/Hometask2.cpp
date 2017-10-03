// Hometask2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
/* 2. «Условия if, if - else, ? ». */

#include <iostream>
#include <cmath>
#include <conio.h>

using namespace std;

void inNumsOutMax() {
	int max = 0;
	for (int i = 0; i < 10; i++) {
		int curNum;
		cout << "Enter num " << i+1 << ": ";
		cin >> curNum;
		if (curNum > max)
			max = curNum;
	}
	cout << "Max num = " << max << endl;
}

void fibonachi() {
	int order;
	cin >> ((cout << "Enter fibonachi num order: "), order);
	int res;
	int pred = 1, predpred = 1;
	if (order == 1)
		res = pred;
	else if (order == 2)
		res = predpred;
	else {
		int curOrder = 3;
		do {
			res = pred + predpred;
			predpred = pred;
			pred = res;
		} while (curOrder++ < order);
	}
	cout << "Fibonachi num = " << res << endl;
}

void inNumsOutMin() {
	int min, i = 1;
	cout << "Enter num " << i << ": ";
	cin >> min;
	do {
		i++;
		int curNum;
		cout << "Enter num " << i << ": ";
		cin >> curNum;
		if (curNum < min) min = curNum;
	} while (i < 20);
	
	cout << "Min = " << min << endl;
}

void sepNum() {
	int num;
	cin >> ((cout << "Separate num: "), num);
	int numDegree = 1;
	while (true) {
		if (pow(10, numDegree) > num)
			break;
		numDegree++;
	}
	cout << endl;
	while (numDegree--) {
		int tenPow = (int)pow(10, numDegree);
		cout << int(num / tenPow) << " ";
		num %= tenPow;
	}
}

float distance(float x1, float y1, float x2, float y2) {
	float deltaX = abs(x2 - x1);
	float deltaY = abs(y2 - y1);
	return sqrt(deltaX * deltaX + deltaY * deltaY);
}

int getSecsFromMidnight(short hours, short minuts, short seconds) {
	return hours * 60 * 60 + minuts * 60 + seconds;
}

double evalTrigSquare(float sideA, float sideB, float sideC) {
	// Полупериметр
	double p = sideA;
	p = (p + sideB + sideC) / 2;
	return sqrt(p * (p - sideA) * (p - sideB) * (p - sideC));
}

int remindersCount(int num) {
	int res = 1;
	for (int i = 1; i < int(num / 2); i++) {
		if ((num % i) == 0)
			res++;
	}
	return res + 1;
}
void helloAndGoodbye() {
	static bool firstCall = true;
	if (firstCall) {
		cout << "Hello" << endl;
		firstCall = false;
	}
	else cout << "Goodbye" << endl;
}

double numDegrees(double num) {
	static short degree = 2;
	switch (degree) {
	case 2: 
		num = pow(num, degree);
		degree = 3;
		break;
	case 3: 
		num = pow(num, degree);
		degree = 4;
		break;
	case 4:
		num = pow(num, degree);
		break;
	}
	return num;
}

void parallelepipedDetails(float edge1, float edge2, float edge3, double &edgesLen, double &square, double &volume) {
	edgesLen = 4 * (edge1 + edge2 + edge3);
	square = 2 * (edge1 * edge2 + edge2 * edge3 + edge1 * edge3);
	volume = edge1 * edge2 * edge3;
}

int main()
{
	setlocale(LC_ALL, "Russian");

	//inNumsOutMax();
	//fibonachi();
	//inNumsOutMin();
	//sepNum();
	//cout << "x1=3,y1=5,x2=6,y2=9, distance = " << distance(3, 5, 6, 9) << endl;
	//cout << "Seconds from midnight (15:35:20): " << getSecsFromMidnight(15, 35, 20) << endl;
	//cout << "Triangle square (3,4,5): " << evalTrigSquare(3, 4, 5) << endl;
	//cout << "remindersCount (12): " << remindersCount(12) << endl;
	//helloAndGoodbye(); helloAndGoodbye(); helloAndGoodbye();
	//---------------
	cout << "numDegrees(2): " << numDegrees(2) << " ";
	cout.flush();
	cout << numDegrees(2) << " ";
	cout.flush();
	cout << numDegrees(2) << endl;
	//---------------

	double edgesLen, square, volume;
	parallelepipedDetails(3, 4, 5, edgesLen, square, volume);
	cout << "parallelepipedDetails(3, 4, 5, edgeLen, square, volume). Edges length: " << edgesLen << " square: " << square << " volume: " << volume << endl;

	//already
	//inNumsOutMax();

	_getch();
    return 0;
}

