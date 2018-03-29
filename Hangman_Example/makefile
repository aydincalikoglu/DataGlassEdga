CC=g++
CFLAGS=-I.
MYAPP = hangman
DEPS_FOLDER = lib
DEPS = $(DEPS_FOLDER)/Game.hpp $(DEPS_FOLDER)/SecretPhrase.hpp $(DEPS_FOLDER)/Hangman.hpp
OBJ = main.o $(DEPS_FOLDER)/Game.o $(DEPS_FOLDER)/SecretPhrase.o $(DEPS_FOLDER)/Hangman.o

RM := rm -rf

%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

$(MYAPP): $(OBJ)
	g++ -o $@ $^ $(CFLAGS)

run:
	./$(MYAPP)

clean:
	-$(RM) $(OBJ)
	-@echo ' '

cleanup:
	-$(RM) $(OBJ) $(MYAPP)
	-@echo ' '
