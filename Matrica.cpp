#include "StdAfx.h"
#include "Matrica.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

Matrica::Matrica(void)
{
	int n1; int m1; int k=1; int ch1; int zn1;
	while(k)
	{
	try{
	cout<<"Vvedite kolvo strok: "; // вот чем не должен заниматься конструктор, так это читать что-то.
	cin>>n1;
	cout<<"Vvedite kolvo stolbcov: ";
	cin>>m1;
	if (m1<=0 || n1<=0)
		throw 1;
    n=n1;
	m=m1;
	r=new Rational* [n];
	for(int i=0; i<n; i++)
	 r[i]=new Rational[m];
	for(int i=0; i<n; i++)
	   for(int j=0; j<m; j++)
	   {
		   cout<<"vvedite chislitel: ";
		   cin>>ch1;
		   cout<<"vvedite chislitel: ";
		   cin>>zn1;
		   r[i][j].set_ch(ch1);
		   r[i][j].set_zn(zn1);
	   }
	k--;
	}
	catch(int k)
	{
		cout<<"ERROR!!"<<endl;
	}
	}
}
Matrica::Matrica(int n1, int m1)
{
   try
   {
	   if( (n1<=0) || (m1<=0) )
		  throw 1;
	   else
	   {
		   this->n=n1;
		   this->m=m1;
	   }
   }
   catch(int k)
   { 
	   cout<<"I can't create this matrix:(("<<endl; // кто это прочитает из winapi приложения?
	   this->n=0;
	   this->m=0;
   }
   r=new Rational* [n];
	for(int i=0; i<n; i++)
	 r[i]=new Rational[m];
}


Matrica::~Matrica(void)
{
	for(int i=0; i<n; i++)
		delete [] r[i];
	delete [] r;
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
Matrica & Matrica::operator|(Matrica m1)
{
	int k=1;
	try
	{
	  if(n!=m1.n)
	    throw 1;
	  else
	  {
	     Matrica m2(this->n, (this->m+m1.m));
		 for(int i=0; i<n; i++)
		 for(int j=0; j<m2.m; j++)
			 if(j<this->m)
			   m2.r[i][j]=this->r[i][j];
			 else
			   m2.r[i][j]=m1.r[i][j-this->m];
		return m2; // возвращается ссылка на локальный объект, который при выходе сразу разрушится
	  }
           
    }
	catch(int k) // как об ошибке вызывающий код узнает?
	{ 
		cout<<"error!"<<endl; 
		return *this;
	}

}
Matrica & Matrica::operator*(int a) // похоже на *=
{
	int b; int c;
	for(int i=0; i<n; i++)
	for(int j=0; j<m; j++)
	{
	 r[i][j].set_ch(r[i][j].get_ch()*a);
	 b=r[i][j].get_ch(); c=r[i][j].get_zn();
	 while(b !=0 && c !=0)
	  if(b>c)
	   {b=b%c;}
	  else
	   {c=c%b;}
	b=b+c;
	r[i][j].set_ch(r[i][j].get_ch()/b);
	r[i][j].set_zn(r[i][j].get_zn()/b);
	}
return *this;
}
Matrica Matrica::operator!()
{
	// неожиданно, но ок
	Matrica m2(m, n);
	for(int i=0; i<m; i++)
	for(int j=0; j<n; j++)
	{
		m2.r[i][j].set_ch(r[j][i].get_ch());
		m2.r[i][j].set_zn(r[j][i].get_zn());
	}
    return  m2;

}

// почему бы не возвращать ссылку?
Rational Matrica::operator()(int a, int b) // uint maybe?
{
	try
	{
		if(a<=0 || b<=0 || b>m || a>n)
			throw 1;
		return r[a-1][b-1];
	}
	catch(int k) //
	{cout<<"ERROR!!!"<<endl;}
}
