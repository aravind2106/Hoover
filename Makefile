CC = g++
CFLAGS= -O3 -Wall -std=c++11 -pedantic 

all: roomba

clean:
	rm -f *.o
	rm -f roomba 
	rm -f *~
	rm -f core

roomba.o: roomba.cpp
	$(CC) $(CFLAGS) -g -c roomba.cpp ${LIBS}

roomba:  roomba.o 
	$(CC) $(CFLAGS) -g  -o roomba roomba.o ${LIBS}
  
demo:	roomba
	./roomba

demo1:	roomba
	./roomba -f input1.txt

demo2:	roomba
	./roomba -f input2.txt
	
demo3:	roomba
	./roomba -f input3.txt
	
demo4:	roomba
	./roomba -f input4.txt

demo5:	roomba
	./roomba -f input5.txt
