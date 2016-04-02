// Base 1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include "Rational.h"
#include "Matrica.h"
using namespace std;
int _tmain(int argc, _TCHAR* argv[])
{
	int n=1;
	while (n) {
	try{
    Matrica m;
	Matrica m1;
	n--;
	m.get_mat();
	m1.get_mat();
	m=m.kont(m1);
	m.get_mat();
	/*Rational r1;
	Rational r2;
	n--;
	r1.get_rat(r1);
	r2.get_rat(r2);
	r1=r1+r2;
	r1.get_rat(r1);
	r1=r1*r2;
	r1.get_rat(r1);*/
	}
	catch(int n){
		cout<<"ERROR!!!!!"<<endl<<endl;
	}
}
	system("pause");
	return 0;
}

