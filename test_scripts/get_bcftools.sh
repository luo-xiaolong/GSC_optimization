#!/usr/bin/env bash
mkdir bcftools_folder
cd bcftools_folder 
wget https://github.com/samtools/bcftools/releases/download/1.11/bcftools-1.11.tar.bz2
tar -xf bcftools-1.11.tar.bz2
cd bcftools-1.11
./configure
make
cp bcftools ../../