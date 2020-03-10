# navi_dont_sleep
Navi sleep prevention, see https://gitlab.freedesktop.org/drm/amd/issues/892#note_426367 .

Need OpenCV library to be installed. Also OpenCL for Navi should be turned on and OpenCV should be compiled using OpenCL support (by default it should be, check instructions on OpenCV github).

AMD OpenCL driver and instructions are available on AMD site. You can check opencl info using `clinfo` command from command line.

Compile: 

    git clone https://github.com/miptsu/navi_dont_sleep.git
    cd navi_dont_sleep
    mkdir build
    cd build
    cmake ..
    make

Then run program from `/build` directory.

You will see window named "uptime" and uptime inside this window. Press 'esc' to exit program. Navi works better while this program is runnung (my uptime rised from minutes to days).
