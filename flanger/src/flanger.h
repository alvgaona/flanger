#ifndef _FLANGER_H_
#define _FLANGER_H_

#define ONOFF 0b00000001
#define CAMBIAR_FREC 0b00000010

#define SALTEAR_CICLOS 10

#include <avr/io.h>
#include <avr/interrupt.h>

void boardinit()
{
	PORTC.DIR = 0b10000000; // Seteamos el pin 7 como output y los demás como input
	PORTC.OUT = 0x00;
	PORTC.PIN1CTRL = (PORT_OPC_PULLDOWN_gc | PORT_ISC_FALLING_gc);
	PORTC.PIN0CTRL = (PORT_OPC_TOTEM_gc | PORT_ISC_BOTHEDGES_gc);
	PORTC.PIN7CTRL = (PORT_OPC_TOTEM_gc | PORT_ISC_BOTHEDGES_gc);
	PORTCFG.MPCMASK = 0xFC;
	PORTC.PIN2CTRL = (PORT_OPC_TOTEM_gc | PORT_ISC_INPUT_DISABLE_gc);
	PORTC.INTCTRL = 0x00;
	PORTC.INT0MASK = 0x00;
	PORTC.INT1MASK = 0x00;
	

     PORTB.DIR = 0x0C;
     PORTB.OUT = 0x00;
     PORTB.PIN0CTRL = (PORT_OPC_TOTEM_gc | PORT_ISC_BOTHEDGES_gc);
     PORTB.PIN1CTRL = (PORT_OPC_TOTEM_gc | PORT_ISC_BOTHEDGES_gc);
     PORTB_PIN2CTRL = (PORT_OPC_TOTEM_gc | PORT_ISC_INPUT_DISABLE_gc);
     PORTB.PIN3CTRL = (PORT_OPC_TOTEM_gc | PORT_ISC_INPUT_DISABLE_gc);
	PORTB.INTCTRL = 0x00;
     PORTB.INT0MASK = 0x00;
     PORTB.INT1MASK = 0x00;
       
     
}

void adc_init()
{
     ADCA_CTRLB = (1 << ADC_CONMODE_bp) | ADC_RESOLUTION_12BIT_gc; //Signed mode and 12 bit resolution
     ADCA_PRESCALER = ADC_PRESCALER_DIV64_gc; //CLK is set to 32 MHz => CLK_ADC = 250 kHz
     ADCA_REFCTRL = (ADC_REFSEL_VCC_gc | (0 << ADC_TEMPREF_bp) | (0 << ADC_BANDGAP_bp)); //BANDGAP Reference selected
     
     ADCA_CH0_CTRL = ((0 << ADC_CH_START_bp) | ADC_CH_INPUTMODE_SINGLEENDED_gc); //Input mode single ended
     ADCA_CH1_CTRL = ((0 << ADC_CH_START_bp) | ADC_CH_INPUTMODE_SINGLEENDED_gc); //Input mode single ended

     ADCA_CMP = 0x0000;
     
     ADCA_CH0_MUXCTRL = ADC_CH_MUXPOS_PIN7_gc; //PIN7 input selected (PA7)
     ADCA_CH1_MUXCTRL = ADC_CH_MUXPOS_PIN5_gc; //PIN5 input selected for channel 2
     
/*     ADCA_EVCTRL = (ADC_SWEEP_01_gc | ADC_EVACT_NONE_gc); // Configura entre qué canales "swepear"*/
     
//   Enables low level interrupts and global interrupts
     ADCA_CH0_INTCTRL = (ADC_CH_INTMODE_COMPLETE_gc | ADC_CH_INTLVL_LO_gc); // Avisa cuando convierte
     ADCA_CH1_INTCTRL = (ADC_CH_INTMODE_COMPLETE_gc | ADC_CH_INTLVL_LO_gc); // Avisa cuando convierte
     ADCA_CH2_INTCTRL = ADC_CH_INTLVL_OFF_gc;
     ADCA_CH3_INTCTRL = ADC_CH_INTLVL_OFF_gc;
     
     PMIC.CTRL = (1 << PMIC_LOLVLEN_bp); // Habilita las interrupciones de baja prioridad
     
     sei(); // Habilita las interrupciones globales

//   Freerun mode on and enables adc
     ADCA_CTRLB |= ADC_FREERUN_bm;
     ADCA_CTRLA |= ADC_ENABLE_bm;
}

void clk_init()
{
	OSC_CTRL = 0x00; //Disable all clock sources
	OSC_CTRL |= OSC_RC32KEN_bm; //Enables RC32 kHz oscillator
	while(!(OSC_STATUS & OSC_RC32KRDY_bm)); //Waits for it to stabilize
	OSC_CTRL |= OSC_RC32MEN_bm; //Enables RC32 MHz oscillator
	
	CPU_CCP = CCP_IOREG_gc; //Disable protected IOs to update settings
	
	CLK_PSCTRL = ((CLK_PSCTRL & (~(CLK_PSADIV_gm | CLK_PSBCDIV1_bm | CLK_PSBCDIV0_bm)))
	| CLK_PSADIV_1_gc | CLK_PSBCDIV_1_1_gc); //Prescales to CLK/16
	
	OSC_DFLLCTRL = ((OSC_DFLLCTRL & (~(OSC_RC32MCREF_bm | OSC_RC2MCREF_bm))) |
	OSC_RC32MCREF_bm); //Calibrates RC32MHz with RC32kHz
	DFLLRC32M_CTRL |= DFLL_ENABLE_bm; //Enables the auto-calibration
	while(!(OSC_STATUS & OSC_RC32MRDY_bm)); //Waits for RC32MHz to stabilize
	
	CPU_CCP = CCP_IOREG_gc;//Disable protected IOs to update settings
	
	CLK_CTRL = ((CLK_CTRL & (~CLK_SCLKSEL_gm)) | CLK_SCLKSEL_RC32M_gc); //Selectes RC32MHz clock source
	OSC_CTRL &= (~(OSC_RC2MEN_bm | OSC_XOSCEN_bm | OSC_PLLEN_bm)); //Disables every other clock source
	
	PORTCFG_CLKEVOUT = 0x00;
}

void dac_init(){

	DACB_CTRLA = (DAC_CH0EN_bm | DAC_ENABLE_bm);
	DACB_CTRLB = DAC_CHSEL_SINGLE_gc;
	DACB_CTRLC = DAC_REFSEL_AVCC_gc;
}



void dac_write(unsigned char channel, unsigned int value)
{
   switch(channel)
   {
       case 0:
       {
           while(!(DACB_STATUS & DAC_CH0DRE_bm));
           DACB_CH0DATA = value;
           break;
       }
       case 1:
       {
            while(!(DACB_STATUS & DAC_CH1DRE_bm));
            DACB_CH1DATA = value;
            break;
       }
   }
}






#endif
