//#include <iostream>

#include "vector3.h"
#include "mathx.h"

#include "randomx.h"

int main(int argc, char** argv)
{
	Vector3 v = Vector3::one;

	std::cout << "gvl test" << std::endl;
	std::cout << v << std::endl;
	std::cout << Mathx::golden << std::endl;

	v *= 0.3f;
	v += Vector3::forward;

	//Randomx::SetSeed(0);

	Vector3 random = Randomx::InsideUnitSphere();

	float g = Randomx::Gaussian();
	std::cout << g << std::endl;
}