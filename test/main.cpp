
#include <iostream>

#include "sharedLibHeader.h"

using namespace std;

int main()
{
	cout << "Hello world!" << endl;

	sharedLibClass sharedLib;
	sharedLib.test();

	return(0);
}
