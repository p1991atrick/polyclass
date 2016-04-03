//
//  Polynomial.hpp
//  Polynomial
//
//  Created by Patrick Kelly on 3/30/16.
//  Copyright © 2016 Patrick Kelly. All rights reserved.
//

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
	poly(int _a, int _b, int _c, int _d = 999, int _e = 999, int _f = 999);
	//copy
	poly(const poly &obj);
	//destructor
	~poly();
	//member functions
	void set_coefs (int, int, int);
	int evaluate (int);
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
	//evaluate

private:
	static char sign (int *);
	void verify_size ();
};
#endif /* Polynomial_h */
