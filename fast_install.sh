cd lib
tar -xf SDL2-2.0.8.tar.gz
tar -xf freetype-2.9.tar.gz
tar -xf SDL2_ttf-2.0.15.tar.gz
sudo apt-get install freeglut3-dev
cd SDL2-2.0.8
sudo ./configure
make -j4
sudo make -j4 install
cd ../freetype-2.9
sudo ./configure
make -j4
sudo make -j4 install
cd ../SDL2_ttf-2.0.15
sudo ./configure
make -j4
sudo make -j4 install
