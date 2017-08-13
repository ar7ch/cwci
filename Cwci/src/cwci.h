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

typedef unsigned int bool;
typedef unsigned long u_long;

#define true 1
#define false 0

extern const char * EXEC_NAME;

typedef struct
{
	 u_long words_counter;
	 u_long bytes_counter; 
	 u_long chars_counter; 
	 u_long spaces_counter;
	 u_long digit_counter;
	 u_long lines_counter;
	 u_long max_line_length;
} wc_counters;

typedef struct
{
	bool max_line_len_selected:1;
	bool standard_input_selected:1;
	bool english_selected:1;
	bool words_opt_selected:1;
	bool bytes_opt_selected:1;
	bool chars_opt_selected:1;
	bool spaces_opt_selected:1;
	bool help_opt_selected:1; 
	bool greeting_opt_selected:1;
	bool digit_opt_selected:1;
	bool lines_opt_selected:1;
} wc_opts_selected;

extern wc_opts_selected  * opts_selected;
extern wc_counters * counters;
void error (char * error_msg, char * error_object);
void initialize_structs (int flag);
void initialize_parameters (int *argc, char **argv[]);
void wc_engine (int argc, char *argv);
void output_results (char *argv);
void setup_locale ();
void print_help ();
