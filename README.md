Bienvenue sur la librairie julius

I/ Introduction

Lors de ses batailles, l'empereur romain JULES CÉSAR cryptait les messages qu'il envoyait à ses généraux. Sa méthode de codage consistait à décaler les lettres de n rangs, vers la droite, dans l'alphabet. Cette méthode de cryptage est appelée chiffrement de César, ou Code César.

II/ Description du contenue de la librairie

La librairie julius réalise les opérations de chiffrement (et déchiffrement) de Cesar sur un texte, pouvant être renseigné comme variable globale d'un programme C (voir examples/cesar.c), en argument de la ligne de commande (voir examples/cipher.c) ou directement depuis un fichier .txt (voir examples/cipher_file.c). 

III/ Utilisation de la librairie julius:

1ere étape: dezipper et placer la librairie julius dans un répertoire
2ème étape: remplacer le chemin de check dans ./src/julius.c (par défaut : /home/boyer/Bureau/Cesar/) par le chemin du répertoire sur lequel se trouve julius. 
3ème étape: sur le shell, se placer dans le répertoire de la librarie
4ème étape: faire un export LD_LIBRARY_PATH=$(pwd)/lib
5ème étape: make
6ème étape: il est maintenant possible d'utiliser la librairie. Les tests peuvent se faire avec les fichiers d'exemple. Pour cela: 
7ème étape: ./bin/cesardyn .... dans la ligne de commande. Dans le cas de cypher_file(dyn ou stat), renseigner en argument le chemin du fichier à crypter. 

IV/ Remarques générales

 Pour décrypter, faire un shift négatif (opposé du shift de cryptage initial)
 
 BOYER François
