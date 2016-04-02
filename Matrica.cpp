#include "StdAfx.h"
#include "Matrica.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

Matrica::Matrica(void)
{
	int n1; int m1;
	cout<<"Vvedite kolvo strok: ";
	cin>>n1;
	cout<<"Vvedite kolvo stolbcov: ";
	cin>>m1;
	if (m1<=0 || n1<=0)
		throw 1;
    this->n=n1;
	this->m=m1;
	r=(Rational**)malloc(n*sizeof(Rational));
	for(int i=0; i<n; i++)
	 r[i]=(Rational*)malloc(m*sizeof(Rational));
	for(int i=0; i<n; i++)
	for(int j=0; j<m; j++)
	{
		Rational r1;
		this->r[i][j]=r1;
	}
}


Matrica::~Matrica(void)
{
}
void Matrica::get_mat()
{
	for(int i=0; i<this->n; i++){
		for(int j=0; j<this->m; j++){
			this->r[i][j].get_rat();
		    cout<<"   ";
		}
	cout<<endl<<endl;
	}
}
Matrica Matrica::kont(Matrica m12)
{
	if (this->n != m12.n)
		throw 1;
	int m1=this->m+m12.m;
	Rational **r1;
	r1=(Rational**)malloc(n*sizeof(Rational));
	for(int i=0; i<n; i++)
	 r1[i]=(Rational*)malloc(m1*sizeof(Rational));
	for(int i=0; i<this->n; i++){
	 for(int j=0; i<m; j++)
		r1[i][j]=this->r[i][j];
	  for(int j=this->m-1; j<m1; j++)
		  r1[i][j]=m12.r[i][j-(m-1)];
	}
	this->r=r1;
	this->r=(Rational**)malloc(n*sizeof(Rational));
	for(int i=0; i<n; i++)
	 this->r[i]=(Rational*)malloc(m1*sizeof(Rational));
	this->m=m1;
	return *this;
}