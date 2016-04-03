//
//  Polynomial.cpp
//  Polynomial
//
//  Created by Patrick Kelly on 3/30/16.
//  Copyright © 2016 Patrick Kelly. All rights reserved.
//

#include "Polynomial.h"

//private functions
char poly::sign(int *numptr)
{
	if (*numptr >= 0)
	{
		return '+';
	}
	else if (*numptr < 0)
	{
		return '-';
	}
	else
	{
		return '=';
	}
}
void poly::verify_size()
{
	if (*degree != int(polyarray.size()))
	{
		polyarray.resize(*degree);
	}
}


poly::poly()
{
	polyarray.resize(3);
	polyarray[0] = 0;
	polyarray[1] = 0;
	polyarray[2] = 0;
	degree = new int;
	*degree=0;
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
	degree = new int;
	*degree = *obj.degree;
	polyarray.resize(*degree);
	for (int i=0; i<*degree; i++)
		polyarray[i] = obj.polyarray[i];
}

poly::~poly()
{
	delete degree;
}

void poly::set_coefs(int _a, int _b, int _c)
{
	polyarray[0] = _a;
	polyarray[1] = _b;
	polyarray[2] = _c;
	*degree = 3;
}

int poly::evaluate(int eval)
{
	int x = 0, power = *degree - 1;
	for (int i=0;i<*degree;i++)
	{
		if (power == 0)
		{
			x = x + (polyarray[i] * eval);
		}
		else
		{
			x = x + pow((polyarray[i] * eval), power);
		}
		power--;
	}
	return x;
}


//IO overloads
ostream& operator<< (ostream &stream, const poly &obj)
{
	int x = *obj.degree;
	int count = x-1;
	for (int i=0;i<x;i++)
	{
		int coef = obj.polyarray[i];
		int nextcoef = obj.polyarray[i+1];
		if (count > 1)
		{
			stream << abs(coef) << " X^" << count << " " << poly::sign(&nextcoef) << " ";
		}
		else if (count == 1 && obj.polyarray[i+1] != 0)
		{
			stream << abs(coef) << " X" << " " << poly::sign(&nextcoef) << " ";
		}
		else if (count == 1 && obj.polyarray[i+1] == 0)
		{
			stream << abs(coef) << " X";
		}
		else if (count == 0 && coef != 0)
		{
			stream << abs(coef);
		}
		count--;
	}
	return stream;
}
istream& operator>> (istream &stream, poly &obj)
{
	//resize array
	*obj.degree = 3;
	obj.polyarray.resize(*obj.degree);
	//ask for number of coeffeciants
	cout << "X^2: ";
	stream >> obj.polyarray[0];
	cout << "X: ";
	stream >> obj.polyarray[1];
	cout << "Constaint: ";
	stream >> obj.polyarray[2];
	return stream;
}

//math overloads
poly poly::operator= (const poly &right)
{
	*degree = *right.degree;
	verify_size();
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
	*temp.degree = *degree;
	return temp;
}

poly poly::operator- (const poly &right)
{
	poly temp; //temp class for function
	for (int i=0;i<*degree;i++)
	{
		temp.polyarray[i] = polyarray[i] - right.polyarray[i];
		*temp.degree = *temp.degree + 1;
	}
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

bool poly::operator== (const poly &right)
{
	if (*degree != *right.degree)
	{
		return false;
	}
	int x = 0;
	for (int i=0;i<*degree;i++)
	{
		if (polyarray[i] == right.polyarray[i])
		{
			x++;
		}
	}
	if (x == *degree && x == *right.degree)
	{
		return true;
	}
	return false;
}






















