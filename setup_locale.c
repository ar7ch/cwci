#include "libwc.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <wctype.h>
#include <wchar.h>
#include <locale.h>

void setup_locale()
{
  char locale[3];
  select:
  printf("Select language/Выберите язык [en/ru]: ");
  scanf("%2s", locale);
  locale[0] = tolower(locale[0]);
  locale[1] = tolower(locale[1]);
  if(!strcmp(locale, "ru"))
    english_selected = false;
  else if(!strcmp(locale, "en"))
    english_selected = true;
  else
    goto select;
}
