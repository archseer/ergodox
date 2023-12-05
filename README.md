https://github.com/ARMmbed/homebrew-formulae
```
ln -s $(pwd)/planck ../qmk_firmware/keyboards/planck/keymaps/archseer
# ln -s $(pwd)/ergodox ../qmk_firmware/layouts/community/ergodox/archseer
# ln -s $(pwd)/ergodox ../qmk_firmware/keyboards/ergodox_ez/keymaps/archseer
cp -fR ergodox ../qmk_firmware/keyboards/ergodox_ez/keymaps/archseer/
brew install dfu-util avr-gcc arm-none-eabi-gcc
make planck/rev6:archseer:dfu-util

RUNTIME=podman util/docker_build.sh ergodox_ez:archseer

RUNTIME=podman util/docker_build.sh ergodox_ez:archseer:flash
```

