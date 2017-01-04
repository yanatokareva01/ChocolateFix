CC = gcc
CFLAGS =-std=c89 -Wall  -Werror -pedantic
EXE = bin/game
SRC = src
OFILES = $(patsubst %.c,%.o,$(wildcard $(SRC)/*.c)) 

all: $(EXE)

$(EXE): $(OFILES)
	$(CC) $^ -o $@

$(SRC)/%.o: $(SRC)/%.c
	$(CC) $(CFLAGS) -c $^ -o $@

clean:
	rm $(SRC)/*.o && rm $(EXE)
