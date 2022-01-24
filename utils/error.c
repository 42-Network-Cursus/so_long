#include "../head/so_long.h"

void	map_free(char **map)
{
	int i;

	i = 0;
	while (map[i])
		free(map[i++]);
	free(map);
}

void	error(char *msg, t_data *var)
{
	if (var->map)
		map_free(var->map);
	printf("Error.\n");
	printf("%s\n", msg);
	exit(EXIT_SUCCESS);
}