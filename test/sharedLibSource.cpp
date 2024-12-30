
#include "sharedLibHeader.h"

#include <iostream>

#include "libHeader.h"
#include "genHeader.h"

using namespace std;

void sharedLibClass::test()
{
	cout << "sharedLibClass.test() call." << endl;

	libClass lib;
	lib.test();

	genClass gen;
	gen.test();
}