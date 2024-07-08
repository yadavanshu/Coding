# Ubuntu


**Basic Commands**
- ls: List directory contents
- cd: Change directory
- pwd: Print working directory
- cp: Copy files or directories
- mv: Move/rename files or directories
- rm: Remove files or directories
- touch: Create an empty file
- cat: Concatenate and display file content
- echo: Display a line of text
- find: Search for files in a directory hierarchy

## Miscellaneous

- alias [name]='[command]': Create an alias
- unalias [name]: Remove an alias
- history: Show command history
- clear: Clear the terminal screen

- env : to check the enivroment variable of the machine


/bin/bash : to enter the bash of the vm 
/bin/sh : to enter the shell of the vm


- locate : to find the path of file 
- ls --help | more : 
- man ls : 
- cal :
- cal 2020 :
- script : to recorde exit: to exit from script
- alias lg="log --oneline --graph --decorate" :
- alias -p : 






shell scripting --> .sh files
-------------------------------------------------------------------------------------------------------------------------------

Ubuntu -> AWS EC2 Instance
--------------------------

- $ sudo apt-get update  --> to up-to-date the system



sudo is used to execute any command as a superuser

- sudo apt update
- sudo apt upgrade

**Add new user**
- sudo adduser ben


- which ls --> gives /usr/bin/ls

- ps --> to show shell ps - process status

- hostname 
- uname
- uname -r
- uname -a

- ifconfig
- ip
- netstat
- ss
- ps
- who
- env
- lsblk
- lsof
- man uname
- apropros usb

## Manage and Install in Linux

- sudo apt update
- sudo apt install pidgin
- apt list --installed
- sudo apt remove pidgin  --> it will not remove user data
- sudo apt purge pidgin  --> will remove anything
- sudo apt list --installed | grep ^pidgin
- sudo apt purge pidgin-data  --> will remove anything
- sudo apt update && sudo apt upgrade




--------------------------------------------------------------------
- ls -l ---> to see the permissions

- chmod +x run.sh ---> to give executable permission



#!/bin/bash

name=$1 --> to give arguments 

echo "Hi, my name is $name"


whoami=$(whoami)
pwd=$(pwd)


echo "y/n"
read condition

if [[$condition == "y"]] then
        echo "Hi,"
else
        echo "Bye,"


x=1

while [[$x -le 100]]   --> -le --> less than equal to
do 
    echo "Hey, "
done










