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
#include <sys/stat.h>


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
    size_t getFileSize(std::string);
    void sortiNodeVector();
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
    void deleteFileSystem();
};

//f->file
//c->create
//u->upload
//d->download
//r->remove
//n->chang name
//m->map
//l->list
//x->delete VFS


#endif //SOI_FILESYSTEM_FS_H
