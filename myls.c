#include <stdio.h>		/* Header file for system call printf */
#include <unistd.h>		/* Header file for system call gtcwd */
#include <sys/types.h>		/* Header file for system calls opendir, readdir y closedir */
#include <dirent.h>
#include <string.h>


int main(int argc, char *argv[])
{	
	char directorio[PATH_MAX];
	/*tamaño de directorio path_max*/
	if(argc < 2){
		getcwd(directorio, -1);
		/*si no pasan un directorio cogemos en el que estemos*/
		
	}
	else{
		strcpy(directorio,argv[1]);
	}

	DIR* direccion = opendir(directorio);
	if (direccion == NULL){
		/*guardamos la dirección de memoria del directorio y comprobamos si es nula*/
		printf("EL directorio no existe\n");
		return -1;
	}
	/*en el bucle iremos printando el valor que encontremos en la structura dir en d_name*/
	struct dirent *puntero_directorio = readdir(direccion);
	while (puntero_directorio != NULL){
		printf("%s\n",puntero_directorio -> d_name);
		/*iremos renovando la posición de memoria para que recorra todo el dir*/
		puntero_directorio = readdir(direccion);
	}
return 0;
}

