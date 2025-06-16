#include "mini_rt.h"

t_projectile	*create_projectile(t_tuples *position, t_tuples *velocity)
{
	t_projectile	*proj;

	proj = malloc(sizeof(t_projectile));
	if (!proj)
		return (NULL);
	proj->position = position;
	proj->velocity = velocity;
	return (proj);
}

t_environment	*create_environment(t_tuples *gravity, t_tuples *wind)
{
	t_environment	*env;

	env = malloc(sizeof(t_environment));
	if (!env)
		return (NULL);
	env->gravity = gravity;
	env->wind = wind;
	return (env);
}

t_projectile	*tick(t_environment *env, t_projectile *proj)
{
	t_projectile *new_projectile;
	t_tuples *new_pos;
	t_tuples *new_velocity;
	t_tuples *tmp;

	new_pos = tup_add(proj->position, proj->velocity);
	tmp = tup_add(proj->velocity, env->gravity);
	new_velocity = tup_add(tmp, env->wind);
	free(tmp);
	new_projectile = create_projectile(new_pos, new_velocity);
	free(proj->position);
	free(proj->velocity);
	free(proj);
	return (new_projectile);
}
