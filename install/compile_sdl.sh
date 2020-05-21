#!bin/bash
cd lib/SDL2-2.0.8
sudo ./configure
make -j4
sudo make -j4 install
cd ../SDL2_ttf-2.0.15
sudo ./configure
make -j4
sudo make -j4 install
