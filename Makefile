arch = 

all:	clear compile program mensaje

clear:
	clear
compile:
	avr-gcc -Wall -Os -mmcu=atxmega16a4 -c $(arch).c -o $(arch).o
	avr-gcc -Wall -Os -mmcu=atxmega16a4 -o $(arch).elf $(arch).o
	avr-objdump -h -S $(arch).elf > $(arch).lss
	avr-objdump -h -S $(arch).elf > $(arch).lst
	avr-objcopy -j .text -j .data -O ihex $(arch).elf $(arch).hex
	
clean:
	rm *.o
	#rm *.hex
	rm *.elf
	rm *~

program:
	sudo avrdude -p atxmega16a4 -P /dev/ttyUSB0 -c avr109 -b 115200 -U flash:w:$(arch).hex -e
