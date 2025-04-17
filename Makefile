CC = clang
CFLANGS = -Wall -Wextra -g
EXEC = main
SRC = main.c echo.c

all: $(EXEC)

$(EXEC): $(SRC)
		$(CC) $(CFLANGS) -o $(EXEC) $(SRC)

rebuild: clean all

run: $(EXEC)
		@echo "Running ..."
		./$(EXEC) 5 2 #Values to run thread levels

clean: 
		rm -f $(EXEC)