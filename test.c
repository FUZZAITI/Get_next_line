#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h> // para o strcpy


#ifndef BUFFER_SIZE
# define BUFFER_SIZE 10
#endif

void test(int fd);
int main(void)
{
	int		fd;
	char	*line;
    int     n;

	fd = open("text.txt", O_RDONLY);
	if (fd < 0)
	{
		perror("open");
		return (1);
	}
	line = malloc(BUFFER_SIZE + 1);
	n = read(fd, line, BUFFER_SIZE);
	line[n] = '\0';
	printf("%s", line);
    n = read(fd, line, BUFFER_SIZE);
	line[n] = '\0';
	printf("%s", line);
    test(fd);
	close(fd);
	return (0);
}

void test(int fd)
{
    char  *line2;
    int     n;

    line2 = malloc(BUFFER_SIZE + 1);
    n = read(fd, line2, BUFFER_SIZE);
    line2[n] = '\0';
	printf("%s", line2);
    n = read(fd, line2, BUFFER_SIZE);
	line2[n] = '\0';
	printf("%s", line2);

}
