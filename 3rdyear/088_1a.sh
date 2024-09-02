#!/bin/bash
#
#	Assignment1
#	Name =  Hrithvik Kondalkar
#	Roll = 002211001088
#	
#Assignment 1A
#Familiarity with User and System level OS Commands

echo "Question 1A"

#Q1. who:-It displays the information about all the users who have logged into the system currently
#A1.
echo "running who command - displays all users" 
who
#running who command - displays all users
#(unknown) :0           2023-10-30 11:07 (:0)
#be2284   pts/0        2024-07-29 12:20 (172.16.4.139)
#root     pts/1        2024-07-29 11:39 (172.16.5.159)
#be22L05  pts/2        2024-07-29 12:43 (172.16.4.141)
#be22L06  pts/3        2024-07-29 11:57 (172.16.4.144)
#be22105  pts/4        2024-07-29 12:14 (172.16.4.133)
#be2288   pts/5        2024-07-29 11:58 (172.16.4.140)
#be22107  pts/6        2024-07-29 12:49 (172.16.4.143)
#be22103  pts/7        2024-07-29 12:05 (172.16.4.155)
#be2276   pts/8        2024-07-29 11:59 (172.16.4.137)
#be22100  pts/9        2024-07-29 12:00 (172.16.4.158)
#be22L04  pts/10       2024-07-29 11:50 (172.16.4.216)
#be22108  pts/11       2024-07-29 12:01 (172.16.4.159)
#be22L04  pts/12       2024-07-29 12:21 (172.16.4.161)
#be2296   pts/13       2024-07-29 12:04 (172.16.4.176)
#be2294   pts/14       2024-07-29 12:05 (172.16.4.153)
#be22104  pts/15       2024-07-29 12:06 (172.16.4.135)
#be22109  pts/17       2024-07-29 12:57 (172.16.4.148)
#be2298   pts/19       2024-07-29 12:50 (172.16.4.157)
#be2286   pts/20       2024-07-29 12:09 (172.16.4.129)
#be2279   pts/21       2024-07-29 12:09 (172.16.4.145)
#be2292   pts/22       2024-07-29 12:10 (172.16.4.146)
#be2295   pts/23       2024-07-29 12:12 (172.16.4.136)
#be2279   pts/24       2024-07-29 12:13 (172.16.4.145)
#be22106  pts/25       2024-07-29 12:18 (172.16.4.162)
#be21140  pts/26       2024-07-29 12:58 (172.16.4.149)
#be22101  pts/27       2024-07-29 12:59 (172.16.4.163)
#be2289   pts/28       2024-07-29 12:38 (172.16.4.147)
#be2297   pts/30       2024-07-29 12:50 (172.16.4.160)
#be2296   pts/31       2024-07-29 13:02 (172.16.4.154)


#Q2. whoami:- It displays Current username, Terminal number, date and time at which user logged into the system
#A2.
echo "running whoami command - displays current user"
whoami
#running whoami command - displays current user
#be2288


#Q3. pwd:- It displays current working directory
#A3. 
echo "running pwd command - current working directory"
pwd
#running pwd command - current working directory
#/home/usr/student/ug/yr22/be2288/thirdyear/os


#Q4. date:- It displays system date and time
#A4. 	
echo "running date command - displays date"
date
#running date command - displays date
#Mon Jul 29 13:17:56 IST 2024

#Q5. ls - It lists the files and directories stored in the current directory. To list the files in a directory use the following syntax: $ls dirname
echo "running ls command- displays files and directories in current directory"
ls
#running ls command- displays files and directories in current directory
#1088.sh
#output1a.txt
#sortme.txt


#Q6. mkdir – It is used to create directories by using the command: $mkdir dirname
#A6.
echo "running mkdir - new dir : newdir"
mkdir newdir
#running mkdir - new dir : newdir


#Q7. clear- It clears the screen
#A7. 
echo "not running clear - as it will clear my output"
#not running clear - as it will clear my output


#Q8. cd - It is used to change the current working directory to any other directory specified
#A8.
echo "running cd"
echo "current dir"
pwd
cd newdir
echo "current dir"
pwd
#running cd
#current dir
#/home/usr/student/ug/yr22/be2288/thirdyear/os
#current dir
#/home/usr/student/ug/yr22/be2288/thirdyear/os/newdir


#Q9. cd.. -This command is used to come out from the current working directory.
#A9. 
echo "going back in parent dir"
cd ..
echo "current dir"
pwd
#going back in parent dir
#current dir
#/home/usr/student/ug/yr22/be2288/thirdyear/os



