mkdir build
cd build
cmake ..
make test && make memcheck
cd ..
