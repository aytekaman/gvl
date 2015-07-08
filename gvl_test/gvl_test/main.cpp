#include <iostream>

#include "vector3.h"
#include "mathx.h"

int main(int argc, char** argv)
{
	Vector3 v = Vector3::one;

	std::cout << "gvl test" << std::endl;
	std::cout << v << std::endl;
	std::cout << Mathx::golden << std::endl;
}