/*
This is free software: you are free to change and redistribute it.
There is NO WARRANTY, to the extent permitted by law.
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <wctype.h>
#include <wchar.h>
#include <locale.h>
#include "libwc.h"

const char * EXEC_NAME;
int main(int argc, char *argv[])
{
  setlocale(LC_ALL, "");
  EXEC_NAME = argv[0];
  setup_locale();
  initialize_parameters(&argc, &argv);
  wc_engine(argc, argv);
  output_results(argv);
  return 0;
}
