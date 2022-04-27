mkOutput_P5 : main.o Menu.o Player.o Space.o Monster.o Obstacle.o Item.o Blank.o 
	g++ -std=c++11 -g main.o Menu.o Player.o Space.o Monster.o Obstacle.o Item.o Blank.o -o mkOutput_P5

main.o : main.cpp
	g++ -std=c++11 -c main.cpp

Menu.o : Menu.hpp Menu.cpp
	g++ -std=c++11 -c Menu.cpp

Player.o : Player.hpp Player.cpp
	g++ -std=c++11 -c Player.cpp

Space.o : Space.hpp Space.cpp
	g++ -std=c++11 -c Space.cpp

Monster.o : Monster.hpp Monster.cpp
	g++ -std=c++11 -c Monster.cpp

Obstacle.o : Obstacle.hpp Obstacle.cpp
	g++ -std=c++11 -c Obstacle.cpp

Item.o : Item.hpp Item.cpp
	g++ -std=c++11 -c Item.cpp

Blank.o : Blank.hpp Blank.cpp
	g++ -std=c++11 -c Blank.cpp

clean :
	rm *.o mkOutput_P5
