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
#include <unistd.h>
void greeting()
{
  if(opts_selected->english_selected)
    printf("Hello, %s!\n", getlogin());
  else
    printf("Привет, %s!\n", getlogin());
}
