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

#include <cwci.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void initialize_parameters(int *argc, char **argv[])
{
  char ch;
  while((ch = getopt(*argc, *argv, "wbcsidhlgL")) != EOF)
  {
    switch(ch){
      case 'w':
        opts_selected->words_opt_selected = true;
        break;
      case 'b':
        opts_selected->bytes_opt_selected = true;
        break;
      case 'L':
        opts_selected->max_line_len_selected = true;
        break;
      case 'i':
        opts_selected->standard_input_selected = true;
        break;
      case 'c':
        opts_selected->chars_opt_selected = true;
        break;
      case 's':
        opts_selected->spaces_opt_selected = true;
        break;
      case 'd':
        opts_selected->digit_opt_selected = true;
        break;
      case 'h':
        print_help();
      case 'l':
        opts_selected->lines_opt_selected = true;
        break;
      case 'g':
        opts_selected->greeting_opt_selected = true;
        break;
      default:
        exit(1); //no need for error(), getopt() will output the error
    }
  }
    *argc -= optind;
    if(optind > 1)
      *argv += optind;
    if(*argc == 1 && optind == 1)
    {
      if(opts_selected->english_selected)
        error("error: no operation specified (-h for help)\n", NULL);
      else
        error("ошибка: не указана операция (-h для справки)\n", NULL);
    }
    if(*argc == 0 && !opts_selected->help_opt_selected)
    {
      if(opts_selected->english_selected)
        error("error: expected filename, quoutes-delimited character sequence or full path to file (-h for help)\n", NULL);
      else
        error("ошибка: ожидалось имя файла, последовательность символов в кавычках или полный путь до файла (-h для справки)\n", NULL);
    }
}
