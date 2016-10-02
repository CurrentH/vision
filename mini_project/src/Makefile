CC	  = g++#Compiler

CFLAGS    = -w -c -std=c++11#Compiler Flags

LDFLAGS	  = #Linker options

SOURCES   = main.cpp#
SOURCES  += sources/image1.cpp#
SOURCES  += sources/image2.cpp#
SOURCES  += sources/image3.cpp#
SOURCES  += sources/image4_1.cpp#
SOURCES  += sources/image4_2.cpp#

OBJECTS  = $(SOURCES:.cpp=.o)#Object files

EXECUTEABLE= a.out #Output name

all: $(SOURCES) $(EXECUTEABLE)

$(EXECUTEABLE): $(OBJECTS)
	$(CC) $(OBJECTS) `pkg-config --libs opencv` $(LDFLAGS) -o $(EXECUTEABLE)

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:  ; rm $(OBJECTS) $(EXECUTEABLE)

run:	; ./$(EXECUTEABLE)
