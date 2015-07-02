;*************************************************************************
;* A P P L I C A T I O N   N O T E   F O R   T H E   A V R   F A M I L Y
;* 
;* Number            : AVR000
;* File Name         : ATxmega16A4def;inc
;* Title             : Register/Bit Definitions for the ATxmega16A4
;* Date              : Jan 01 2008
;* Version           : 1;00
;* Support E-mail    : avr@atmel;com
;* Target MCU        : ATxmega16A4
;* 
;* DESCRIPTION
;* When including this file in the assembly program file, all I/O register 
;* names and I/O register bit names appearing in the data book can be used;
;* In addition, the six registers forming the three data pointers X, Y and 
;* Z have been assigned names XL - ZH; Highest RAM address for Internal 
;* SRAM is also defined 
;* 
;*************************************************************************




; ***** SPECIFY DEVICE ***************************************************
;device ATxmega16A4


;equ	SIGNATURE_000 = 0x1E
;equ	SIGNATURE_001 = 0x94
;equ	SIGNATURE_002 = 0x41



; ***** ABSOLUTE I/O REGISTER LOCATIONS **********************************


;***************************************************************************
;** GPIO - General Purpose IO Registers
;***************************************************************************
	
;equ GPIO_GPIOR0 = 0		// General Purpose IO Register 0
;equ GPIO_GPIOR1 = 1		// General Purpose IO Register 1
;equ GPIO_GPIOR2 = 2		// General Purpose IO Register 2
;equ GPIO_GPIOR3 = 3		// General Purpose IO Register 3
;equ GPIO_GPIOR4 = 4		// General Purpose IO Register 4
;equ GPIO_GPIOR5 = 5		// General Purpose IO Register 5
;equ GPIO_GPIOR6 = 6		// General Purpose IO Register 6
;equ GPIO_GPIOR7 = 7		// General Purpose IO Register 7
;equ GPIO_GPIOR8 = 8		// General Purpose IO Register 8
;equ GPIO_GPIOR9 = 9		// General Purpose IO Register 9
;equ GPIO_GPIOR10 = 10		// General Purpose IO Register 10
;equ GPIO_GPIOR11 = 11		// General Purpose IO Register 11
;equ GPIO_GPIOR12 = 12		// General Purpose IO Register 12
;equ GPIO_GPIOR13 = 13		// General Purpose IO Register 13
;equ GPIO_GPIOR14 = 14		// General Purpose IO Register 14
;equ GPIO_GPIOR15 = 15		// General Purpose IO Register 15

;***************************************************************************
;** OCD - On-Chip Debug System
;***************************************************************************
	
;equ OCD_OCDR0 = 46		// OCD Register 0
;equ OCD_OCDR1 = 47		// OCD Register 1

;***************************************************************************
;** CPU - CPU Registers
;***************************************************************************
	
;equ CPU_CCP = 52		// Configuration Change Protection
;equ CPU_RAMPD = 56		// Ramp D
;equ CPU_RAMPX = 57		// Ramp X
;equ CPU_RAMPY = 58		// Ramp Y
;equ CPU_RAMPZ = 59		// Ramp Z
;equ CPU_EIND = 60		// Extended Indirect Jump
;equ CPU_SPL = 61		// Stack Pointer Low
;equ CPU_SPH = 62		// Stack Pointer High
;equ CPU_SREG = 63		// Status Register

;***************************************************************************
;** CLK - Clock System
;***************************************************************************
	
;equ CLK_CTRL = 64		// Control Register
;equ CLK_PSCTRL = 65		// Prescaler Control Register
;equ CLK_LOCK = 66		// Lock register
;equ CLK_RTCCTRL = 67		// RTC Control Register

;***************************************************************************
;** SLEEP - Sleep Controller
;***************************************************************************
	
;equ SLEEP_CTRL = 72		// Control Register

;***************************************************************************
;** OSC - Oscillator Control
;***************************************************************************
	
;equ OSC_CTRL = 80		// Control Register
;equ OSC_STATUS = 81		// Status Register
;equ OSC_XOSCCTRL = 82		// External Oscillator Control Register
;equ OSC_XOSCFAIL = 83		// External Oscillator Failure Detection Register
;equ OSC_RC32KCAL = 84		// 32kHz Internal Oscillator Calibration Register
;equ OSC_PLLCTRL = 85		// PLL Control REgister
;equ OSC_DFLLCTRL = 86		// DFLL Control Register

;***************************************************************************
;** DFLLRC32M - DFLL for 32MHz RC Oscillator
;***************************************************************************
	
;equ DFLLRC32M_CTRL = 96		// Control Register
;equ DFLLRC32M_CALA = 98		// Calibration Register A
;equ DFLLRC32M_CALB = 99		// Calibration Register B
;equ DFLLRC32M_COMP0 = 100		// Oscillator Compare Register 0
;equ DFLLRC32M_COMP1 = 101		// Oscillator Compare Register 1
;equ DFLLRC32M_COMP2 = 102		// Oscillator Compare Register 2

;***************************************************************************
;** DFLLRC2M - DFLL for 2MHz RC Oscillator
;***************************************************************************
	
;equ DFLLRC2M_CTRL = 104		// Control Register
;equ DFLLRC2M_CALA = 106		// Calibration Register A
;equ DFLLRC2M_CALB = 107		// Calibration Register B
;equ DFLLRC2M_COMP0 = 108		// Oscillator Compare Register 0
;equ DFLLRC2M_COMP1 = 109		// Oscillator Compare Register 1
;equ DFLLRC2M_COMP2 = 110		// Oscillator Compare Register 2

;***************************************************************************
;** PR - Power Reduction
;***************************************************************************
	
;equ PR_PRGEN = 112		// General Power Reduction
;equ PR_PRPA = 113		// Power Reduction Port A
;equ PR_PRPB = 114		// Power Reduction Port B
;equ PR_PRPC = 115		// Power Reduction Port C
;equ PR_PRPD = 116		// Power Reduction Port D
;equ PR_PRPE = 117		// Power Reduction Port E
;equ PR_PRPF = 118		// Power Reduction Port F

;***************************************************************************
;** RST - Reset Controller
;***************************************************************************
	
;equ RST_STATUS = 120		// Status Register
;equ RST_CTRL = 121		// Control Register

;***************************************************************************
;** WDT - Watch-Dog Timer
;***************************************************************************
	
;equ WDT_CTRL = 128		// Control
;equ WDT_WINCTRL = 129		// Windowed Mode Control
;equ WDT_STATUS = 130		// Status

;***************************************************************************
;** MCU - MCU Control
;***************************************************************************
	
;equ MCU_DEVID0 = 144		// Device ID byte 0
;equ MCU_DEVID1 = 145		// Device ID byte 1
;equ MCU_DEVID2 = 146		// Device ID byte 2
;equ MCU_REVID = 147		// Revision ID
;equ MCU_JTAGUID = 148		// JTAG User ID
;equ MCU_MCUCR = 150		// MCU Control
;equ MCU_EVSYSLOCK = 152		// Event System Lock
;equ MCU_AWEXLOCK = 153		// AWEX Lock

;***************************************************************************
;** PMIC - Programmable Interrupt Controller
;***************************************************************************
	
;equ PMIC_STATUS = 160		// Status Register
;equ PMIC_INTPRI = 161		// Interrupt Priority
;equ PMIC_CTRL = 162		// Control Register

;***************************************************************************
;** DMA - DMA Controller
;***************************************************************************
	
;equ DMA_CTRL = 256		// Control
;equ DMA_INTFLAGS = 259		// Transfer Interrupt Status
;equ DMA_STATUS = 260		// Status
;equ DMA_TEMP = 262		// Temporary Register For 16/24-bit Access
;equ DMA_CH0_CTRLA = 272		// Channel Control
;equ DMA_CH0_CTRLB = 273		// Channel Control
;equ DMA_CH0_ADDRCTRL = 274		// Address Control
;equ DMA_CH0_TRIGSRC = 275		// Channel Trigger Source
;equ DMA_CH0_TRFCNT = 276		// Channel Block Transfer Count
;equ DMA_CH0_REPCNT = 278		// Channel Repeat Count
;equ DMA_CH0_SRCADDR0 = 280		// Channel Source Address 0
;equ DMA_CH0_SRCADDR1 = 281		// Channel Source Address 1
;equ DMA_CH0_SRCADDR2 = 282		// Channel Source Address 2
;equ DMA_CH0_DESTADDR0 = 284		// Channel Destination Address 0
;equ DMA_CH0_DESTADDR1 = 285		// Channel Destination Address 1
;equ DMA_CH0_DESTADDR2 = 286		// Channel Destination Address 2
;equ DMA_CH1_CTRLA = 288		// Channel Control
;equ DMA_CH1_CTRLB = 289		// Channel Control
;equ DMA_CH1_ADDRCTRL = 290		// Address Control
;equ DMA_CH1_TRIGSRC = 291		// Channel Trigger Source
;equ DMA_CH1_TRFCNT = 292		// Channel Block Transfer Count
;equ DMA_CH1_REPCNT = 294		// Channel Repeat Count
;equ DMA_CH1_SRCADDR0 = 296		// Channel Source Address 0
;equ DMA_CH1_SRCADDR1 = 297		// Channel Source Address 1
;equ DMA_CH1_SRCADDR2 = 298		// Channel Source Address 2
;equ DMA_CH1_DESTADDR0 = 300		// Channel Destination Address 0
;equ DMA_CH1_DESTADDR1 = 301		// Channel Destination Address 1
;equ DMA_CH1_DESTADDR2 = 302		// Channel Destination Address 2
;equ DMA_CH2_CTRLA = 304		// Channel Control
;equ DMA_CH2_CTRLB = 305		// Channel Control
;equ DMA_CH2_ADDRCTRL = 306		// Address Control
;equ DMA_CH2_TRIGSRC = 307		// Channel Trigger Source
;equ DMA_CH2_TRFCNT = 308		// Channel Block Transfer Count
;equ DMA_CH2_REPCNT = 310		// Channel Repeat Count
;equ DMA_CH2_SRCADDR0 = 312		// Channel Source Address 0
;equ DMA_CH2_SRCADDR1 = 313		// Channel Source Address 1
;equ DMA_CH2_SRCADDR2 = 314		// Channel Source Address 2
;equ DMA_CH2_DESTADDR0 = 316		// Channel Destination Address 0
;equ DMA_CH2_DESTADDR1 = 317		// Channel Destination Address 1
;equ DMA_CH2_DESTADDR2 = 318		// Channel Destination Address 2
;equ DMA_CH3_CTRLA = 320		// Channel Control
;equ DMA_CH3_CTRLB = 321		// Channel Control
;equ DMA_CH3_ADDRCTRL = 322		// Address Control
;equ DMA_CH3_TRIGSRC = 323		// Channel Trigger Source
;equ DMA_CH3_TRFCNT = 324		// Channel Block Transfer Count
;equ DMA_CH3_REPCNT = 326		// Channel Repeat Count
;equ DMA_CH3_SRCADDR0 = 328		// Channel Source Address 0
;equ DMA_CH3_SRCADDR1 = 329		// Channel Source Address 1
;equ DMA_CH3_SRCADDR2 = 330		// Channel Source Address 2
;equ DMA_CH3_DESTADDR0 = 332		// Channel Destination Address 0
;equ DMA_CH3_DESTADDR1 = 333		// Channel Destination Address 1
;equ DMA_CH3_DESTADDR2 = 334		// Channel Destination Address 2

