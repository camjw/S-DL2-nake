brew install sdl2
brew install sdl2_ttf
brew install sdl2_mixer
git clone https://github.com/google/googletest
cd googletest
mkdir build
cd build
cmake ..
make && make install
cd ../..
