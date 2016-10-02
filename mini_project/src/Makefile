CC	  = g++#Compiler

CFLAGS    = -w -c -std=c++11#Compiler Flags

LDFLAGS	  = #Linker options

SOURCES   = main.cpp image1.cpp image2.cpp image3.cpp image4_1.cpp image4_2.cpp#

OBJECTS  = $(SOURCES:.cpp=.o)#Object files

EXECUTEABLE= a.out #Output name

all: $(SOURCES) $(EXECUTEABLE)

$(EXECUTEABLE): $(OBJECTS)
	$(CC) $(OBJECTS) `pkg-config --libs opencv` $(LDFLAGS) -o $(EXECUTEABLE)

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:  ; rm $(OBJECTS) $(EXECUTEABLE)

run:	; ./$(EXECUTEABLE)
