#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>

int main(int argc, char *argv[])
{
    if(argc!=2)
    {
        fprintf(stderr, "Usage: ./recover image\n ");
        return 1;
    }
    
    FILE *file1 = fopen("card.raw","r");
    
    if(file1==NULL)
    {
        fprintf(stderr,"Could not open card.raw");
        return 1;
    }
    
    FILE *recimg = NULL;
    
    unsigned char buffer[512];
    char filename[8];
    int counter = 0;
    bool flag = false;
    
    while(fread(buffer, 512, 1, file1))
    {
        if(buffer[0]==0xff && buffer[1]==0xd8 && buffer[2]==0xff && (buffer[3]&0xf0) == 0xe0)
        {
            if(flag==true)
            {
                fclose(recimg);
            }
            else
            {
                flag=true;
            }
            sprintf(filename, "%03i.jpg", counter);
            recimg = fopen(filename, "w");
            counter++;
        }
        if(flag==true)
        {
            fwrite(&buffer, 512, 1, recimg);
        }
    }
    fclose(file1);
    fclose(recimg);
    return 0;
}
