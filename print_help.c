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

void print_help()
{
  if(opts_selected->english_selected)
  {
    printf("cwci - a C wc implementation v. 0.2\n\nSynopsis: %s [OPTIONS] [FILE] or [STRING]\nprint word, byte, character, space, digit, newline counts for file\n", EXEC_NAME);
    printf("A word is a non-zero-length sequence of characters delimited by white space.\nOptions:\n-w\tprint the word counts\n-b\tprint the byte counts\n-c\tprint the character counts\n-s\tprint the space counts\n-d\tprint the digit counts\n-h\tprint this help and exit\n-l\tprint the newline count\n-L\tprint max line length\n-i\tenable reading from stdin\n-g\tprint greeting for user\nwritten by Artyom Bulgakov <https://github.com/blgkv>\n\nPart of this help was taken from official wc man page. Copyright © 2017 Free Software Foundation, Inc.\nThanks to Paul Rubin, David MacKenzie and to all Coreutils developers.\n\n");
    printf("This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public\nLicense as published by the Free Software Foundation,\neither version 3 of the License, or (at your option) any later version.\nSource code is available at <https://github.com/blgkv/cwci>\n");
  }
  else
  {
    printf("cwci - a C wc implementation v. 0.2\n\nИспользование: %s [ОПЦИИ] [ФАЙЛ]\n\nПечатает количество слов, байтов, символов, пробелов, цифр, строк для указанного файла\n", EXEC_NAME);
    printf("За слово считается ненулевая последовательность символов, разделенная пробелами.\nЧтение из стандартного ввода в разработке\n\nОпции:\n\n -w\n\tнапечатать количество слов\n\n -b\n\tнапечатать количество байтов\n\n -c\n\tнапечатать количество символов\n\n -s\n\tнапечатать количество пробелов\n\n -d\n\tнапечатать количество цифр\n\n-h\n\tпоказать эту справку и выйти\n\n-l\n\tнапечатать количество строк\n\n-L\n\tнапечатать максимальную длину строк в тексте\n\n-g\n\tнапечатать приветствие для пользователя\n\nauthor\n\tнаписано Artyom Bulgakov <https://github.com/blgkv>\n\nЧасть этого текста была взята из справочной страницы wc. Copyright © 2017 Free Software Foundation, Inc.\nСпасибо Paul Rubin, David MacKenzie и всем разработчикам Coreutils.\n\n");
    printf("Это свободная программа: вы можете перераспространять ее и/или изменять ее на условиях Стандартной общественной\nлицензии GNU в том виде, в каком она была опубликована Фондом свободного программного обеспечения;\nлибо версии 3 лицензии, либо (по вашему выбору) любой более поздней версии.\nЭта программа распространяется в надежде, что она будет полезной, но БЕЗО ВСЯКИХ ГАРАНТИЙ;\nдаже без неявной гарантии ТОВАРНОГО ВИДА или ПРИГОДНОСТИ ДЛЯ ОПРЕДЕЛЕННЫХ ЦЕЛЕЙ.\nПодробнее см. в Стандартной общественной лицензии GNU.\nИсходный код программы доступен по адресу <https://github.com/blgkv/cwci>\n");
  }
}
