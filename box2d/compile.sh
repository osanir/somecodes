#!/bin/bash

g++ -c main.cpp 
g++ main.o -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system -lGL -lsfml-audio -lb2d
./sfml-app 

