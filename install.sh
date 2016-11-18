#!/bin/bash

# use this file to compile code on your system
echo "preparing to install Battleship..."
mkdir _temp && cd _temp
cmake ../
make

echo "finished installing Battleship you may now use it"
echo "either run start.sh or directly ./run inside _temp directory"