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
export LD_LIBRARY_PATH=${CURDIR}
greeting.o: ${CURDIR}/src/greeting.c ${CURDIR}/src/cwci.h
	gcc -I\${CURDIR}/src -Wall -c -fPIC ${CURDIR}/src/greeting.c -o greeting.o
setup_locale.o: ${CURDIR}/src/setup_locale.c ${CURDIR}/src/cwci.h
	gcc -I\${CURDIR}/src -Wall -c -fPIC ${CURDIR}/src/setup_locale.c -o setup_locale.o
print_help.o: ${CURDIR}/src/print_help.c ${CURDIR}/src/cwci.h
	gcc -I\${CURDIR}/src -Wall -c -fPIC ${CURDIR}/src/print_help.c -o print_help.o
initialize_structs.o: ${CURDIR}/src/initialize_structs.c ${CURDIR}/src/cwci.h
	gcc -I\${CURDIR}/src -Wall -c -fPIC ${CURDIR}/src/initialize_structs.c -o initialize_structs.o
initialize_parameters.o: ${CURDIR}/src/initialize_parameters.c ${CURDIR}/src/cwci.h
	gcc -I\${CURDIR}/src -Wall -c -fPIC ${CURDIR}/src/initialize_parameters.c -o initialize_parameters.o
output_results.o: ${CURDIR}/src/output_results.c ${CURDIR}/src/cwci.h
	gcc -I\${CURDIR}/src -Wall -c -fPIC ${CURDIR}/src/output_results.c -o output_results.o
wc_engine.o: ${CURDIR}/src/wc_engine.c ${CURDIR}/src/cwci.h
	gcc -I\${CURDIR}/src -Wall -c -fPIC ${CURDIR}/src/wc_engine.c -o wc_engine.o
cwci.o: ${CURDIR}/src/cwci.c ${CURDIR}/src/cwci.h
	gcc -I\${CURDIR}/src -Wall -c ${CURDIR}/src/cwci.c -o cwci.o
libcwci.so: greeting.o setup_locale.o print_help.o initialize_structs.o initialize_parameters.o output_results.o wc_engine.o
	gcc -shared -Wall greeting.o setup_locale.o print_help.o initialize_structs.o initialize_parameters.o output_results.o wc_engine.o -o libcwci.so
cwci: cwci.o libcwci.so
	gcc cwci.o -L\${CURDIR} -lcwci -o cwci
	rm greeting.o setup_locale.o print_help.o initialize_structs.o initialize_parameters.o output_results.o wc_engine.o cwci.o