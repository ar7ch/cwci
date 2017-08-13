#include <cwci.h>
#include <stdio.h>
#include <stdlib.h>

void error (char * error_msg, char * error_object)
{
	if (error_object != NULL)
		fprintf (stderr, "%s: %s: %s\n", EXEC_NAME, error_object, error_msg);
	else
		fprintf (stderr, "%s: %s\n", EXEC_NAME, error_msg);
	exit(0);
}