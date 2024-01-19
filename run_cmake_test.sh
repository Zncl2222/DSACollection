#!/bin/bash
mkdir build
cd build
cmake ..
make test

# line=$(grep -A 12 "# Set test targets" ../CMakeLists.txt)
line=$(sed -n '/# Set test targets/,/# End of test targets/p' ../CMakeLists.txt)

for target in $(echo $line | awk '{for(i=7;i<NF;i++) print $i}'); do
    if [ $target = ")" ]; then
        break
    fi
    make memcheck_$target
done

cd ..
