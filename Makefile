greeting.o: greeting.c libwc.h
	gcc -c greeting.c
setup_locale.o: setup_locale.c libwc.h
	gcc -c setup_locale.c
print_help.o: print_help.c libwc.h
	gcc -c print_help.c
initialize_global_variables.o: initialize_global_variables.c libwc.h
	gcc -c initialize_global_variables.c
initialize_parameters.o: initialize_parameters.c libwc.h
	gcc -c initialize_parameters.c
output_results.o: output_results.c libwc.h
	gcc -c output_results.c
wc_engine.o: wc_engine.c libwc.h
	gcc -c wc_engine.c
wc.o: wc.c libwc.h
	gcc -c wc.c
wc: greeting.o setup_locale.o print_help.o initialize_global_variables.o initialize_parameters.o output_results.o wc_engine.o wc.o
	gcc greeting.o setup_locale.o print_help.o initialize_global_variables.o initialize_parameters.o output_results.o wc_engine.o wc.o -o wc
