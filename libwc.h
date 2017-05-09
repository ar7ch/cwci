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

typedef int bool;
#define true 1
#define false 0

extern unsigned long words_counter, bytes_counter, chars_counter, spaces_counter, digit_counter, lines_counter, max_line_length;
extern bool max_line_len_selected, standard_input_selected, english_selected, words_opt_selected, bytes_opt_selected, chars_opt_selected, spaces_opt_selected, help_opt_selected, greeting_opt_selected, digit_opt_selected, lines_opt_selected;
extern const char * EXEC_NAME;


void greeting();
void initialize_parameters(int *argc, char **argv[]);
void wc_engine(int argc, char *argv[]);
void initialize_global_variables();
void output_results(char *argv[]);
void setup_locale();
void print_help();
