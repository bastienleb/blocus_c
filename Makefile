
# CHAPITRE 1 : BUT FINAL

but : projet

# CHAPITRE 2 : VARIABLES

OFILES = fin.o \
		 jeux.o \
		 graphique.o \
		 main.o

CC = gcc

CFLAGS = -lgraph -Wall

# CHAPITRE 3 : DEPENDANCES (REGLES IMPLICITES)

  graphique.o: jeux.h fin.h

  jeux.o: graphique.h jeux.h

  main.o : graphique.h jeux.h fin.h

#CHAPITRE 4 : DEPENDANCES AVEC COMMANDES

projet : $(OFILES)
	$(CC) -o projet $(OFILES) $(CFLAGS)

run :
	./projet

#CHAPITRE 5 : NETTOYAGE DES FICHIERS GENERES

clean :
	-rm -f $(OFILES) projet

#CHAPITRE 6 : BUTS FACTICES

.PHONY : but clean
