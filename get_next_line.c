#include <unistd.h>
#include <stdlib.h>
#include <stddef.h>
#include <fcntl.h> 
#include <stdio.h>

int main()
{
	int		fd;
	char	buf[50];
	int		n;

	fd = open("text.txt", O_RDONLY);
	if (fd < 0)
		return (1);

	n = read(fd, buf, 35);
	if (n < 0)
	{
		perror("read");
		close(fd);
		return (1);
	}
	buf[n] = '\0';
	printf("%s", buf);
	close(fd);
	return (0);
}
