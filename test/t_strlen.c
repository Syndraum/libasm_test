#include <header.h>

int u_strlen(int log, const char *str){
	int org;
	int your;
	int error = 0;

	org = strlen(str);
	your = ft_strlen(str);
	dprintf(log, "Testing '%s'\n", str);
	printf("%s '%s' ", TESTING, str);
	if (org != your){
		dprintf(log, " ERROR\tstrlen return\t: %d\n\tYour\t\t: %d\n", org, your);
		error = 1;
	}
	else
		dprintf(log, " %d\n", your);
	print_result(error);
	return error;
}

int t_strlen(int log){
	const char * array[] = {
		"",
		"test",
		"	",
		"jkwsfn0qjqonfonoibnonwf",
		NULL
	};
	int i = -1;
	int error = 0;

	print_title(log, "TEST STRLEN");
	while (array[++i]){
		error += u_strlen(log, array[i]);
	}
	// print_result(error);
	return error;
}