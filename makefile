LIB=-L/headers/
INC=-I/src/
CFLAGS = -c -Wall -Iheaders -std=c++11

c1511002_BSTindex: Main.o MainFunctions.o
	g++ Main.o MainFunctions.o -o c1511002_BSTindex

Main.o: src/Main.cpp headers/Timer.h headers/IndexLinkedList.h headers/MainFunctions.h
	g++ $(CFLAGS) src/Main.cpp

MainFunctions.o: src/MainFunctions.cpp headers/IndexLinkedList.h
	g++ $(CFLAGS) src/MainFunctions.cpp

clean:
	rm *.o c1511002_BSTindex