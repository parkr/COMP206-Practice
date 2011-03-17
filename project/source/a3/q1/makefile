passweb: passweb.o
	gcc -Wall -o passweb passweb.o
	
passweb.o: passweb.c cipher.c menu.c passweb.h
	gcc -Wall -c passweb.c

clean:
	rm *.o
	rm passweb
	
backup:
	cp *.c ../../../backup/
	cp *.h ../../../backup/
