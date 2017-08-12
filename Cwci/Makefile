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

OBJECTS = greeting.o setup_locale.o print_help.o initialize_structs.o initialize_parameters.o output_results.o wc_engine.o
SRC_DIR = ${CURDIR}/src
DIR = ${CURDIR}
.PHONY: clean rebuild
clean:
	rm -f *.o
rebuild:
	rm -f *.o *.a *.so
#to keep it simple we'll have to use -fPIC flag even for static lib
#it's okay, but it will be slighty slower
greeting.o: $(SRC_DIR)/greeting.c $(SRC_DIR)/cwci.h
	gcc -I\$(SRC_DIR) -Wall -c -fPIC $(SRC_DIR)/greeting.c -o greeting.o
setup_locale.o: $(SRC_DIR)/setup_locale.c $(SRC_DIR)/cwci.h
	gcc -I\$(SRC_DIR) -Wall -c -fPIC $(SRC_DIR)/setup_locale.c -o setup_locale.o
print_help.o: $(SRC_DIR)/print_help.c $(SRC_DIR)/cwci.h
	gcc -I\$(SRC_DIR) -Wall -c -fPIC $(SRC_DIR)/print_help.c -o print_help.o
initialize_structs.o: $(SRC_DIR)/initialize_structs.c $(SRC_DIR)/cwci.h
	gcc -I\$(SRC_DIR) -Wall -c -fPIC $(SRC_DIR)/initialize_structs.c -o initialize_structs.o
initialize_parameters.o: $(SRC_DIR)/initialize_parameters.c $(SRC_DIR)/cwci.h
	gcc -I\$(SRC_DIR) -Wall -c -fPIC $(SRC_DIR)/initialize_parameters.c -o initialize_parameters.o
output_results.o: $(SRC_DIR)/output_results.c $(SRC_DIR)/cwci.h
	gcc -I\$(SRC_DIR) -Wall -c -fPIC $(SRC_DIR)/output_results.c -o output_results.o
wc_engine.o: $(SRC_DIR)/wc_engine.c $(SRC_DIR)/cwci.h
	gcc -I\$(SRC_DIR) -Wall -c -fPIC $(SRC_DIR)/wc_engine.c -o wc_engine.o
cwci.o: $(SRC_DIR)/cwci.c $(SRC_DIR)/cwci.h
	gcc -I\$(SRC_DIR) -Wall -c $(SRC_DIR)/cwci.c -o cwci.o
libcwci.so: $(OBJECTS)
	export LD_LIBRARY_PATH=$(DIR) ; gcc -shared -Wall $(OBJECTS) -o libcwci.so
libcwci.a: $(OBJECTS)
	ar -rcs libcwci.a $(OBJECTS)
cwci_static: cwci.o libcwci.a
	gcc cwci.o -L\$(DIR) -lcwci -o cwci
cwci_dynamic: cwci.o libcwci.so
	gcc cwci.o -L\$(DIR) -lcwci -o cwci