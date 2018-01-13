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
    unsigned hole, nodes; //indexOfFirstiNode = 0 , indexOdLastNode = 0;
    while(1){
        nodes = inodeVector_.size();
        //sortiNodeVector();
        /*for(unsigned i = 0 ;  i < inodeVector_.size(); i++){
            if(inodeVector_[i].begin < inodeVector_[indexOfFirstiNode].begin)
                indexOfFirstiNode=i;
            if(inodeVector_[i].end()>inodeVector_[indexOdLastNode].end())
                indexOdLastNode=i;
        }*/
        if(nodes == 0 || inodeVector_[0].begin - SYSTEM_BLOCKS >= blocks){
            return SYSTEM_BLOCKS;
        }

        for( unsigned i = 1 ; i < inodeVector_.size() ; ++i) {
            hole = inodeVector_[i].begin - inodeVector_[i-1].end() ;
            if(hole >= blocks )
                return inodeVector_[i-1].end();
        }
        if(nodes != 0 && size_ - inodeVector_[nodes-1].end() >= blocks) {
            std::cout<<blocks<<std::endl;
            return inodeVector_[nodes-1].end();
        }
        /*jezeli nie znajdziesz miejsca defragmentacja*/
        defragment();
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
    sortiNodeVector();
    /*firstINode = inodeVector_[0];
    for(unsigned i = 1 ; i < inodeVector_.size() ; i++){
        if(firstINode.begin > inodeVector_[i].begin)
            firstINode = inodeVector_[i];
    }*/
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
        std::cout << std::setw(10) << i
                  << std::setw(10) << inodeVector_[i].begin
                  << std::setw(10) << inodeVector_[i].end()-1
                  << std::setw(10) << inodeVector_[i].blocks
                  << std::setw(10) << inodeVector_[i].size
                  << std::setw(30) << inodeVector_[i].name << std::endl;
    }
}

void VirtualFileSystem::mapFileSystem() {
    char tab[size_];
    for(unsigned i = 0 ; i< SYSTEM_BLOCKS; ++i)
        tab[i] = '*';
    for(unsigned i = SYSTEM_BLOCKS; i < size_; ++i)
        tab[i]='|';
    for(unsigned i = 0 ; i < inodeVector_.size(); ++i){
        for(unsigned j = inodeVector_[i].begin; j < inodeVector_[i].end(); ++j)
            tab[j]=inodeVector_[i].name[0];
    }
    std::cout<<"Legenda: "<<std::endl
             <<" '*' blok systemowy "<<std::endl
             <<" '|' blok wolny "<<std::endl
             <<" 'n' blok zajety -> pierwsza litera nazwy pliku" << std::endl
             <<"wielkosc bloku "<<BLOCK_SIZE<<std::endl;
    for(unsigned i = 0; i < size_ ; ++i)
    {
        std::cout<<tab[i];
    }
    std::cout<<std::endl;
}

VirtualFileSystem::inode *VirtualFileSystem::findInode(std::string name) {
    for(unsigned i = 0; i<inodeVector_.size() ; ++i){
        if(inodeVector_[i].name == name)
            return &inodeVector_[i];
    }
    return NULL;
}

void VirtualFileSystem::renameFile(std::string oldName, std::string newName) {
    if(findInode(newName) != NULL){
        throw std::logic_error("File with that name already exists");
    }
    inode *node;
    if((node = findInode(oldName)) == NULL){
        throw std::logic_error("File with that name doesn't exist");
    }
    strcpy(node->name, newName.c_str());
}

void VirtualFileSystem::openFile() {
    size_ = static_cast<unsigned int>(getFileSize(name_) / BLOCK_SIZE);
    buffer_ buff[SYSTEM_BLOCKS];
    std::ifstream ifile;
    ifile.open(name_.c_str(), std::ios::in| std::ios::binary);
    for(unsigned i = 0 ; i < SYSTEM_BLOCKS ; i++){
        ifile.read(buff[i], BLOCK_SIZE);
    }
    numberBlocksUsed_ = SYSTEM_BLOCKS;
    for(unsigned i = 0; i < SYSTEM_BLOCKS ; i++){
        for(unsigned j = 0 ; i < BLOCK_SIZE; i += sizeof(inode))
        {
            inode new_inode =  *reinterpret_cast<inode *>(buff[j]+i);
            if(new_inode.used)
            {
                inodeVector_.push_back(new_inode);
                numberBlocksUsed_ += new_inode.blocks;
            }
        }
    }
    ifile.close();
}

