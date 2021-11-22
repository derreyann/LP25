#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#include<dirent.h>
#include <sys/stat.h>

int main( int argc, char *argv[] )  {
        struct stat sb;
        struct dirent **namelist;
        int n;
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
                printf("%s ",namelist[n]->d_name);
                if( stat(namelist[n]->d_name, &sb) != -1) // Check the return value of stat
                {
                    if( S_ISREG( sb.st_mode ) != 0 )
                    {
                        printf( "file\n");
                    }
                    if( S_ISLNK( sb.st_mode ) != 0 )
                    {
                        printf( "symbolic link\n") ;
                    }
                    if( S_ISDIR( sb.st_mode ) != 0 )
                    {
                        printf( "directory\n") ;
                    }
                printf("%.2f k ", (float)sb.st_size/1000);
                }
                free(namelist[n]);
            }
            free(namelist);
        }
        }
