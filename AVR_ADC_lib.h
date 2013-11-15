/*
 * AVR_ADC_lib.h
 *
 *  Created on: 15 nov. 2013
 *      Author: A127590
 */

#ifndef AVR_ADC_LIB_H_
#define AVR_ADC_LIB_H_



#include <avr/io.h>



//	24.9.1 ADMUX – ADC Multiplexer Selection Register
//
//	 Bit 7:6 – REFS[1:0]: Reference Selection Bits
//	These bits select the voltage reference for the ADC, as shown in  Table 24-3 . If these bits are changed during a
//	conversion, the change will not go in effect until this conversion is complete  (ADIF in ADCSRA is set). The internal
//	voltage reference options may not be used if an external reference voltage is being applied to the AREF pin.
//
//	Table 24-3. Voltage Reference Selections for ADC
//		REFS1 REFS0 Voltage Reference Selection
//		0     0     AREF, Internal Vref turned off
//		0     1     AVCC with external capacitor at AREF pin
//		1     0     Reserved
//		1     1     Internal 1.1V Voltage Reference with external capacitor at AREF pin
typedef enum
{
	AREF = 0,		/*<! 0 		0 		AREF, Internal V ref turned off										*/
	AVCC = 1,		/*<! 0		1		AVCC with external capacitor at AREF pin							*/
	Reserved = 2,	/*<! 1		0		Reserved															*/
	Int_1_1V = 3,	/*<! 1		1		Internal 1.1V Voltage Reference with external capacitor at AREF pin	*/
} eVotltageReference_t;



/*	24.9.2 ADCSRA – ADC Control and Status Register A
 *
 *  Bits 2:0 – ADPS[2:0]: ADC Prescaler Select Bits
 *	These bits determine the division factor between the system clock frequency and the input clock to the ADC.
 *	Table 24-5. ADC Prescaler Selections
 *
 *	ADPS2 ADPS1 ADPS0 Division Factor
 *	0     0     0     2
 *	0     0     1     2
 *	0     1     0     4
 *	0     1     1     8
 *	1     0     0     16
 *	1     0     1     32
 *	1     1     0     64
 *	1     1     1     128 */
typedef enum
{
	FCPU_2 		= 1,		/*<! F_CPU/2	*/
	FCPU_4 		= 2,		/*<! F_CPU/4	*/
	FCPU_8 		= 3,		/*<! F_CPU/8	*/
	FCPU_16 	= 4,		/*<! F_CPU/16	*/
	FCPU_32 	= 5,		/*<! F_CPU/32	*/
	FCPU_64		= 6,		/*<! F_CPU/64	*/
	FCPU_128	= 7,		/*<! F_CPU/128	*/
} ePrescaler_t ;


/*! \brief
 *  \details
 *  \param [in] uint16_t
 *  \return Nothing.
 */
void ADC_SelectVoltageReference( eVotltageReference_t ) ;



/*! \brief
 *  \details
 *  \param [in] uint16_t
 *  \return Nothing.
 */
void ADC_SelectChannel( char ) ;



/*! \brief
 *  \details
 *  \param [in] uint16_t
 *  \return Nothing.
 */
void ADC_SelectPrescaler( ePrescaler_t ) ;



/*! \brief
 *  \details
 *  \param [in] uint16_t
 *  \return Nothing.
 */
void ADC_Enable( ) ;



/*! \brief
 *  \details
 *  \param [in] uint16_t
 *  \return Nothing.
 */
void ADC_Disable( ) ;



/*! \brief
 *  \details
 *  \param [in] uint16_t
 *  \return Nothing.
 */
uint16_t ADC_Read( ) ;



#undef PDEBUG_INIT
#undef PDEBUG



#ifdef DEBUG
	#define PDEBUG_INIT( BR ) USART_Init( BR )
	// no need of a terminal \n. put by default
	#define PDEBUG( msg ) printf( msg )
#else /* DEBUG */
	#define PDEBUG_INIT( BR ) /* not debugging: nothing */
	#define PDEBUG( msg ) /* not debugging: nothing */
#endif /* DEBUG */



#endif /* AVR_ADC_LIB_H_ */
