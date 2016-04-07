//
//  Polynomial.hpp
//  Polynomial
//
//  Created by Patrick Kelly on 3/30/16.
//  Copyright © 2016 Patrick Kelly. All rights reserved.
//
/* -----------------------------------------------------------------------------

 FILE:              Polynomial.h

 DESCRIPTION:       header file for poly class

 COMPILER:          GNU++11

 NOTES:             Put other information here ...

 MODIFICATION HISTORY:

 Author                  Date               Version
 ---------------         ----------         --------------
 Patrick Kelly			 2016-1-04			X.X (git source control)

 ----------------------------------------------------------------------------- */
#ifndef Polynomial_h
#define Polynomial_h

#include <stdio.h>
#include <iostream>
#include <vector>
#include <cmath>

using std::cout;
using std::vector;
using std::ostream;
using std::istream;
using std::endl;

class poly
{
	vector<int> polyarray;
	int *degree;
public:
		//constructors
	poly();
	poly(int _a, int _b, int _c = 999, int _d = 999, int _e = 999, int _f = 999);//for standard numbers
	poly(const int *array, int n);	//for arrays
	poly(const vector<int> *array);	//for vectors
		//copy
	poly(const poly &obj);
		//destructor
	~poly();
		//member functions
	void set_coefs (int, int, int, int _d =999);
	double evaluate (const int) const;
		//operator overloads
	//IO
	friend ostream &operator<< (ostream &stream, const poly &obj); //output
	friend istream &operator>> (istream &stream, poly &obj); //input
	//equals
	poly operator= (const poly &right);
	//math
	poly operator+ (const poly &);
	poly operator- (const poly &);
	poly operator* (const poly &);
	//bool check
	bool operator== (const poly &);

private:
	static char sign (int *) ; //for ostream overload
	void verify_size (); //resizes vector size if needed. 
};
#endif /* Polynomial_h */
