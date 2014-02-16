#!/usr/bin/env bash
#
# Mike's Makefile Alternative
#
# Usage:
#   ./make.sh all copy1
#   ./make.sh watch copy1
#

#set -x

if [ -z $2 ]; then
  echo "You must supply the src file basename."
  exit 1
fi
BASENAME=$2

case $1 in
  # makes dev cycles feel faster;
  # more like a scripting language
  watch )
    echo -e "---> Watching...\n"
    while true; do
      clear

      ./make.sh all $BASENAME

      if [ $? -eq 0 ]; then
        echo -e "---> Executing...\n"
        build/$BASENAME &
        PID="$!"
      else
        PID=""
      fi

      # watch for file change
      inotifywait -q -q -e 'close_write' $BASENAME.cpp

      # kill the process
      if [ $PID -gt 0 ] ; then
        kill $PID
      fi
    done
    ;;
  clean)
    echo -e "---> Cleaning...\n"
    rm -rf build/
    ;;
  all)
    echo -e "---> Building...\n"
    mkdir -p build/ && \
    g++ -std=c++11 -o build/$BASENAME $BASENAME.cpp && \
    #g++ -std=c++11 -c Vector.cpp -o build/Vector.o && \
    #g++ -std=c++11 -c $BASENAME.cpp -o build/$BASENAME.o && \
    #g++ -std=c++11 -o build/$BASENAME build/Vector.o build/$BASENAME.o && \
    chmod +x build/$BASENAME
    ;;
  *)
    echo "Usage: $0 {all|clean|watch}"
    exit 1
    ;;
esac
