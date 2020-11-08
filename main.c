#include <header.h>

int main(int argc, char const *argv[])
{
	int log;

	log = open("log.txt", O_WRONLY | O_CREAT | O_TRUNC, S_IRWXU);
	t_strlen(log);
	t_strcpy(log);
	t_strcmp(log);
	t_write(log);
	close(log);
	return 0;
}