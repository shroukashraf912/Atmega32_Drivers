#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "TIMER_interface.h"
#include "TIMER_private.h"
#include "TIMER_configure.h"

static void (*G_TIM0_CALLBACK[2]) (void) = {NULL, NULL}; // Initialize to NULL
static u32  G_u32IntervalCount;

void MTIMERS_voidInit (u16 A_u16Timer_ID)
{
	switch (A_u16Timer_ID)
	{
		case Timer_0:
			/*************************** Timer 0 ***************************/
			/* step1: choose clk mode */
			#if   W_Form_Generation_Mode == Normal
				CLR_BIT(TCCR0, WGM01);
				CLR_BIT(TCCR0, WGM00);
			#elif W_Form_Generation_Mode == PWM
				CLR_BIT(TCCR0, WGM01);
				SET_BIT(TCCR0, WGM00);
			#elif W_Form_Generation_Mode == CTC
				SET_BIT(TCCR0, WGM01);
				CLR_BIT(TCCR0, WGM00);
			#elif W_Form_Generation_Mode == Fast_PWM
				SET_BIT(TCCR0, WGM01);
				SET_BIT(TCCR0, WGM00);
			#endif

			/* step2: select prescaler */
			#if Prescaler_Select == Prescaler_8
				CLR_BIT(TCCR0, CS02);
				SET_BIT(TCCR0, CS01);
				CLR_BIT(TCCR0, CS00);
			#elif Prescaler_Select == Prescaler_64
				CLR_BIT(TCCR0, CS02);
				SET_BIT(TCCR0, CS01);
				SET_BIT(TCCR0, CS00);
			#elif Prescaler_Select == Prescaler_256
				SET_BIT(TCCR0, CS02);
				CLR_BIT(TCCR0, CS01);
				CLR_BIT(TCCR0, CS00);
			#elif Prescaler_Select == Prescaler_1024
				SET_BIT(TCCR0, CS02);
				CLR_BIT(TCCR0, CS01);
				SET_BIT(TCCR0, CS00);
			#endif

			/* step3: Compare_Match_Mode */
			#if Compare_Match_Mode == CTC
				#if   OC0_PIN == Disconnected
					CLR_BIT(TCCR0, COM01);
					CLR_BIT(TCCR0, COM00);
				#elif OC0_PIN == TOGGLE
					CLR_BIT(TCCR0, COM01);
					SET_BIT(TCCR0, COM00);
				#elif OC0_PIN == CLEAR
					SET_BIT(TCCR0, COM01);
					CLR_BIT(TCCR0, COM00);
				#elif OC0_PIN == SET
					SET_BIT(TCCR0, COM01);
					SET_BIT(TCCR0, COM00);
				#endif
			#elif Compare_Match_Mode == Fast_PWM
				#if   OC0_PIN == Disconnected
					CLR_BIT(TCCR0, COM01);
					CLR_BIT(TCCR0, COM00);
				#elif OC0_PIN == CLR_COM_SET_TOP
					SET_BIT(TCCR0, COM01);
					CLR_BIT(TCCR0, COM00);
				#elif OC0_PIN == SET_COM_CLR_TOP
					SET_BIT(TCCR0, COM01);
					SET_BIT(TCCR0, COM00);
				#endif
			#elif Compare_Match_Mode == PWM
				#if   OC0_PIN == Disconnected
					CLR_BIT(TCCR0, COM01);
					CLR_BIT(TCCR0, COM00);
				#elif OC0_PIN == CLR_UP_SET_DOWN
					SET_BIT(TCCR0, COM01);
					CLR_BIT(TCCR0, COM00);
				#elif OC0_PIN == SET_UP_CLR_DOWN
					SET_BIT(TCCR0, COM01);
					SET_BIT(TCCR0, COM00);
				#endif
			#endif

			/* step4: Enable interrupt of OVF OR CTC */
			#if Timer_Interrupt == ENABLE
				#if Interrupt_Enable == CTC_Interrupt
					SET_BIT(TIMSK, OCIE0);
				#else
					SET_BIT(TIMSK, TOIE0);
				#endif
			#else
				CLR_BIT(TIMSK, OCIE0);
				CLR_BIT(TIMSK, TOIE0);
			#endif
			/***************************************************************/
		break;

		case Timer_1:
			/*************************** Timer 1 ***************************/
			// Timer 1 initialization (if needed)
			/***************************************************************/
		break;

		case Timer_2:
			/*************************** Timer 2 ***************************/
			// Timer 2 initialization (if needed)
			/***************************************************************/
		break;
	}
}

void MTIMERS_voidSetPreloadValue(u16 A_u16Timer_ID, u16 A_u16Preload)
{
	switch (A_u16Timer_ID)
	{
		case Timer_0:
			TCNT0 = A_u16Preload;
		break;
	}
}

