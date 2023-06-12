CXX = g++
CXXFLAGS = -std=c++14 -Wall -MMD -Werror=vla
EXEC = biquadris
OBJECTS = GraphicalDisplay.o window.o myBlock.o IBlock.o JBlock.o LBlock.o OBlock.o SBlock.o StarBlock.o TBlock.o ZBlock.o Blind.o BoardAbstract.o BoardConcrete.o Decorator.o Level.o Level0.o Level1.o Level2.o Level3.o Level4.o Subject.o TextDisplay.o Game.o SingleTetrisGame.o CommandInterpreter.o main.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC} -lX11

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
