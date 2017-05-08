typedef int bool;
#define true 1
#define false 0

extern unsigned long words_counter, bytes_counter, chars_counter, spaces_counter, letters_counter, number_counter, digit_counter, lines_counter, max_word_length;
extern bool english_selected, words_opt_selected, bytes_opt_selected, chars_opt_selected, spaces_opt_selected, letters_opt_selected, help_opt_selected, greeting_opt_selected, digit_opt_selected, number_opt_selected, lines_opt_selected;
extern const char * EXEC_NAME;


void greeting();
void initialize_parameters(int *argc, char **argv[]);
void wc_engine(int argc, char *argv[]);
void initialize_global_variables();
void output_results(char *argv[]);
void setup_locale();
void print_help();
