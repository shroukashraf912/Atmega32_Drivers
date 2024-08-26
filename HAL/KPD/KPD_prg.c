#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "../../MCAL/DIO/DIO_interface.h"
#include "../../MCAL/TIMER/TIMER_interface.h"
#include "KPD_int.h"
#include "KYD_cfg.h"

// Keypad layout mapping
//static const u8 global_Au8_SwitchVal[4][4] = {
//    { '1', '2', '3', 'A' },
//    { '4', '5', '6', 'B' },
//    { '7', '8', '9', 'C' },
//    { '*', '0', '#', 'D' }
//};

static const u8 global_Au8_SwitchVal[4][4] = {
    { '7', '8', '9', '/' },
    { '4', '5', '6', '*' },
    { '1', '2', '3', '-' },
    { 'C', '0', '=', '+' }
};


void HKPD_vInit(void)
{
    // Initialize columns as output and set them high
    for (u8 local_u8_PinID = COL_START; local_u8_PinID <= COL_END; local_u8_PinID++) {
        MDIO_vWrtPinDir(KPD_PORT, local_u8_PinID, DIO_PIN_OUTPUT);
        MDIO_vWrtPinVal(KPD_PORT, local_u8_PinID, DIO_HIGH);
    }

    // Initialize rows as input and enable internal pull-up resistors
    for (u8 local_u8_PinID = ROW_START; local_u8_PinID <= ROW_END; local_u8_PinID++) {
        MDIO_vWrtPinDir(KPD_PORT, local_u8_PinID, DIO_PIN_INPUT);
        MDIO_vEnableInternalPullUp(KPD_PORT, local_u8_PinID, DIO_HIGH);
    }
}

u8 HKPD_u8GetPressedKey(void)
{
    u8 local_u8_Column, local_u8_Row, local_u8_PinVal;
    u8 local_u8_PressedKey = KPD_NOT_PRESSED;

    // Loop through each column
    for (local_u8_Column = COL_START; local_u8_Column <= COL_END; local_u8_Column++) {
        // Activate the current column
        MDIO_vWrtPinVal(KPD_PORT, local_u8_Column, DIO_LOW);

        // Loop through each row
        for (local_u8_Row = ROW_START; local_u8_Row <= ROW_END; local_u8_Row++) {
            // Read the row pin value
            local_u8_PinVal = MDIO_u8GetPinVal(KPD_PORT, local_u8_Row);

            // Check if a key is pressed
            if (local_u8_PinVal == 0) {
                // Get the corresponding key value
                local_u8_PressedKey = global_Au8_SwitchVal[local_u8_Row - ROW_START][local_u8_Column - COL_START];

                // Wait for the key to be released
                while (MDIO_u8GetPinVal(KPD_PORT, local_u8_Row) == 0);

                // Debounce delay
                MTIMERS_voidDelay_ms(20);
            }
        }

        // Deactivate the current column
        MDIO_vWrtPinVal(KPD_PORT, local_u8_Column, DIO_HIGH);
    }

    return local_u8_PressedKey;
}
