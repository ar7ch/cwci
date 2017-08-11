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
#include <string.h>
#include <ctype.h>
#include <wctype.h>
#include <wchar.h>
#include <locale.h>
#include <sys/stat.h>
#include <errno.h>

void wc_engine(int argc, char *argv)
{
  char current_char;
  bool word_flag = false;
  int word_len_counter = 0;
  int line_len_counter = 0;
  int ch;
    FILE *file_to_read;
    if(!opts_selected->standard_input_selected)
    {
      if(!(file_to_read = fopen(argv, "r")))
      {
        fprintf(stderr, "%s: %s: %s\n", EXEC_NAME, argv, strerror(ENOENT));
        exit(ENOENT);
      }
    }
  if(opts_selected->bytes_opt_selected && !opts_selected->standard_input_selected)
  {
    struct stat buff;
    stat(argv, &buff);
    counters->bytes_counter = buff.st_size;
  }
  
  /*for(int i = 0; i < argc; i++){
    char ch[] = argv[i];
    for(int j = 0; ch[j] != '\0'; i++)  }*/
  if(opts_selected->greeting_opt_selected)
    greeting();
  if(opts_selected->help_opt_selected)
    print_help();
  if(!opts_selected->standard_input_selected)
  {
  while((ch = fgetc(file_to_read)) != EOF)
  {
    current_char = ch;

    if(!word_flag && opts_selected->words_opt_selected)
    {
      word_flag = true;
      if(current_char != ' ')
        word_len_counter++;
    }
    else if(word_flag && current_char != ' ' && current_char != '\n' && current_char != '\t' && opts_selected->words_opt_selected)
    {
      word_len_counter++;
    }
    if(word_flag && current_char == ' ' && opts_selected->words_opt_selected && word_len_counter == 0) //exception for several spaces in a row
    {
      word_flag = false;
      word_len_counter = 0;
    }
    if(word_flag && (current_char == ' ' || current_char == '\n' || current_char == '\t') && opts_selected->words_opt_selected)
    {
      counters->words_counter++;
      word_flag = false;
      word_len_counter = 0;
    }

    if(isdigit(current_char) && opts_selected->digit_opt_selected)
    {
      counters->digit_counter++;
    }
    if(opts_selected->chars_opt_selected)
    {
      counters->chars_counter++;
    }
    if(opts_selected->max_line_len_selected)
    {
      line_len_counter++;
    }
    if(opts_selected->spaces_opt_selected && current_char == ' ')
    {
      counters->spaces_counter++;
    }
    if(opts_selected->lines_opt_selected && current_char == '\n')
    {
      counters->lines_counter++;
      if(opts_selected->max_line_len_selected)
      {
        if(counters->max_line_length < line_len_counter)
          counters->max_line_length = line_len_counter;
        line_len_counter = 0;
      }
    }
  }
  }
  else
  {
    char * str_to_read = malloc(sizeof(char) * (strlen(argv)+1));
    strcpy(str_to_read, argv);
    for(int i = 0; i < strlen(str_to_read)+1; i++)
    {
      current_char = str_to_read[i];
      if(opts_selected->bytes_opt_selected)
      {
        if(current_char >= -128 && current_char <= 127)
          counters->bytes_counter += 1;
        else
          counters->bytes_counter += 2;
      }
    if(!word_flag && opts_selected->words_opt_selected)
    {
      word_flag = true;
      if(current_char != ' ')
        word_len_counter++;
    }
    else if(word_flag && current_char != ' ' && current_char != '\n' && current_char != '\t' && opts_selected->words_opt_selected)
    {
      word_len_counter++;
    }
    if(word_flag && current_char == ' ' && opts_selected->words_opt_selected && word_len_counter == 0) //exception for several spaces in a row
    {
      word_flag = false;
      word_len_counter = 0;
    }
    if(word_flag && (current_char == ' ' || current_char == '\n' || current_char == '\t' || current_char == '\0') && opts_selected->words_opt_selected)
    {
      counters->words_counter++;
      word_flag = false;
      word_len_counter = 0;
    }

    if(isdigit(current_char) && opts_selected->digit_opt_selected)
    {
      counters->digit_counter++;
    }
    if(opts_selected->chars_opt_selected)
    {
      counters->chars_counter++;
    }
    if(opts_selected->max_line_len_selected)
    {
      line_len_counter++;
    }
    if(opts_selected->spaces_opt_selected && current_char == ' ')
    {
      counters->spaces_counter++;
    }
    if(opts_selected->lines_opt_selected && current_char == '\n')
    {
      counters->lines_counter++;
      if(opts_selected->max_line_len_selected)
      {
        if(counters->max_line_length < line_len_counter)
          counters->max_line_length = line_len_counter;
        line_len_counter = 0;
      }
    }
    }
    free(str_to_read);
  }
  if(!opts_selected->standard_input_selected)
    fclose(file_to_read);
}
