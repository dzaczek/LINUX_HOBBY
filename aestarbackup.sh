#!/bin.sh
#Create 1 gb parta
#v0.01
# $1 what backup 
# $2 namebackup 
#Change passss this  is password for encrypt
passss="test1"
target=$1
backupname=$2
#size file deflaut 100mb
size=102400 
mkdir backuptar
namebackup="backuptar/$backupname";
sizex=$((size*1024))
numfile=$(($(du  --max-depth=0 $target | cut -d$'\t' -f1)/$size)); echo $numfile
numfile=$(($numfile+1));
#create tar file 
tar  -c -M -L $size $(for i in `seq 1 $numfile`; do echo "--file=$namebackup$i.tar"; done) $target
#Openssl crypt created files and deleted old tar 
for mi in `seq 1 $numfile`;
do 
openssl enc -aes-256-cbc  -in $namebackup$mi.tar -out $namebackup$mi.tar.r2d2 -k $passss && rm  $namebackup$mi.tar 
done
