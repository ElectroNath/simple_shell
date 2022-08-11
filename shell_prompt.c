#include "main.h"

/**
 * shell_prompt - call prompt from another function (prompt)
 *
 **/
void shell_prompt(void)
{
	for (;;)
	{
		char *text = NULL, **environ;
		pid_t child_pid;
		int status, lenbuf;
		size_t bufsize = 0;

		place("$ ");
		lenbuf = getline(&text, &bufsize, stdin);
		if (lenbuf == -1)
			exit(98);
		if (findslashExit(text, "exit") == 0)
			exit(0);
		if (findslashEnv(text, "env") == 0)
		{
			while (*environ != NULL)
			{
				if (!(_strcmprdir(*environ, "USER")) ||
						!(_strcmprdir(*environ, "LANGUAGE")) ||
						!(_strcmprdir(*environ, "SESSION")) ||
						!(_strcmprdir(*environ, "COMPIZ_CONFIG_PROFILE")) ||
						!(_strcmprdir(*environ, "SHLV")) ||
						!(_strcmprdir(*environ, "HOME")) ||
						!(_strcmprdir(*environ, "C_IS")) ||
						!(_strcmprdir(*environ, "DESKTOP_SESSION")) ||
						!(_strcmprdir(*environ, "LOGNAME")) ||
						!(_strcmprdir(*environ, "TERM")) ||
						!(_strcmprdir(*environ, "PATH")))
				{
					place(*environ), place("\n"); }
				environ++; }}
		child_pid = fork();
		if (child_pid < 0)
			perror("Error");
		if (child_pid == 0)
			keysInit(text);
		else
			wait(&status);
	}}