;***************************************************************************
;** EVSYS - Event System
;***************************************************************************
	
;equ EVSYS_CH0MUX = 384		// Event Channel 0 Multiplexer
;equ EVSYS_CH1MUX = 385		// Event Channel 1 Multiplexer
;equ EVSYS_CH2MUX = 386		// Event Channel 2 Multiplexer
;equ EVSYS_CH3MUX = 387		// Event Channel 3 Multiplexer
;equ EVSYS_CH4MUX = 388		// Event Channel 4 Multiplexer
;equ EVSYS_CH5MUX = 389		// Event Channel 5 Multiplexer
;equ EVSYS_CH6MUX = 390		// Event Channel 6 Multiplexer
;equ EVSYS_CH7MUX = 391		// Event Channel 7 Multiplexer
;equ EVSYS_CH0CTRL = 392		// Channel 0 Control Register
;equ EVSYS_CH1CTRL = 393		// Channel 1 Control Register
;equ EVSYS_CH2CTRL = 394		// Channel 2 Control Register
;equ EVSYS_CH3CTRL = 395		// Channel 3 Control Register
;equ EVSYS_CH4CTRL = 396		// Channel 4 Control Register
;equ EVSYS_CH5CTRL = 397		// Channel 5 Control Register
;equ EVSYS_CH6CTRL = 398		// Channel 6 Control Register
;equ EVSYS_CH7CTRL = 399		// Channel 7 Control Register
;equ EVSYS_STROBE = 400		// Event Strobe
;equ EVSYS_DATA = 401		// Event Data

;***************************************************************************
;** NVM - Non Volatile Memory
;***************************************************************************
	
;equ NVM_ADDR0 = 448		// Address Register 0
;equ NVM_ADDR1 = 449		// Address Register 1
;equ NVM_ADDR2 = 450		// Address Register 2
;equ NVM_DATA0 = 452		// Data Register 0
;equ NVM_DATA1 = 453		// Data Register 1
;equ NVM_DATA2 = 454		// Data Register 2
;equ NVM_CMD = 458		// Command
;equ NVM_CTRLA = 459		// Control Register A
;equ NVM_CTRLB = 460		// Control Register B
;equ NVM_INTCTRL = 461		// Interrupt Control
;equ NVM_STATUS = 463		// Status
;equ NVM_LOCKBITS = 464		// Lock Bits

;***************************************************************************
;** ACA - Analog Comparator A
;***************************************************************************
	
;equ ACA_AC0CTRL = 896		// Analog Comparator 0 Control
;equ ACA_AC1CTRL = 897		// Analog Comparator 1 Control
;equ ACA_AC0MUXCTRL = 898		// Analog Comparator 0 MUX Control
;equ ACA_AC1MUXCTRL = 899		// Analog Comparator 1 MUX Control
;equ ACA_CTRLA = 900		// Control Register A
;equ ACA_CTRLB = 901		// Control Register B
;equ ACA_WINCTRL = 902		// Window Mode Control
;equ ACA_STATUS = 903		// Status

;***************************************************************************
;** ADCA - Analog to Digital Converter A
;***************************************************************************
	
;equ ADCA_CTRLA = 512		// Control Register A
;equ ADCA_CTRLB = 513		// Control Register B
;equ ADCA_REFCTRL = 514		// Reference Control
;equ ADCA_EVCTRL = 515		// Event Control
;equ ADCA_PRESCALER = 516		// Clock Prescaler
;equ ADCA_INTFLAGS = 518		// Interrupt Flags
;equ ADCA_TEMP = 519		// Temporary register
;equ ADCA_CAL = 524		// Calibration Value
;equ ADCA_CH0RES = 528		// Channel 0 Result
;equ ADCA_CH1RES = 530		// Channel 1 Result
;equ ADCA_CH2RES = 532		// Channel 2 Result
;equ ADCA_CH3RES = 534		// Channel 3 Result
;equ ADCA_CMP = 536		// Compare Value
;equ ADCA_CH0_CTRL = 544		// Control Register
;equ ADCA_CH0_MUXCTRL = 545		// MUX Control
;equ ADCA_CH0_INTCTRL = 546		// Channel Interrupt Control
;equ ADCA_CH0_INTFLAGS = 547		// Interrupt Flags
;equ ADCA_CH0_RES = 548		// Channel Result
;equ ADCA_CH1_CTRL = 552		// Control Register
;equ ADCA_CH1_MUXCTRL = 553		// MUX Control
;equ ADCA_CH1_INTCTRL = 554		// Channel Interrupt Control
;equ ADCA_CH1_INTFLAGS = 555		// Interrupt Flags
;equ ADCA_CH1_RES = 556		// Channel Result
;equ ADCA_CH2_CTRL = 560		// Control Register
;equ ADCA_CH2_MUXCTRL = 561		// MUX Control
;equ ADCA_CH2_INTCTRL = 562		// Channel Interrupt Control
;equ ADCA_CH2_INTFLAGS = 563		// Interrupt Flags
;equ ADCA_CH2_RES = 564		// Channel Result
;equ ADCA_CH3_CTRL = 568		// Control Register
;equ ADCA_CH3_MUXCTRL = 569		// MUX Control
;equ ADCA_CH3_INTCTRL = 570		// Channel Interrupt Control
;equ ADCA_CH3_INTFLAGS = 571		// Interrupt Flags
;equ ADCA_CH3_RES = 572		// Channel Result

;***************************************************************************
;** DACB - Digital to Analog Converter B
;***************************************************************************
	
;equ DACB_CTRLA = 800		// Control Register A
;equ DACB_CTRLB = 801		// Control Register B
;equ DACB_CTRLC = 802		// Control Register C
;equ DACB_EVCTRL = 803		// Event Input Control
;equ DACB_TIMCTRL = 804		// Timing Control
;equ DACB_STATUS = 805		// Status
;equ DACB_GAINCAL = 808		// Gain Calibration
;equ DACB_OFFSETCAL = 809		// Offset Calibration
;equ DACB_CH0DATA = 824		// Channel 0 Data
;equ DACB_CH1DATA = 826		// Channel 1 Data

;***************************************************************************
;** RTC - Real-Time Counter
;***************************************************************************
	
;equ RTC_CTRL = 1024		// Control Register
;equ RTC_STATUS = 1025		// Status Register
;equ RTC_INTCTRL = 1026		// Interrupt Control Register
;equ RTC_INTFLAGS = 1027		// Interrupt Flags
;equ RTC_TEMP = 1028		// Temporary register
;equ RTC_CNT = 1032		// Count Register
;equ RTC_PER = 1034		// Period Register
;equ RTC_COMP = 1036		// Compare Register

;***************************************************************************
;** TWIC - Two-Wire Interface C
;***************************************************************************
	
;equ TWIC_CTRL = 1152		// TWI Common Control Register
;equ TWIC_MASTER_CTRLA = 1153		// Control Register A
;equ TWIC_MASTER_CTRLB = 1154		// Control Register B
;equ TWIC_MASTER_CTRLC = 1155		// Control Register C
;equ TWIC_MASTER_STATUS = 1156		// Status Register
;equ TWIC_MASTER_BAUD = 1157		// Baurd Rate Control Register
;equ TWIC_MASTER_ADDR = 1158		// Address Register
;equ TWIC_MASTER_DATA = 1159		// Data Register
;equ TWIC_SLAVE_CTRLA = 1160		// Control Register A
;equ TWIC_SLAVE_CTRLB = 1161		// Control Register B
;equ TWIC_SLAVE_STATUS = 1162		// Status Register
;equ TWIC_SLAVE_ADDR = 1163		// Address Register
;equ TWIC_SLAVE_DATA = 1164		// Data Register
;equ TWIC_SLAVE_ADDRMASK = 1165		// Address Mask Register

;***************************************************************************
;** TWIE - Two-Wire Interface E
;***************************************************************************
	
;equ TWIE_CTRL = 1184		// TWI Common Control Register
;equ TWIE_MASTER_CTRLA = 1185		// Control Register A
;equ TWIE_MASTER_CTRLB = 1186		// Control Register B
;equ TWIE_MASTER_CTRLC = 1187		// Control Register C
;equ TWIE_MASTER_STATUS = 1188		// Status Register
;equ TWIE_MASTER_BAUD = 1189		// Baurd Rate Control Register
;equ TWIE_MASTER_ADDR = 1190		// Address Register
;equ TWIE_MASTER_DATA = 1191		// Data Register
;equ TWIE_SLAVE_CTRLA = 1192		// Control Register A
;equ TWIE_SLAVE_CTRLB = 1193		// Control Register B
;equ TWIE_SLAVE_STATUS = 1194		// Status Register
;equ TWIE_SLAVE_ADDR = 1195		// Address Register
;equ TWIE_SLAVE_DATA = 1196		// Data Register
;equ TWIE_SLAVE_ADDRMASK = 1197		// Address Mask Register

