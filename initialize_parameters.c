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
  while((ch = getopt(*argc, *argv, "wbcsdnhtlg")) != EOF)
  {
    switch(ch){
      case 'w':
        words_opt_selected = true;
        break;
      case 'b':
        bytes_opt_selected = true;
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
        fprintf(stderr,"%s: expected filename or full path to file\n«%s -h» for help\n", EXEC_NAME, EXEC_NAME);
      else
        fprintf(stderr,"%s: ожидалось имя файла или полный путь до файла\n«%s -h» для вывода справки\n", EXEC_NAME, EXEC_NAME);
      exit(3);
    }
}
