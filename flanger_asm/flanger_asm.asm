.include "ATxmega16A4def.inc"
.include "macros.inc"

.CSEG
.ORG 0x00
reset_d:			jmp	main_d

.CSEG
.ORG 0x100
main_d: ;Aca empieza nuestro codigo

; stack_pointer_init
				ldi 	r24, LOW(RAMEND)
				out 	CPU_SPL, r24
				ldi 	r24, HIGH(RAMEND)
				out		CPU_SPH, r24
;board_init
				ldi	r24,0x80
				sts	PORTC_DIR,r24 
				ldi	r24,0x00
				sts	PORTC_OUT,r24 
				sts	PORTC_PIN0CTRL,r24  
				sts	PORTC_PIN7CTRL,r24 
				sts 	PORTC_INTCTRL,r24 
				sts	PORTC_INT0MASK,r24
				sts	PORTC_INT1MASK,r24	
				ldi 	r24,0x12
				sts	PORTC_PIN1CTRL,r24
				ldi 	r24,0xFC
				sts	PORTCFG_MPCMASK,r24
; Configuracion del puerto B
				ldi	r24,0x0C
				sts	PORTB_DIR,r24	
				ldi	r24,0x00
				sts	PORTB_OUT,r24
				sts	PORTB_PIN0CTRL,r24
				sts	PORTB_PIN1CTRL,r24
				sts	PORTB_INTCTRL,r24
				sts	PORTB_INT0MASK,r24
				sts	PORTB_INT1MASK,r24
				ldi	r24,0x07
				sts	PORTB_PIN2CTRL,r24
; adc_init			
				ldi	r24,0x10
				sts	ADCA_CTRLB,r24 ;Modo con signo y 12 bit de resolución
				ldi	r24,0x04
				sts	ADCA_PRESCALER,r24 ;Se setea CLK_ADC = CLK_PER/64
				ldi	r24,0x10
				sts	ADCA_REFCTRL,r24 ;Seleccion de referencia a VCC/1.6 V
				ldi	r24,0x01
				sts	ADCA_CH0_CTRL,r24 ;Setea el Single Ended Input
				ldi	r24,0x00
				sts	ADCA_CMP,r24
				ldi	r24,0x38
				sts	ADCA_CH0_MUXCTRL,r24 ;Seteo el PIN7 como input del ADCA_CH0
				ldi	r24,0x02
				sts	ADCA_CH0_INTCTRL,r24 ;Seteo cuando avisa que termina la conversión
				ldi	r24,0x00
				sts	ADCA_CH1_INTCTRL,r24 
				sts	ADCA_CH2_INTCTRL,r24
				sts	ADCA_CH3_INTCTRL,r24	
				ldi	r24,0x01
				sts	PMIC_CTRL,r24 ;Habilito interrupciones de baja prioridad
				SEI	;Habilito interrupciones globales
				ldi	r24,0x18
				sts	ADCA_CTRLB,r24 ;Seteo el modo de ADC en free-running
				ldi	r24,0x01
				sts	ADCA_CTRLA,r24 ;Habilito el ADC
; clk_init
				ldi	r24,0x00
				sts	OSC_CTRL,r24 ;Deshabilito todas las fuentes de clock
				ldi	r24,0x04
				sts	OSC_CTRL,r24 ;Habilito RC32K oscilador
polling32K:			
				lds	r24,OSC_STATUS
				sbrs 	r24,0 ;Espero a que estabilice
				jmp 	polling32K
				ldi	r24,0x06 
				sts	OSC_CTRL,r24 ;Habilito RC32M oscilador
				ldi	r24,0xD8
				sts	CPU_CCP,r24 ;Deshabilita IOs protegidos para actualizar la configuración
				ldi	r24,0x00
				sts	CLK_PSCTRL,r24	;Se setea el prescaler del clock en DIV1
				sts	OSC_DFLLCTRL,r24 ;Calibro el RC32M con el RC32K
				ldi	r24,0x01
				sts	DFLLRC32M_CTRL,r24 ;Habilito la auto-calibración
polling32M:	
				lds	r24,OSC_STATUS
				sbrs 	r24,1 ;Espero a que estabilice el RC32M
				jmp 	polling32M
				ldi	r24,0xD8
				sts	CPU_CCP,r24 ;Deshabilita IOs protegidos para actualizar la configuración
				ldi	r24,0x01
				sts	CLK_CTRL,r24 ;Selecciona el clock source al RC32M
				ldi	r24,0x02
				sts	OSC_CTRL,r24 ;Deshabilita todos las otras clock sources
