all: sokoban
compteur.o: compteur.c fonction.h
	gcc -Wall -o compteur.o -c compteur.c
fonctions_main.o: fonctions_main.c fonction.h
	gcc -Wall -o fonctions_main.o -c fonctions_main.c
position_manu.o: position_manu.c fonction.h
	gcc -Wall -o position_manu.o -c position_manu.c
main.o: main.c fonction.h
	gcc -Wall -o main.o -c main.c
lire_tableau.o: lire_tableau.c fonction.h
	gcc -Wall -o lire_tableau.o -c lire_tableau.c
affichage_tableau.o: affichage_tableau.c fonction.h
	gcc -Wall -o affichage_tableau.o -c affichage_tableau.c
deplacement.o: deplacement.c fonction.h
	gcc -Wall -o deplacement.o -c deplacement.c
sokoban: main.o affichage_tableau.o lire_tableau.o deplacement.o position_manu.o fonctions_main.o compteur.o
	gcc -Wall -o sokoban main.o deplacement.o position_manu.o affichage_tableau.o lire_tableau.o fonctions_main.o compteur.o
