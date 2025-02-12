#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

#include "gnl/get_next_line.c"


int	main()
{
	int	fd;
	int	rows;
	//char	*line;
	
	rows = 0;
	fd = open("culo", O_RDONLY);
	while(get_next_line(fd))
	{	
		rows++;
		printf("%d\n", rows);
	}
	close(fd);
	
	//printf("_______\n_______");
	
	fd = open("culo", O_RDONLY);
	printf("%s", get_next_line(fd));
	close(fd);
}
