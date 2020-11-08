#include "header.h"

int	u_strdup(int log, char *str){
	char	*org;
	char	*your;
	int		error = 0;

	org = strdup(str);
	your = ft_strdup(org);
	dprintf(log, "Testing '%s'\n", str);
	printf("%s '%s' ", TESTING, str);
	if (strcmp(org, your)){
		error = 1;
		dprintf(log, " ERROR\tstrlen return\t: %s\n\tYour\t\t: %s\n", org, your);
	}
	if (strlen(org) > 0){
		org[0]++;
		if (!strcmp(org, your))
		{
			error = 1;
			dprintf(log, " ERROR\tYou do not make allocation\n");
		}
	}
	free(org);
	free(your);
	print_result(error);
	return (error);
}

int	t_strdup(int log){
	char * array[] = {
		"",
		"test",
		"	",
		"jkwsfn0qjqonfonoibnonwf",
		NULL
	};
	int i = -1;
	int error = 0;

	print_title(log, "TEST STRDUP");
	while (array[++i]){
		error += u_strdup(log, array[i]);
	}
	return error;
}