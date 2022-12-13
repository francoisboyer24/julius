all: libs cesar

cesar : bin/cesarstat bin/cesardyn bin/cipherstat bin/cipherdyn bin/cipher_filestat bin/cipher_filedyn
libs :lib/libjulius.a lib/libjulius.so

#LD_LIBRARY_PATH=${ld_library_path}


CPFLAGS=-I./include
#option -I <=> chemin des fichiers d'entetes inclus avec #include <>

LDFLAGS=-L./lib
#option -L <=> chemin des librairies non standards

#mise en place du mode verbose
#V = 1
ifeq ($V,1)
A=
else 
A=@
endif

build/julius.o : ./src/julius.c 
	@echo "On compile $< pour produire $@"
	$A gcc $(CPFLAGS) -c ./src/julius.c -o build/julius.o 

#production de la librairie statique
lib/libjulius.a : build/julius.o
	@echo "On compile $< pour produire la librairie statique $@"
	$A ar qvs lib/libjulius.a build/julius.o

#production de la librairie dynamique
build/julius_fPic.o : src/julius.c 
	$A gcc -fPIC -c src/julius.c -o build/julius_fPic.o

lib/libjulius.so : build/julius_fPic.o
	@echo "On compile $< pour produire la librairie dynamique $@"
	$A gcc -shared build/julius_fPic.o -o lib/libjulius.so
	

# demander une édition de liens statique avec la lib julius : -l<NOM>
bin/cesarstat: examples/cesar.c
	@echo "Edition de lien statique pour $< avec la librairie julius"
	$A gcc $(CPFLAGS) -static examples/cesar.c $(LDFLAGS) -ljulius -o bin/cesarstat 
	
bin/cipherstat: examples/cipher.c
	@echo "Edition de lien statique pour $< avec la librairie julius"
	$A gcc $(CPFLAGS) -static examples/cipher.c $(LDFLAGS) -ljulius -o bin/cipherstat 

bin/cipher_filestat: examples/cipher_file.c
	@echo "Edition de lien statique pour $< avec la librairie julius"
	$A gcc $(CPFLAGS) -static examples/cipher_file.c $(LDFLAGS) -ljulius -o bin/cipher_filestat 

# demander une édition de liens dynamique avec la lib julius : -l<NOM>
bin/cesardyn: examples/cesar.c
	@echo "Edition de lien dynamique pour $< avec la librairie julius"
	$A gcc $(CPFLAGS) $(LDFLAGS) examples/cesar.c -o bin/cesardyn -ljulius

bin/cipherdyn: examples/cipher.c
	@echo "Edition de lien dynamique pour $< avec la librairie julius" 
	gcc $(CPFLAGS) $(LDFLAGS) examples/cipher.c -o bin/cipherdyn -ljulius 

bin/cipher_filedyn: examples/cipher_file.c
	@echo "Edition de lien dynamique pour $< avec la librairie julius" 
	gcc $(CPFLAGS) $(LDFLAGS) examples/cipher_file.c -o bin/cipher_filedyn -ljulius 

clean: 
	rm -rf ./build/*.o ./bin/* *.o *.exe *.a *.sa
