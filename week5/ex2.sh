#!/bin/bash
if ! [[ -f 'file' ]]; then
  echo 1 > file
fi

while true;
  do
    if ln file file.lock; then
      echo $(( $(tail -n 1 file) + 1 )) >> file
      rm file.lock
    fi
  done
