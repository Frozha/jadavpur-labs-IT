#!/bin/bash
# Output

#
#Creating a directory 'All My Cprogs Files' in the current working directory...
#Directory 'All My Cprogs Files' created.

#Moving all .c files to 'All My Cprogs Files' directory...
#All .c files moved to 'All My Cprogs Files'.

#Listing all files in the current directory:
#088_8.sh  'All My Cprogs Files'   reset.sh   textfile.txt

#Displaying the current working directory:
#/workspaces/jadavpur-labs-IT/3rdyear/os/Assignment8

#Displaying the current date in dd:mm:yy format:
#13:11:24

#Counting the number of files in the current directory:
#Number of files in the current directory: 4

#Creating a file named 'c_files_list.txt' that lists all .c files in the current directory...
#'c_files_list.txt' created with a list of .c files.

#Enter two numbers to calculate their sum.
#Enter first number:
#2
#Enter second number:
#2
#Sum of 2 and 2 is: 4

#Enter a filename to convert lowercase to uppercase and vice versa:
#textfile.txt
#Converted file saved as 'converted_textfile.txt'.
#
#Enter a number to generate a pattern:
#4
#Pattern:
#1 
#1 2 
#1 2 3 
#1 2 3 4 


# Override HOME variable to be the current working directory
# for the sake of not affecting all other C files
HOME=$(pwd)

# 1. Create a directory ‘All My Cprogs Files’ in your home directory
echo
echo "Creating a directory 'All My Cprogs Files' in the current working directory..."
mkdir "$HOME/All My Cprogs Files"
echo "Directory 'All My Cprogs Files' created."

# 2. Move all the C files to the new directory
echo
echo "Moving all .c files to 'All My Cprogs Files' directory..."
mv "$HOME"/*.c "$HOME/All My Cprogs Files"
echo "All .c files moved to 'All My Cprogs Files'."

# 3. Show the list of files in your current directory
echo
echo "Listing all files in the current directory:"
ls

# 4. Show Current working directory
echo
echo "Displaying the current working directory:"
pwd

# 5. Display date in the dd:mm:yy format
echo
echo "Displaying the current date in dd:mm:yy format:"
date +"%d:%m:%y"

# 6. Count the number of files in the current directory
echo
echo "Counting the number of files in the current directory:"
file_count=$(find "$HOME" -type f | wc -l)
echo "Number of files in the current directory: $file_count"

# 7. Create a file that lists all of the .c files in the current directory
echo
echo "Creating a file named 'c_files_list.txt' that lists all .c files in the current directory..."
find "$HOME" -name "*.c" > c_files_list.txt
echo "'c_files_list.txt' created with a list of .c files."

# 8. Script for addition of two numbers (real numbers included)
echo
echo "Enter two numbers to calculate their sum."
echo "Enter first number:"
read num1
echo "Enter second number:"
read num2
sum=$(echo "$num1 + $num2" | bc)
echo "Sum of $num1 and $num2 is: $sum"

# 9. Script to convert lowercase to uppercase and uppercase to lowercase in a file
echo
echo "Enter a filename to convert lowercase to uppercase and vice versa:"
read filename
if [ -f "$filename" ]; then
    tr 'a-zA-Z' 'A-Za-z' < "$filename" > converted_"$filename"
    echo "Converted file saved as 'converted_$filename'."
else
    echo "File '$filename' does not exist. Skipping case conversion."
fi

# 10. Generate a pattern based on input 'n'
echo
echo "Enter a number to generate a pattern:"
read n
echo "Pattern:"
for ((i = 1; i <= n; i++)); do
    for ((j = 1; j <= i; j++)); do
        echo -n "$j "
    done
    echo ""
done