#Q10. rmdir - Directories can be deleted using the rmdir command - $rmdir dirname
#A10.
echo "rmdir - remove directory"
rmdir newdir
#rmdir - remove directory



#Q11. cat – It displays the contents of a file - $cat filename
#A11. 
echo "somedata" > somefile.txt
echo "using cat to view somefile.txt"
cat somefile.txt
#using cat to view somefile.txt
#somedata



#Q12. cp - It is used to copy a file - $ cp source_file destination_file
#A12.
echo "copying somefile to someotherfile"
cp somefile.txt someotherfile.txt
#copying somefile to someotherfile



#Q13. mv- It is used to change the name of a file - $ mv old_file new_file
#A13.
echo "moving somefile to newfile"
mv somefile.txt newfile.txt
#moving somefile to newfile



#Q14. rm – It is used to delete an existing file - $ rm filename
#A14.
echo "deleting txt files"
rm newfile.txt someotherfile.txt
#deleting txt files



#Q15. stat- It is used to display file or file system status - $ stat filename
#A15.
echo "stat - displaying file info"
stat 088_1a.sh
#stat - displaying file info
#  File: ‘088_1a.sh’
#  Size: 7770            Blocks: 16         IO Block: 4096   regular file
#Device: fd02h/64770d    Inode: 1883492923  Links: 1
#Access: (0755/-rwxr-xr-x)  Uid: ( 3071/  be2288)   Gid: ( 2924/  ugyr22)
#Context: unconfined_u:object_r:user_home_t:s0
#Access: 2024-08-05 12:59:05.394227249 +0530
#Modify: 2024-08-05 12:58:38.898226907 +0530
#Change: 2024-08-05 12:59:01.836227203 +0530
# Birth: -



#Q16. stty – Change and print terminal line settings. Its option – “stty –a” prints all current settings in human readable form
#A16.
echo "stty - terminal line settings"
stty -a
#stty - terminal line settings
#speed 38400 baud; rows 38; columns 142; line = 0;
#intr = ^C; quit = ^\; erase = ^?; kill = ^U; eof = ^D; eol = M-^?; eol2 = M-^?;
#swtch = <undef>; start = ^Q; stop = ^S; susp = ^Z; rprnt = ^R; werase = ^W;
#lnext = ^V; flush = ^O; min = 1; time = 0;
#-parenb -parodd -cmspar cs8 -hupcl -cstopb cread -clocal -crtscts
#-ignbrk -brkint -ignpar -parmrk -inpck -istrip -inlcr -igncr icrnl ixon -ixoff
#-iuclc -ixany -imaxbel iutf8
#opost -olcuc -ocrnl onlcr -onocr -onlret -ofill -ofdel nl0 cr0 tab0 bs0 vt0 ff0
#isig icanon iexten echo echoe echok -echonl -noflsh -xcase -tostop -echoprt
#echoctl echoke



#Q17. tty – It prints the filename of the terminal connected to standard input.
#A17.
echo "tty - filename of terminal connected to std in"
tty
#tty - filename of terminal connected to std in
#/dev/pts/5



#Q18. uname –It prints system information
#A18.
echo "uname - system info"
uname
#uname - system info
#Linux



#Q19. umask – It specifies user file creation mask, implying which of the 3 permissions are to be denied to the owner,group and others.
#A19.
echo "umask - user file creation mask"
umask -S
#umask - user file creation mask
#u=rwx,g=rx,o=rx



#Q20. find – It searches for files in a directory hierarchy
#A20. 
echo "find - file searching"
echo "filedata" > myfile.txt
find myfile.txt
rm myfile.txt
#find - file searching
#myfile.txt



#Q21. sort – It sorts the lines of text files
#A21.
echo "sorting a file."
echo "original file: "
cat sortme.txt
echo "sorted : "
sort sortme.txt
#sorting a file.
#original file: 
#2
#45
#1
#23
#46
#23
#21
#43
#sorted : 
#1
#2
#21
#23
#23
#43
#45
#46



#Q22. ps - It displays information about the current processes.
#A22.
echo "running ps - current processes"
ps
#running ps - current processes
#  PID TTY          TIME CMD
# 7083 pts/5    00:00:00 bash
#10558 pts/5    00:00:00 vim
#14953 pts/5    00:00:00 00_01.sh
#14972 pts/5    00:00:00 ps



#Q23. chmod 777 file1 - gives full permission to owner, group and others
#A23.
chmod 777 sortme.txt
echo "chmod was used to set sortme.txt permissions"



#Q24. chmod o-w file1 - Removes write permission for others.
#A24.
chmod o-w sortme.txt
echo “chmod was used to remove write permissions for sortme.txt for others”





