IDIR =include
CFLAGS=-I$(IDIR)
LIBS=-lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio 
HEADERS = Board.h Bottle.h Game.h GreenBottle.h RedBottle.h Rock.h RockBottle.h
OPTIONS = -std=c++11

all: theGame clean

%.o: src/%.cpp
	$(CXX) -c $< -o $@ $(CFLAGS) $(OPTIONS)

%.o: include/%.h
	$(CXX) -c $< -o $@ ./

theGame: main.o Board.o Bottle.o Game.o GreenBottle.o RedBottle.o Rock.o RockBottle.o
	g++ -o aLosPiedrazos main.o Board.o Bottle.o Game.o GreenBottle.o RedBottle.o Rock.o RockBottle.o $(LIBS)

clean:
	@echo "** Removing object files and executable..."
	rm -f *.o