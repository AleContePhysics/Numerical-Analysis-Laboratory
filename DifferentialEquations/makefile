LIBS:=`root-config --libs`
INCS:=`root-config --cflags`

es8.5 : es8.5.cpp equazionidifferenziali.h algebravettoriale.h algoritmieqdiff.h
	g++ -o es8.5 es8.5.cpp ${INCS} ${LIBS}