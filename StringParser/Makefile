CC = g++
CC_FLAGS = -Wall -ansi -pedantic -Werror -std=c++11 
EXEC = libstringwrapper.so
SOURCES = stringwrapper.cpp
HEADERS = stringwrapper.h

all: $(EXEC)

$(EXEC): $(SOURCES) $(HEADERS)
	$(CC) $(CC_FLAGS) $(SOURCES) -fPIC -shared -o $(EXEC)

clean:
	rm -f $(EXEC)
