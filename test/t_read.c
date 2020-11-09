#include <header.h>

int	u_read(int log, int right, void *buf, size_t count){
	ssize_t	org, your;
	int		e_org, e_your;
	int		fd_org, fd_your;
	char	*s_org = 0, *s_your = 0;
	int		error = 0;

	fd_org = open("read_test", right);
	fd_your = open("read_test", right);
	dprintf(log, "Testing '%s' %zu\n", buf, count);
	printf("%s '%s' %zu ", TESTING, buf, count);
	fflush(stdout);
	errno = 0;
	org = read(fd_org, buf, count);
	e_org = errno;
	s_org = strdup(buf);
	errno = 0;
	memset(buf, 0, 7);
	your = ft_read(fd_your, buf, count);
	e_your = errno;
	s_your = strdup(buf);
	close(fd_org);
	close(fd_your);
	if (org != your || e_org != e_your){
		dprintf(log, " ERROR\tread return\t: %zd\terrno : %d\n\tYour\t\t: %zd\terrno : %d\n", org, e_org, your, e_your);
		error = 1;
	}
	if (s_your && s_org){
		if (strcmp(s_your, s_org)){
			dprintf(log, " ERROR\tread buf\t: %s\n\tYour\t\t: %s\n", s_org, s_your);
			error = 1;
		}
	}
	free(s_org);
	free(s_your);
	print_result(error);
	return error;
}

int	t_read(int log){
	int		wronly = O_WRONLY;
	int		rdonly = O_RDONLY;
	char	*buf;
	int		counts[] = {
		7,
		3,
		10,
		2,
		0
	};
	int size = 5, i = -1, error = 0;;

	buf = malloc(7);
	print_title(log, "TEST READ");
	while (++i < size){
		memset(buf, 0, 7);
		error += u_read(log, rdonly, buf, counts[i]);
	}
	error += u_read(log, wronly, buf, counts[0]);
	free(buf);
	return error;
}