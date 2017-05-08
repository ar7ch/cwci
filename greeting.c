#include "libwc.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <wctype.h>
#include <wchar.h>
#include <locale.h>

void greeting()
{
  if(english_selected)
    printf("Hello, %s!\n", getlogin());
  else
    printf("Привет, %s!\n", getlogin());
}
