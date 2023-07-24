# variables

cc=gcc
bin=mips
objets=argument.o parser.o writer.o mips.o dictionnaire.o

#cible : dépendance 

mips: $(objets)
	$(cc) $(objets) -o $(bin)

dictionnaire.o: dictionnaire.h dictionnaire.c
	$(cc) -c dictionnaire.c -o dictionnaire.o
	
argument.o: argument.h argument.c
	$(cc) -c argument.c -o argument.o

parser.o: parser.h parser.c
	$(cc) -c parser.c -o parser.o

writer.o: writer.h writer.c
	$(cc) -c writer.c -o writer.o

mips.o: mips.c
	$(cc) -c mips.c -o mips.o

#cible : nettoyage
	
clean:
	\rm -f *.o
	\rm -f $(bin)
	\rm -f *~
