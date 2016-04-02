#pragma once
class Rational
{
	int ch; int zn;
public:
	Rational(void );
	void get_rat();
	int get_zn();
	int ger_ch();
    Rational & operator+(Rational & r1);
	~Rational(void);
	Rational & operator*(Rational & r1);
};

