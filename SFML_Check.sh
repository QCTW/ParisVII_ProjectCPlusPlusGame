#!/bin/bash

if [ -d "$1" ]; then 
  echo "SFML include directory: $1 found"; 
else 
  echo "SFML library $1 is not installed! Visit SFML page to install: http://www.sfml-dev.org/tutorials/2.0/start-linux.php";
fi
