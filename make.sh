#!/usr/bin/env bash
set -x
if [ -z $2 ]
then
  echo "You must supply the src file basename."
  exit 1
fi
FILE=$2

case $1 in
  watch )
    echo -e "\n---> Watching...\n"
    while true
    do
      while inotifywait -e close_write $FILE.cpp
      do
        echo
      done;
      echo -e "\n---> File $FILE changed.\n"
      ./make.sh all $FILE;
    done
    ;;
  clean)
    echo -e "\n---> Cleaning...\n"
    ;;
  all)
    echo -e "\n---> Building...\n"
    mkdir -p build/
    g++ -std=c++11 -o build/$FILE $FILE.cpp
    chmod +x build/$FILE
    ;;
  *)
    echo "Usage: $0 {all|watch}"
    exit 1
    ;;
esac
