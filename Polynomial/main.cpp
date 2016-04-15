//
//  main.cpp
//  Polynomial
//
//  Created by Patrick Kelly on 3/29/16.
//  Copyright © 2016 Patrick Kelly. All rights reserved.
//
/* -----------------------------------------------------------------------------

 FILE:              main.cpp

 DESCRIPTION:       driver for poly class

 COMPILER:          GNU++11

 NOTES:             

 MODIFICATION HISTORY:

 Author                  Date               Version
 ---------------         ----------         --------------
 Patrick Kelly			 2016-1-04			X.X (git source control)

 ----------------------------------------------------------------------------- */
//header files
#include <iostream>

//personal header files
#include "My_Macros.h"
#include "Polynomial.h"

/* -----------------------------------------------------------------------------
 FUNCTION:          main()
 DESCRIPTION:       driver for poly class
 RETURNS:           0
 NOTES:
 ----------------------------------------------------------------------------- */
int main(/*int argc, const char * argv[]*/)
{
	poly set2(5, 3);
	poly *set3;
	set3 = new poly;
	set3->set_coefs(3, -9, 1);
	poly set1 = *set3;
	poly *set4;
	set4 = new poly;
	set4->set_coefs(-2, 4,-1,-3);
	//polynomial of any length
	const int size = 4;
	int array[size] = {4,-3,2,-6};
	poly set5(array, size);
	vector<int> array_b = {-3,-5,6,3};
	poly set6(&array_b);

	poly *set10 = &set5;

	cout << "Set1: " << set1 << endl;	// always changing
	cout << "Set2: " << set2 << endl;
	cout << "Set3: " << *set3 << endl;
	cout << "Set4: " << *set4 << endl;
	cout << "Set5: " << *set10 << endl;
	cout << "Set6: " << set6 << endl;
	/*skip line*/
	cout << endl << endl;

	cout << "Test add" << endl << "(" << set2 << ") + (" << *set3 << ") =\n";
	set1 = set2 + *set3;
	cout << set1 << endl;
	cout << "Test add" << endl << "(" << *set3 << ") + (" << set5 << ") =\n";
	set1 = *set3 + set5;
	cout << set1 << endl;
	cout << "Test add" << endl << "(" << set6 << ") + (" << *set4 << ") =\n";
	set1 = set6 + *set4;
	cout << set1 << endl;

	cout << "Test multiply" << endl << "(" << set2 << ") * (" << *set3 << ") =\n";
	set1 = set2 * (*set3);
	cout << set1 << endl << endl;
	cout << "Test multiply" << endl << "(" << *set10 << ") * (" << set6 << ") =\n";
	set1 = set5 * set6;
	cout << set1 << endl << endl;


	//test cin
	cin >> set1;
	cout << set1 << endl << endl;

	//test subtraction
	cout << "Test subtraction" << endl << "(" << set2 << ") - (" << set5 << ") =\n";
	set1 = set2 - set5;
	cout << set1 << endl << endl;
	set1 = set5 - *set3;
	cout << set1 << endl << endl;


	//test bool logic
	cout << "Does set1 == set4\n";
	set1 = *set4;
	if (set1 == *set4)
	{
		cout << "True\n";
	}
	else
	{
		cout << "False\n";
	}
	cout << endl;
	cout << "Does set1 == set3\n";
	if (set1 == *set3)
	{
		cout << "True\n";
	}
	else
	{
		cout << "False\n";
	}
	cout << endl;


	//evaluate polynomial
	cout << "Set2 = " << "(" << set2 << ")\n"  << "evaluated at 4 = " << set2.evaluate(4) << endl << endl;
	cout << "Set5 = " << "(" << set5 << ")\n"  << "evaluated at 2 = " << set5.evaluate(2) << endl << endl;

	delete set3;
	delete set4;
    return 0;
}