;dac_init		
				ldi	r24,0x09
				sts	DACB_CTRLA,r24
				ldi	r24,0x00
				sts	DACB_CTRLB,r24
				ldi	r24,0x04
				sts	DACB_CTRLC,r24
		
		; inicializacion de nuestras cosas
				ldi	XL, LOW(MEMORIA); inicializo el puntero que recorrera la memoria
				ldi	XH, HIGH(MEMORIA); inicializo el puntero que recorrera la memoria
				clr	chek_cont_lo; inicializo el contador del antirrebote
				clr	chek_cont_hi; inicializo el contador del antirrebote
				clr	n_lo;
				clr	n_hi;
				
WHILE_1:
				;Lectura del ADC por polling;	
	WAIT_ADC:	lds	gpv1,ADCA_INTFLAGS; traigo banderas de «conversion_lista» del ADC
				sbrs 	gpv1,0; El bit 0 corresponde al canal 0
				jmp 	WAIT_ADC
				cbr	gpv1,0; Limpio el bit correspondiente al canal 0, los demas no los toco
				sts	ADCA_INTFLAGS,gpv1; limpio el flag de conversión completada del canal 0
				
				lds	xn_lo,ADCA_CH0RES; leo el low byte del resultado del ADC (1 Word)
				lds xn_hi,ADCA_CH0RES+1; leo el high byte del resultado del ADC (1 Word)
				
				st 	X+,xn_lo; Guardo el low byte en el espacio de memoria que tiene asignado X e incremento en 1
				st 	X+,xn_hi; Guardo el high byte en el espacio de memoria siguiente al anterior e incremento
				
				cpi	XH,HIGH(MEMORIA+MEM_LENGTH*2)
				brcc	RESET_X; if XH>HIGH(MEMORIA+MEM_LENGT*2) then RESET_X else
				cpi	XL,LOW(MEMORIA+MEM_LENGTH*2)
				brcc	NO_RESET_X; if XL<LOW(MEMORIA+MEM_LENGT*2) then NO_RESET_X endif
	RESET_X:	ldi	XL, LOW(MEMORIA); reiniciamos el puntero
				ldi	XH, HIGH(MEMORIA); reiniciamos el puntero
				
				;Calculo la posicion de memoria que se guardo para luego aplicar el filtro
				ldi gpv1,HIGH(MEMORIA)
				mov aux0,gpv1
				ldi gpv1,LOW(MEMORIA)
				mov aux1,gpv1
				mov aux2,XL
				mov aux3,XH
				sub aux2,aux1
				sbc aux3,aux0
				mov n_lo,aux2
				mov n_hi,aux3
			
				
		NO_RESET_X:	
				
		; chek inputs routine english labels rules!
				inc	chek_cont_lo
				mov	gpv1,chek_cont_lo
				cpi	gpv1,0xFF 
				brcs	READY_CONT
				clr	chek_cont_lo; if chek_cont_lo==0xFF then hago esto
				inc	chek_cont_hi; if chek_cont_lo==0xFF then hago esto
		READY_CONT:	
				sts	PORTC_IN, gpv1; traigo el estado de los pines //¡Me parece que aca tenes que hacer OUT en vez de IN!
				or	reg_pins,gpv1; guardo el estado de los pines sin pisar los estados anteriores
				
				mov	gpv1,chek_cont_hi
				cpi	gpv1, (1<<(MAX_CONT_CHEK_PINS-7)); me fijo si se alcanzo la cuenta maxima
				brcc	SHOW_MUST_GO_ON
			; Aca se colocan las cosas para hacer con los pulsadores externos
				; Aca se colocan las cosas para hacer con los pulsadores externos
				sbrc	reg_pins,PIN_FRECUENCIA
				jmp	FRECUENCIA_LISTA
				inc	saltear
				mov	gpv1,saltear
				cpi	gpv1,MAX_SALTEAR
				brcc	FRECUENCIA_LISTA;
				ldi	gpv1, 1; reiniciamos el salteador
				mov	saltear,gpv1; reiniciamos el salteador
			FRECUENCIA_LISTA:
				
				clr	chek_cont_hi; reiniciar el contador
				clr	chek_cont_lo; reiniciar el contador
				clr	reg_pins; borrar el registro de los pines apretados para empezar a registrar de nuevo
			
