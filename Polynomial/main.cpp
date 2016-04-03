//
//  main.cpp
//  Polynomial
//
//  Created by Patrick Kelly on 3/29/16.
//  Copyright © 2016 Patrick Kelly. All rights reserved.
//


#include "main.h"
#include "Polynomial.h"

int main(/*int argc, const char * argv[]*/) {

	poly set4;
	poly set2(5, 3, 6);
	poly set3(3, -9, 1);
	poly set1 = set3;
	set4.set_coefs(-2, 4,-1);
	cout << "Set1: " << set1 << endl;	// always changing
	cout << "Set2: " << set2 << endl;
	cout << "Set3: " << set3 << endl;
	cout << "Set4: " << set4 << endl;
	/*skip line*/
	cout << endl << endl;

	cout << "Test add" << endl << "(" << set2 << ") + (" << set3 << ") =\n";
	set1 = set2 + set3;
	cout << set1 << endl << endl;

	cout << "Test multiply" << endl << "(" << set2 << ") * (" << set3 << ") =\n";
	set1 = set2 * set3;
	cout << set1 << endl << endl;


	//test cin
//	cin >> set1;
//	cout << set1 << endl << endl;

	//test subtraction
	cout << "Test subtraction" << endl << "(" << set2 << ") - (" << set4 << ") =\n";
	set1 = set2 - set4;
	cout << set1 << endl << endl;

	//test bool logic
	cout << "Does set1 == set4\n";
	set1 = set4;
	if (set1 == set4)
	{
		cout << "True\n";
	}
	else
	{
		cout << "False\n";
	}
	cout << endl;
	cout << "Does set1 == set3\n";
	if (set1 == set3)
	{
		cout << "True\n";
	}
	else
	{
		cout << "False\n";
	}
	cout << endl;


	//evaluate poly
	int solution = set2.evaluate(4);
	cout << solution << endl;

	
    return 0;
}
