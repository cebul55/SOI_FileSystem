// Autor: Michał Artur Krawczak

#include "fs.h"

int main(int argc , char* argv[]){

    if(argc < 2){
        std::cout<<"more than 1 argument needed\n";
        return 0;
    }
    else{
        if(*argv[1] == 'f'){
            VirtualFileSystem vfs(argv[2]);
            if(argc > 3){
                if(*argv[3]=='c') {
                    vfs.createFile(atoi(argv[4]));
                    return 0;
                }
                vfs.openFile();
                /*if(*argv[3]=='u'){
                    vfs.uploadFile((std::string)argv[4]);
                    return 0;
                }
                else if(*argv[3]=='d'){
                    vfs.downloadFile((std::string)argv[4]);
                    return 0;
                }
                else if(*argv[3]=='l'){
                    vfs.listAllFiles();
                    return 0;
                }*/
                switch(*argv[3]){
                    case 'u':
                        vfs.uploadFile((std::string)argv[4]);
                        return 0;
                    case 'd':
                        vfs.downloadFile((std::string)argv[4]);
                        return 0;
                    case 'r':
                        vfs.removeFile((std::string)argv[4]);
                        return 0;
                    case 'n':
                        vfs.renameFile((std::string)argv[4], (std::string)argv[5]);
                        return 0;
                    case 'l':
                        vfs.listAllFiles();
                        return 0;
                    case 'm':
                        vfs.mapFileSystem();
                        return 0;
                    case 'x':
                        vfs.deleteFileSystem();
                        return 0;
                    default:
                    std::cout<<"sprawdz liste komend w pdf\n";
                        return 0;

                }
            }
        }
    }
    //f->file
    //c->create
    //u->upload
    //d->download
    //r->remove
    //n->chang name
    //m->map
    //l->list
    //x->delete VFS
    //VirtualFileSystem vi("KACPER");
    //vi.openFile();
    //vi.downloadFile("ja.txt");
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

    //vi.listAllFiles();
    //vi.mapFileSystem();
    //std::cout<<"USUWAMY ja.txt"<<std::endl;
    //vi.removeFile("ja.txt");
    //vi.listAllFiles();
    //vi.mapFileSystem();


    return 0;
}
