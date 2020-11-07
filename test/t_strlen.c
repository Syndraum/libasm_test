#include <header.h>

int u_strlen(char *str){
	int org;
	int your;

	org = strlen(str);
	your = ft_strlen(str);
	printf("Testing '%s'\n", str);
	if (org != your){
		printf("ERROR\tstrlen return\t: %d\n\tYour\t\t: %d\n", org, your);
		return 0;
	}
	printf(" %d\n", your);
	return 1;
}

int	u_strcpy(char *str){
	char	*org;
	char	*your;
	int		len;

	len = strlen(str) + 1;
	org = malloc(len);
	strcpy(org, str);
	your = malloc(len);
	ft_strcpy(your, str);
	printf("Testing '%s'\n", str);
	if (strncmp(org, your, len)){
		printf("ERROR\tstrcpy return\t: '%s'\n\tYour\t\t: '%s'\n", org, your);
		free(org);
		free(your);
		return 0;
	}
	printf(" '%s'\n", your);
	free(org);
	free(your);
	return 1;
}

int is_same_sign(int i, int j){
	if (i == 0 && j == 0)
		return 1;
	else if (i < 0 && j < 0)
		return 1;
	else if (i > 0 && j > 0)
		return 1;
	return 0;
}

int	u_strcmp(char *s1, char *s2){
	int org;
	int your;

	org = strcmp(s1, s2);
	your = ft_strcmp(s1, s2);
	printf("Testing '%s' '%s'\n", s1, s2);
	if (!is_same_sign(org, your)){
		printf("ERROR\tstrcmp return\t: %d\n\tYour\t\t: %d\n", org, your);
		return 0;
	}
	printf(" %d\n", your);
	return 1;
}

int t_strlen(){
	printf("TEST STRLEN\n");
	u_strlen("");
	u_strlen("test");
	u_strlen("	");
	u_strlen("jkwsfn0qjqonfonoibnonwf");
	printf("TEST STRCPY\n");
	u_strcpy("jkwsfn0qjqonfonoibnonwf");
	printf("TEST STRCMP\n");
	u_strcmp("", "");
	u_strcmp("a", "a");
	u_strcmp("a", "c");
	u_strcmp("c", "a");
	u_strcmp("abb", "abba");
	u_strcmp("abba", "abb");
	return 1;
}