#include <stdio.h>
#include <stdlib.h>

int main()
{
    unsigned int len_max = 128;
    unsigned int current_size = 0;

    char *pStr = malloc(len_max);
    current_size = len_max;

    printf("\nEnter a very very very long String value:");

    if(pStr != NULL)
    {
    int c = EOF;
    unsigned int i =0;
        //accept user input until hit enter or end of file
    while (( c = getchar() ) != '\n' && c != EOF)
    {
        pStr[i++]=(char)c;

        //if i reached maximize size then realloc size
        if(i == current_size)
        {
                        current_size = i+len_max;
            pStr = realloc(pStr, current_size);
        }
    }

    pStr[i] = '\0';

        printf("\nLong String value:%s \n\n",pStr);
        
        
        ///writing into the file
        FILE *f_ptr;
        f_ptr= fopen("ABC.txt","w");
         if (f_ptr == NULL)
     {
          puts("Issue in opening the Output file");
     }
     fputs(pStr,f_ptr);
     fclose(f_ptr);
     
    }
}
