#pragma once
class Rational
{
	int ch; int zn;
public:
	Rational(void);
	Rational(int ch1, int zn1);
	void get_rat(); // это print
	int get_zn(); // const; unsigned int maybe?
	int get_ch(); // const
	void set_ch(int a); // зачем?
	void set_zn(int a); // зачем?
    Rational & operator+(Rational r1);
	~Rational(void); // зачем?
	Rational & operator*(Rational r1);
};