;***************************************************************************
;** PORT_CFG - Port Configuration
;***************************************************************************
	
;equ PORTCFG_MPCMASK = 176		// Multi-pin Configuration Mask
;equ PORTCFG_VPCTRLA = 178		// Virtual Port Control Register A
;equ PORTCFG_VPCTRLB = 179		// Virtual Port Control Register B
;equ PORTCFG_CLKEVOUT = 180		// Clock and Event Out Register

;***************************************************************************
;** VPORT0 - Virtual Port 0
;***************************************************************************
	
;equ VPORT0_DIR = 16		// I/O Port Data Direction
;equ VPORT0_OUT = 17		// I/O Port Output
;equ VPORT0_IN = 18		// I/O Port Input
;equ VPORT0_INTFLAGS = 19		// Interrupt Flag Register

;***************************************************************************
;** VPORT1 - Virtual Port 1
;***************************************************************************
	
;equ VPORT1_DIR = 20		// I/O Port Data Direction
;equ VPORT1_OUT = 21		// I/O Port Output
;equ VPORT1_IN = 22		// I/O Port Input
;equ VPORT1_INTFLAGS = 23		// Interrupt Flag Register

;***************************************************************************
;** VPORT2 - Virtual Port 2
;***************************************************************************
	
;equ VPORT2_DIR = 24		// I/O Port Data Direction
;equ VPORT2_OUT = 25		// I/O Port Output
;equ VPORT2_IN = 26		// I/O Port Input
;equ VPORT2_INTFLAGS = 27		// Interrupt Flag Register

;***************************************************************************
;** VPORT3 - Virtual Port 3
;***************************************************************************
	
;equ VPORT3_DIR = 28		// I/O Port Data Direction
;equ VPORT3_OUT = 29		// I/O Port Output
;equ VPORT3_IN = 30		// I/O Port Input
;equ VPORT3_INTFLAGS = 31		// Interrupt Flag Register

;***************************************************************************
;** PORTA - Port A
;***************************************************************************
	
;equ PORTA_DIR = 1536		// I/O Port Data Direction
;equ PORTA_DIRSET = 1537		// I/O Port Data Direction Set
;equ PORTA_DIRCLR = 1538		// I/O Port Data Direction Clear
;equ PORTA_DIRTGL = 1539		// I/O Port Data Direction Toggle
;equ PORTA_OUT = 1540		// I/O Port Output
;equ PORTA_OUTSET = 1541		// I/O Port Output Set
;equ PORTA_OUTCLR = 1542		// I/O Port Output Clear
;equ PORTA_OUTTGL = 1543		// I/O Port Output Toggle
;equ PORTA_IN = 1544		// I/O port Input
;equ PORTA_INTCTRL = 1545		// Interrupt Control Register
;equ PORTA_INT0MASK = 1546		// Port Interrupt 0 Mask
;equ PORTA_INT1MASK = 1547		// Port Interrupt 1 Mask
;equ PORTA_INTFLAGS = 1548		// Interrupt Flag Register
;equ PORTA_PIN0CTRL = 1552		// Pin 0 Control Register
;equ PORTA_PIN1CTRL = 1553		// Pin 1 Control Register
;equ PORTA_PIN2CTRL = 1554		// Pin 2 Control Register
;equ PORTA_PIN3CTRL = 1555		// Pin 3 Control Register
;equ PORTA_PIN4CTRL = 1556		// Pin 4 Control Register
;equ PORTA_PIN5CTRL = 1557		// Pin 5 Control Register
;equ PORTA_PIN6CTRL = 1558		// Pin 6 Control Register
;equ PORTA_PIN7CTRL = 1559		// Pin 7 Control Register

;***************************************************************************
;** PORTB - Port B
;***************************************************************************
	
;equ PORTB_DIR = 1568		// I/O Port Data Direction
;equ PORTB_DIRSET = 1569		// I/O Port Data Direction Set
;equ PORTB_DIRCLR = 1570		// I/O Port Data Direction Clear
;equ PORTB_DIRTGL = 1571		// I/O Port Data Direction Toggle
;equ PORTB_OUT = 1572		// I/O Port Output
;equ PORTB_OUTSET = 1573		// I/O Port Output Set
;equ PORTB_OUTCLR = 1574		// I/O Port Output Clear
;equ PORTB_OUTTGL = 1575		// I/O Port Output Toggle
;equ PORTB_IN = 1576		// I/O port Input
;equ PORTB_INTCTRL = 1577		// Interrupt Control Register
;equ PORTB_INT0MASK = 1578		// Port Interrupt 0 Mask
;equ PORTB_INT1MASK = 1579		// Port Interrupt 1 Mask
;equ PORTB_INTFLAGS = 1580		// Interrupt Flag Register
;equ PORTB_PIN0CTRL = 1584		// Pin 0 Control Register
;equ PORTB_PIN1CTRL = 1585		// Pin 1 Control Register
;equ PORTB_PIN2CTRL = 1586		// Pin 2 Control Register
;equ PORTB_PIN3CTRL = 1587		// Pin 3 Control Register
;equ PORTB_PIN4CTRL = 1588		// Pin 4 Control Register
;equ PORTB_PIN5CTRL = 1589		// Pin 5 Control Register
;equ PORTB_PIN6CTRL = 1590		// Pin 6 Control Register
;equ PORTB_PIN7CTRL = 1591		// Pin 7 Control Register

;***************************************************************************
;** PORTC - Port C
;***************************************************************************
	
;equ PORTC_DIR = 1600		// I/O Port Data Direction
;equ PORTC_DIRSET = 1601		// I/O Port Data Direction Set
;equ PORTC_DIRCLR = 1602		// I/O Port Data Direction Clear
;equ PORTC_DIRTGL = 1603		// I/O Port Data Direction Toggle
;equ PORTC_OUT = 1604		// I/O Port Output
;equ PORTC_OUTSET = 1605		// I/O Port Output Set
;equ PORTC_OUTCLR = 1606		// I/O Port Output Clear
;equ PORTC_OUTTGL = 1607		// I/O Port Output Toggle
;equ PORTC_IN = 1608		// I/O port Input
;equ PORTC_INTCTRL = 1609		// Interrupt Control Register
;equ PORTC_INT0MASK = 1610		// Port Interrupt 0 Mask
;equ PORTC_INT1MASK = 1611		// Port Interrupt 1 Mask
;equ PORTC_INTFLAGS = 1612		// Interrupt Flag Register
;equ PORTC_PIN0CTRL = 1616		// Pin 0 Control Register
;equ PORTC_PIN1CTRL = 1617		// Pin 1 Control Register
;equ PORTC_PIN2CTRL = 1618		// Pin 2 Control Register
;equ PORTC_PIN3CTRL = 1619		// Pin 3 Control Register
;equ PORTC_PIN4CTRL = 1620		// Pin 4 Control Register
;equ PORTC_PIN5CTRL = 1621		// Pin 5 Control Register
;equ PORTC_PIN6CTRL = 1622		// Pin 6 Control Register
;equ PORTC_PIN7CTRL = 1623		// Pin 7 Control Register

;***************************************************************************
;** PORTD - Port D
;***************************************************************************
	
;equ PORTD_DIR = 1632		// I/O Port Data Direction
;equ PORTD_DIRSET = 1633		// I/O Port Data Direction Set
;equ PORTD_DIRCLR = 1634		// I/O Port Data Direction Clear
;equ PORTD_DIRTGL = 1635		// I/O Port Data Direction Toggle
;equ PORTD_OUT = 1636		// I/O Port Output
;equ PORTD_OUTSET = 1637		// I/O Port Output Set
;equ PORTD_OUTCLR = 1638		// I/O Port Output Clear
;equ PORTD_OUTTGL = 1639		// I/O Port Output Toggle
;equ PORTD_IN = 1640		// I/O port Input
;equ PORTD_INTCTRL = 1641		// Interrupt Control Register
;equ PORTD_INT0MASK = 1642		// Port Interrupt 0 Mask
;equ PORTD_INT1MASK = 1643		// Port Interrupt 1 Mask
;equ PORTD_INTFLAGS = 1644		// Interrupt Flag Register
;equ PORTD_PIN0CTRL = 1648		// Pin 0 Control Register
;equ PORTD_PIN1CTRL = 1649		// Pin 1 Control Register
;equ PORTD_PIN2CTRL = 1650		// Pin 2 Control Register
;equ PORTD_PIN3CTRL = 1651		// Pin 3 Control Register
;equ PORTD_PIN4CTRL = 1652		// Pin 4 Control Register
;equ PORTD_PIN5CTRL = 1653		// Pin 5 Control Register
;equ PORTD_PIN6CTRL = 1654		// Pin 6 Control Register
;equ PORTD_PIN7CTRL = 1655		// Pin 7 Control Register

;***************************************************************************
;** PORTE - Port E
;***************************************************************************
	
;equ PORTE_DIR = 1664		// I/O Port Data Direction
;equ PORTE_DIRSET = 1665		// I/O Port Data Direction Set
;equ PORTE_DIRCLR = 1666		// I/O Port Data Direction Clear
;equ PORTE_DIRTGL = 1667		// I/O Port Data Direction Toggle
;equ PORTE_OUT = 1668		// I/O Port Output
;equ PORTE_OUTSET = 1669		// I/O Port Output Set
;equ PORTE_OUTCLR = 1670		// I/O Port Output Clear
;equ PORTE_OUTTGL = 1671		// I/O Port Output Toggle
;equ PORTE_IN = 1672		// I/O port Input
;equ PORTE_INTCTRL = 1673		// Interrupt Control Register
;equ PORTE_INT0MASK = 1674		// Port Interrupt 0 Mask
;equ PORTE_INT1MASK = 1675		// Port Interrupt 1 Mask
;equ PORTE_INTFLAGS = 1676		// Interrupt Flag Register
;equ PORTE_PIN0CTRL = 1680		// Pin 0 Control Register
;equ PORTE_PIN1CTRL = 1681		// Pin 1 Control Register
;equ PORTE_PIN2CTRL = 1682		// Pin 2 Control Register
;equ PORTE_PIN3CTRL = 1683		// Pin 3 Control Register
;equ PORTE_PIN4CTRL = 1684		// Pin 4 Control Register
;equ PORTE_PIN5CTRL = 1685		// Pin 5 Control Register
;equ PORTE_PIN6CTRL = 1686		// Pin 6 Control Register
;equ PORTE_PIN7CTRL = 1687		// Pin 7 Control Register

