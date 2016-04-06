//
//  Polynomial.cpp
//  Polynomial
//
//  Created by Patrick Kelly on 3/30/16.
//  Copyright © 2016 Patrick Kelly. All rights reserved.
//
/* -----------------------------------------------------------------------------

 FILE:              Polynomial.cpp

 DESCRIPTION:       class implemntation file

 COMPILER:          GNU++11

 NOTES:             Put other information here ...

 MODIFICATION HISTORY:

 Author                  Date               Version
 ---------------         ----------         --------------
 Patrick Kelly			 2016-1-04			X.X (git source control)

 ----------------------------------------------------------------------------- */
#include "Polynomial.h"

//private functions
/* -----------------------------------------------------------------------------
 FUNCTION:          sign(int *)
 DESCRIPTION:       determins if given number is positive or negitive
 RETURNS:           char
 NOTES:
 ----------------------------------------------------------------------------- */
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

/* -----------------------------------------------------------------------------
 FUNCTION:          verify_size()
 DESCRIPTION:		resizes the vector size as needed
 RETURNS:           void
 NOTES:
 ----------------------------------------------------------------------------- */
void poly::verify_size()
{
	if (*degree != int(polyarray.size()))
	{
		*degree = int(polyarray.size());
	}
}

//constructors
/* -----------------------------------------------------------------------------
 FUNCTION:          poly()
 DESCRIPTION:       default constructor
 RETURNS:           none
 NOTES:
 ----------------------------------------------------------------------------- */
poly::poly()
{
	polyarray.reserve(1);
	degree = new int;
	*degree = 0;
}

/* -----------------------------------------------------------------------------
 FUNCTION:          poly(int X6)
 DESCRIPTION:       overloaded constructor
 RETURNS:           none
 NOTES:
 ----------------------------------------------------------------------------- */
poly::poly(int _a, int _b, int _c, int _d, int _e, int _f)
{
	degree = new int;
	polyarray.push_back(_a);
	polyarray.push_back(_b);
	polyarray.push_back(_c);
	if (_d != 999)
	{
		polyarray.push_back(_d);
	}
	if (_e != 999)
	{
		polyarray.push_back(_e);
	}
	if (_f != 999)
	{
		polyarray.push_back(_f);
	}
	verify_size();
}

/* -----------------------------------------------------------------------------
 FUNCTION:          poly(int for array, int for array size)
 DESCRIPTION:       overloaded constructor for passing in arrays
 RETURNS:           none
 NOTES:
 ----------------------------------------------------------------------------- */
poly::poly (const int *array, int n)
{
	degree = new int;
	*degree = n;
	polyarray.resize(*degree);
	for (int i=0;i<*degree;i++)
	{
		polyarray[i] = array[i];
	}
}

/* -----------------------------------------------------------------------------
 FUNCTION:          poly(vector<int>)
 DESCRIPTION:       overloaded constructor for passing in vectors
 RETURNS:           none
 NOTES:
 ----------------------------------------------------------------------------- */
poly::poly (const vector<int> *array)
{
	degree = new int;
	*degree = int(array->size());
	polyarray.resize(*degree);
	for (int i=0;i<*degree;i++)
	{
		polyarray[i] = array->at(i);
	}
}

/* -----------------------------------------------------------------------------
 FUNCTION:          poly()
 DESCRIPTION:       copy constructor
 RETURNS:           none
 NOTES:
 ----------------------------------------------------------------------------- */
poly::poly(const poly &obj)
{
	degree = new int;
	*degree = *obj.degree;
	polyarray.resize(*degree);
	for (int i=0; i<*degree; i++)
		polyarray[i] = obj.polyarray[i];
}

/* -----------------------------------------------------------------------------
 FUNCTION:          poly()
 DESCRIPTION:       destructor
 RETURNS:           none
 NOTES:
 ----------------------------------------------------------------------------- */
poly::~poly()
{
	delete degree;
}

/* -----------------------------------------------------------------------------
 FUNCTION:          set_coefs(int X3)
 DESCRIPTION:       sets the three default coefecients
 RETURNS:           void
 NOTES:
 ----------------------------------------------------------------------------- */
