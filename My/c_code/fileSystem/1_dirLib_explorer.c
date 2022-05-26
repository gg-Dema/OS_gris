#include <dirent.h>
#include <stdio.h>
#include <string.h>
//programma per la ricerca di file all'interno della directory indicata

int main (int argc, char *argv[]){
    int found = 0; 
    DIR *dir_pointer; //viene considerato un descrittore 
    struct dirent* dirent_pointer;  //qui ci stanno le info della dir
    if(argc <3) return (printf("usage: ./dirLib_explorer dirname name\n"), -1); 
    dir_pointer = opendir(argv[1]); 
    if(dir_pointer == NULL) return -1; 
    while( (dirent_pointer = readdir(dir_pointer)) != NULL){
        if (strcmp(dirent_pointer -> d_name, argv[2])==0){
            found = 1;
            break; 
        }
    }
    printf("%s\n", found ? "trovato" : "non trovato"); 
    closedir(dir_pointer); 
    return 0; 
}
