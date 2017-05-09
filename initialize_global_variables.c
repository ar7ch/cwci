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

unsigned long words_counter = 0;
unsigned long bytes_counter = 0;
unsigned long chars_counter = 0;
unsigned long spaces_counter = 0;
unsigned long digit_counter = 0;
unsigned long lines_counter = 0;
unsigned long max_line_length = 0;
bool max_line_len_selected = false;
bool english_selected = false;
bool words_opt_selected = false;
bool bytes_opt_selected = false;
bool chars_opt_selected = false;
bool spaces_opt_selected = false;
bool help_opt_selected = false;
bool greeting_opt_selected = false;
bool digit_opt_selected = false;
bool lines_opt_selected = false;
bool standard_input_selected = true;
