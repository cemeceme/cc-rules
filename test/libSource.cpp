

#include "libHeader.h"

#include <iostream>

#include "genHeader.h"

using namespace std;

void libClass::test()
{
	cout << "libClass.test() call." << endl;
	
	genClass gen;
	gen.test();
}