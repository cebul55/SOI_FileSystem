#include <iostream>
#include <stdio.h>
#include <cstdlib>

int main(int argc , char* argv[]) {
    unsigned char *tab;
    int ptr , i;
    FILE *file = fopen("soi","rb");
    fseek(file,0,2);   //ustawia pozycje wskaznika na offset
    ptr = ftell(file); //zwraca pozycje wskaznika w otwartym pliku
    tab = (unsigned char*)malloc(ptr);
    fseek(file,0,0);
    fread(tab, sizeof(unsigned char),ptr,file);
    fclose(file);
    for(i = 0 ; i<ptr;i++){
        printf("%x ",tab[i]);
        if((i+1)%16 == 0)
            printf("\n");
    }

    return 0;
}