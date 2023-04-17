#include <stdio.h>
#include <stdlib.h>
#include "get_next_line.h"
#include <fcntl.h>

int main(int argc, char *argv[])
{
	char	*ret;
	int		fd;
	int		fd1;
	int		fd2;
	size_t	i;

	//-------- MANDATORY PART TEST --------//
	if (argc < 2)
	{
		printf("PLEASE INPUT FILE");
		return (0);
	}
	while (*(++argv))
	{
		i = 0;
		fd = open(*argv, O_RDONLY);
		while ((ret = get_next_line(fd)))
		{
			printf("%zu: %s", i++, ret);
			free(ret);
		}
		close(fd);
		printf("\n----\n");
	}

	//-------- BONUS PART TEST --------//
	// if (argc < 3)
	// {
	//  printf("PLEASE INPUT FILE");
	//  return (0);
	// }
	// fd1 = open(argv[1], O_RDONLY);
	// fd2 = open(argv[2], O_RDONLY);
	// i = 0;
	// while (i < 6)
	// {
	//  ret = get_next_line(fd1);
	//  printf("%zu: %s", i, ret);
	//  free(ret);


	//  ret = get_next_line(fd2);
	//  printf("%zu: %s", i++, ret);
	//  free(ret);
	// }
	// close(fd1);
	// close(fd2);

	return (0);
}

__attribute__((destructor))
static void destructor() {
	system("leaks -q a.out");
}
