#!/usr/bin/env bash
#set -x
if [ -z $2 ]; then
  echo "You must supply the src file basename."
  exit 1
fi
BASENAME=$2

case $1 in
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
    chmod +x build/$BASENAME
    ;;
  *)
    echo "Usage: $0 {all|clean|watch}"
    exit 1
    ;;
esac