void poly::set_coefs(int _a, int _b, int _c, int _d)
{
	polyarray.push_back(_a);
	polyarray.push_back(_b);
	polyarray.push_back(_c);
	if (_d != 999)
	{
		polyarray.push_back(_d);
	}
	verify_size();
}

/* -----------------------------------------------------------------------------
 FUNCTION:          evaluate(int)
 DESCRIPTION:       evaluates the polynomial at the given number
 RETURNS:           double
 NOTES:
 ----------------------------------------------------------------------------- */
double poly::evaluate(const int eval) const
{
	int x = 0, power = *degree - 1;
	for (int i=0;i<*degree;i++)
	{
		if (power == 0)
		{
			x = x + (polyarray[i]);
		}
		else
		{
			x = x + (polyarray[i] * pow(eval, power));
		}
		power--;
	}
	return x;
}

//IO overloads

/* -----------------------------------------------------------------------------
 FUNCTION:          operator <<
 DESCRIPTION:       overload for ostream
 RETURNS:           stream
 NOTES:
 ----------------------------------------------------------------------------- */
ostream& operator<< (ostream &stream, const poly &obj)
{
	int x = *obj.degree;
	int count = x-1;
	int tempnext = obj.polyarray[1];	//show first value without abs() function
	stream << obj.polyarray[0] << "X^" << count << " " << poly::sign(&tempnext) << " ";
	count--;

	for (int i=1;i<x;i++) //loop until end of vector
	{
		int coef = obj.polyarray[i];
		int nextcoef = obj.polyarray[i+1];
		if (coef != 0)
		{
			if (count > 1)
			{
				stream << abs(coef) << "X^" << count << " " << poly::sign(&nextcoef) << " ";
			}
			else if (count == 1 && obj.polyarray[i+1] != 0)
			{
				stream << abs(coef) << "X" << " " << poly::sign(&nextcoef) << " ";
			}
			else if (count == 1 && obj.polyarray[i+1] == 0)
			{
				stream << abs(coef) << "X";
			}
			else if (count == 0 && coef != 0)
			{
				stream << abs(coef);
			}
		}
		count--;
	}
	return stream;
}

/* -----------------------------------------------------------------------------
 FUNCTION:          operator >>
 DESCRIPTION:       overloads istream
 RETURNS:           stream
 NOTES:
 ----------------------------------------------------------------------------- */
istream& operator>> (istream &stream, poly &obj)
{
	//resize array
	*obj.degree = 4;
	obj.polyarray.resize(*obj.degree);
	//ask for number of coeffeciants
	cout << "X^3: ";
	stream >> obj.polyarray[0];
	cout << "X^2: ";
	stream >> obj.polyarray[1];
	cout << "X: ";
	stream >> obj.polyarray[2];
	cout << "Constaint: ";
	stream >> obj.polyarray[3];
	return stream;
}

//math overloads

/* -----------------------------------------------------------------------------
 FUNCTION:          operator =
 DESCRIPTION:       overloads =
 RETURNS:           poly class
 NOTES:
 ----------------------------------------------------------------------------- */
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

/* -----------------------------------------------------------------------------
 FUNCTION:          operator +
 DESCRIPTION:       overloads +
 RETURNS:           poly class
 NOTES:
 ----------------------------------------------------------------------------- */
poly poly::operator+ (const poly &right)
{
	vector<int> temp = {0}; //temp class for function
	if (*right.degree > *degree)
	{
		temp.resize(*right.degree);
		for (int i=0;i<*right.degree;i++)
		{
			temp[i] = right.polyarray[i];
		}
		int j=0, x=*right.degree-*degree;
		for (int i=*degree-1;i>-1;i--)
		{
			temp.at(temp.size()-(j+1)) = ((right.polyarray.at(i+x) + (polyarray.at(i))));
			j++;
		}
	}
	else if (*degree > *right.degree)
	{
		temp.resize(*degree);
		for (int i=0;i<*degree;i++)
		{
			temp[i] = polyarray[i];
		}
		int j=0, x=*degree-*right.degree;
		for (int i=*right.degree-1;i>-1;i--)
		{
			temp.at(temp.size()-(j+1)) = ((polyarray.at(i+x) + (right.polyarray.at(i))));
			j++;
		}
	}
	else if (*degree == *right.degree)
	{
		temp.resize(*degree);
		for (int i=0;i<*degree;i++)
		{
			temp[i] = polyarray[i] + right.polyarray[i];
		}
	}
	poly returnable(&temp);
	return returnable;
}

