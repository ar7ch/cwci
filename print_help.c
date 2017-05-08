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
  if(english_selected)
  {
    printf("cwci - a C wc implementation v. 0.2\n\nSynopsis: %s [OPTIONS] [FILE]\n\nprint word, byte, character, space, digit, integer, letter, newline counts for file\n", EXEC_NAME);
    printf("A word is a non-zero-length sequence of letters delimited by white space.\nAn integer is a non-zero-length sequence of digits delimited by white space.\nReading from standard input is under development\n\nOptions:\n\n-w\n\tprint the word counts\n\n-b\n\tprint the byte counts\n\n-c\n\tprint the character counts\n\n-s\n\tprint the space counts\n\n-d\n\tprint the digit counts\n\n-h\n\tprint help\n\n-t\n\tprint the letter count\n\n-n\n\tprint the integer count\n\n-l\n\tprint the newline count\n\n -g\n\t print greeting for user\n\n author\n\twritten by Artyom Bulgakov <https://github.com/blgkv>\n\nPart of this help was taken from official wc man page. Copyright © 2017 Free Software Foundation, Inc.\nThanks to Paul Rubin, David MacKenzie and all Coreutils developers.\n\n");
    printf("This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public\nLicense as published by the Free Software Foundation,\neither version 3 of the License, or (at your option) any later version.\nThis program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY;\nwithout even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.\nSee the GNU General Public License for more details.\nSource code is available at <https://github.com/blgkv/cwci>\n");
  }
  else
  {
    printf("cwci - a C wc implementation v. 0.2\n\nИспользование: %s [ОПЦИИ] [ФАЙЛ]\n\nПечатает количество слов, байтов, символов, пробелов, цифр, чисел, букв, строк для указанного файла\n", EXEC_NAME);
    printf("За слово считается ненулевая последовательность букв, разделенная пробелами.\nЗа число считается ненулевая последовательность цифр, разделенная пробелами.\nЧтение из стандартного ввода в разработке\n\nОпции:\n\n -w\n\t печать количества слов\n\n -b\n\t печать количества байтов\n\n -c\n\t печать количества символов\n\n -s\n\t печать количества пробелов\n\n -d\n\t печать количества цифр \n\n -h\n\t печать справочной страницы\n\n -t\n\t печать количества букв\n\n -n\n\t печать количества цифр\n\n -l\n\t печать количетсва строк\n\n -g\n\t печать приветствия для пользователя\n\n author\n\t написано Artyom Bulgakov <https://github.com/blgkv>\n\nЧасть этого текста была взята из справочной страницы wc. Copyright © 2017 Free Software Foundation, Inc.\nСпасибо Paul Rubin, David MacKenzie и всем разработчикам Coreutils.\n\n");
    printf("Это свободная программа: вы можете перераспространять ее и/или изменять ее на условиях Стандартной общественной\nлицензии GNU в том виде, в каком она была опубликована Фондом свободного программного обеспечения;\nлибо версии 3 лицензии, либо (по вашему выбору) любой более поздней версии.\nЭта программа распространяется в надежде, что она будет полезной, но БЕЗО ВСЯКИХ ГАРАНТИЙ;\nдаже без неявной гарантии ТОВАРНОГО ВИДА или ПРИГОДНОСТИ ДЛЯ ОПРЕДЕЛЕННЫХ ЦЕЛЕЙ.\nПодробнее см. в Стандартной общественной лицензии GNU.\nИсходный код программы доступен по адресу <https://github.com/blgkv/cwci>\n");
  }
}

/*"За слово считается ненулевая последовательность букв, разделенная пробелами. За число считается ненулевая последовательность цифр, разделенная пробелами. Чтение из стандартного ввода в разработке\n
Опции:\n\n
-w\n\t
печать количества слов\n\n
-b\n\t
печать количества байтов\n\n
-c\n\t
печать количества символов\n\n
-s\n\t
печать количества пробелов\n\n
-d\n\t
печать количества цифр \n\n
-h\n\t
печать справочной страницы\n\n
-t\n\t
печать количества букв\n\n
-n\n\t
печать количества цифр\n\n
-l\n\t
печать количетсва строк\n\n
-g\n\t
печать приветствия для пользователя\n\n
author\n\t
написано Artyom Bulgakov github.com/blgkv\n
Часть этого текста была взята из справочной страницы wc.  Copyright  ©  2017  Free  Software  Foundation,  Inc.   License  GPLv3+:  GNU  GPL  version  3  or  later <http://gnu.org/licenses/gpl.html>.\n
Спасибо Paul Rubin, David MacKenzie и всем разработчикам Coreutils.\n\n
Это свободная программа: вы можете перераспространять ее и/или изменять
ее на условиях Стандартной общественной лицензии GNU в том виде, в каком
она была опубликована Фондом свободного программного обеспечения; либо
версии 3 лицензии, либо (по вашему выбору) любой более поздней версии.\n
Эта программа распространяется в надежде, что она будет полезной,
но БЕЗО ВСЯКИХ ГАРАНТИЙ; даже без неявной гарантии ТОВАРНОГО ВИДА
или ПРИГОДНОСТИ ДЛЯ ОПРЕДЕЛЕННЫХ ЦЕЛЕЙ. Подробнее см. в Стандартной
общественной лицензии GNU.\n
Исходный код программы доступен по адресу github.com/blgkv/cwci\n"*/
/*"A word is a non-zero-length sequence of letters delimited by white space. An integer is a non-zero-length sequence of digits delimited by white space. Reading from standard input is under development\n
Options:\n\n
-w\n\t
print the word counts\n\n
-b\n\t
print the byte counts\n\n
-c\n\t
print the character counts\n\n
-s\n\t
print the space counts\n\n
-d\n\t
print the digit counts\n\n
-h\n\t
print help\n\n
-t\n\t
print the letter count\n\n
-n\n\t
print the integer count\n\n
-l\n\t
print the newline count\n\n
-g\n\t
print greeting for user\n\n
author\n\t
written by Artyom Bulgakov github.com/blgkv\n
Part of this help was taken from official wc man page. Copyright  ©  2017  Free  Software  Foundation,  Inc.   License  GPLv3+:  GNU  GPL  version  3  or  later <http://gnu.org/licenses/gpl.html>.\n
Thanks to Paul Rubin, David MacKenzie and all Coreutils developers.\n\n
This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.\n
This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.\n
Source code is available at github.com/blgkv/cwci\n"*/
