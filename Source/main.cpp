// Standard
#include <iostream>
#include <string>
// Pyston
#include "Libraries/Pyston/Python.h"
	
using std::cout;
using std::string;

int main(void)
{
	// Initialises the Python interpreter.
	Py_Initialize();

	PyRun_SimpleString("meow = 'Meow!'");

	PyRun_SimpleString("print(meow)");

	return 0;
}
