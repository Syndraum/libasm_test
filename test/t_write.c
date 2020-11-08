#include <header.h>

int	u_write(int log, int right, const void *buf, size_t count){
	ssize_t org, your;
	int e_org, e_your;
	int fd_org, fd_your;
	int error = 0;

	fd_org = open("org.txt", right, S_IRWXU);
	fd_your = open("your.txt", right, S_IRWXU);
	dprintf(log, "Testing '%s' %zu\n", buf, count);
	printf("%s '%s' %zu ", TESTING, buf, count);
	fflush(stdout);
	errno = 0;
	org = write(fd_org, buf, count);
	e_org = errno;
	errno = 0;
	your = ft_write(fd_your, buf, count);
	e_your = errno;
	if (org != your || e_org != e_your){
		dprintf(log, " ERROR\twrite return\t: %zd\terrno : %d\n\tYour\t\t: %zd\terrno : %d\n", org, e_org, your, e_your);
		error = 1;
	}
	// else
	// 	dprintf(log, " %zd %d\n", your, e_your);
	close(fd_org);
	close(fd_your);
	remove("org.txt");
	remove("your.txt");
	print_result(error);
	return error;
}

int	t_write(int log){
	int wronly = O_WRONLY | O_CREAT | O_TRUNC;
	int rdonly = O_RDONLY;
	const char * bufs[] = {
		"Bonjour",
		"Bonjour",
		"Bonjour",
		"",
		NULL
	};
	int counts[] = {
		7,
		3,
		10,
		2,
		2
	};
	int size = 5, i = -1, error = 0;;

	print_title(log, "TEST WRITE");
	while (++i < size){
		error += u_write(log, wronly, bufs[i], counts[i]);
	}
	error += u_write(log, rdonly, bufs[0], counts[0]);
	return error;
}