void MTIMERS_voidSetCompareValue(u16 A_u16Timer_ID, u16 A_u16CompareValue)
{
	switch (A_u16Timer_ID)
	{
		case Timer_0:
			OCR0 = A_u16CompareValue;
		break;
	}
}

void MTIMERS_vSetInterval_CTC_Asynch(u16 A_u16Timer_ID, u16 A_u16IntervalCounts, u16 A_u16CompareValue, void (*A_fptr)(void))
{
	switch (A_u16Timer_ID)
	{
		case Timer_0:
			G_u32IntervalCount = A_u16IntervalCounts;
			G_TIM0_CALLBACK[TIM_CB_CTC] = A_fptr;
			MTIMERS_voidSetCompareValue(A_u16Timer_ID, A_u16CompareValue);
			MTIMERS_voidStartTimer(A_u16Timer_ID);
		break;
	}
}

void MTIMERS_voidSetInterval_Asynch(u16 A_u16Timer_ID, u16 A_u16IntervalCounts, void (*A_fptr)(void))
{
	switch (A_u16Timer_ID)
	{
		case Timer_0:
			G_u32IntervalCount = A_u16IntervalCounts;
			G_TIM0_CALLBACK[TIM_CB_OVF] = A_fptr;
			MTIMERS_voidStartTimer(A_u16Timer_ID);
		break;
	}
}

void MTIMERS_voidStartTimer(u16 A_u16Timer_ID)
{
	// Start timer by setting the prescaler bits
	switch (A_u16Timer_ID)
	{
		case Timer_0:
			TCCR0 = (TCCR0 & Bit_Mask_Of_Timer) | (Start_Timer);
		break;
	}
}

void MTIMERS_voidStopTimer(u16 A_u16Timer_ID)
{
	switch (A_u16Timer_ID)
	{
		case Timer_0:
			TCCR0 = (TCCR0 & Bit_Mask_Of_Timer) | (Stop_Timer);
		break;
	}
}

void MTIMERS_voidDelay_ms(u16 A_u16Delay_ms)
{
	// Set the Timer0 preload value
	MTIMERS_voidSetPreloadValue(Timer_0, 131);  // Preload value calculated

	// Start the Timer with a prescaler of 64
	MTIMERS_voidStartTimer(Timer_0);

	// Loop for the desired number of milliseconds
	for (u16 i = 0; i < A_u16Delay_ms; i++)
	{
		// Wait for the overflow flag to be set
		while ((TIFR & (1 << TOV0)) == 0);

		// Clear the overflow flag
		TIFR |= (1 << TOV0);

		// Reset the preload value
		MTIMERS_voidSetPreloadValue(Timer_0, 131);
	}

	// Stop the Timer
	MTIMERS_voidStopTimer(Timer_0);
}


void MTIMERS_voidDelay_us(u32 A_u32Delay_us)
{
    // Set Timer 0 to Normal mode
    TCCR0 = 0; // Clear the TCCR0 register

    // Use no prescaler for maximum resolution
    TCCR0 |= (1 << CS00); // Prescaler = 1

    // Each tick = 1 / 8,000,000 seconds = 0.125 microseconds

    u32 ticks_required = (A_u32Delay_us * 8) / 1; // Calculate number of ticks

    while (ticks_required > 255)
    {
        // Wait for timer overflow
        while (!(TIFR & (1 << TOV0)));

        // Clear the overflow flag
        TIFR |= (1 << TOV0);

        ticks_required -= 255; // Decrease the tick count by 255
    }

    // For the remaining ticks
    TCNT0 = 255 - ticks_required;

    // Wait for the final overflow
    while (!(TIFR & (1 << TOV0)));

    // Clear the overflow flag
    TIFR |= (1 << TOV0);

    // Stop the timer by clearing the clock source
    TCCR0 = 0;
}


/* Timer 0 overflow ISR */
void __vector_11(void) __attribute__((signal));
void __vector_11(void)
{
	static u32 LS_u32Counter = 0;
	LS_u32Counter++;

	if (LS_u32Counter == G_u32IntervalCount)
	{
		if (G_TIM0_CALLBACK[TIM_CB_OVF] != NULL)
		{
			G_TIM0_CALLBACK[TIM_CB_OVF]();
			LS_u32Counter = 0;
		}
	}
}

/* Timer 0 CTC ISR */
void __vector_10(void) __attribute__((signal));
void __vector_10(void)
{
	static u32 LS_u32Counter = 0;
	LS_u32Counter++;

	if (LS_u32Counter == G_u32IntervalCount)
	{
		if (G_TIM0_CALLBACK[TIM_CB_CTC] != NULL)
		{
			G_TIM0_CALLBACK[TIM_CB_CTC]();
			LS_u32Counter = 0;
		}
	}
}
