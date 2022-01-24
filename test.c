#include "gnl/get_next_line.h"
#include "libft/libft.h"
#include <stdio.h>
#include <fcntl.h>


int i = 0;
	while (map[i])
	{
		printf("%s\n", map[i]);
		i++;
	}

int main()
{
    int fd = open("maps/map.ber", O_RDONLY);
/*
    char *line;
	char *tmp1;
	char *tmp2;
	tmp1 = get_next_line(fd);
	while (1)
	{
		tmp2 = get_next_line(fd);
		if (!tmp2)
		{
			//free (tmp2);
			break ;
		}
		line = ft_strjoin(tmp1, tmp2);
		free(tmp1);
		free(tmp2);
	}
	printf("line = %s\n", line);
	char **map;
	map = ft_split(line, '\n');
	free(line);
	int i = 0;
	while (map[i])
		printf("map = %s", map[i++]);
	printf("\n");
	i = 0;
	while (map[i])
		free(map[i++]);
	//free(map[i]);
	free(map);
	*/
    return (0);
}