passweb: passweb.o menu.o cipher.o
	gcc -Wall -o passweb passweb.o cipher.o menu.o
	
passweb.o: passweb.c cipher.h menu.h passweb.h
	gcc -Wall -c passweb.c

menu.o: menu.c menu.h
	gcc -Wall -c menu.c
	
cipher.o: cipher.c cipher.h
	gcc -Wall -c cipher.c
	
clean:
	rm *.o
	rm passweb
	
backup:
	cp *.c ../../../backup/*.c
	cp *.h ../../../backup/*.h
