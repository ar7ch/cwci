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
#include "libwc.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <wctype.h>
#include <wchar.h>
#include <locale.h>

void wc_engine(int argc, char *argv[])
{
  wchar_t current_char;
  bool word_flag = false;
  bool number_flag = false;
  int word_len_counter = 0;
  int ch;
    FILE *file_to_read;
    if(!(file_to_read = fopen(argv[0], "r")))
    {
      if(english_selected)
        fprintf(stderr, "%s: no such file \"%s\"\n", EXEC_NAME, argv[0]);
        else
        fprintf(stderr, "%s: нет такого файла \"%s\"\n", EXEC_NAME, argv[0]);
        exit(3);
    }
  /*for(int i = 0; i < argc; i++){
    char ch[] = argv[i];
    for(int j = 0; ch[j] != '\0'; i++)  }*/
  if(greeting_opt_selected)
    greeting();
  if(help_opt_selected)
    print_help();
  while((ch = fgetwc(file_to_read)) != EOF)
  {
    current_char = ch;
    if(iswalpha(current_char) && (letters_opt_selected || words_opt_selected))
    {
      if(letters_opt_selected)
        letters_counter++;
      if(words_opt_selected)
      {
        word_flag = true;
        word_len_counter++;
      }
    }
    if(words_opt_selected && word_flag && !iswalpha(current_char))
    {
      words_counter++;
      word_flag = false;
      if(word_len_counter > max_word_length)
        max_word_length = word_len_counter;
      word_len_counter = 0;
    }

    if(iswdigit(current_char) && (digit_opt_selected || number_opt_selected))
    {
      if(digit_opt_selected)
        digit_counter++;
      if(number_opt_selected)
      {
        number_flag = true;
      }
    }
    if(number_opt_selected && number_flag && !iswdigit(current_char))
    {
      number_counter++;
      number_flag = false;
    }
    if(bytes_opt_selected)
      {
        if(ch > 127 || ch < -128)
          bytes_counter += sizeof(wchar_t) / 2; //looks like size is calculated like this
        else
          bytes_counter += sizeof(char);
      }
    if(chars_opt_selected)
      chars_counter++;
    if(spaces_opt_selected)
    {
      if(current_char == ' ')
      {
        spaces_counter++;
      }
    }
    if(lines_opt_selected)
    {
      if(current_char == '\n')
        lines_counter++;
    }
  }
if(!standard_input_selected)
  fclose(file_to_read);
//else
  //free(str_to_read);
}
