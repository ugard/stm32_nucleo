# stm32_nucleo

0. zbudowanie openocd ze wsparciem dla swd:

<https://github.com/snowcap-electronics/OpenOCD> branch **snowcap-v0.9.0-2015-07-23**

    ./bootstrap
    ./configure --prefix=/usr/local/openocd/ --disable-werror --enable-usbprog --enable-vsllink --enable-buspirate --enable-ftdi --enable-stlink --enable-arm-jtag-ew --enable-remote-bitbang --enable-dummy
    make

    
1. uruchomienie openocd:
 
    cd tcl
    sudo ../src/openocd -f board/st_nucleo_f103rb.cfg -f interface/stlink-v2.cfg

2. połączenie telnet:
    telnet localhost 4444

3. wgranie pliku:
    reset
    halt
    flash erase_check 0
    program <pełna_ścieżka_do_pliku> verify reset

4. reset urządzenia przyciskiem
