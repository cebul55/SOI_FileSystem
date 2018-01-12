// Autor: Michał Artur Krawczak

#include "fs.h"

int main(int argc , char** argv){

    VirtualFileSystem vi("JAN");
    unsigned size = 20;
    vi.createFile(size);
    vi.listAllFiles();
   // vi.removeFile("JAN.txt");
}
