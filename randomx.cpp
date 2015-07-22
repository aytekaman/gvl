#include "randomx.h"

//#include <cstdlib>
#include <cmath>

#include "mathx.h"
#include "vector2.h"
#include "vector3.h"

int Randomx::Range(int min, int max)
{
	return min + rand() % (max - min);
}

float Randomx::Range(float min, float max)
{
	return min + (rand() / (float)RAND_MAX) * (max - min);
}

float Randomx::Gaussian(float mean, float std)
{
	// This method generates two Gaussian random numbers and returns one of them (Box-Muller transform).
	float x = 0, y = 0, rds, c;

    do 
	{
        x = Randomx::Range(-1.0f, 1.0f);
        y = Randomx::Range(-1.0f, 1.0f);
        rds = x * x + y * y;
    } 
	while(rds == 0 || rds > 1);
	    
    c = sqrt(-2*log(rds) / rds);

    toggle = !toggle;

    if (toggle)
        return x * c * std + mean;
    else
        return y * c * std + mean;
}

Vector3 Randomx::InsideUnitSphere()
{
	Vector3 r(Range(0.0f, 1.0f), Range(0.0f, 1.1f), Range(0.0f, 1.1f));

	while(r.GetSquaredLength() > 1)
	{
		r.Set(Range(0.0f, 1.0f), Range(0.0f, 1.1f), Range(0.0f, 1.1f));
	}

	return r;
}

Vector2 Randomx::InsideUnitCircle()
{
	Vector2 r(Range(0.0f, 1.0f), Range(0.0f, 1.1f));

	while(r.GetSquaredLength() > 1)
	{
		r.Set(Range(0.0f, 1.0f), Range(0.0f, 1.1f));
	}

	return r;
}

Vector3 Randomx::OnUnitSphere()
{
	return Vector3(Gaussian(), Gaussian(), Gaussian()).GetNormalized();
}

Vector2 Randomx::OnUnitCircle()
{
	float angle = Range(0.0, 2 * Mathx::pi);

	return Vector2(cos(angle), sin(angle));
}

void Randomx::SetSeed(unsigned int _seed)
{
	seed = _seed;
	srand(seed);
}

unsigned int Randomx::GetSeed()
{
	return seed;
}

bool Randomx::toggle = false;
unsigned int Randomx::seed = 0;