SHOW_MUST_GO_ON:			
LECTURA_ROM:	ldi gpv1,0x00 ;inicio el contador
				
				
shift: 			ror acc_lo ;shifteo hacia la derecha a traves del carry el low byte de acc
				bst acc_hi,0 ;guardo el bit LSB del high byte de acc en SREG_T
				ror acc_hi ;shifteo hacia la derecha a traves del carry el high byte, ingresa el carry al MSB del high byte y el LSB del high byte va hacia el carry
				bld acc_lo,7 ;guardo en el MSB del low byte lo guardado en SREG_T 
				inc gpv1 ;incremento el contador
				cpi gpv1,9 ;comparo si es igual a 9 el contador
				brne shift ;si no es igual sigo con el codigo
				
				clc ;limpio el carry
				add ZL,acc_lo ;incremento ZL + acc_lo
				adc ZH,acc_hi ;incremento ZH + acc_high + acc. 
				;Finalmente incremente la posicion de memoria de Z
				
				cpi ZH,HIGH(TABLA+TAB_LENGTH/2) ;comparo si el high byte es igual al maximo 
				brlo NO_RESET_Z ;si ZH < HIGH(TABLA+LENGTH_TABLA/2) entonces brancheo, sino puede que sea ZH sea mayor o igual
				brne RESET_Z ;si ZH = HIGH(TABLA+LENGTH_TABLA/2+1), sigo y me fijo el low byte
				cpi ZL,LOW(TABLA+TAB_LENGTH/2+1) ;comparo el low byte con el maximo mas 1
				brlo NO_RESET_Z ;si es menor, brancheo y no reseteo. Sino, se resetea
RESET_Z:		ldi ZH,HIGH(TABLA)
				ldi ZL,LOW(TABLA)
				
NO_RESET_Z:		lpm nb,Z ;asigno a nb el valor de la tabla correspondiente
				
				add acc_lo,saltear ;acc_lo=+saltear (saltear es de 8 bits)
				ldi gpv1,0x00
				adc acc_hi,gpv1 ;acc_high+=carry	

				
				;calculo de la muestra a obtener
				mov gpv2,n_lo
				mov gpv3,n_hi
				sub gpv2,nb
				sbc gpv3,gpv1

				mov nb_posta_lo,gpv2
				mov nb_posta_hi,gpv3

				;esto es el if(nb_posta > MEM_LENGTH)

				subi gpv3,HIGH(MEM_LENGTH)
				brlo no_correccion
				cpi	 gpv3,HIGH(MEM_LENGTH)
				brne correccion
				subi gpv2,LOW(MEM_LENGTH)
				brlo no_correccion

correccion:		ldi	gpv2,LOW(MEM_LENGTH)
				ldi gpv3,HIGH(MEM_LENGTH)
				add nb_posta_lo,gpv2
				adc nb_posta_hi,gpv3

				;Encendido o apagado del efecto
no_correccion:	lds gpv1,PORTC_IN ;muevo lo que hay en PORTC_IN a gpv1  /*Me tirra error de Invalid Register*/
				andi gpv1,ONOFF ;hago and entre la macro y gpv1
				cpi gpv1,0 ;si da cero salteo a dac_write(xn)
				breq EFFECT_OFF
				;si no dio cero sigo a dac_write(xn+xnb_posta)
				ld aux0,-X ;guardo el low byte de xn en aux0
				ld aux0,X+ ;aumento la direccion en 1
				ld aux1,X ;guardo el high byte en aux1

				ldi YL,LOW(MEMORIA) ;utilizo el puntero Y como puntero auxiliar para buscar la muestra nb_posta
				ldi YH,HIGH(MEMORIA) 
				add YL,nb_posta_lo  ;voy hasta esa muestra
				adc YH,nb_posta_hi

				ld  gpv1,Y ;cargo la muestra en Y (puede ser un high byte o low byte)
				andi gpv1,0xF0 ;hago aux2 & 11110000
				cpi gpv1,0x00 ;si aux2 = 0x00, es que la posicion de memoria que llego Y es un high byte
				brne low_byte ;si no es igual estoy para en un low_byte
				ld aux2,-Y ;decremento hacia el low byte de la muestra, y asigno
				ld aux2,Y+ ;incremento Y para ir a buscar el high byte
				ld aux3,Y ;agarro el high byte
				jmp salto

low_byte:			ld aux2,Y+  
				ld aux3,Y
				
salto:			;aca hago x[n]+x[nb_posta]
				add aux0,aux2
				adc	aux1,aux3
				;en aux0 y aux1 esta el resultado

				jmp dac_write

EFFECT_OFF:		ld aux0,-X
				ld aux0,X+
				ld aux1,X

dac_write:		ldi  gpv1,0x00		
				lds  gpv2, DACB_STATUS
	wait_dac: 	sbrs gpv2,0
				jmp	 wait_dac
				sts  DACB_STATUS,gpv1
				
				sts  DACB_CH0DATA,aux0
				sts  DACB_CH0DATA+1,aux1
END:				


		




								
