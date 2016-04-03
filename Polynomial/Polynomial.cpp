//
//  Polynomial.cpp
//  Polynomial
//
//  Created by Patrick Kelly on 3/30/16.
//  Copyright © 2016 Patrick Kelly. All rights reserved.
//

#include "Polynomial.h"

//private functions
char poly::sign(int *arrayptr)
{
	if (*arrayptr >= 0)
	{
		return '+';
	}
	else if (*arrayptr < 0)
	{
		return '-';
	}
	else
	{
		return '=';
	}
}

poly::poly()
{
	polyarray.reserve(3);
	polyarray[0] = 0;
	degree = new int;
}

poly::poly(int _a, int _b, int _c, int _d, int _e, int _f)
{
	degree = new int;
	*degree = 3;
	polyarray.resize(*degree);
	polyarray[0] = _a;
	polyarray[1] = _b;
	polyarray[2] = _c;
	if (_d != 999)
	{
		*degree = 4;
		polyarray.resize(*degree);
		polyarray[3] = _d;
	}
	if (_e != 999)
	{
		*degree = 5;
		polyarray.resize(*degree);
		polyarray[4] = _e;
	}
	if (_f != 999)
	{
		*degree = 6;
		polyarray.resize(*degree);
		polyarray[5] = _f;
	}
}

poly::poly(const poly &obj)
{
	*degree = *obj.degree;
	for (int i=0; i<*degree; i++)
		polyarray[i] = obj.polyarray[i];
}

poly::~poly()
{
	delete degree;
}

ostream& operator<< (ostream &stream, const poly &obj)
{
	int x = *obj.degree;
	int count = x;
	for (int i=0;i<x;i++)
	{
		int coef = obj.polyarray[i];
		if (count < 1)
			stream << coef << "X^" << count << poly::sign(&coef);
		else if (count == 1)
		{
			stream << coef << "X" << poly::sign(&coef);
		}
		else if (count == 0)
		{
			stream << coef;
		}
		count--;
	}
	return stream;
}
istream& operator>> (istream &stream, poly &obj)
{
	//ask for number of coeffeciants
	cout << "X^2: ";
	stream >> obj.polyarray[2];
	cout << "X: ";
	stream >> obj.polyarray[1];
	cout << "Constaint: ";
	stream >> obj.polyarray[0];
	return stream;
}

poly poly::operator= (const poly &right)
{
	*degree = *right.degree;
	for (int i=0;i<*degree;i++)
	{
		polyarray[i] = right.polyarray[i];
	}
	return *this;
}

poly poly::operator+ (const poly &right)
{
	poly temp; //temp class for function
	for (int i=0;i<*degree;i++)
		temp.polyarray[i] = polyarray[i] + right.polyarray[i];
	return temp;
}

poly poly::operator- (const poly &right)
{
	poly temp; //temp class for function
	for (int i=0;i<*degree;i++)
		temp.polyarray[i] = polyarray[i] - right.polyarray[i];
	return temp;
}

poly poly::operator* (const poly &right)
{
	int a,b,c,d,e;
	a = polyarray[0] * right.polyarray[0]; //x^4
	b = (polyarray[1] * right.polyarray[0]) + (polyarray[0] * right.polyarray[1]);//x^3
	c = (polyarray[0] * right.polyarray[2]) + (polyarray[1] * right.polyarray[1]) + (polyarray[2] * right.polyarray[0]);//X^2
	d = (polyarray[1] * right.polyarray[2]) + (polyarray[2] * right.polyarray[1]);//X
	e = (polyarray[2] * right.polyarray[2]);//constaint
	poly temp(a, b, c, d, e);
	return temp;
}























