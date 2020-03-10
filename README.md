# navi_dont_sleep
Navi sleep prevention, see https://gitlab.freedesktop.org/drm/amd/issues/892#note_426367 .

Need OpenCV library to be installed.

Compile then run program. 

    git clone https://github.com/miptsu/navi_dont_sleep.git
    cd navi_dont_sleep
    mkdir build
    cd build
    cmake ..
    make

You will see window named "uptime" and uptime inside this window. Press 'esc' to exit program. Navi works better while this program is runnung (my uptime rised from minutes to days).
