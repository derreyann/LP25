#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#include<dirent.h>
#include <sys/stat.h>

int main( int argc, char *argv[] )  {
        struct stat sb;
        struct dirent **namelist;
        int n;
        int a=0;
        if(argc < 1)
        {
            exit(EXIT_FAILURE);
        }
        else if (argc == 1)
        {
            n=scandir(".",&namelist,NULL,alphasort);
        }
        else
        {
            n = scandir(argv[1], &namelist, NULL, alphasort);
        }
        if(n < 0)
        {
            perror("scandir");
            exit(EXIT_FAILURE);
        }
        else
        {
            while (n--)
            {
                if(strcmp(argv[2],namelist[n]->d_name)==0){
                    printf("%s ",namelist[n]->d_name);
                }
                free(namelist[n]);
            }
            free(namelist);
        }
}
