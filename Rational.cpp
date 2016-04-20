#include "stdafx.h"
#include "StdAfx.h"
#include "Rational.h"
#include <iostream>
using namespace std;
Rational::Rational(void) 
{
}
Rational::Rational(int ch1, int zn1) // unsigned int zn1
{
	try{
	if(zn1<=0) // == 0
		throw 1; // специальный класс на исключения
	  int a=ch1; int b=zn1;
	  while( a !=0 && b !=0)
	  {
        if(a>b)
		{ a=a%b; }
		else
		{ b=b%a;}
	  }
	 a=a+b;
	 this->ch=ch1/a;
	 this->zn=zn1/a;
	}
	catch(int k) // кому нужен этот catch? try-catch делает вызывающий код -- так узнает об ошибке
	{
		cout<<"ERROR!"<<endl;
	}
}


Rational::~Rational(void)
{
}
int Rational::get_ch()
{
	return this->ch;
}
int Rational::get_zn()
{
	return this->zn;
}
void Rational::get_rat()
{
	cout<<this->ch;
	cout<<"/";
	cout<<this->zn;
}
Rational&  Rational::operator+(Rational r) // это +=
{
	int newch, newzn;
	if(Rational::zn!=r.get_zn()){
	newzn=Rational::zn*r.get_zn();
	newch=r.get_zn()*Rational::ch+r.get_ch()*zn;
	}
	else{
		newzn=r.get_zn();
	    newch=r.get_ch()+ch;
	}
	int a=newch; int b=newzn;
	  while( a !=0 && b !=0)
	  {
        if(a>b)
		{ a=a%b; }
		else
		{ b=b%a;}
	  }
	 a=a+b;
	 this->ch=newch/a;
	 this->zn=newzn/a;
	 return *this;
}
Rational & Rational::operator*(Rational r) // это *=
{
	int newch=ch*r.get_ch();
	int newzn=zn*r.get_zn();
	int a=newch; int b=newzn;
	  while( a !=0 && b !=0)
	  {
        if(a>b)
		{ a=a%b; }
		else
		{ b=b%a;}
	  }
	 a=a+b;
	 this->ch=newch/a;
	 this->zn=newzn/a;
	 return *this;;
}
void Rational::set_ch(int a)
{
	this->ch=a;
}
void Rational::set_zn(int a)
{
	this->zn=a;
}