
# code details

EXE = ./library
SRC= main.c book_management.c librarian.c user.c login.c page.c

# generic build details

CC=      gcc
CFLAGS= -std=c99 -Wall
CLINK= 

# compile to object code

OBJ= $(SRC:.c=.o)

.c.o:
	$(CC) $(CFLAGS) -c -o $@ $<

# build executable: type 'make'

$(EXE): $(OBJ)
	$(CC) $(OBJ) $(CLINK) -o $(EXE) 

# clean up and remove object code and executable: type 'make clean'

clean:
	rm -f $(OBJ) $(EXE)

# dependencies

main.o:      main.c page.h
book_management.o:   book_management.c book_management.h
librarian.o: librarian.c librarian.h page.h
user.o:      user.c user.h login.h
login.o:	login.c login.h book_management.h user.h librarian.h page.h



