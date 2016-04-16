#pragma once
#include "rational.h"
class Matrica
{
int n; int m;
Rational **r;
public:
	Matrica(void);
	Matrica(int n1, int m1);
	~Matrica(void);
	void get_mat();
	Matrica & operator|(Matrica m1);
	Matrica & operator*(int a);
	Matrica operator!();
	Rational operator()(int a, int b);
};


