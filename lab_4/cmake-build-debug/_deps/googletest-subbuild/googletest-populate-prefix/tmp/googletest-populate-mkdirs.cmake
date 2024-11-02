# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "A:/mai_stuff/OOP/lab_4/cmake-build-debug/_deps/googletest-src"
  "A:/mai_stuff/OOP/lab_4/cmake-build-debug/_deps/googletest-build"
  "A:/mai_stuff/OOP/lab_4/cmake-build-debug/_deps/googletest-subbuild/googletest-populate-prefix"
  "A:/mai_stuff/OOP/lab_4/cmake-build-debug/_deps/googletest-subbuild/googletest-populate-prefix/tmp"
  "A:/mai_stuff/OOP/lab_4/cmake-build-debug/_deps/googletest-subbuild/googletest-populate-prefix/src/googletest-populate-stamp"
  "A:/mai_stuff/OOP/lab_4/cmake-build-debug/_deps/googletest-subbuild/googletest-populate-prefix/src"
  "A:/mai_stuff/OOP/lab_4/cmake-build-debug/_deps/googletest-subbuild/googletest-populate-prefix/src/googletest-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "A:/mai_stuff/OOP/lab_4/cmake-build-debug/_deps/googletest-subbuild/googletest-populate-prefix/src/googletest-populate-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "A:/mai_stuff/OOP/lab_4/cmake-build-debug/_deps/googletest-subbuild/googletest-populate-prefix/src/googletest-populate-stamp${cfgdir}") # cfgdir has leading slash
endif()
