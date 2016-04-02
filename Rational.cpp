#include "StdAfx.h"
#include "Rational.h"
#include <iostream>
using namespace std;

Rational::Rational(void)
{
	int ch1; int zn1;
	cout<<"Vvedite chislitel: ";
	cin>>ch1;
	cout<<"Vvedite znamenatel: ";
	cin>>zn1;
	if(zn1<=0)
		throw 1;
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


Rational::~Rational(void)
{
}
int Rational::ger_ch()
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
Rational&  Rational::operator+(Rational & r)
{
	int newch, newzn;
	if(Rational::zn!=r.get_zn()){
	newzn=Rational::zn*r.get_zn();
	newch=r.get_zn()*Rational::ch+r.ger_ch()*zn;
	}
	else{
		newzn=r.get_zn();
	    newch=r.ger_ch()+ch;
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
Rational & Rational::operator*(Rational & r)
{
	int newch=ch*r.ger_ch();
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