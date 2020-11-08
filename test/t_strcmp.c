#include <header.h>

int is_same_sign(int i, int j){
	if (i == 0 && j == 0)
		return 1;
	else if (i < 0 && j < 0)
		return 1;
	else if (i > 0 && j > 0)
		return 1;
	return 0;
}

int	u_strcmp(int log, const char *s1, const char *s2){
	int org;
	int your;
	int error = 0;

	org = strcmp(s1, s2);
	your = ft_strcmp(s1, s2);
	dprintf(log, "Testing '%s' '%s'\n", s1, s2);
	printf("%s '%s' '%s' ", TESTING, s1, s2);
	if (!is_same_sign(org, your)){
		dprintf(log, " ERROR\tstrcmp return\t: %d\n\tYour\t\t: %d\n", org, your);
		error = 1;
	}
	print_result(error);
	return error;
}

int t_strcmp(int log){
	const char * arg1[] = {
		"",
		"a",
		"a",
		"c",
		"abb",
		"abba",
		NULL
	};
	const char * arg2[] = {
		"",
		"a",
		"c",
		"a",
		"abba",
		"abb",
		NULL
	};
	int i = -1;
	int error = 0;
	print_title(log, "TEST STRCMP");
	while (arg1[++i]){
		error += u_strcmp(log, arg1[i], arg2[i]);
	}
	return error;
}