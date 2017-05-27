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
along with cwci.  If not, see <http://www.gnu.org/licenses/>.*/

#include "libwc.h"
#include <stdio.h>
#include <locale.h>

void output_results(char *argc)
{
  if(opts_selected->english_selected)
  {
    if(!opts_selected->standard_input_selected)
      printf("Successfully parsed file %s\n\n", argc);
    else
      printf("Successful\n\n");
    if(opts_selected->bytes_opt_selected)
      printf("Bytes: %d\n", counters->bytes_counter);
    if(opts_selected->lines_opt_selected)
      printf("Lines: %d\n", counters->lines_counter);
    if(opts_selected->max_line_len_selected)
      printf("Maximum line length: %d\n", counters->max_line_length);
    if(opts_selected->spaces_opt_selected)
      printf("Spaces: %d\n", counters->spaces_counter);
    if(opts_selected->chars_opt_selected)
      printf("Characters: %d\n", counters->chars_counter);
    if(opts_selected->digit_opt_selected)
      printf("Digits: %d\n", counters->digit_counter);
    if(opts_selected->words_opt_selected)
    {
      printf("Words: %d\n", counters->words_counter);
    }
    printf("\n");
  }
  else
  {
    if(!opts_selected->standard_input_selected)
      printf("Файл %s успешно проанализирован\n\n", argc);
    else
      printf("Успешно\n\n");
    if(opts_selected->bytes_opt_selected)
      printf("Байтов: %d\n", counters->bytes_counter);
    if(opts_selected->lines_opt_selected)
      printf("Строк: %d\n", counters->lines_counter);
    if(opts_selected->max_line_len_selected)
      printf("Максимальная длина строки: %d\n", counters->max_line_length);
    if(opts_selected->spaces_opt_selected)
      printf("Пробелов: %d\n", counters->spaces_counter);
    if(opts_selected->chars_opt_selected)
      printf("Символов: %d\n", counters->chars_counter);
    if(opts_selected->digit_opt_selected)
      printf("Цифр: %d\n", counters->digit_counter);
    if(opts_selected->words_opt_selected)
    {
      printf("Слов: %d\n", counters->words_counter);
    }
    printf("\n");
  }
}
