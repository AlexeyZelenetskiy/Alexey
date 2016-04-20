#pragma once
#include "rational.h"

// про константность методов стоит подумать.
class Matrica
{
int n; int m; // uint
Rational **r;
public:
	Matrica(void);
	Matrica(int n1, int m1); // uint
	~Matrica(void);
	void get_mat(); // print, видимо
	Matrica & operator|(Matrica m1); // const Matrica& m1
	Matrica & operator*(int a);
	Matrica operator!();
	Rational operator()(int a, int b);
};


