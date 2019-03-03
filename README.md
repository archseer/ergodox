https://github.com/ARMmbed/homebrew-formulae
```
ln -s $(pwd)/planck ../qmk_firmware/keyboards/planck/keymaps/archseer
ln -s $(pwd)/ergodox ../qmk_firmware/layouts/community/ergodox/archseer
brew install dfu-util avr-gcc arm-none-eabi-gcc
make planck/rev6:archseer:dfu-util
```

