#!/bin/sh

VFS_FILE="drive"

echo 'wypisujemy segmenty dysku'
./SOI_FileSystem f $VFS_FILE m

echo 'wypisujemy wszystkie pliki'
./SOI_FileSystem f $VFS_FILE l

echo 'dodajemy plik ktory sie nie zmiesci, przeprowadzamy defragmentacje dysku'
./SOI_FileSystem f $VFS_FILE u abc.txt

echo 'wypisujemy segmenty dysku'
./SOI_FileSystem f $VFS_FILE m

echo 'wypisujemy wszystkie pliki'
./SOI_FileSystem f $VFS_FILE l

./SOI_FileSystem f $VFS_FILE n Plik_2kB-kopia.txt 1.txt


./SOI_FileSystem f $VFS_FILE n abc.txt 2.txt


./SOI_FileSystem f $VFS_FILE d 1.txt

./SOI_FileSystem f $VFS_FILE d 2.txt

diff 1.txt Plik_2kB-kopia.txt

diff 2.txt abc.txt

echo 'usuwamy dysk'
./SOI_FileSystem f $VFS_FILE x
