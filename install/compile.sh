cd ..
sudo cp sound_lib/libfmod.dylib /usr/local/lib
sudo cp sound_lib/libfmodL.dylib /usr/local/lib
cd lib
for f in *.gz; do tar -xvf "$f"; done
cd libelf-0.8.13
sudo ./configure
make -j4
sudo make -j4 install
cd ../libXrender-0.9.10
sudo ./configure
make -j4
sudo make -j4 install
cd ../libXrandr-1.5.2
sudo ./configure
make -j4
sudo make -j4 install
cd ../libxshmfence-1.3
sudo ./configure
make -j4
sudo make -j4 install
cd ../libXxf86vm-1.1.4
sudo ./configure
make -j4
sudo make -j4 install
cd ../xcb-proto-1.14
sudo ./configure
make -j4
sudo make -j4 install
cd ../libxcb-1.14
sudo ./configure
make -j4
sudo make -j4 install
cd ../libXfixes-5.0
sudo ./configure
make -j4
sudo make -j4 install
cd ../libXdamage-1.1
sudo ./configure
make -j4
sudo make -j4 install
cd ../libX11-1.6.9
sudo ./configure
make -j4
sudo make -j4 install
cd ../libpciaccess-0.13.4
sudo ./configure
make -j4
sudo make -j4 install
cd ../libdrm-2.4.100
sudo ./configure
make -j4
sudo make -j4 install
cd ../zlib-1.2.11
sudo ./configure
make -j4
sudo make -j4 install
cd ../mesa-19.0.8
sudo ./configure --enable-autotools
make -j4
sudo make -j4 install
cd ../..
sudo sh compile_sdl.sh
