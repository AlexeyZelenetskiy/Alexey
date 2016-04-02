#pragma once
#include "rational.h"
class Matrica
{
int n; int m;
Rational **r;
public:
	Matrica(void);
	~Matrica(void);
	void get_mat();
	Matrica kont(Matrica m);
};

