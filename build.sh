gcc -I include -o build/StudManageSys *.c

if (($?==0))
then
    ./build/StudManageSys
fi