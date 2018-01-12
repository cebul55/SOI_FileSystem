//
// Created by Bartosz Cybulski on 12.01.2018.
//
//todo przerobic bez boost
//todo skrypt
//todo pozmieniac żeby bylo inne najlepiej chuj inne !



#include "fs.h"


VirtualFileSystem::VirtualFileSystem(std::string name):
    name_(name)
{
    //open();
}
VirtualFileSystem::~VirtualFileSystem() {
    //close();
}

unsigned VirtualFileSystem::alloc(unsigned blocks) {
    while(1){
        unsigned nodes = inodeVector_.size();
        if(nodes == 0 || inodeVector_[0].begin - SYSTEM_BLOCKS >= blocks )
            return SYSTEM_BLOCKS;
        for( unsigned i = 1 ; i < inodeVector_.size() ; ++i) {
            unsigned hole = inodeVector_[i].begin - inodeVector_[i-1].end();
            if(hole >= blocks)
                return inodeVector_[i-1].end();
        }
        if(nodes != 0 && size_ - inodeVector_[nodes-1].end() >= blocks)
            return inodeVector_[nodes-1].end();
        /*jezeli nie znajdziesz miejsca defragmentacja*/
        //todo defragment();
    }
}
int VirtualFileSystem::cmpInode(inode a, inode b) { return a.begin < b.begin ;}

void VirtualFileSystem::close() {
    sort(inodeVector_.begin(), inodeVector_.end(), cmpInode);
    buffer_ buff[SYSTEM_BLOCKS];
    unsigned index = 0;
    for( unsigned j=0; j < SYSTEM_BLOCKS ; j++){
        for(unsigned i = 0 ; i < BLOCK_SIZE ; i+= sizeof(inode)){
            index++;
            inode *ptr = reinterpret_cast<inode*>(buff[j] + i);
            if(index < inodeVector_.size())
                *ptr = inodeVector_[index];
            else{
                for(unsigned k = 0 ; k < sizeof(inode); ++k){
                    *(buff[j] + i + k ) = 0 ;
                }
            }
        }
    }
    std::fstream ofile;
    ofile.open(name_.c_str(), std::ios::in|std::ios::out|std::ios::binary);
    ofile.seekp(std::ios_base::beg);
    for(unsigned j = 0 ; j < SYSTEM_BLOCKS ; j++){
        ofile.write(buff[j], BLOCK_SIZE);
    }
    ofile.close();
}

void VirtualFileSystem::createFile(unsigned size) {
    if(size <= SYSTEM_BLOCKS)
    {
        throw std::logic_error("Disk is too small");
    }
    size_ = size;
    buffer_ buf;
    for(unsigned i = 0 ; i < BLOCK_SIZE ; ++i)
    {
        buf[i] = '\0' ;
    }
    numberBlocksUsed_ = SYSTEM_BLOCKS;
    std::fstream ofile;
    ofile.open(name_.c_str() , std::ios::out | std::ios::binary);
    for(unsigned i = 0 ; i<size ; ++i){
        ofile.write(buf, BLOCK_SIZE);
    }
    ofile.close();
}

void VirtualFileSystem::removeFile(std::string fileName) {
    inode *node;
    if((node = findInode(fileName)) == NULL)
        throw std::logic_error("File doesn't exist.");
    std::swap(*node,inodeVector_.back());
    inodeVector_.pop_back();
}

void VirtualFileSystem::listAllFiles(){
    std::cout << std::setw(10) << "start"
              << std::setw(10) << "koniec"
              << std::setw(10) << "rozmiar"
              << std::setw(10) << "rozmiar"
              << std::setw(30) << "nazwa" << std::endl;
    std::cout << std::setw(10) << "[blok]"
              << std::setw(10) << "[blok]"
              << std::setw(10) << "[bloki]"
              << std::setw(10) << "[bajty]" << std::endl;
    for(unsigned i = 0; i < inodeVector_.size(); ++i)
    {
        std::cout << std::setw(10) << inodeVector_[i].begin
                  << std::setw(10) << inodeVector_[i].end()-1
                  << std::setw(10) << inodeVector_[i].blocks
                  << std::setw(10) << inodeVector_[i].size
                  << std::setw(30) << inodeVector_[i].name << std::endl;
    }
}

VirtualFileSystem::inode *VirtualFileSystem::findInode(std::string name) {
    for(unsigned i = 0; i<inodeVector_.size() ; ++i){
        if(inodeVector_[i].name == name)
            return &inodeVector_[i];
    }
    return NULL;
}

