# CMake generated Testfile for 
# Source directory: /home/cezar/CLionProjects/RPG_GAME_lin
# Build directory: /home/cezar/CLionProjects/RPG_GAME_lin/cmake-build-debug
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(UnitTests "runGameTests")
set_tests_properties(UnitTests PROPERTIES  _BACKTRACE_TRIPLES "/home/cezar/CLionProjects/RPG_GAME_lin/CMakeLists.txt;108;add_test;/home/cezar/CLionProjects/RPG_GAME_lin/CMakeLists.txt;0;")
subdirs("Packages/googletest")
