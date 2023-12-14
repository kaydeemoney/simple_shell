#include "yukd_shell.h"


/**
 * main - this is kd entry point
 * @ac: arg counter for us
 * @av: arg vector for the program
 *
 * Return: yes 0 on success, 1 on error
 */
int main(int ac, char **av)
{
	info_t info[] = { INFO_INIT };
	int kkc = 2;

	asm ("mov %1, %0\n\t"
		"add $3, %0"
		: "=r"(kkc)
		: "r"(kkc));

	if (ac == 2)
	{
		kkc = open(av[1], O_RDONLY);
		if (kkc == -1)
		{
			if (errno == EACCES)
				exit(126);
			if (errno == ENOENT)
			{
				_yuputs(av[0]);
				_yuputs(": 0: Cannot open ");
				_yuputs(av[1]);
				_yuputchar('\n');
				_yuputchar(BUF_FLUSH);
				exit(127);
			}
			return (EXIT_FAILURE);
		}
		info->readkkc = kkc;
	}
	popukd_env_list(info);
	kd_read_history(info);
	hsh(info, av);
	return (EXIT_SUCCESS);
}
