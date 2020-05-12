 cp sound_lib/libfmod.dylib /usr/local/lib
 cp sound_lib/libfmodL.dylib /usr/local/lib
cd lib
for f in *.gz; do tar -xvf "$f"; done
cd libelf-0.8.13
 ./configure
make -j4
make -j4 install
cd ../libXrender-0.9.10
 ./configure
make -j4
make -j4 install
cd ../libXrandr-1.5.2
 ./configure
make -j4
make -j4 install
cd ../libxshmfence-1.3
 ./configure
make -j4
make -j4 install
cd ../libXxf86vm-1.1.4
 ./configure
make -j4
make -j4 install
cd ../xcb-proto-1.14
 ./configure
make -j4
make -j4 install
cd ../libpthread-stubs-0.1.tar.gz
./configure
make -j4
make -j4 install
cd ../libxcb-1.14
export PKG_CONFIG_PATH=/usr/local/lib/pkgconfig
 ./configure
make -j4
make -j4 install
cd ../libXfixes-5.0
 ./configure
make -j4
make -j4 install
cd ../libXdamage-1.1
 ./configure
make -j4
make -j4 install
cd ../libX11-1.6.9
 ./configure
make -j4
make -j4 install
cd ../libpciaccess-0.13.4
 ./configure
make -j4
make -j4 install
cd ../libdrm-2.4.100
 ./configure
make -j4
make -j4 install
cd ../zlib-1.2.11
 ./configure
make -j4
make -j4 install
cd ../mesa-19.0.8
 ./configure --enable-autotools
make -j4
make -j4 install
cd ../SDL2-2.0.8
 ./configure
make -j4
make -j4 install
cd ../freetype-2.9
 ./configure
make -j4
make -j4 install
cd ../SDL2_ttf-2.0.15
 ./configure
make -j4
make -j4 install
