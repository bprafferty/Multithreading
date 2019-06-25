##################################################################
#                   -- Program Assignment #1 -- 
#          Brian Rafferty -- cssc0852 -- redID: 816988452
#						CS 570, Summer 2019
#							 makefile
##################################################################
COMPILER=g++
FLAGS=-c -Wall
LFLAGS=-lpthread -lrt

SRCFILE=player.cpp
OBJFILE=$(SRCFILE:.cpp=.o)
EXE=player

all: $(SRCFILE) $(EXE)
	
$(EXE): $(OBJFILE)
	$(COMPILER) $(LFLAGS) $(OBJFILE) -o $@

.cpp.o:
	$(COMPILER) $(FLAGS) $< -o $@

clean:
	rm *.o $(OBJFILE)

#######################[ EOF: makefile ]##########################