/* -----------------------------------------------------------------------------
 FUNCTION:          operator -
 DESCRIPTION:       overloads -
 RETURNS:           poly class
 NOTES:
 ----------------------------------------------------------------------------- */
poly poly::operator- (const poly &right)
{
	vector<int> temp = {0}; //temp class for function
	if (*right.degree > *degree)
	{
		temp.resize(*right.degree);
		for (int i=0;i<*right.degree;i++)
		{
			temp[i] = right.polyarray[i];
		}
		int j=0, x=*right.degree-*degree;
		for (int i=*degree-1;i>-1;i--)
		{
			temp.at(temp.size()-(j+1)) = ((right.polyarray.at(i+x) - (polyarray.at(i))));
			j++;
		}
	}
	else if (*degree > *right.degree)
	{
		temp.resize(*degree);
		for (int i=0;i<*degree;i++)
		{
			temp[i] = polyarray[i];
		}
		int j=0, x=*degree-*right.degree;
		for (int i=*right.degree-1;i>-1;i--)
		{
			temp.at(temp.size()-(j+1)) = ((polyarray.at(i+x) - (right.polyarray.at(i))));
			j++;
		}
	}
	else if (*degree == *right.degree)
	{
		for (int i=0;i<*degree;i++)
		{
			temp[i] = polyarray[i] + right.polyarray[i];
		}
	}
	poly returnable(&temp);
	return returnable;
}

/* -----------------------------------------------------------------------------
 FUNCTION:          operator *
 DESCRIPTION:       overloads *
 RETURNS:           poly class
 NOTES:
 ----------------------------------------------------------------------------- */
poly poly::operator* (const poly &right)
{
	vector<int> array;
	if (*degree == *right.degree && *degree == 2)
	{
		array.push_back(polyarray[0] * right.polyarray[0]); //x^2
		array.push_back((polyarray[1] * right.polyarray[0]) + (polyarray[0] * right.polyarray[1]));	//x
		array.push_back(polyarray[1] * right.polyarray[1]);
	}
	else if (*degree == *right.degree && *degree == 3)
	{
		array.push_back(polyarray[0] * right.polyarray[0]); //x^4
		array.push_back((polyarray[1] * right.polyarray[0]) + (polyarray[0] * right.polyarray[1]));//x^3
		array.push_back((polyarray[0] * right.polyarray[2]) + (polyarray[1] * right.polyarray[1]) + (polyarray[2] * right.polyarray[0]));//X^2
		array.push_back((polyarray[1] * right.polyarray[2]) + (polyarray[2] * right.polyarray[1]));//X
		array.push_back((polyarray[2] * right.polyarray[2]));//constaint
	}
	else if (*degree == *right.degree && *degree == 4)
	{
		array.push_back(polyarray[0] * right.polyarray[0]); //x^9
		array.push_back(0);									//x^8
		array.push_back(0);									//x^7
		array.push_back((polyarray[0] * right.polyarray[1])+ (polyarray[1] * right.polyarray[0])); //x^6
		array.push_back(0);									//x^5
		array.push_back(polyarray[1] * right.polyarray[1]);	//x^4
		array.push_back((polyarray[0] * right.polyarray[2]) + (polyarray[0] * right.polyarray[3]) + (polyarray[2] * right.polyarray[0]) + (polyarray[3] * right.polyarray[0]));//x^3
		array.push_back((polyarray[1] * right.polyarray[2]) + (polyarray[1] * right.polyarray[3]) + (polyarray[2] * right.polyarray[1]) + (polyarray[3] * right.polyarray[1]));//X^2
		array.push_back((polyarray[2] * right.polyarray[2]) + (polyarray[2] * right.polyarray[3]) + (polyarray[3] * right.polyarray[2]));//X
		array.push_back((polyarray[3] * right.polyarray[3]));//constaint
	}

	poly temp(&array);
	return temp;
}

/* -----------------------------------------------------------------------------
 FUNCTION:          operator ==
 DESCRIPTION:       overloads ==
 RETURNS:           bool
 NOTES:
 ----------------------------------------------------------------------------- */
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






















