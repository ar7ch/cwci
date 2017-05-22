/*This file is part of cwci.

Cwci is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

Cwci is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with Cwci.  If not, see <http://www.gnu.org/licenses/>.*/

#include "libwc.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>
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
    opts_selected->english_selected = false;
  else if(!strcmp(locale, "en"))
    opts_selected->english_selected = true;
  else
    goto select;
}
