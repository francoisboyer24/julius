all: libs cesar

cesar : build/cesarstat build/cesardyn build/cipherstat build/cipherdyn build/cipher_filestat build/cipher_filedyn
libs :lib/libjulius.a lib/libjulius.so

export LD_LIBRARY_PATH = $(pwd)

CPFLAGS=-I.$(LD_LIBRARY_PATH)/include
#option -I <=> chemin des fichiers d'entetes inclus avec #include <>

LDFLAGS=-L.$(LD_LIBRARY_PATH)/lib
#option -L <=> chemin des librairies non standards



julius.o : julius.c 
	gcc $(CPFLAGS) -c julius.c -o julius.o 

#production de la librairie statique
lib/libjulius.a : julius.o
	ar qvs lib/libjulius.a julius.o

#production de la librairie dynamique
lib/julius_fpic.o : julius.c 
	gcc -c -fPIC julius.c -o lib/julius_fpic.o

lib/libjulius.so : lib/julius_fpic.o
	gcc -shared lib/julius_fpic.o -o lib/libjulius.so
	

# demander une édition de liens statique avec la lib julius : -l<NOM>
build/cesarstat: examples/cesar.c
	gcc $(CPFLAGS) -static examples/cesar.c $(LDFLAGS) -ljulius -o build/cesarstat 
	
build/cipherstat: examples/cipher.c
	gcc $(CPFLAGS) -static examples/cipher.c $(LDFLAGS) -ljulius -o build/cipherstat 

build/cipher_filestat: examples/cipher_file.c
	gcc $(CPFLAGS) -static examples/cipher_file.c $(LDFLAGS) -ljulius -o build/cipher_filestat 

# demander une édition de liens dynamique avec la lib println : -l<NOM>
build/cesardyn: examples/cesar.c 
	gcc $(CPFLAGS) examples/cesar.c $(LDFLAGS) -ljulius -o build/cesardyn 

build/cipherdyn: examples/cipher.c 
	gcc $(CPFLAGS) examples/cipher.c $(LDFLAGS) -ljulius -o build/cipherdyn 

build/cipher_filedyn: examples/cipher_file.c 
	gcc $(CPFLAGS) examples/cipher_file.c $(LDFLAGS) -ljulius -o build/cipher_filedyn 

clean: 
	rm -rf build/* lib/* *.o
