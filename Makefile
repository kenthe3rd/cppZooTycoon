zooTycoon.exe: main.o zoo.o animal.o tiger.o penguin.o turtle.o menu.o
	g++ -std=c++11 -g main.o zoo.o animal.o tiger.o penguin.o turtle.o menu.o -o zooTycoon.exe

main.o: main.cpp
	g++ -std=c++11 -c -g main.cpp

menu.o: menu.cpp menu.hpp
	g++ -std=c++11 -c -g menu.cpp

zoo.o: zoo.cpp zoo.hpp
	g++ -std=c++11 -c -g zoo.cpp

animal.o: animal.cpp animal.hpp
	g++ -std=c++11 -c -g animal.cpp

tiger.o: tiger.cpp tiger.hpp
	g++ -std=c++11 -c -g tiger.cpp

penguin.o: penguin.cpp tiger.cpp
	g++ -std=c++11 -c -g penguin.cpp

turtle.o: turtle.cpp turtle.hpp
	g++ -std=c++11 -c -g turtle.cpp

clean:
	rm *.o zooTycoon.exe

zip:
	zip -D Hall_Kenneth_Project2.zip *.cpp *.hpp *.pdf Makefile
