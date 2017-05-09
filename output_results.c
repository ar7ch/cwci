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

void output_results(char *argc[])
{
  if(english_selected)
  {
    printf("Successfully parsed file %s\n\n", argc[0]);
    if(bytes_opt_selected)
      printf("Bytes: %d\n", bytes_counter);
    if(lines_opt_selected)
      printf("Lines: %d\n", lines_counter);
    if(max_line_len_selected)
      printf("Maximum line length: %d\n", max_line_length);
    if(spaces_opt_selected)
      printf("Spaces: %d\n", spaces_counter);
    if(chars_opt_selected)
      printf("[all visible]Chars: %d\n", chars_counter > 0 ? chars_counter - 1 : chars_counter);
    if(digit_opt_selected)
      printf("Digits: %d\n", digit_counter);
    if(words_opt_selected)
    {
      printf("Words: %d\n", words_counter);
    }
  }
  else
  {
    printf("Файл %s успешно проанализирован\n\n", argc[0]);
    if(bytes_opt_selected)
      printf("Байтов: %d\n", bytes_counter);
    if(lines_opt_selected)
      printf("Строк: %d\n", lines_counter);
    if(max_line_len_selected)
      printf("Максимальная длина строки: %d\n", max_line_length);
    if(spaces_opt_selected)
      printf("Пробелов: %d\n", spaces_counter);
    if(chars_opt_selected)
      printf("[всех видимых]Символов: %d\n", chars_counter > 0 ? chars_counter - 1 : chars_counter);
    if(digit_opt_selected)
      printf("Цифр: %d\n", digit_counter);
    if(words_opt_selected)
    {
      printf("Слов: %d\n", words_counter);
    }
  }
}
