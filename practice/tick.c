#include "../include/rt.h"

typedef struct projectile_s projectile_t;
typedef struct env_s		env_t;

struct projectile_s
{
	tuple_t	pos;
	tuple_t	velo;
};

struct env_s
{
	tuple_t	gravity;
	tuple_t	wind;
};

projectile_t	tick(env_t env, projectile_t proj);

int	main(void)
{
	projectile_t	proj;
	env_t			env;
	int				i;

	proj.pos = point(0, 0, 0);
	proj.velo = vec_normalize(vector(0, 0, 0));
	// printf("%f", proj.velo); exit(0);

	env.gravity = vector(0, -1, 0);
	env.wind = vector(1, 0, 0);

	// proj = tick(env, proj);
	i = 0;
	// for (; proj.pos.y > 0; proj = tick(env, proj))
	// {
		proj = tick(env, proj);
		printf("tick #%d:\n", i);
		printf("gravity: [%f, %f, %f]\n", env.gravity.x, env.gravity.y, env.gravity.z);
		printf("wind: [%f, %f, %f]\n", env.wind.x, env.wind.y, env.wind.z);
		printf("velo: [%f, %f, %f]\n", proj.velo.x, proj.velo.y, proj.velo.z);
		printf("pos: (%f, %f, %f)\n", proj.pos.x, proj.pos.y, proj.pos.z);
		i++;
		printf("\n");
	// }
}

projectile_t	tick(env_t env, projectile_t proj)
{
	proj.velo = addtup(addtup(proj.velo, env.gravity), env.wind);
	proj.pos = addtup(proj.pos, proj.velo);
	return (proj);
}
