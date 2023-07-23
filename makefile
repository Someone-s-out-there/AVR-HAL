# all:

test: test/blinky/main.cpp
	avr-g++ -mmcu=atmega328p test/blinky/main.cpp -I ./ -o test/blinky/blinky -Wall -Wextra -pedantic -O1

flash: test
	sudo avrdude "-C/home/sjoerd/.arduino15/packages/arduino/tools/avrdude/6.3.0-arduino17/etc/avrdude.conf" -v -V -patmega328p -carduino "-P/dev/ttyUSB1" -b57600 -D "-Uflash:w:test/blinky/blinky:e"
