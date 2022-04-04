#include <stdio.h>	/*Header file for system call printf*/
#include <sys/types.h>	/*Header file for system call fstat*/
#include <sys/stat.h>
#include <fcntl.h>	/*Header file for system call fcntl*/
#include <dirent.h> 	/*Header file for system call opendir, closedir,readdir...*/
#include <unistd.h>


int main(int argc, char *argv[])
{
int final;
int inicial;
int resultado;
char directorio[PATH_MAX];
int fichero;
/*declaramos las variables que usaremos*/

	getcwd(directorio,-1);	/*obtenemos el directorio a usar*/
	DIR* direccion = opendir(directorio); /*Extraemos su dirección*/
	if (direccion == NULL){
		printf("Error al abrir el directorio\n");
		return -1;	/*comprobamos que no de errores obtener la direccion*/
	}
	struct dirent *archivo = readdir(direccion);  /*obtenemos la estructura a usar*/
	while (archivo != NULL){  /*mientras que encontremos archivo ejecutaremos*/
		if ((archivo -> d_type) == DT_REG){
			fichero = open((archivo -> d_name), O_RDONLY);  /*abrimos el archivo para usarlo*/
			if (fichero < 0){
				printf("Error abriendo un fichero, cerrando programa...\n");
				return -1;
			}

			inicial = lseek(fichero, 0, SEEK_END); /*Cogemos la posición de final del fichero*/
			final = lseek(fichero, 0, SEEK_SET);/*Cogemos la posición de inicio del fichero*/
			resultado = (inicial - final);/*Restamos para obtener el tamaño*/
			printf("%s\t", archivo -> d_name);
			printf("%i\n", resultado);
			fichero = close(fichero); /*Cerramos el fichero en cuestion*/
			if (fichero < 0){
				printf("Error cerrando archivo, cerrando programa...\n");
				return -1;
			}
	
	}
		archivo = readdir(direccion); /*Saltamos al siguiente archivo y repetimos proceso*/
	}
	return 0;
}
