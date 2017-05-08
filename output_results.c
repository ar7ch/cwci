#include "libwc.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <wctype.h>
#include <wchar.h>
#include <locale.h>


void output_results(char *argc[])
{
  if(english_selected)
  {
    printf("Successfully parsed file %s\n\n", argc[0]);
    if(bytes_opt_selected)
      printf("Bytes: %d\n", bytes_counter / sizeof(wchar_t));
    if(lines_opt_selected)
      printf("Lines: %d\n", lines_counter);
    if(spaces_opt_selected)
      printf("Spaces: %d\n", spaces_counter);
    if(chars_opt_selected)
      printf("[all visible]Chars: %d\n", chars_counter > 0 ? chars_counter - 1 : chars_counter);
    if(digit_opt_selected)
      printf("Digits: %d\n", digit_counter);
    if(number_opt_selected)
      printf("Numbers: %d\n", number_counter);
    if(letters_opt_selected)
      printf("Letters: %d\n", letters_counter);
    if(words_opt_selected)
    {
      printf("Words: %d\n", words_counter);
      if(words_counter > 0)
        printf("Max word size: %d\n", max_word_length);
    }
  }
  else
  {
    printf("Файл %s успешно проанализирован!\n\n", argc[0]);
    if(bytes_opt_selected)
      printf("Байтов: %d\n", bytes_counter);
    if(lines_opt_selected)
      printf("Строк: %d\n", lines_counter);
    if(spaces_opt_selected)
      printf("Пробелов: %d\n", spaces_counter);
    if(chars_opt_selected)
      printf("[всех видимых]Символов: %d\n", chars_counter > 0 ? chars_counter - 1 : chars_counter);
    if(digit_opt_selected)
      printf("Цифр: %d\n", digit_counter);
    if(number_opt_selected)
      printf("Чисел: %d\n", number_counter);
    if(letters_opt_selected)
      printf("Букв: %d\n", letters_counter);
    if(words_opt_selected)
    {
      printf("Слов: %d\n", words_counter);
      if(words_counter > 0)
        printf("Самое длинное слово в файле: %d\n", max_word_length);
    }
  }
}
