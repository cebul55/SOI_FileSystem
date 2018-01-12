//
// Created by Bartosz Cybulski on 12.01.2018.
//

#ifndef SOI_FILESYSTEM_FS_H
#define SOI_FILESYSTEM_FS_H


#include <fstream>
#include <string>
#include <cstring>
#include <iostream>
#include <iomanip>
#include <vector>


class VirtualFileSystem{
    static const unsigned BLOCK_SIZE = 1024;
    static const unsigned SYSTEM_BLOCKS = 8;

    struct inode{
        bool used;
        unsigned begin;
        unsigned end(){ return begin + blocks; }
        unsigned size;
        unsigned blocks;
        char name[48];
    }; // inode size -> 64
    //todo exception

    std::vector<inode> inodeVector_;
    typedef char buffer_ [BLOCK_SIZE];
    std::string name_;
    unsigned size_;
    unsigned numberBlocksUsed_;

    unsigned alloc(unsigned);
    void defragment();
    void close();
    inode *findInode(std::string);
    static int cmpInode(inode, inode);
public:
    VirtualFileSystem(std::string name);
    ~VirtualFileSystem();
    void createFile(unsigned);
    void openFile();
    void uploadFile(std::string);
    void downloadFile(std::string);
    void renameFile(std::string, std::string);
    void removeFile(std::string);
    void listAllFiles();
    void mapFileSystem();
    //void open();
    /*std::string get_title()
    {
        return std::string("Wirtualny system plikow");
    }*/
};

#endif //SOI_FILESYSTEM_FS_H
