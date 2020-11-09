#include <header.h>

t_cmp	*filecmp(int f1, int f2){
	t_cmp	*cmp;

	cmp = malloc(sizeof(t_cmp));
	cmp->line = 0;
	cmp->line1 = NULL;
	cmp->line2 = NULL;
	cmp->diff = 0;
	while (get_next_line(f1, &cmp->line1) > 0 || get_next_line(f2, &cmp->line2) > 0)
	{
		(cmp->line)++;
		cmp->diff = strcmp(cmp->line1, cmp->line2);
		free (cmp->line1);
		free (cmp->line2);
		if(cmp->diff)
			return cmp;

	}
	cmp->diff = strcmp(cmp->line1, cmp->line2);
	free (cmp->line1);
	free (cmp->line2);
	return cmp;
}

int	u_write(int log, int right, const void *buf, size_t count){
	ssize_t	org, your;
	t_cmp	*cmp;
	int		e_org, e_your;
	int		fd_org, fd_your;
	int		error = 0;

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
	close(fd_org);
	close(fd_your);
	fd_org = open("org.txt", O_RDONLY);
	fd_your = open("your.txt", O_RDONLY);
	if (e_org == 0){
		cmp = filecmp(fd_org, fd_your);
		if (cmp->diff){
			dprintf(log, " ERROR\torg file\t: '%s'\n\tYour file\t: '%s'\n", cmp->line1, cmp->line2);
			error = 1;
		}
		free(cmp);
	}
	if (org != your || e_org != e_your){
		dprintf(log, " ERROR\twrite return\t: %zd\terrno : %d\n\tYour\t\t: %zd\terrno : %d\n", org, e_org, your, e_your);
		error = 1;
	}
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
		"Bonjour",
		"",
		NULL
	};
	int counts[] = {
		7,
		3,
		10,
		0,
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