;***************************************************************************
;** PORTR - Port R
;***************************************************************************
	
;equ PORTR_DIR = 2016		// I/O Port Data Direction
;equ PORTR_DIRSET = 2017		// I/O Port Data Direction Set
;equ PORTR_DIRCLR = 2018		// I/O Port Data Direction Clear
;equ PORTR_DIRTGL = 2019		// I/O Port Data Direction Toggle
;equ PORTR_OUT = 2020		// I/O Port Output
;equ PORTR_OUTSET = 2021		// I/O Port Output Set
;equ PORTR_OUTCLR = 2022		// I/O Port Output Clear
;equ PORTR_OUTTGL = 2023		// I/O Port Output Toggle
;equ PORTR_IN = 2024		// I/O port Input
;equ PORTR_INTCTRL = 2025		// Interrupt Control Register
;equ PORTR_INT0MASK = 2026		// Port Interrupt 0 Mask
.EQU PMIC_CTRL = 0x00A2
.EQU RAMEND = 0x2044
.EQU r5 = 4
.EQU r20 = 10
.EQU DACB_STATUS = r20
.EQU PORTCFG_MPCMASK = 0x0834
.EQU ADCA_CH0_CTRL = 0x0087
.EQU CCP = 0x0042
.EQU DACB_CTRLC = 0x0a8b
;equ PORTR_INT1MASK = 2027		// Port Interrupt 1 Mask
;equ PORTR_INTFLAGS = 2028		// Interrupt Flag Register
;equ PORTR_PIN0CTRL = 2032		// Pin 0 Control Register
;equ PORTR_PIN1CTRL = 2033		// Pin 1 Control Register
;equ PORTR_PIN2CTRL = 2034		// Pin 2 Control Register
;equ PORTR_PIN3CTRL = 2035		// Pin 3 Control Register
;equ PORTR_PIN4CTRL = 2036		// Pin 4 Control Register
;equ PORTR_PIN5CTRL = 2037		// Pin 5 Control Register
;equ PORTR_PIN6CTRL = 2038		// Pin 6 Control Register
;equ PORTR_PIN7CTRL = 2039		// Pin 7 Control Register

;***************************************************************************
;** TCC0 - Timer/Counter C0
;***************************************************************************
	
;equ TCC0_CTRLA = 2048		// Control Register A
;equ TCC0_CTRLB = 2049		// Control Register B
;equ TCC0_CTRLC = 2050		// Control register C
;equ TCC0_CTRLD = 2051		// Control Register D
;equ TCC0_CTRLE = 2052		// Control Register E
;equ TCC0_INTCTRLA = 2054		// Interrupt Control Register A
;equ TCC0_INTCTRLB = 2055		// Interrupt Control Register B
;equ TCC0_CTRLFCLR = 2056		// Control Register F Clear
;equ TCC0_CTRLFSET = 2057		// Control Register F Set
;equ TCC0_CTRLGCLR = 2058		// Control Register G Clear
;equ TCC0_CTRLGSET = 2059		// Control Register G Set
;equ TCC0_INTFLAGS = 2060		// Interrupt Flag Register
;equ TCC0_TEMP = 2063		// Temporary Register For 16-bit Access
;equ TCC0_CNT = 2080		// Count
;equ TCC0_PER = 2086		// Period
;equ TCC0_CCA = 2088		// Compare or Capture A
;equ TCC0_CCB = 2090		// Compare or Capture B
;equ TCC0_CCC = 2092		// Compare or Capture C
;equ TCC0_CCD = 2094		// Compare or Capture D
;equ TCC0_PERBUF = 2102		// Period Buffer
;equ TCC0_CCABUF = 2104		// Compare Or Capture A Buffer
;equ TCC0_CCBBUF = 2106		// Compare Or Capture B Buffer
;equ TCC0_CCCBUF = 2108		// Compare Or Capture C Buffer
;equ TCC0_CCDBUF = 2110		// Compare Or Capture D Buffer

;***************************************************************************
;** TCC1 - Timer/Counter C1
;***************************************************************************
	
;equ TCC1_CTRLA = 2112		// Control  Register A
;equ TCC1_CTRLB = 2113		// Control Register B
;equ TCC1_CTRLC = 2114		// Control register C
;equ TCC1_CTRLD = 2115		// Control Register D
;equ TCC1_CTRLE = 2116		// Control Register E
;equ TCC1_INTCTRLA = 2118		// Interrupt Control Register A
;equ TCC1_INTCTRLB = 2119		// Interrupt Control Register B
;equ TCC1_CTRLFCLR = 2120		// Control Register F Clear
;equ TCC1_CTRLFSET = 2121		// Control Register F Set
;equ TCC1_CTRLGCLR = 2122		// Control Register G Clear
;equ TCC1_CTRLGSET = 2123		// Control Register G Set
;equ TCC1_INTFLAGS = 2124		// Interrupt Flag Register
;equ TCC1_TEMP = 2127		// Temporary Register For 16-bit Access
;equ TCC1_CNT = 2144		// Count
;equ TCC1_PER = 2150		// Period
;equ TCC1_CCA = 2152		// Compare or Capture A
;equ TCC1_CCB = 2154		// Compare or Capture B
;equ TCC1_PERBUF = 2166		// Period Buffer
;equ TCC1_CCABUF = 2168		// Compare Or Capture A Buffer
;equ TCC1_CCBBUF = 2170		// Compare Or Capture B Buffer

;***************************************************************************
;** AWEXC - Advanced Waveform Extension C
;***************************************************************************
	
;equ AWEXC_CTRL = 2176		// Control Register
;equ AWEXC_FDEMASK = 2178		// Fault Detection Event Mask
;equ AWEXC_FDCTRL = 2179		// Fault Detection Control Register
;equ AWEXC_STATUS = 2180		// Status Register
;equ AWEXC_DTBOTH = 2182		// Dead Time Both Sides
;equ AWEXC_DTBOTHBUF = 2183		// Dead Time Both Sides Buffer
;equ AWEXC_DTLS = 2184		// Dead Time Low Side
;equ AWEXC_DTHS = 2185		// Dead Time High Side
;equ AWEXC_DTLSBUF = 2186		// Dead Time Low Side Buffer
;equ AWEXC_DTHSBUF = 2187		// Dead Time High Side Buffer
;equ AWEXC_OUTOVEN = 2188		// Output Override Enable

;***************************************************************************
;** HIRESC - High-Resolution Extension C
;***************************************************************************
	
;equ HIRESC_CTRLA = 2192		// Control Register

;***************************************************************************
;** USARTC0 - Universal Asynchronous Receiver-Transmitter C0
;***************************************************************************
	
;equ USARTC0_DATA = 2208		// Data Register
;equ USARTC0_STATUS = 2209		// Status Register
;equ USARTC0_CTRLA = 2211		// Control Register A
;equ USARTC0_CTRLB = 2212		// Control Register B
;equ USARTC0_CTRLC = 2213		// Control Register C
;equ USARTC0_BAUDCTRLA = 2214		// Baud Rate Control Register A
;equ USARTC0_BAUDCTRLB = 2215		// Baud Rate Control Register B

;***************************************************************************
;** USARTC1 - Universal Asynchronous Receiver-Transmitter C1
;***************************************************************************
	
;equ USARTC1_DATA = 2224		// Data Register
;equ USARTC1_STATUS = 2225		// Status Register
;equ USARTC1_CTRLA = 2227		// Control Register A
;equ USARTC1_CTRLB = 2228		// Control Register B
;equ USARTC1_CTRLC = 2229		// Control Register C
;equ USARTC1_BAUDCTRLA = 2230		// Baud Rate Control Register A
;equ USARTC1_BAUDCTRLB = 2231		// Baud Rate Control Register B

;***************************************************************************
;** SPIC - Serial Peripheral Interface C
;***************************************************************************
	
;equ SPIC_CTRL = 2240		// Control Register
;equ SPIC_INTCTRL = 2241		// Interrupt Control Register
;equ SPIC_STATUS = 2242		// Status Register
;equ SPIC_DATA = 2243		// Data Register

;***************************************************************************
;** TCD0 - Timer/Counter D0
;***************************************************************************
	
;equ TCD0_CTRLA = 2304		// Control Register A
;equ TCD0_CTRLB = 2305		// Control Register B
;equ TCD0_CTRLC = 2306		// Control register C
;equ TCD0_CTRLD = 2307		// Control Register D
;equ TCD0_CTRLE = 2308		// Control Register E
;equ TCD0_INTCTRLA = 2310		// Interrupt Control Register A
;equ TCD0_INTCTRLB = 2311		// Interrupt Control Register B
;equ TCD0_CTRLFCLR = 2312		// Control Register F Clear
;equ TCD0_CTRLFSET = 2313		// Control Register F Set
;equ TCD0_CTRLGCLR = 2314		// Control Register G Clear
;equ TCD0_CTRLGSET = 2315		// Control Register G Set
;equ TCD0_INTFLAGS = 2316		// Interrupt Flag Register
;equ TCD0_TEMP = 2319		// Temporary Register For 16-bit Access
;equ TCD0_CNT = 2336		// Count
;equ TCD0_PER = 2342		// Period
;equ TCD0_CCA = 2344		// Compare or Capture A
;equ TCD0_CCB = 2346		// Compare or Capture B
;equ TCD0_CCC = 2348		// Compare or Capture C
;equ TCD0_CCD = 2350		// Compare or Capture D
;equ TCD0_PERBUF = 2358		// Period Buffer
;equ TCD0_CCABUF = 2360		// Compare Or Capture A Buffer
;equ TCD0_CCBBUF = 2362		// Compare Or Capture B Buffer
;equ TCD0_CCCBUF = 2364		// Compare Or Capture C Buffer
;equ TCD0_CCDBUF = 2366		// Compare Or Capture D Buffer


