#pragma once

struct Vector2;
struct Vector3;

class Randomx
{
public:
	static int		Range(int min, int max);
	static float	Range(float min, float max);

	static float	Gaussian(float mean = 0, float std = 1);

	static Vector3	InsideUnitSphere();
	static Vector2	InsideUnitCircle();

	static Vector3	OnUnitSphere();
	static Vector2	OnUnitCircle();

	static void		SetSeed(unsigned int seed);
	static unsigned int	GetSeed();

private:
	static bool		toggle;
	static unsigned int	seed;
};