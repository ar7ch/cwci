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
#include <stdlib.h>

wc_counters * counters;
wc_opts_selected  * opts_selected;

void initialize_structs()
{
opts_selected = malloc(sizeof(wc_counters));
counters = malloc(sizeof(wc_counters));

counters->words_counter = 0;
counters->bytes_counter = 0;
counters->chars_counter = 0;
counters->spaces_counter = 0;
counters->digit_counter = 0;
counters->lines_counter = 0;
counters->max_line_length = 0;
opts_selected->max_line_len_selected = false;
opts_selected->english_selected = false;
opts_selected->words_opt_selected = false;
opts_selected->bytes_opt_selected = false;
opts_selected->chars_opt_selected = false;
opts_selected->spaces_opt_selected = false;
opts_selected->help_opt_selected = false;
opts_selected->greeting_opt_selected = false;
opts_selected->digit_opt_selected = false;
opts_selected->lines_opt_selected = false;
opts_selected->standard_input_selected = false;
}