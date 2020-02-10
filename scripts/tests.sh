#! /bin/sh

set -ex

ls -la
ls -la Content

git submodule update --init --recursive
sudo apt-get install -y libfreetype6-dev libxrandr-dev libudev-dev libogg-dev libflac-dev libvorbis-dev libopenal-dev
sudo ln -s /usr/bin/gcc-8 /usr/local/bin/gcc
sudo ln -s /usr/bin/g++-8 /usr/local/bin/g++
mkdir -p .build
# shellcheck disable=SC2164
cd .build
cmake .. -DBUILD_TESTS=On
cd ..
cmake --build .build

./.build/tests
#cmake --build .