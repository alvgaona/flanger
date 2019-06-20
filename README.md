# Flanger
Flanging effect produced by a microcontroller. Particularly, implemented with Atmel ATxmega16a4. This undergraduate 
project was made for a subject in Electronics Engineering at University of Buenos Aires, Argentina. 

# Simulation
To get started, before implementing the flanger filter in the microcontroller, there was a simulation made in MATLAB
. The code is very simple and you can view it in "Flanger.m". In addition, there are some examples for you to download and apply the effect.

# Microcontroller
The next step, after verifying the simulation, was to write the algorithm and program the Atxmega16a4 via UART. At 
first, we wanted to implement it with an ATmegaXX but the ADC wasn't fast enough. However, we encountered some issues regarding the ADC Clock, which was that the ADC can't go at max speed according to the datasheet provided by Atmel. The max speed we could check was 1 Msps. Although, once we started to write code in main and make the CPU take time to process the data, the max speed started to fall until aprox 260 ksps.

# Hardware
The hardware included some low pass filters before the ADC input and after the DAC ouput. Some decoupling capacitors
 between GND and VCC. AVCC was connected directly to AVCC. However, you might want to improve the stability of AVCC 
 following the recommendations in the datasheets. Also some presets for on and off regarding the flanging  and the 
 variation of the sine frequency which controls the parameter ![alt text](img/controlled_param.svg) from the 
 following equation. 

![alt text](img/flanging_difference_equation.svg)
