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
}

/* -----------------------------------------------------------------------------
 FUNCTION:          poly(int X6)
 DESCRIPTION:       overloaded constructor
 RETURNS:           none
 NOTES:
 ----------------------------------------------------------------------------- */
poly::poly(int _a, int _b, int _c, int _d, int _e, int _f)
{
	polyarray.push_back(_a);
	polyarray.push_back(_b);
	if (_c != 999)
	{
		polyarray.push_back(_c);
	}
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
}

/* -----------------------------------------------------------------------------
 FUNCTION:          poly(int for array, int for array size)
 DESCRIPTION:       overloaded constructor for passing in arrays
 RETURNS:           none
 NOTES:
 ----------------------------------------------------------------------------- */
poly::poly (const int *array, int n)
{
	polyarray.resize(n);
	for (int i=0;i<n;i++)
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
	polyarray.resize(int((*array).size()));
	for (int i=0;i<int((*array).size());i++)
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
	polyarray.resize(obj.polyarray.size());
	for (int i=0; i<obj.polyarray.size(); i++)
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
}

/* -----------------------------------------------------------------------------
 FUNCTION:          evaluate(int)
 DESCRIPTION:       evaluates the polynomial at the given number
 RETURNS:           double
 NOTES:
 ----------------------------------------------------------------------------- */
double poly::evaluate(const int eval) const
{
	int x = 0, power = int(polyarray.size()) - 1;
	for (int i=0;i<int(polyarray.size());i++)
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
	int x = int(obj.polyarray.size());
	int count = x-1;
	stream << obj.polyarray[0] << "X^" << count << " ";
	count--;

	for (int i=1;i<x;i++) //loop until end of vector
	{
		int coef = obj.polyarray[i];
		if (coef != 0)
		{
			if (count > 1)
			{
				stream << poly::sign(&coef) << " " << abs(coef) << "X^" << count << " ";
			}
			else if (count == 1 && obj.polyarray[i+1] != 0)
			{
				stream << poly::sign(&coef) << " " << abs(coef) << "X" << " ";
			}
			else if (count == 1 && obj.polyarray[i+1] == 0)
			{
				stream << poly::sign(&coef) << " " << abs(coef) << "X";
			}
			else if (count == 0 && coef != 0)
			{
				stream << poly::sign(&coef) << " " << abs(coef);
			}
		}
		else if (coef == 0)
		{

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
	obj.polyarray.resize(4);
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
	polyarray.resize(int(right.polyarray.size()));
	for (int i=0;i<int(right.polyarray.size());i++)
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
	if (int(right.polyarray.size()) > int(polyarray.size()))
	{
		temp.resize(int(right.polyarray.size()));
		for (int i=0;i<int(right.polyarray.size());i++)
		{
			temp[i] = right.polyarray[i];
		}
		int j=0, x=int(right.polyarray.size())-int(polyarray.size());
		for (int i=int(polyarray.size())-1;i>-1;i--)
		{
			temp.at(temp.size()-(j+1)) = ((right.polyarray.at(i+x) + (polyarray.at(i))));
			j++;
		}
	}
	else if (int(polyarray.size()) > int(right.polyarray.size()))
	{
		temp.resize(int(polyarray.size()));
		for (int i=0;i<int(polyarray.size());i++)
		{
			temp[i] = polyarray[i];
		}
		int j=0, x=int(polyarray.size())-int(right.polyarray.size());
		for (int i=int(right.polyarray.size())-1;i>-1;i--)
		{
			temp.at(temp.size()-(j+1)) = ((polyarray.at(i+x) + (right.polyarray.at(i))));
			j++;
		}
	}
	else if (int(polyarray.size()) == int(right.polyarray.size()))
	{
		temp.resize(int(polyarray.size()));
		for (int i=0;i<int(polyarray.size());i++)
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
	if (int(right.polyarray.size()) > int(polyarray.size()))
	{
		temp.resize(int(right.polyarray.size()));
		for (int i=0;i<int(right.polyarray.size());i++)
		{
			temp[i] = right.polyarray[i];
		}
		int j=0, x=int(right.polyarray.size())-int(polyarray.size());
		for (int i=int(polyarray.size())-1;i>-1;i--)
		{
			temp.at(temp.size()-(j+1)) = ((right.polyarray.at(i+x) - (polyarray.at(i))));
			j++;
		}
	}
	else if (int(polyarray.size()) > int(right.polyarray.size()))
	{
		temp.resize(int(polyarray.size()));
		for (int i=0;i<int(polyarray.size());i++)
		{
			temp[i] = polyarray[i];
		}
		int j=0, x=int(polyarray.size())-int(right.polyarray.size());
		for (int i=int(right.polyarray.size())-1;i>-1;i--)
		{
			temp.at(temp.size()-(j+1)) = ((polyarray.at(i+x) - (right.polyarray.at(i))));
			j++;
		}
	}
	else if (int(polyarray.size()) == int(right.polyarray.size()))
	{
		for (int i=0;i<int(polyarray.size());i++)
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
	int x,y;
	if (int(polyarray.size()) < int(right.polyarray.size()))  //finds biggest degree and makes that y
	{
		x=int(polyarray.size())-1;
		y=int(right.polyarray.size())-1;
	}
	else if (int(polyarray.size()) > int(right.polyarray.size()))
	{
		y=int(polyarray.size())-1;
		x=int(right.polyarray.size())-1;
	}
	else	//for if equal
	{
		x=int(polyarray.size())-1;
		y=int(right.polyarray.size())-1;
	}	//create 2 2d arrays for solution and degree markings
	int exp[9][9] = {{000000000},{000000000},{000000000},{000000000},{000000000},{000000000},{000000000},{000000000},{000000000}};
	int darray[9][9] = {{000000000},{000000000},{000000000},{000000000},{000000000},{000000000},{000000000},{000000000},{000000000}};
	vector<int> array;
	for (int i=0;i<x+1;i++)	//for loops calculate every 'square' for darray
	{
		for (int j=0;j<y+1;j++)
		{
			darray[i][j] = (polyarray.at(i) * right.polyarray.at(j));
			exp[i][j] = (y-j)+(x-i);	//exponate level of calculated number
		}
	}
	int count = 0;
	int z = exp[0][0]; //load biggest exponent as starting point
	do{
		for (int i=0;i<x+1;i++) //same loop
		{
			for (int j=0;j<y+1;j++)
			{
				if (exp[i][j] == z) //if the exponent related to the darray number is the same add them into the next slot in the vector
				{
					array.resize(count+1);
					array[count] += (darray[i][j]);
				}
			}
		}
		z--;	//go down one exponent level
		count++;	// increase vector location by one
	}while (z>-1); // loop until exponent level is -1, last possible is 0 for the constaint
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
	if (int(polyarray.size()) != int(right.polyarray.size()))
	{
		return false;
	}
	int x = 0;
	for (int i=0;i<int(polyarray.size());i++)
	{
		if (polyarray[i] == right.polyarray[i])
		{
			x++;
		}
	}
	if (x == int(polyarray.size()) && x == int(right.polyarray.size()))
	{
		return true;
	}
	return false;
}






