.EQU PORTB_DIR = 0x0620
.EQU PORTB_OUT = 0x0624
.EQU PORTB_PIN0CTRL = 0x0630
.EQU PORTB_PIN1CTRL = 0x0631
.EQU PORTB_PIN2CTRL = 0x0632
.EQU PORTB_INTCTRL = 0x0629
.EQU PORTB_INT0MASK = 0x062A
.EQU PORTB_INT1MASK = 0x062B

.EQU PORTC_DIR = 0x0640
.EQU PORTC_sts = 0x0644
.EQU PORTC_PIN0CTRL = 0x0650
.EQU PORTC_PIN7CTRL = 0x0657
.EQU	PORTC_INTCTRL = 0x0649
.EQU PORTC_INT0MASK = 0x064A
.EQU	PORTC_INT1MASK = 0x064B
.EQU	PORTC_PIN1CTRl = 0x0651
.EQU PORTC_MPCMASK = 0x00B0

.EQU ADCA_CTRLA = 0x0200
.EQU ADCA_CTRLB = 0x0201
.EQU ADCA_PRESCALER = 0x0204
.EQU ADCA_REFCTRL = 0x0202
.EQU	ADCA_CH0RES = 0x0210
.EQU	ADCA_CH0_MUXCTRL = 0x0221
.EQU ADCA_CMP = 0x0218
.EQU ADCA_CH0_INTCTRL = 0x0222
.EQU ADCA_CH1_INTCTRL = 0x0223
.EQU	ADCA_CH2_INTCTRL = 0x0224
.EQU ADCA_CH3_INTCTRL = 0x0225
.EQU ADCA_CH0_INTFLAGS = 0x0223

.EQU DACB_CTRLA = 0x0320
.EQU	DACB_CTRLB = 0x0321
.EQU DACB_CTRL C = 0x322
.EQU DACB_CH0DATA_LOW = 0x0338
.EQU	DACB_CH0DATA_HIGH = 0x0339

.EQU OSC_CTRL = 0x0050
.EQU OSC_STATUS = 0x0051
.EQU OSC_DFLLCTRL = 0x0056

.EQU CLK_CTRL = 0x0040
.EQU CLK_PSCTRL = 0x0041

.EQU DFLLRC32M_CTRL = 0x0060

;***************************************************************************
;** TCD1 - Timer/Counter D1
;***************************************************************************
	
;equ TCD1_CTRLA = 2368		// Control  Register A
;equ TCD1_CTRLB = 2369		// Control Register B
;equ TCD1_CTRLC = 2370		// Control register C
;equ TCD1_CTRLD = 2371		// Control Register D
;equ TCD1_CTRLE = 2372		// Control Register E
;equ TCD1_INTCTRLA = 2374		// Interrupt Control Register A
;equ TCD1_INTCTRLB = 2375		// Interrupt Control Register B
;equ TCD1_CTRLFCLR = 2376		// Control Register F Clear
;equ TCD1_CTRLFSET = 2377		// Control Register F Set
;equ TCD1_CTRLGCLR = 2378		// Control Register G Clear
;equ TCD1_CTRLGSET = 2379		// Control Register G Set
;equ TCD1_INTFLAGS = 2380		// Interrupt Flag Register
;equ TCD1_TEMP = 2383		// Temporary Register For 16-bit Access
;equ TCD1_CNT = 2400		// Count
;equ TCD1_PER = 2406		// Period
;equ TCD1_CCA = 2408		// Compare or Capture A
;equ TCD1_CCB = 2410		// Compare or Capture B
;equ TCD1_PERBUF = 2422		// Period Buffer
;equ TCD1_CCABUF = 2424		// Compare Or Capture A Buffer
;equ TCD1_CCBBUF = 2426		// Compare Or Capture B Buffer

;***************************************************************************
;** HIRESD - High-Resolution Extension D
;***************************************************************************
	
;equ HIRESD_CTRLA = 2448		// Control Register

;***************************************************************************
;** USARTD0 - Universal Asynchronous Receiver-Transmitter D0
;***************************************************************************
	
;equ USARTD0_DATA = 2464		// Data Register
;equ USARTD0_STATUS = 2465		// Status Register
;equ USARTD0_CTRLA = 2467		// Control Register A
;equ USARTD0_CTRLB = 2468		// Control Register B
;equ USARTD0_CTRLC = 2469		// Control Register C
;equ USARTD0_BAUDCTRLA = 2470		// Baud Rate Control Register A
;equ USARTD0_BAUDCTRLB = 2471		// Baud Rate Control Register B

;***************************************************************************
;** USARTD1 - Universal Asynchronous Receiver-Transmitter D1
;***************************************************************************
	
;equ USARTD1_DATA = 2480		// Data Register
;equ USARTD1_STATUS = 2481		// Status Register
;equ USARTD1_CTRLA = 2483		// Control Register A
;equ USARTD1_CTRLB = 2484		// Control Register B
;equ USARTD1_CTRLC = 2485		// Control Register C
;equ USARTD1_BAUDCTRLA = 2486		// Baud Rate Control Register A
;equ USARTD1_BAUDCTRLB = 2487		// Baud Rate Control Register B

;***************************************************************************
;** SPID - Serial Peripheral Interface D
;***************************************************************************
	
;equ SPID_CTRL = 2496		// Control Register
;equ SPID_INTCTRL = 2497		// Interrupt Control Register
;equ SPID_STATUS = 2498		// Status Register
;equ SPID_DATA = 2499		// Data Register

;***************************************************************************
;** TCE0 - Timer/Counter E0
;***************************************************************************
	
;equ TCE0_CTRLA = 2560		// Control Register A
;equ TCE0_CTRLB = 2561		// Control Register B
;equ TCE0_CTRLC = 2562		// Control register C
;equ TCE0_CTRLD = 2563		// Control Register D
;equ TCE0_CTRLE = 2564		// Control Register E
;equ TCE0_INTCTRLA = 2566		// Interrupt Control Register A
;equ TCE0_INTCTRLB = 2567		// Interrupt Control Register B
;equ TCE0_CTRLFCLR = 2568		// Control Register F Clear
;equ TCE0_CTRLFSET = 2569		// Control Register F Set
;equ TCE0_CTRLGCLR = 2570		// Control Register G Clear
;equ TCE0_CTRLGSET = 2571		// Control Register G Set
;equ TCE0_INTFLAGS = 2572		// Interrupt Flag Register
;equ TCE0_TEMP = 2575		// Temporary Register For 16-bit Access
;equ TCE0_CNT = 2592		// Count
;equ TCE0_PER = 2598		// Period
;equ TCE0_CCA = 2600		// Compare or Capture A
;equ TCE0_CCB = 2602		// Compare or Capture B
;equ TCE0_CCC = 2604		// Compare or Capture C
;equ TCE0_CCD = 2606		// Compare or Capture D
;equ TCE0_PERBUF = 2614		// Period Buffer
;equ TCE0_CCABUF = 2616		// Compare Or Capture A Buffer
;equ TCE0_CCBBUF = 2618		// Compare Or Capture B Buffer
;equ TCE0_CCCBUF = 2620		// Compare Or Capture C Buffer
;equ TCE0_CCDBUF = 2622		// Compare Or Capture D Buffer

;***************************************************************************
;** HIRESE - High-Resolution Extension E
;***************************************************************************
	
;equ HIRESE_CTRLA = 2704		// Control Register

;***************************************************************************
;** USARTE0 - Universal Asynchronous Receiver-Transmitter E0
;***************************************************************************
	
;equ USARTE0_DATA = 2720		// Data Register
;equ USARTE0_STATUS = 2721		// Status Register
;equ USARTE0_CTRLA = 2723		// Control Register A
;equ USARTE0_CTRLB = 2724		// Control Register B
;equ USARTE0_CTRLC = 2725		// Control Register C
;equ USARTE0_BAUDCTRLA = 2726		// Baud Rate Control Register A
;equ USARTE0_BAUDCTRLB = 2727		// Baud Rate Control Register B

;***************************************************************************
;** IRCOM - IR Communication Module
;***************************************************************************
	
;equ IRCOM_CTRL = 2296		// Control Register
;equ IRCOM_TXPLCTRL = 2297		// IrDA Transmitter Pulse Length Control Register
;equ IRCOM_RXPLCTRL = 2298		// IrDA Receiver Pulse Length Control Register

;***************************************************************************
;** AES - AES Crypto Module
;***************************************************************************
	
;equ AES_CTRL = 192		// AES Control Register
;equ AES_STATUS = 193		// AES Status Register
;equ AES_STATE = 194		// AES State Register
;equ AES_KEY = 195		// AES Key Register
;equ AES_INTCTRL = 196		// AES Interrupt Control Register


; ***** ALL MODULE BASE ADRESSES *****************************************

