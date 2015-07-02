arch = 

all:	clear compile mensaje program mensaje

clear:
	clear
compile:
	avra $(arch).asm
#	avr-gcc -Wall -Os -mmcu=atxmega16a4 -o $(arch).elf $(arch).o
	#avr-objdump -h -S $(arch).elf > $(arch).lss
	#avr-objdump -h -S $(arch).elf > $(arch).lst
#	avra -h
#	rm flagner.o
#	avr-objcopy -j .text -j .data -O ihex $(arch).elf $(arch).hex
	
	

program:
	sudo avrdude -p atxmega16a4 -P /dev/ttyUSB0 -c avr109 -b 115200 -U flash:w:$(arch).hex -e

mensaje:
	avra -h
	#		##################################		#
	#		##### SE COMPILO TODO PAPA!! #####		#
	#		##################################		#
