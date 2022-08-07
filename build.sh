#!/bin/sh
cd "$(dirname "$0")"
g++ -O -c src/*.cpp
g++ *.o -o hacking-game -lsfml-graphics -lsfml-window -lsfml-system
