PROJ_NAME = marketdb
SRC_DIR = src
INC_DIR = /usr/include/postgresql
LIB_DIR = /usr/lib
BIN_DIR = bin
CC = gcc

$(PROJ_NAME):
	$(CC) -o $(BIN_DIR)/$(PROJ_NAME) $(SRC_DIR)/*.c -Wall -pedantic-errors -std=c11 -I$(INC_DIR) -L$(LIB_DIR) -lpq -lm

.PHONY: clean

clean:
	rm $(BIN_DIR)/$(PROJ_NAME) -r
