LIBS:=`root-config --libs`
INCS:=`root-config --cflags`

all: calcolus execusion

calcolus: calcolus.cpp integrali.h random.h funzioni.h
	g++ -o calcolus calcolus.cpp ${INCS} ${LIBS}

execusion: execusion.cpp integrali.h random.h funzioni.h
	g++ -o execusion execusion.cpp ${INCS} ${LIBS}


