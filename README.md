**metadata-project**

This project was developed to help artists and users manage their MP3 file meta-data. 
It is our aim to allow users to catagorize their audio files with ID3 tags they
otherwise could not alter. 


**Download Instructions**

# vcpkg and taglib

This project requires taglib and cmake. We recommend downloading vcpkg and using taglibs cmake installation.

*Step 1*
Clone vcpkg to a dedicated directory on your computer using 
"git clone https://github.com/microsoft/vcpkg.git"

*Step 2*
In your command line
use "cd vcpkg" to access the directory
then "./bootstrap-vcpkg.bat"

*Step 3*
Install taglib by running
"./vcpkg install taglib" while still in the vcpkg directory

*Step 4*
COMPLETE AFTER CLONING "meta-project"
link meta-project and vcpkg by running
g++ -std=c++17 -o meta-project-2 meta-project-2.cpp -I<vcpkg_root>\installed\x64-windows\include -L<vcpkg_root>\installed\x64-windows\lib -ltag


# Cloning the Repository

in vscode or github codespaces type
"git clone https://github.com/amamiyasiren/metadata-project.git"
to clone the repository. Add it to a dedicated directory on your computer.
