/*
 * AVR_ADC_lib.c
 *
 *  Created on: 15 nov. 2013
 *      Author: A127590
 */



#include "AVR_ADC_lib.h"



void ADC_SelectVoltageReference( eVotltageReference_t eVotltageReference )
{
	// Select the voltage reference
	ADMUX = (ADMUX & 0x3F) & ( (eVotltageReference & 0x03)<<REFS0 ) ;
}



void ADC_SelectChannel( char cChannel )
{
	ADMUX = (ADMUX & 0xF0) & (cChannel & 0x0F) ;
}



void ADC_SelectPrescaler( ePrescaler_t ePrescaler )
{
	ADCSRA = (ADCSRA & 0xF8) & (ePrescaler & 0x07) ;
}



void ADC_Enable( )
{
	// Clear the ADC Power Reduction bit
	PRR &= ~(1 << PRADC) ;
	// Enable the ADC
	ADCSRA |= (1 << ADEN) ;
}



void ADC_Disable( )
{
	// Set the ADC Power Reduction bit
	PRR |= (1 << PRADC) ;
	// Disable the ADC
	ADCSRA &= ~(1 << ADEN) ;
}



void ADC_Start( )
{
	// Start the Conversion
	ADCSRA |= (1 << ADSC) ;
}



uint16_t ADC_Read( )
{
	// Read the ADC value
	uint16_t uiADCvalue = ADCL ;
	uiADCvalue |= (ADCH<<8) ;

	return uiADCvalue ;
}
