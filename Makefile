#This file is part of cwci.
#
#Cwci is free software: you can redistribute it and/or modify
#it under the terms of the GNU General Public License as published by
#the Free Software Foundation, either version 3 of the License, or
#(at your option) any later version.
#
#Cwci is distributed in the hope that it will be useful,
#but WITHOUT ANY WARRANTY; without even the implied warranty of
#MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#GNU General Public License for more details.
#
#You should have received a copy of the GNU General Public License
#along with cwci.  If not, see <http://www.gnu.org/licenses/>.

greeting.o: greeting.c libwc.h
	gcc -c greeting.c
setup_locale.o: setup_locale.c libwc.h
	gcc -c setup_locale.c
print_help.o: print_help.c libwc.h
	gcc -c print_help.c
initialize_structs.o: initialize_structs.c libwc.h
	gcc -c initialize_structs.c
initialize_parameters.o: initialize_parameters.c libwc.h
	gcc -c initialize_parameters.c
output_results.o: output_results.c libwc.h
	gcc -c output_results.c
wc_engine.o: wc_engine.c libwc.h
	gcc -c wc_engine.c
wc.o: wc.c libwc.h
	gcc -c wc.c
wc: greeting.o setup_locale.o print_help.o initialize_structs.o initialize_parameters.o output_results.o wc_engine.o wc.o
	gcc greeting.o setup_locale.o print_help.o initialize_structs.o initialize_parameters.o output_results.o wc_engine.o wc.o -o wc