;equ GPIO_base = 0x0000		// General Purpose IO Registers
;equ OCD_base = 0x002E		// On-Chip Debug System
;equ CPU_base = 0x0030		// CPU Registers
;equ CLK_base = 0x0040		// Clock System
;equ SLEEP_base = 0x0048		// Sleep Controller
;equ OSC_base = 0x0050		// Oscillator Control
;equ DFLLRC32M_base = 0x0060		// DFLL for 32MHz RC Oscillator
;equ DFLLRC2M_base = 0x0068		// DFLL for 2MHz RC Oscillator
;equ PR_base = 0x0070		// Power Reduction
;equ RST_base = 0x0078		// Reset Controller
;equ WDT_base = 0x0080		// Watch-Dog Timer
;equ MCU_base = 0x0090		// MCU Control
;equ PMIC_base = 0x00A0		// Programmable Interrupt Controller
;equ DMA_base = 0x0100		// DMA Controller
;equ EVSYS_base = 0x0180		// Event System
;equ NVM_base = 0x01C0		// Non Volatile Memory Controller
;equ ACA_base = 0x0380		// Analog Comparator A
;equ ADCA_base = 0x0200		// Analog to Digital Converter A
;equ DACB_base = 0x0320		// Digital to Analog Converter B
;equ RTC_base = 0x0400		// Real-Time Counter
;equ TWIC_base = 0x480		// Two-Wire Interface C
;equ TWIE_base = 0x4A0		// Two-Wire Interface E
;equ PORTCFG_base = 0x00B0		// Port Configuration
;equ VPORT0_base = 0x0010		// Virtual Port 0
;equ VPORT1_base = 0x0014		// Virtual Port 1
;equ VPORT2_base = 0x0018		// Virtual Port 2
;equ VPORT3_base = 0x001C		// Virtual Port 3
;equ PORTA_base = 0x0600		// Port A
;equ PORTB_base = 0x0620		// Port B
;equ PORTC_base = 0x0640		// Port C
;equ PORTD_base = 0x0660		// Port D
;equ PORTE_base = 0x0680		// Port E
;equ PORTR_base = 0x07E0		// Port R
;equ TCC0_base = 0x800		// Timer/Counter C0
;equ TCC1_base = 0x840		// Timer/Counter C1
;equ AWEXC_base = 0x880		// Advanced Waveform Extension C
;equ HIRESC_base = 0x890		// High-Resolution Extension C
;equ USARTC0_base = 0x8A0		// Universal Asynchronous Receiver-Transmitter C0
;equ USARTC1_base = 0x8B0		// Universal Asynchronous Receiver-Transmitter C1
;equ SPIC_base = 0x8C0		// Serial Peripheral Interface C
;equ TCD0_base = 0x900		// Timer/Counter D0
;equ TCD1_base = 0x940		// Timer/Counter D1
;equ HIRESD_base = 0x990		// High-Resolution Extension D
;equ USARTD0_base = 0x9A0		// Universal Asynchronous Receiver-Transmitter D0
;equ USARTD1_base = 0x9B0		// Universal Asynchronous Receiver-Transmitter D1
;equ SPID_base = 0x9C0		// Serial Peripheral Interface D
;equ TCE0_base = 0xA00		// Timer/Counter E0
;equ HIRESE_base = 0xA90		// High-Resolution Extension E
;equ USARTE0_base = 0xAA0		// Universal Asynchronous Receiver-Transmitter E0
;equ IRCOM_base = 0x8F8		// IR Communication Module
;equ AES_base = 0x0C0		// AES Crypto Module


; ***** IO REGISTER OFFSETS **********************************************


;***************************************************************************
;** GPIO - General Purpose IO
;***************************************************************************/
;equ GPIO_GPIOR0_offset = 0x00		// General Purpose IO Register 0
;equ GPIO_GPIOR1_offset = 0x01		// General Purpose IO Register 1
;equ GPIO_GPIOR2_offset = 0x02		// General Purpose IO Register 2
;equ GPIO_GPIOR3_offset = 0x03		// General Purpose IO Register 3
;equ GPIO_GPIOR4_offset = 0x04		// General Purpose IO Register 4
;equ GPIO_GPIOR5_offset = 0x05		// General Purpose IO Register 5
;equ GPIO_GPIOR6_offset = 0x06		// General Purpose IO Register 6
;equ GPIO_GPIOR7_offset = 0x07		// General Purpose IO Register 7
;equ GPIO_GPIOR8_offset = 0x08		// General Purpose IO Register 8
;equ GPIO_GPIOR9_offset = 0x09		// General Purpose IO Register 9
;equ GPIO_GPIOR10_offset = 0x0A		// General Purpose IO Register 10
;equ GPIO_GPIOR11_offset = 0x0B		// General Purpose IO Register 11
;equ GPIO_GPIOR12_offset = 0x0C		// General Purpose IO Register 12
;equ GPIO_GPIOR13_offset = 0x0D		// General Purpose IO Register 13
;equ GPIO_GPIOR14_offset = 0x0E		// General Purpose IO Register 14
;equ GPIO_GPIOR15_offset = 0x0F		// General Purpose IO Register 15

;***************************************************************************
;** XOCD - On-Chip Debug System
;***************************************************************************/
;equ OCD_OCDR0_offset = 0x00		// OCD Register 0
;equ OCD_OCDR1_offset = 0x01		// OCD Register 1

;***************************************************************************
;** CPU - CPU
;***************************************************************************/
;equ CPU_CCP_offset = 0x04		// Configuration Change Protection
;equ CPU_RAMPD_offset = 0x08		// Ramp D
;equ CPU_RAMPX_offset = 0x09		// Ramp X
;equ CPU_RAMPY_offset = 0x0A		// Ramp Y
;equ CPU_RAMPZ_offset = 0x0B		// Ramp Z
;equ CPU_EIND_offset = 0x0C		// Extended Indirect Jump
;equ CPU_SPL_offset = 0x0D		// Stack Pointer Low
;equ CPU_SPH_offset = 0x0E		// Stack Pointer High
;equ CPU_SREG_offset = 0x0F		// Status Register

;***************************************************************************
;** CLK - Clock System
;***************************************************************************/
;equ CLK_CTRL_offset = 0x00		// Control Register
;equ CLK_PSCTRL_offset = 0x01		// Prescaler Control Register
;equ CLK_LOCK_offset = 0x02		// Lock register
;equ CLK_RTCCTRL_offset = 0x03		// RTC Control Register
;equ PR_PRGEN_offset = 0x00		// General Power Reduction
;equ PR_PRPA_offset = 0x01		// Power Reduction Port A
;equ PR_PRPB_offset = 0x02		// Power Reduction Port B
;equ PR_PRPC_offset = 0x03		// Power Reduction Port C
;equ PR_PRPD_offset = 0x04		// Power Reduction Port D
;equ PR_PRPE_offset = 0x05		// Power Reduction Port E
;equ PR_PRPF_offset = 0x06		// Power Reduction Port F

;***************************************************************************
;** SLEEP - Sleep Controller
;***************************************************************************/
;equ SLEEP_CTRL_offset = 0x00		// Control Register

;***************************************************************************
;** OSC - Oscillator
;***************************************************************************/
;equ OSC_CTRL_offset = 0x00		// Control Register
;equ OSC_STATUS_offset = 0x01		// Status Register
;equ OSC_XOSCCTRL_offset = 0x02		// External Oscillator Control Register
;equ OSC_XOSCFAIL_offset = 0x03		// External Oscillator Failure Detection Register
;equ OSC_RC32KCAL_offset = 0x04		// 32kHz Internal Oscillator Calibration Register
;equ OSC_PLLCTRL_offset = 0x05		// PLL Control REgister
;equ OSC_DFLLCTRL_offset = 0x06		// DFLL Control Register

;***************************************************************************
;** DFLL - DFLL
;***************************************************************************/
;equ DFLL_CTRL_offset = 0x00		// Control Register
;equ DFLL_CALA_offset = 0x02		// Calibration Register A
;equ DFLL_CALB_offset = 0x03		// Calibration Register B
;equ DFLL_COMP0_offset = 0x04		// Oscillator Compare Register 0
;equ DFLL_COMP1_offset = 0x05		// Oscillator Compare Register 1
;equ DFLL_COMP2_offset = 0x06		// Oscillator Compare Register 2

;***************************************************************************
;** RST - Reset
;***************************************************************************/
;equ RST_STATUS_offset = 0x00		// Status Register
;equ RST_CTRL_offset = 0x01		// Control Register

;***************************************************************************
;** WDT - Watch-Dog Timer
;***************************************************************************/
;equ WDT_CTRL_offset = 0x00		// Control
;equ WDT_WINCTRL_offset = 0x01		// Windowed Mode Control
;equ WDT_STATUS_offset = 0x02		// Status

;***************************************************************************
;** MCU - MCU Control
;***************************************************************************/
;equ MCU_DEVID0_offset = 0x00		// Device ID byte 0
;equ MCU_DEVID1_offset = 0x01		// Device ID byte 1
;equ MCU_DEVID2_offset = 0x02		// Device ID byte 2
;equ MCU_REVID_offset = 0x03		// Revision ID
;equ MCU_JTAGUID_offset = 0x04		// JTAG User ID
;equ MCU_MCUCR_offset = 0x06		// MCU Control
;equ MCU_EVSYSLOCK_offset = 0x08		// Event System Lock
;equ MCU_AWEXLOCK_offset = 0x09		// AWEX Lock

;***************************************************************************
;** PMIC - Programmable Multi-level Interrupt Controller
;***************************************************************************/
;equ PMIC_STATUS_offset = 0x00		// Status Register
;equ PMIC_INTPRI_offset = 0x01		// Interrupt Priority
;equ PMIC_CTRL_offset = 0x02		// Control Register

;***************************************************************************
;** DMA - DMA Controller
;***************************************************************************/
;equ DMA_CH_CTRLA_offset = 0x00		// Channel Control
;equ DMA_CH_CTRLB_offset = 0x01		// Channel Control
;equ DMA_CH_ADDRCTRL_offset = 0x02		// Address Control
;equ DMA_CH_TRIGSRC_offset = 0x03		// Channel Trigger Source
;equ DMA_CH_TRFCNT_offset = 0x04		// Channel Block Transfer Count
;equ DMA_CH_REPCNT_offset = 0x06		// Channel Repeat Count
;equ DMA_CH_SRCADDR0_offset = 0x08		// Channel Source Address 0
;equ DMA_CH_SRCADDR1_offset = 0x09		// Channel Source Address 1
;equ DMA_CH_SRCADDR2_offset = 0x0A		// Channel Source Address 2
;equ DMA_CH_DESTADDR0_offset = 0x0C		// Channel Destination Address 0
;equ DMA_CH_DESTADDR1_offset = 0x0D		// Channel Destination Address 1
;equ DMA_CH_DESTADDR2_offset = 0x0E		// Channel Destination Address 2
;equ DMA_CTRL_offset = 0x00		// Control
;equ DMA_INTFLAGS_offset = 0x03		// Transfer Interrupt Status
;equ DMA_STATUS_offset = 0x04		// Status
;equ DMA_TEMP_offset = 0x06		// Temporary Register For 16/24-bit Access
;equ DMA_CH0_offset = 0x10		// DMA Channel 0
;equ DMA_CH1_offset = 0x20		// DMA Channel 1
;equ DMA_CH2_offset = 0x30		// DMA Channel 2
;equ DMA_CH3_offset = 0x40		// DMA Channel 3

