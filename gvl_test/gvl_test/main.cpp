#include <vector>

#include "mathx.h"
#include "randomx.h"
#include "vector3.h"

int main(int argc, char** argv)
{
	Vector3 v = Vector3::one;

	std::cout << "gvl test" << std::endl;
	std::cout << v << std::endl;
	std::cout << Mathx::golden << std::endl;

	v *= 0.3f;
	v += Vector3::forward;

	Vector3 random = Randomx::InsideUnitSphere();
	random.Set(1,2,3);
	random.Normalize();
	std::cout << random << std::endl;

	float g = Randomx::Gaussian();
	std::cout << g << std::endl;

	Vector3 a = 5;
	std::cout << a << std::endl;

	std::vector<Vector3> randomVectors;

	for(int i = 0; i < 256; i++)
	{
		randomVectors.push_back(Randomx::OnUnitSphere());
	}
}