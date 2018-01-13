// Autor: Michał Artur Krawczak

#include "fs.h"

int main(int argc , char** argv){

    VirtualFileSystem vi("KACPER");
    unsigned size = 20;
    vi.createFile(size);
    //vi.uploadFile("ja.txt");
    vi.uploadFile("Plik 2kB.txt");
    vi.uploadFile("Plik 2kB-kopia.txt");
    vi.uploadFile("Plik 2kB-kopia 2.txt");
    //vi.uploadFile("x.txt");
    //vi.removeFile("ja.txt");
    vi.uploadFile("Plik 2kB-kopia 3.txt");
    vi.uploadFile("Plik 2kB-kopia 4.txt");
    //vi.removeFile("Plik 2kB.txt");
    vi.removeFile("Plik 2kB-kopia.txt");
    vi.removeFile("Plik 2kB-kopia 3.txt");
    vi.uploadFile("ja.txt");


    //vi.uploadFile("Plik 2kB-kopia 5.txt");

    vi.listAllFiles();
    vi.mapFileSystem();
    //std::cout<<"USUWAMY ja.txt"<<std::endl;
    //vi.removeFile("ja.txt");
    //vi.listAllFiles();
    //vi.mapFileSystem();



}
