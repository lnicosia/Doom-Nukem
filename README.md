# Doom-Nukem
![](docs/Doom-main.png)

This is my Doom-Nukem project from 42.

A game engine similar to the original Doom or Duke Nukem 3D games.

## Summary

* [Introduction](#introduction)
* [Technologies](#technologies)
* [Constraints](#contraints)
* [Features](#features)
* [Installation](#installation)
* [How to use](#User guide)
* [Authors](#authors)

## Introduction

Following the first two graphical projects from 42 ([FdF](https://github.com/lnicosia/Fdf) and [Fract'ol](https://github.com/lnicosia/fractol)), the students must now recreate the legendary Wolfenstein 3D and Doom video games. But of course, it is more fun if they have to do it with the  same conditions John Carmack and his crew had at the time. This means everything in C and only C, no hardware acceleration and a lot of metal music.

## Technologies

This project was coded in C and used 3 external libraries:

* SDL2 for graphical rendering.
* SDL2_ttf (extension of SDL2) for text rendering.
* FMOD for the sound/music part.

## Constraints

Here is a non exhaustive list of the restrictions we had to follow:

* C was mandatory

* Drawing only by filling a one-dimension array of pixels
* Computing everything on the CPU (using even 0,001% of the GPU would be flagged as 'cheat') while maintaining a decent framerate, because there was no GPU in 1993
* Using different libraries for the graphical and sound parts
* Compiling and linking the graphical l libraries ourselves
* Of course any crash or memory leak would mean the project has failed

## Features

This game features two applications: doom-nukem and doom-editor.

The first one is the game executable. It allows you to play any map created with the editor. You play a soldier 

## Installation

## User guide

## Authors

Gabriel Erhard

Lucas Nicosia

Simon Patry