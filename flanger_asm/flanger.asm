.include "ATxmega16A4def.inc"
.cseg
.org 0x100
.DSEG


.EQU N_LO = 0x2004
.EQU N_HI = 0x2005
.EQU XN_LO = 0x2008
.EQU XN_HI = 0x2009
.EQU ADC_RES_LO = 0x0210
.EQU ADC_RES_HI = 0x0211
.EQU ADC_FLAG = 0x0223
.EQU PORTC = 0x0648
.EQU POINT_JMP = 0x2000
.EQU SINPOS_LO = 0x2002
.EQU SINPOS_HI = 0x2003

.EQU SPL = 0x003D;
.EQU SPH = 0x003E;


dac_write:
		ldi r20,0x00		
		lds r21, DACB_STATUS
wait_dac:  sbrs r6,0
		jmp wait_dac
		lds R20,DACB_STATUS
		sts DACB_CH0DATA_LOW,r24
		sts DACB_CH0DATA_HIGH,r25
		ret
main:

stack_init: 
		ldi r20, HIGH(RAMEND)
		out sph, r20
		ldi r20, LOW(RAMEND)
		out SPL, r20

board_init:
	
;Configura el puerto C
		ldi 	r16,0x80
		sts	PORTC_DIR,r16 
		ldi 	r16,0x00
		sts	PORTC_sts,r16 
		sts	PORTC_PIN0CTRL,r16 ; 0x0650 = PORTC_PIN0CTRL
		sts	PORTC_PIN7CTRL,r16 ; 0x0657 = PORTC_PIN7CTRL
		sts  PORTC_INTCTRL,r16 ; 0x0649 = PORTC_INTCTRL
		sts	PORTC_INT0MASK,r16
		sts	PORTC_INT1MASK,r16	
		ldi 	r16,0x12
		sts	PORTC_PIN1CTRL,r16o
		ldi 	r16,0xFC
		sts	PORTCFG_MPCMASK,r16

;Configura el puerto B
		ldi	r16,0x0C
		sts	PORTB_DIR,r16	
		ldi	r16,0x00
		sts	PORTB_OUT,r16
		sts	PORTB_PIN0CTRL,r16
		sts	PORTB_PIN1CTRL,r16
		sts	PORTB_INTCTRL,r16
		sts	PORTB_INT0MASK,r16
		sts	PORTB_INT1MASK,r16
		ldi	r16,0x07
		sts	PORTB_PIN2CTRL,r16
		
adc_init:	
		ldi	r16,0x10
		sts	ADCA_CTRLB,r16 ;Modo con signo y 12 bit de resolución
		ldi	r16,0x04
		sts	ADCA_PRESCALER,r16 ;Se setea CLK_ADC = CLK_PER/64
		ldi	r16,0x10
		sts	ADCA_REFCTRL,r16 ;Seleccion de referencia a VCC/1.6 V
		ldi	r16,0x01
		sts	ADCA_CH0_CTRL,r16 ;Setea el Single Ended Input
		ldi	r16,0x00
		sts	ADCA_CMP,r16
		ldi	r16,0x38
		sts	ADCA_CH0_MUXCTRL,r16 ;Seteo el PIN7 como input del ADCA_CH0
		ldi	r16,0x02
		sts	ADCA_CH0_INTCTRL,r16 ;Seteo cuando avisa que termina la conversión
		ldi	r16,0x00
		sts	ADCA_CH1_INTCTRL,r16 
		sts	ADCA_CH2_INTCTRL,r16
		sts	ADCA_CH3_INTCTRL,r16	
		ldi	r16,0x01
		sts	PMIC_CTRL,r16 ;Habilito interrupciones de baja prioridad
		SEI ;Habilito interrupciones globales
		ldi	r16,0x18
		sts	ADCA_CTRLB,r16 ;Seteo el modo de ADC en free-running
		ldi	r16,0x01
		sts	ADCA_CTRLA,r16 ;Habilito el ADC
clk_init:
		ldi	r16,0x00
		sts	OSC_CTRL,r16 ;Deshabilito todas las fuentes de clock
		ldi	r16,0x04
		sts	OSC_CTRL,r16 ;Habilito RC32K oscilador
		
		lds	r16,OSC_STATUS
polling32K:
		sbrs	r16,0 ;Espero a que estabilice
		rjmp	polling32K
		ldi	r16,0x06 
		sts	OSC_CTRL,r16 ;Habilito RC32M oscilador
		ldi	r16,0xD8
		sts	CCP,r16 ;Deshabilita IOs protegidos para actualizar la configuración
		ldi	r16,0x00
		sts	CLK_PSCTRL,r16	;Se setea el prescaler del clock en DIV1
		sts	OSC_DFLLCTRL,r16 ;Calibro el RC32M con el RC32K
		ldi	r16,0x01
		sts	DFLLRC32M_CTRL,r16 ;Habilito la auto-calibración

		lds	r16,OSC_STATUS
polling32M:
		sbrs	r16,1 ;Espero a que estabilice el RC32M
		rjmp polling32M
		ldi	r16,0xD8
		sts	CCP,r16 ;Deshabilita IOs protegidos para actualizar la configuración
		ldi	r16,0x01
		sts	CLK_CTRL,r16 ;Selecciona el clock source al RC32M
		ldi	r16,0x02
		sts	OSC_CTRL,r16 ;Deshabilita todos las otras clock sources
	
