#! /bin/sh

set -ex

mkdir -p .build
cd .build
cmake .. -DBUILD_TESTS=On -DBUILD_COVERAGE=On
cmake --build .
cmake --build . --target gcov
cmake --build . --target test

cd ..
gcovr -r . -e .build -e tests