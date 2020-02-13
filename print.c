#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

void	print(char *i)
{
	int fd;

	fd = open("./useless", O_CREAT | O_TRUNC | O_RDWR, S_IRWXO);
	dprintf(fd, "%s\n", i);
	close (fd);
}