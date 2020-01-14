# Egg::System
This is conifguration stuff for the Egg project - handy SDK to write the Linux daemons

# How to build?

Configure and install compiler configuration for Egg (Linux daemon SDK):

  - pushd build

  - configure using cmake: "cmake OPTIONS ..", where the options are:

    * -DCMAKE_INSTALL_PREFIX:PATH=<phoenix prefix>
    * -G"Eclipse CDT4 - Unix Makefiles" (to embed in Eclipse as the project)

  - Typical configuration:

    cmake \
        -DCMAKE_INSTALL_PREFIX:PATH=/opt/egg  \
        -G"Eclipse CDT4 - Unix Makefiles" \
        ..

  - Build and install: make && make install

  - Clean up: rm -rf ./*

  - popd
