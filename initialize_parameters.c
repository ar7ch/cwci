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
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <wctype.h>
#include <wchar.h>
#include <locale.h>

void initialize_parameters(int *argc, char **argv[])
{
  char ch;
  while((ch = getopt(*argc, *argv, "wbcsidnhtlgL")) != EOF)
  {
    switch(ch){
      case 'w':
        words_opt_selected = true;
        break;
      case 'b':
        bytes_opt_selected = true;
        break;
      case 'L'
        max_line_len_selected = true;
        break;
      case 'i':
        standard_input_selected = true;
        break;
      case 'c':
        chars_opt_selected = true;
        break;
      case 's':
        spaces_opt_selected = true;
        break;
      case 'd':
        digit_opt_selected = true;
        break;
      case 'n':
        number_opt_selected = true;
        break;
      case 'h':
        help_opt_selected = true;
        break;
      case 't':
        letters_opt_selected = true;
        break;
      case 'l':
        lines_opt_selected = true;
        break;
      case 'g':
        greeting_opt_selected = true;
        break;
      default:
        if(english_selected)
          fprintf(stderr, "«%s -h» for help\n", EXEC_NAME);
        else
          fprintf(stderr, "«%s -h» для вывода справки\n", EXEC_NAME);
        exit(1);
    }
  }
    *argc -= optind;
    if(optind > 1)
      *argv += optind;
    //else if(optind == 1) //got only executive
      //help_opt_selected = true;
    if(*argc == 1 && optind == 1)
    {
      if(english_selected)
        fprintf(stderr, "%s: expected options\n«%s -h» for help\n", EXEC_NAME, EXEC_NAME);
      else
        fprintf(stderr, "%s: на вход ожидались аргументы\n«%s -h» для вывода справки\n", EXEC_NAME, EXEC_NAME);
      exit(2);
    }
    if(*argc == 0)
    {
      if(help_opt_selected)
      {
        print_help();
        exit(0);
      }
      if(english_selected)
        fprintf(stderr,"%s: expected filename, quoutes-delimited character sequence or full path to file\n«%s -h» for help\n", EXEC_NAME, EXEC_NAME);
      else
        fprintf(stderr,"%s: ожидалось имя файла, последовательность символов в кавычках или полный путь до файла\n«%s -h» для вывода справки\n", EXEC_NAME, EXEC_NAME);
      exit(3);
    }
}
