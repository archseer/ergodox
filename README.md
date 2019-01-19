# archseer's layout

Roughly based on https://github.com/qmk/qmk_firmware/tree/master/layouts/community/ergodox/romanzolotarev-norman-plover-osx-hjkl

# Building

This layout is maintained in its own repository. To build it, you will need the QMK firmware checked out, and this repo either checked out to something like layouts/community/archseer, or symlinked there. One way to achieve that is this:
``
$ git clone https://github.com/qmk/qmk_firmware.git
$ cd qmk_firmware
$ git clone https://github.com/archseer/ergodox.git \
            layouts/community/ergodox/archseer
$ make ergodox_ez:archseer
