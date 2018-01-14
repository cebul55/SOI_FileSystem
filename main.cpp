// Autor: Michał Artur Krawczak

#include "fs.h"

int main(int argc , char* argv[]){

    if(argc < 2){
        std::cout<<"more than 1 argument needed\n";
        return 0;
    }
    else{
        if
    }
    VirtualFileSystem vi("KACPER");
    vi.openFile();
    vi.downloadFile("ja.txt");
    /*unsigned size = 20;
    vi.createFile(size);
    //vi.uploadFile("ja.txt");
    vi.uploadFile("Plik 2kB.txt");
    vi.uploadFile("Plik 2kB-kopia.txt");
    vi.uploadFile("Plik 2kB-kopia 2.txt");
    //vi.uploadFile("x.txt");
    //vi.removeFile("ja.txt");
    vi.uploadFile("Plik 2kB-kopia 3.txt");
    vi.uploadFile("Plik 2kB-kopia 4.txt");
    vi.renameFile("Plik 2kB-kopia 4.txt","pliiiik.txt");
    //vi.removeFile("Plik 2kB.txt");
    vi.removeFile("Plik 2kB-kopia.txt");
    vi.removeFile("Plik 2kB-kopia 3.txt");
    vi.uploadFile("ja.txt");
    vi.downloadFile("pliiiik.txt");*/
    //vi.uploadFile("Plik 2kB-kopia 3.txt");



    //vi.uploadFile("Plik 2kB-kopia 5.txt");

    vi.listAllFiles();
    vi.mapFileSystem();
    //std::cout<<"USUWAMY ja.txt"<<std::endl;
    //vi.removeFile("ja.txt");
    //vi.listAllFiles();
    //vi.mapFileSystem();



}
