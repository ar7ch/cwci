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
#include <stdio.h>

void print_help()
{
  if(opts_selected->english_selected)
  {
    printf("This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.\nSource code is available at <https://github.com/blgkv/cwci>\n");
    printf("cwci - a C wc implementation v. 0.2\n\nSynopsis: %s [OPTIONS] [FILE(s)] or [STRING]\nprint word, byte, character, space, digit, newline counts for files\n", EXEC_NAME);
    printf("A word is a non-zero-length sequence of characters delimited by white space.\nOptions:\n\t-w\tprint the word counts\n\t-b\tprint the byte counts\n\t-c\tprint the character counts\n\t-s\tprint the space counts\n\t-d\tprint the digit counts\n\t-h\tprint this help and quit\n\t-l\tprint the newline count\n\t-L\tprint max line length\n\t-i\tenable reading from stdin\n\t-g\tprint greeting for user\nwritten by Artyom Bulgakov <https://github.com/blgkv>\n\nPart of this help was taken from official wc man page. Copyright © 2017 Free Software Foundation, Inc.\nThanks to Paul Rubin, David MacKenzie and to all Coreutils developers.\n");
  }  
  else
  {
     printf("Это свободная программа: вы можете перераспространять ее и/или изменять ее на условиях Стандартной общественной лицензии GNU в том виде, в каком она была опубликована Фондом свободного программного обеспечения; либо версии 3 лицензии, либо (по вашему выбору) любой более поздней версии.\nЭта программа распространяется в надежде, что она будет полезной, но БЕЗО ВСЯКИХ ГАРАНТИЙ; даже без неявной гарантии ТОВАРНОГО ВИДА или ПРИГОДНОСТИ ДЛЯ ОПРЕДЕЛЕННЫХ ЦЕЛЕЙ. Подробнее см. в Стандартной общественной лицензии GNU.\nИсходный код программы доступен по адресу <https://github.com/blgkv/cwci>\n");
    printf("cwci - a C wc implementation v. 0.2\n\nИспользование: %s [ОПЦИИ] [ФАЙЛ(ы)]\n\nПечатает количество слов, байтов, символов, пробелов, цифр, строк для указанных файлов\n", EXEC_NAME);
    printf("За слово считается ненулевая последовательность символов, разделенная пробелами.\nОпции:\n\t-w\tнапечатать количество слов\n\t-b\tнапечатать количество байтов\n\t-c\tнапечатать количество символов\n\t-s\tнапечатать количество пробелов\n\t-d\tнапечатать количество цифр\n\t-h\tпоказать эту справку и выйти\n\t-l\tнапечатать количество строк\n\t-L\tнапечатать максимальную длину строк в тексте\n\t-g\tнапечатать приветствие для пользователя\n\nauthor\n\tнаписано Artyom Bulgakov <https://github.com/blgkv>\n\nЧасть этого текста была взята из справочной страницы wc. Copyright © 2017 Free Software Foundation, Inc.\nСпасибо Paul Rubin, David MacKenzie и всем разработчикам Coreutils.\n");
  }
}
