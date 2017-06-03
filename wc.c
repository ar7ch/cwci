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
along with cwci. If not, see <http://www.gnu.org/licenses/>.*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "libwc.h"

const char * EXEC_NAME;
int main(int argc, char *argv[]) 
{
  setlocale(LC_ALL, "");
  EXEC_NAME = argv[0];
  initialize_structs(1);
  setup_locale();
  initialize_parameters(&argc, &argv);
  for(int i = 0; i < argc; i++)
  {
  wc_engine(argc, argv[i]);
  output_results(argv[i]);
  initialize_structs(0);
  }
  free(opts_selected);
  free(counters);
  return 0;
}
