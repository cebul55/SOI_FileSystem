//
// Created by Bartosz Cybulski on 12.01.2018.
//
#include "fs.h"

void showHelp(){
    std::cout<<"Help:"<<std::endl
             <<"'f' <file_name> 'operation to do' [text_file1] [text_file2]"<<std::endl
             <<"f - file"<<std::endl
             <<"c [int] - create file of n blocks"<<std::endl
             <<"u [file_name] - upload file"<<std::endl
             <<"d [file_name] - download file"<<std::endl
             <<"r [file_name] - remove file"<<std::endl
             <<"n [file_name 1] [file_name2] - rename file"<<std::endl
             <<"m - map file system"<<std::endl
             <<"l - list all files"<<std::endl
             <<"x - delete virtual file system"<<std::endl;
}

int main(int argc , char* argv[]){

    if(argc < 2){
        std::cout<<"more than 1 argument needed\n";
        showHelp();
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

    return 0;
}
