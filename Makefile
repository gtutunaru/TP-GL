CC=g++
CFLAGS = -Wall -g -pedantic -std=c++11

MAIN= exec
SRCS= lexer.cpp symbole.cpp automate.cpp state.cpp state0.cpp  state1.cpp state2.cpp state3.cpp state4.cpp state5.cpp state6.cpp state7.cpp state8.cpp state9.cpp main.cpp
OBJS=$(SRCS:.cpp=.o)

$(MAIN): $(OBJS)
	$(CC) -o $(MAIN) $(OBJS)

%.o: %.cpp %.h
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean
clean:
	rm *.o $(MAIN)