;***************************************************************************
;** EVSYS - Event System
;***************************************************************************/
;equ EVSYS_CH0MUX_offset = 0x00		// Event Channel 0 Multiplexer
;equ EVSYS_CH1MUX_offset = 0x01		// Event Channel 1 Multiplexer
;equ EVSYS_CH2MUX_offset = 0x02		// Event Channel 2 Multiplexer
;equ EVSYS_CH3MUX_offset = 0x03		// Event Channel 3 Multiplexer
;equ EVSYS_CH4MUX_offset = 0x04		// Event Channel 4 Multiplexer
;equ EVSYS_CH5MUX_offset = 0x05		// Event Channel 5 Multiplexer
;equ EVSYS_CH6MUX_offset = 0x06		// Event Channel 6 Multiplexer
;equ EVSYS_CH7MUX_offset = 0x07		// Event Channel 7 Multiplexer
;equ EVSYS_CH0CTRL_offset = 0x08		// Channel 0 Control Register
;equ EVSYS_CH1CTRL_offset = 0x09		// Channel 1 Control Register
;equ EVSYS_CH2CTRL_offset = 0x0A		// Channel 2 Control Register
;equ EVSYS_CH3CTRL_offset = 0x0B		// Channel 3 Control Register
;equ EVSYS_CH4CTRL_offset = 0x0C		// Channel 4 Control Register
;equ EVSYS_CH5CTRL_offset = 0x0D		// Channel 5 Control Register
;equ EVSYS_CH6CTRL_offset = 0x0E		// Channel 6 Control Register
;equ EVSYS_CH7CTRL_offset = 0x0F		// Channel 7 Control Register
;equ EVSYS_STROBE_offset = 0x10		// Event Strobe
;equ EVSYS_DATA_offset = 0x11		// Event Data

;***************************************************************************
;** NVM - Non Volatile Memory Controller
;***************************************************************************/
;equ NVM_ADDR0_offset = 0x00		// Address Register 0
;equ NVM_ADDR1_offset = 0x01		// Address Register 1
;equ NVM_ADDR2_offset = 0x02		// Address Register 2
;equ NVM_DATA0_offset = 0x04		// Data Register 0
;equ NVM_DATA1_offset = 0x05		// Data Register 1
;equ NVM_DATA2_offset = 0x06		// Data Register 2
;equ NVM_CMD_offset = 0x0A		// Command
;equ NVM_CTRLA_offset = 0x0B		// Control Register A
;equ NVM_CTRLB_offset = 0x0C		// Control Register B
;equ NVM_INTCTRL_offset = 0x0D		// Interrupt Control
;equ NVM_STATUS_offset = 0x0F		// Status
;equ NVM_LOCKBITS_offset = 0x10		// Lock Bits
;equ NVM_LOCKBITS_LOCKBITS_offset = 0x00		// Lock Bits
;equ NVM_FUSES_FUSEBYTE0_offset = 0x00		// User ID
;equ NVM_FUSES_FUSEBYTE1_offset = 0x01		// Watchdog Configuration
;equ NVM_FUSES_FUSEBYTE2_offset = 0x02		// Reset Configuration
;equ NVM_FUSES_FUSEBYTE4_offset = 0x04		// Start-up Configuration
;equ NVM_FUSES_FUSEBYTE5_offset = 0x05		// EESAVE and BOD Level
;equ NVM_PROD_SIGNATURES_RCOSC2M_offset = 0x00		// RCOSC 2MHz Calibration Value
;equ NVM_PROD_SIGNATURES_RCOSC32K_offset = 0x02		// RCOSC 32kHz Calibration Value
;equ NVM_PROD_SIGNATURES_RCOSC32M_offset = 0x03		// RCOSC 32MHz Calibration Value
;equ NVM_PROD_SIGNATURES_LOTNUM0_offset = 0x08		// Lot Number Byte 0, ASCII
;equ NVM_PROD_SIGNATURES_LOTNUM1_offset = 0x09		// Lot Number Byte 1, ASCII
;equ NVM_PROD_SIGNATURES_LOTNUM2_offset = 0x0A		// Lot Number Byte 2, ASCII
;equ NVM_PROD_SIGNATURES_LOTNUM3_offset = 0x0B		// Lot Number Byte 3, ASCII
;equ NVM_PROD_SIGNATURES_LOTNUM4_offset = 0x0C		// Lot Number Byte 4, ASCII
;equ NVM_PROD_SIGNATURES_LOTNUM5_offset = 0x0D		// Lot Number Byte 5, ASCII
;equ NVM_PROD_SIGNATURES_WAFNUM_offset = 0x10		// Wafer Number
;equ NVM_PROD_SIGNATURES_COORDX0_offset = 0x12		// Wafer Coordinate X Byte 0
;equ NVM_PROD_SIGNATURES_COORDX1_offset = 0x13		// Wafer Coordinate X Byte 1
;equ NVM_PROD_SIGNATURES_COORDY0_offset = 0x14		// Wafer Coordinate Y Byte 0
;equ NVM_PROD_SIGNATURES_COORDY1_offset = 0x15		// Wafer Coordinate Y Byte 1
;equ NVM_PROD_SIGNATURES_ADCACAL0_offset = 0x20		// ADCA Calibration Byte 0
;equ NVM_PROD_SIGNATURES_ADCACAL1_offset = 0x21		// ADCA Calibration Byte 1
;equ NVM_PROD_SIGNATURES_ADCBCAL0_offset = 0x24		// ADCB Calibration Byte 0
;equ NVM_PROD_SIGNATURES_ADCBCAL1_offset = 0x25		// ADCB Calibration Byte 1
;equ NVM_PROD_SIGNATURES_TEMPSENSE0_offset = 0x2E		// Temperature Sensor Calibration Byte 0
;equ NVM_PROD_SIGNATURES_TEMPSENSE1_offset = 0x2F		// Temperature Sensor Calibration Byte 0

;***************************************************************************
;** AC - Analog Comparator
;***************************************************************************/
;equ AC_AC0CTRL_offset = 0x00		// Analog Comparator 0 Control
;equ AC_AC1CTRL_offset = 0x01		// Analog Comparator 1 Control
;equ AC_AC0MUXCTRL_offset = 0x02		// Analog Comparator 0 MUX Control
;equ AC_AC1MUXCTRL_offset = 0x03		// Analog Comparator 1 MUX Control
;equ AC_CTRLA_offset = 0x04		// Control Register A
;equ AC_CTRLB_offset = 0x05		// Control Register B
;equ AC_WINCTRL_offset = 0x06		// Window Mode Control
;equ AC_STATUS_offset = 0x07		// Status

;***************************************************************************
;** ADC - Analog/Digital Converter
;***************************************************************************/
;equ ADC_CH_CTRL_offset = 0x00		// Control Register
;equ ADC_CH_MUXCTRL_offset = 0x01		// MUX Control
;equ ADC_CH_INTCTRL_offset = 0x02		// Channel Interrupt Control
;equ ADC_CH_INTFLAGS_offset = 0x03		// Interrupt Flags
;equ ADC_CH_RES_offset = 0x04		// Channel Result
;equ ADC_CTRLA_offset = 0x00		// Control Register A
;equ ADC_CTRLB_offset = 0x01		// Control Register B
;equ ADC_REFCTRL_offset = 0x02		// Reference Control
;equ ADC_EVCTRL_offset = 0x03		// Event Control
;equ ADC_PRESCALER_offset = 0x04		// Clock Prescaler
;equ ADC_INTFLAGS_offset = 0x06		// Interrupt Flags
;equ ADC_TEMP_offset = 0x07		// Temporary register
;equ ADC_CAL_offset = 0x0C		// Calibration Value
;equ ADC_CH0RES_offset = 0x10		// Channel 0 Result
;equ ADC_CH1RES_offset = 0x12		// Channel 1 Result
;equ ADC_CH2RES_offset = 0x14		// Channel 2 Result
;equ ADC_CH3RES_offset = 0x16		// Channel 3 Result
;equ ADC_CMP_offset = 0x18		// Compare Value
;equ ADC_CH0_offset = 0x20		// ADC Channel 0
;equ ADC_CH1_offset = 0x28		// ADC Channel 1
;equ ADC_CH2_offset = 0x30		// ADC Channel 2
;equ ADC_CH3_offset = 0x38		// ADC Channel 3

;***************************************************************************
;** DAC - Digital/Analog Converter
;***************************************************************************/
;equ DAC_CTRLA_offset = 0x00		// Control Register A
;equ DAC_CTRLB_offset = 0x01		// Control Register B
;equ DAC_CTRLC_offset = 0x02		// Control Register C
;equ DAC_EVCTRL_offset = 0x03		// Event Input Control
;equ DAC_TIMCTRL_offset = 0x04		// Timing Control
;equ DAC_STATUS_offset = 0x05		// Status
;equ DAC_GAINCAL_offset = 0x08		// Gain Calibration
;equ DAC_OFFSETCAL_offset = 0x09		// Offset Calibration
;equ DAC_CH0DATA_offset = 0x18		// Channel 0 Data
;equ DAC_CH1DATA_offset = 0x1A		// Channel 1 Data

;***************************************************************************
;** RTC - Real-Time Clounter
;***************************************************************************/
;equ RTC_CTRL_offset = 0x00		// Control Register
;equ RTC_STATUS_offset = 0x01		// Status Register
;equ RTC_INTCTRL_offset = 0x02		// Interrupt Control Register
;equ RTC_INTFLAGS_offset = 0x03		// Interrupt Flags
;equ RTC_TEMP_offset = 0x04		// Temporary register
;equ RTC_CNT_offset = 0x08		// Count Register
;equ RTC_PER_offset = 0x0A		// Period Register
;equ RTC_COMP_offset = 0x0C		// Compare Register