dac_init:
		ldi	r16,0x09
		sts	DACB_CTRLA,r16
		ldi	r16,0x00
		sts	DACB_CTRLB,r16
		ldi	r16,0x04
		sts	DACB_CTRLC,r16
		ret


		ldi	r28, 0x01	
		ldi	r29, 0x01	
WAIT_ADC:	lds	r24, ADC_FLAG	; flag de conversión lista
		sbrs	r24, 0	
		jmp	WAIT_ADC	
		sts	ADC_FLAG, r28	; poner en cero el flag de conversión
		lds	r24, ADC_RES_LO	; leer valor del ADC
		lds	r25, ADC_RES_HI	; leer valor del ADC
		sts	XN_LO, r24	; muestra x[n]
		sts	XN_HI, r25	; muestra x[n]
		lds	r18, N_LO	; traer valor de n
		lds	r19, N_HI	; traer valor de n
		movw	r30, r18	; cálculo de la posición de memoria
		add	r30, r30	; cálculo de la posición de memoria
		adc	r31, r31	; cálculo de la posición de memoria
		subi	r30, 0xF6	; cálculo de la posición de memoria
		sbci	r31, 0xDF	; cálculo de la posición de memoria
		st	Z, r24		; almacenar x[n] en la memoria
		std	Z+1, r25	; almacenar x[n] en la memoria
		lds	r20, PORTC	; lectura del portC
		sbrs	r20, 1	; chequeo si se presionó el botón de cambiar frecuencia
		jmp	RST_FREC	
		lds	r20, POINT_JMP	
		subi	r20, 0xFF	
		sts	POINT_JMP, r20	
RST_FREC:	lds	r20, POINT_JMP	; chequea que la frecuencia no supere el maximo de 10 para que no se exceda la memoria
		cpi	R20, 10	
;MEMORIA RAM!		brcs	REDAY_FREC
		sts	POINT_JMP, r29	
READY_FREC:	lds	r20, SINPOS_LO	; leo posición de la tabla
		lds	r21, SINPOS_HI	; leo posición de la tabla
		mov	r30, r21	
		eor	r31, r31	
		add	r30, r30	; cálculo de posición de la tabla
		adc	r31, r31	
		subi	r30, 0x88	
		sbci	r31, 0xFE	
		lpm	r30, Z		; lectura de nb de la tabla de valores
		ldi	r31, 0x00	
		sts	0x2006, r30	
		sts	0x2007, r31	
		lds	r22, 0x2000	
		add	r20, r22	
		adc	r21, r1	; acc+=saltear
		sts	SINPOS_LO, r20	; guardo posición de la tabla en memoria SRAM
		sts	SINPOS_HI, r21	; guardo posición de la tabla en memoria SRAM
		sub	r18, r30	; resolvemos nb_posta= n-nb
		sbc	r19, r31	; resolvemos nb_posta= n-nb
		cpi	R18, 0xE9	; cargo 1001 en R20|R18
		ldi	R20, 0x03	; cargo 1001 en R20|R18
		cpc	r19, r20	; verifico si desbordé la memoria
; VERIFICACIÓN DE MEMORIA		;brcs	SALTAR_MEM	; verifico si desbordé la memoria
		subi	r18, 0x18	; le sumamos para no salir de la memoria circular
		sbci	r19, 0xFC	; le sumamos para no salir de la memoria circular
SALTAR_MEM:	sts	0x27DA, r18	; almacenamos nb_posta en memoria
		sts	0x27DB, r19	; almacenamos nb_posta en memoria
		lds	r18, 0x0648	; leemos estado de on/off del efecto
		sbrs	r18, 0	; confirmamos que esté o no activado
		rjmp	FX_OFF	; 0x13ce <main+0xcc>
		lds	r30, 0x27DA	; cargo Z con la dirección de x[n-nb]
		lds	r31, 0x27DB	; cargo Z con la dirección de x[n-nb]
		add	r30, r30	
		adc	r31, r31	
		subi	r30, 0xF6	
		sbci	r31, 0xDF	
		ld	r18, Z	; traigo el valor de x[n-nb] de memoria
		ldd	r19, Z+1	; traigo el valor de x[n-nb] de memoria
		add	r24, r18	; lo sumo con la muestra actual
		adc	r25, r19	; lo sumo con la muestra actual
FX_OFF:	call	dac_write	; lo sacamos por el DAC
		lds	r24, N_LO	
		lds	r25, N_HI	
		adiw	r24, 0x01	; incrementamos valor de n
		sts	N_LO, r24	; almacenamos n 
		sts	N_HI, r25	; almacenamos n 
		cpi	r24, 0xE8	; verifico si desbordé la memoria
		sbci	r25, 0x03	; verifico si desbordé la memoria
		ldi	r25, 0x84	;brcc	RST_MEM	; verifico si desbordé la memoria
		jmp	WAIT_ADC	
RST_MEM:	sts	N_LO, r1	; reiniciar posición de memoria cíclica
		sts	N_HI, r1	; reiniciar posición de memoria cíclica
		jmp	WAIT_ADC	


