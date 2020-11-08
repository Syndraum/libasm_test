#include <header.h>

int	u_strcpy(int log, const char *str){
	char	*org;
	char	*your;
	int		len;

	len = strlen(str) + 1;
	org = malloc(len);
	strcpy(org, str);
	your = malloc(len);
	ft_strcpy(your, str);
	dprintf(log, "Testing '%s'\n", str);
	printf("%s '%s' ", TESTING, str);
	if (strncmp(org, your, len)){
		dprintf(log, " ERROR\tstrcpy return\t: '%s'\n\tYour\t\t: '%s'\n", org, your);
		print_result(1);
		free(org);
		free(your);
		return 1;
	}
	dprintf(log, " '%s'\n", your);
	print_result(0);
	free(org);
	free(your);
	return 0;
}

int	t_strcpy(int log){
	const char * array[] = {
		"",
		"test",
		"	",
		"jkwsfn0qjqonfonoibnonwf",
		NULL
	};
	int i = -1;
	int error = 0;

	print_title(log, "TEST STRCPY");
	while (array[++i]){
		error += u_strcpy(log, array[i]);
	}
	// print_result(error);
	return error;
}