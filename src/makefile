output: main.o outils.o matrice.o remez.o
	g++ remez.o matrice.o outils.o main.o -o main

main.o: main.cpp
	g++ -c main.cpp

outils.o: outils.cpp outils.hpp
	g++ -c outils.cpp outils.hpp

matrice.o: matrice.cpp matrice.hpp
	g++ -c matrice.cpp matrice.hpp

remez.o: remez.cpp remez.hpp
	g++ -c remez.cpp remez.hpp

clean:
	rm *.o