size_t VirtualFileSystem::getFileSize(std::string name) {
    struct stat st;
    if(stat(name.c_str() , &st) != 0)
        return 0;
    return st.st_size;
}

void VirtualFileSystem::uploadFile(std::string source) {
    std::string dest = source;
    if(findInode(dest) != NULL )
        throw std::logic_error("File with that name already is on our disk");
    unsigned source_size = static_cast<unsigned int>(getFileSize(source));
    unsigned source_blocks = (source_size - 1) /BLOCK_SIZE + 1; //zaokralglanie w gore
    unsigned numberOfBlocksFree = size_ - numberBlocksUsed_;
    if(source_blocks > numberOfBlocksFree){
        throw std::overflow_error("Not enough space to upload file");
    }
    unsigned position = alloc(source_blocks);
    buffer_  buff[source_blocks];
    std::ifstream ifile;
    ifile.open(source.c_str());
    for(unsigned i = 0 ; i < source_blocks ; ++i){
        ifile.read(buff[i], BLOCK_SIZE);
    }
    std::ofstream ofile;
    ofile.open(name_.c_str(), std::ios::in|std::ios::out|std::ios::binary);
    ofile.seekp(position * BLOCK_SIZE);
    for(unsigned i = 0 ; i < source_blocks ; ++i){
        ofile.write(buff[i], BLOCK_SIZE);
    }
    inode newInode;
    newInode.used = 1;
    newInode.begin = position;
    newInode.size = source_size;
    newInode.blocks = source_blocks;
    strcpy(newInode.name , dest.c_str());
    inodeVector_.push_back(newInode);
    ofile.close();
    ifile.close();
}

void VirtualFileSystem::downloadFile(std::string) {

}

void VirtualFileSystem::defragment() {
    //todo zmien defragment zeby za kazdym wywolaniem zsuwalo wszystkie pliki
    unsigned index = 0, newPosition = SYSTEM_BLOCKS;
    if (inodeVector_[0].begin == SYSTEM_BLOCKS) {
        for (index = 1; index < inodeVector_.size(); ++index) {
            if (inodeVector_[index - 1].end() < inodeVector_[index].begin) {
                //znalezlismy dziure
                newPosition = inodeVector_[index - 1].end();
                break;
            }
        }
    }
    /*for( index = 0; index < inodeVector_.size(); index++){
        inodeVector_[index].begin = newPosition;
        newPosition = inodeVector_[index].end();
    }*/
    unsigned blocks = inodeVector_[index].blocks;
    unsigned oldPosition = inodeVector_[index].begin;
    inodeVector_[index].begin = newPosition;
    buffer_ buff[blocks];
    std::ifstream ifile;
    ifile.open(name_.c_str());
    ifile.seekg(oldPosition * BLOCK_SIZE);
    for (unsigned i = 0; i < blocks; ++i){
        ifile.read(buff[i], BLOCK_SIZE);
    }
    std::fstream ofile;
    ofile.open(name_.c_str(), std::ios::in|std::ios::out|std::ios::binary);
    ofile.seekp(newPosition * BLOCK_SIZE);
    for(unsigned i = 0; i < blocks ; ++i){
        ofile.write(buff[i], BLOCK_SIZE);
    }
    ifile.close();
    ofile.close();
}

void VirtualFileSystem::sortiNodeVector() {
    inode tmp;
    for(unsigned i = 1; i < inodeVector_.size(); i++){
        for(unsigned j = 0 ; j < inodeVector_.size() - i; j++)
            if(!cmpInode(inodeVector_[j],inodeVector_[j+1])){
                tmp = inodeVector_[j];
                inodeVector_[j]=inodeVector_[j+1];
                inodeVector_[j+1]=tmp;
            }
    }
}
