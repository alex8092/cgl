#include "fs/file.h"

#if defined __unix__

	# include <sys/stat.h>
	# include <fcntl.h>
	# include <stdlib.h>
	# include <stdio.h>
	# include <unistd.h>

	static int	read_secure(int fd, char *buffer, size_t size)
	{
		const ssize_t	ret = read(fd, buffer, size);

		if (ret < 0 || (size_t)ret > size)
		{
			perror("read");
			return (-1);
		}
		else if ((size_t)ret == size)
			return (0);
		return (read_secure(fd, buffer + ret, size - ret));
	}

	char		*cgl_fs_read_file(const char *file, uint64_t *size)
	{
		char		*buffer = 0;
		struct stat	st;
		int			fd = -1;

		if (stat(file, &st) == -1)
		{
			perror("stat");
			return (0);
		}
		else if (access(file, F_OK | R_OK) == -1)
		{
			perror("access");
			return (0);
		}
		buffer = malloc(sizeof(char) * (st.st_size + 1));
		if (!buffer)
		{
			dprintf(2, "Cannot allocate memory for file\n");
			return (0);
		}
		fd = open(file, O_RDONLY);
		if (fd == -1 || read_secure(fd, buffer, st.st_size) == -1)
		{
			free(buffer);
			return (0);
		}
		buffer[st.st_size] = 0;
		if (size)
			*size = (uint64_t)st.st_size;
		close(fd);
		return (buffer);
	}

#endif