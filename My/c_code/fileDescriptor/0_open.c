#include <fcntl.h> //contiene open 
#include <unistd.h> //write and close
#include <assert.h>
#include <string.h>
#include <stdio.h>

int main(){

    //open ritorna un file descriptor in forma di int, al contrario 
    //della file open fopen che ritorna un *FILE file; puntatore a file
    /*
    FLAGS: 
        O_CREAT  /---> if path name not exits: create
        O_WRONLY /---> write only
        O_TRUNC  /---> if file already exist: truncate to length 0 ???
        esistono una marea di flag alernativi 
    A call to open() creates a new open file description, an entry in
    the system-wide table of open files.
    MODE: permessi del file
        0640
        in c l'inizio dei numeri con 0 indica la notazione a base 8
            * (owning) User: read & write
            * Group: read
            * Other: read
        full permission : 0777
    RETURN : fd piu piccolo presente nella entry table 
    */
    int fd = open ("temp.txt", O_CREAT | O_WRONLY | O_TRUNC, 0640); 
    assert (fd != -1); 
    char *str =  "bella per il test"; 
    write(fd, str, strlen(str));
    close(fd); 
    int fd_read = open("temp.txt", O_RDONLY);
    char buffer_read[512];
    ssize_t read_size = read(fd_read, buffer_read, sizeof(buffer_read));
    fwrite(buffer_read, sizeof(char), read_size, stdout); 
    printf("\n");
    return 0;  
}