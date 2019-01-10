
set -e 


ROOT_DIR=`pwd`

if [ ! -e ./build/mac/cmakebuild ]; then mkdir ./build/mac/cmakebuild; fi
cd ./build/mac/cmakebuild
cmake ../../
make clean
make

set +e