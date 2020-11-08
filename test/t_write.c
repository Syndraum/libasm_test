#include <header.h>

int	u_write(int log, int right, const void *buf, size_t count){
	int org, your;
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
		dprintf(log, "ERROR\twrite return\t: %d\terrno : %d\n\tYour\t\t: %d\terrno : %d\n", org, e_org, your, e_your);
		error = 1;
	}
	else
		dprintf(log, " %d %d\n", your, e_your);
	print_result(error);
	return error;
}

int	t_write(int log){
	int wronly = O_WRONLY | O_CREAT | O_TRUNC;
	int rdonly = O_RDONLY;
	const char * bufs[] = {
		"",
		NULL
	};
	int counts[] = {
		2,
		2
	};
	int size = 2, i = -1, error = 0;;

	print_title(log, "TEST WRITE");
	u_write(log, wronly, "a ", 2);
	u_write(log, wronly, NULL, 2);
	return 0;
	while (++i < size){
		error += u_write(log, wronly, bufs[i], counts[i]);
	}
	return error;
}