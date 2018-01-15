#!/bin/sh

VFS_FILE="drive"

echo 'tworzymy dysk o wielkosci 20 blokow'
./SOI_FileSystem f $VFS_FILE c 20

echo 'wypisujemy segmenty dysku'
./SOI_FileSystem f $VFS_FILE m

echo 'dodajemy plik'
./SOI_FileSystem f $VFS_FILE u ja.txt

echo 'wypisujemy wszystkie pliki'
./SOI_FileSystem f $VFS_FILE l

echo 'dodajemy kolejne 2 pliki'
./SOI_FileSystem f $VFS_FILE u Plik_2kB.txt
echo
./SOI_FileSystem f $VFS_FILE u Plik_2kB-kopia.txt

echo 'zmieniamy nazwe 1'
./SOI_FileSystem f $VFS_FILE n ja.txt ty.txt
echo
./SOI_FileSystem f $VFS_FILE l

echo 'pobieramy zmieniony plik'
./SOI_FileSystem f $VFS_FILE d ty.txt

echo 'usuwamy srodkowy plik'
./SOI_FileSystem f $VFS_FILE r Plik_2kB.txt
echo
./SOI_FileSystem f $VFS_FILE m
echo
./SOI_FileSystem f $VFS_FILE l