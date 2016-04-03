//
//  main.cpp
//  Polynomial
//
//  Created by Patrick Kelly on 3/29/16.
//  Copyright © 2016 Patrick Kelly. All rights reserved.
//


#include "main.h"
#include "Polynomial.h"

int main(int argc, const char * argv[]) {

	poly set1;
	poly set2(5, 3, 6);
	poly set3(3, 9, 1);
	set1 = set3;
	cout << set1 << endl;
	cout << set2 << endl;
	cout << set3 << endl;
	set1 = set2 + set3;
	cout << set1 << endl;
	set1 = set2 * set3;
	cout << set1 << endl;
    return 0;
}