;***************************************************************************
;** EBI - External Bus Interface
;***************************************************************************/
;equ EBI_CS_CTRLA_offset = 0x00		// Chip Select Control Register A
;equ EBI_CS_CTRLB_offset = 0x01		// Chip Select Control Register B
;equ EBI_CS_BASEADDR_offset = 0x02		// Chip Select Base Address
;equ EBI_CTRL_offset = 0x00		// Control
;equ EBI_SDRAMCTRLA_offset = 0x01		// SDRAM Control Register A
;equ EBI_REFRESH_offset = 0x04		// SDRAM Refresh Period
;equ EBI_INITDLY_offset = 0x06		// SDRAM Initialization Delay
;equ EBI_SDRAMCTRLB_offset = 0x08		// SDRAM Control Register B
;equ EBI_SDRAMCTRLC_offset = 0x09		// SDRAM Control Register C
;equ EBI_CS0_offset = 0x10		// Chip Select 0
;equ EBI_CS1_offset = 0x14		// Chip Select 1
;equ EBI_CS2_offset = 0x18		// Chip Select 2
;equ EBI_CS3_offset = 0x1C		// Chip Select 3

;***************************************************************************
;** TWI - Two-Wire Interface
;***************************************************************************/
;equ TWI_MASTER_CTRLA_offset = 0x00		// Control Register A
;equ TWI_MASTER_CTRLB_offset = 0x01		// Control Register B
;equ TWI_MASTER_CTRLC_offset = 0x02		// Control Register C
;equ TWI_MASTER_STATUS_offset = 0x03		// Status Register
;equ TWI_MASTER_BAUD_offset = 0x04		// Baurd Rate Control Register
;equ TWI_MASTER_ADDR_offset = 0x05		// Address Register
;equ TWI_MASTER_DATA_offset = 0x06		// Data Register
;equ TWI_SLAVE_CTRLA_offset = 0x00		// Control Register A
;equ TWI_SLAVE_CTRLB_offset = 0x01		// Control Register B
;equ TWI_SLAVE_STATUS_offset = 0x02		// Status Register
;equ TWI_SLAVE_ADDR_offset = 0x03		// Address Register
;equ TWI_SLAVE_DATA_offset = 0x04		// Data Register
;equ TWI_SLAVE_ADDRMASK_offset = 0x05		// Address Mask Register
;equ TWI_CTRL_offset = 0x00		// TWI Common Control Register
;equ TWI_MASTER_offset = 0x0001		// TWI master module
;equ TWI_SLAVE_offset = 0x0008		// TWI slave module

;***************************************************************************
;** PORT - Port Configuration
;***************************************************************************/
;equ PORTCFG_MPCMASK_offset = 0x00		// Multi-pin Configuration Mask
;equ PORTCFG_VPCTRLA_offset = 0x02		// Virtual Port Control Register A
;equ PORTCFG_VPCTRLB_offset = 0x03		// Virtual Port Control Register B
;equ PORTCFG_CLKEVOUT_offset = 0x04		// Clock and Event Out Register
;equ VPORT_DIR_offset = 0x00		// I/O Port Data Direction
;equ VPORT_OUT_offset = 0x01		// I/O Port Output
;equ VPORT_IN_offset = 0x02		// I/O Port Input
.device ATmega328P
;equ VPORT_INTFLAGS_offset = 0x03		// Interrupt Flag Register
;equ PORT_DIR_offset = 0x00		// I/O Port Data Direction
;equ PORT_DIRSET_offset = 0x01		// I/O Port Data Direction Set
;equ PORT_DIRCLR_offset = 0x02		// I/O Port Data Direction Clear
;equ PORT_DIRTGL_offset = 0x03		// I/O Port Data Direction Toggle
;equ PORT_OUT_offset = 0x04		// I/O Port Output
;equ PORT_OUTSET_offset = 0x05		// I/O Port Output Set
;equ PORT_OUTCLR_offset = 0x06		// I/O Port Output Clear
;equ PORT_OUTTGL_offset = 0x07		// I/O Port Output Toggle
;equ PORT_IN_offset = 0x08		// I/O port Input
;equ PORT_INTCTRL_offset = 0x09		// Interrupt Control Register
;equ PORT_INT0MASK_offset = 0x0A		// Port Interrupt 0 Mask
;equ PORT_INT1MASK_offset = 0x0B		// Port Interrupt 1 Mask
;equ PORT_INTFLAGS_offset = 0x0C		// Interrupt Flag Register
;equ PORT_PIN0CTRL_offset = 0x10		// Pin 0 Control Register
;equ PORT_PIN1CTRL_offset = 0x11		// Pin 1 Control Register
;equ PORT_PIN2CTRL_offset = 0x12		// Pin 2 Control Register
;equ PORT_PIN3CTRL_offset = 0x13		// Pin 3 Control Register
;equ PORT_PIN4CTRL_offset = 0x14		// Pin 4 Control Register
;equ PORT_PIN5CTRL_offset = 0x15		// Pin 5 Control Register
;equ PORT_PIN6CTRL_offset = 0x16		// Pin 6 Control Register
;equ PORT_PIN7CTRL_offset = 0x17		// Pin 7 Control Register

;***************************************************************************
;** TC - 16-bit Timer/Counter With PWM
;***************************************************************************/
;equ TC0_CTRLA_offset = 0x00		// Control Register A
;equ TC0_CTRLB_offset = 0x01		// Control Register B
;equ TC0_CTRLC_offset = 0x02		// Control register C
;equ TC0_CTRLD_offset = 0x03		// Control Register D
;equ TC0_CTRLE_offset = 0x04		// Control Register E
;equ TC0_INTCTRLA_offset = 0x06		// Interrupt Control Register A
;equ TC0_INTCTRLB_offset = 0x07		// Interrupt Control Register B
;equ TC0_CTRLFCLR_offset = 0x08		// Control Register F Clear
;equ TC0_CTRLFSET_offset = 0x09		// Control Register F Set
;equ TC0_CTRLGCLR_offset = 0x0A		// Control Register G Clear
;equ TC0_CTRLGSET_offset = 0x0B		// Control Register G Set
;equ TC0_INTFLAGS_offset = 0x0C		// Interrupt Flag Register
;equ TC0_TEMP_offset = 0x0F		// Temporary Register For 16-bit Access
;equ TC0_CNT_offset = 0x20		// Count
;equ TC0_PER_offset = 0x26		// Period
;equ TC0_CCA_offset = 0x28		// Compare or Capture A
;equ TC0_CCB_offset = 0x2A		// Compare or Capture B
;equ TC0_CCC_offset = 0x2C		// Compare or Capture C
;equ TC0_CCD_offset = 0x2E		// Compare or Capture D
;equ TC0_PERBUF_offset = 0x36		// Period Buffer
;equ TC0_CCABUF_offset = 0x38		// Compare Or Capture A Buffer
;equ TC0_CCBBUF_offset = 0x3A		// Compare Or Capture B Buffer
;equ TC0_CCCBUF_offset = 0x3C		// Compare Or Capture C Buffer
;equ TC0_CCDBUF_offset = 0x3E		// Compare Or Capture D Buffer
;equ TC1_CTRLA_offset = 0x00		// Control  Register A
;equ TC1_CTRLB_offset = 0x01		// Control Register B
;equ TC1_CTRLC_offset = 0x02		// Control register C
;equ TC1_CTRLD_offset = 0x03		// Control Register D
;equ TC1_CTRLE_offset = 0x04		// Control Register E
;equ TC1_INTCTRLA_offset = 0x06		// Interrupt Control Register A
;equ TC1_INTCTRLB_offset = 0x07		// Interrupt Control Register B
;equ TC1_CTRLFCLR_offset = 0x08		// Control Register F Clear
;equ TC1_CTRLFSET_offset = 0x09		// Control Register F Set
;equ TC1_CTRLGCLR_offset = 0x0A		// Control Register G Clear
;equ TC1_CTRLGSET_offset = 0x0B		// Control Register G Set
;equ TC1_INTFLAGS_offset = 0x0C		// Interrupt Flag Register
;equ TC1_TEMP_offset = 0x0F		// Temporary Register For 16-bit Access
;equ TC1_CNT_offset = 0x20		// Count
;equ TC1_PER_offset = 0x26		// Period
;equ TC1_CCA_offset = 0x28		// Compare or Capture A
;equ TC1_CCB_offset = 0x2A		// Compare or Capture B
;equ TC1_PERBUF_offset = 0x36		// Period Buffer
;equ TC1_CCABUF_offset = 0x38		// Compare Or Capture A Buffer
;equ TC1_CCBBUF_offset = 0x3A		// Compare Or Capture B Buffer
;equ AWEX_CTRL_offset = 0x00		// Control Register
;equ AWEX_FDEMASK_offset = 0x02		// Fault Detection Event Mask
;equ AWEX_FDCTRL_offset = 0x03		// Fault Detection Control Register
;equ AWEX_STATUS_offset = 0x04		// Status Register
;equ AWEX_DTBOTH_offset = 0x06		// Dead Time Both Sides
;equ AWEX_DTBOTHBUF_offset = 0x07		// Dead Time Both Sides Buffer
;equ AWEX_DTLS_offset = 0x08		// Dead Time Low Side
;equ AWEX_DTHS_offset = 0x09		// Dead Time High Side
;equ AWEX_DTLSBUF_offset = 0x0A		// Dead Time Low Side Buffer
;equ AWEX_DTHSBUF_offset = 0x0B		// Dead Time High Side Buffer
;equ AWEX_OUTOVEN_offset = 0x0C		// Output Override Enable
;equ HIRES_CTRLA_offset = 0x00		// Control Register

;***************************************************************************
;** USART - Universal Asynchronous Receiver-Transmitter
;***************************************************************************/
;equ USART_DATA_offset = 0x00		// Data Register
;equ USART_STATUS_offset = 0x01		//

