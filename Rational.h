#pragma once
class Rational
{
	int ch; int zn;
public:
	Rational(void);
	Rational(int ch1, int zn1);
	void get_rat();
	int get_zn();
	int get_ch();
	void set_ch(int a);
	void set_zn(int a);
    Rational & operator+(Rational r1);
	~Rational(void);
	Rational & operator*(Rational r1);
};

