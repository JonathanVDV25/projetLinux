CFLAGS=-std=c11 -pedantic -Wall -Wvla -Werror -Wno-unused-variable -D_DEFAULT_SOURCE

all: maintenance 

maintenance: utils_v1.o maintenance.o 
	cc $(CFLAGS) -o maintenance maintenance.o utils_v1.o  

maintenance.o: livreDeCompte.h maintenance.c
	cc $(CFLAGS) -c maintenance.c  

utils_v1.o: utils_v1.h utils_v1.c
	cc $(CFLAGS) -c utils_v1.c 

# for dev purpose
clear:
	clear
	
clean:
	rm -f *.o
	rm -f maintenance