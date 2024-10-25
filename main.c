#include <stdbool.h>
#include <stdint.h>
#include "nrf_delay.h"
#include "boards.h"

/**
 * @brief Function for application main entry.
 */
int main(void)
{
    /* Configure board. */
    bsp_board_init(BSP_INIT_LEDS);

    int led_blink_pattern[4] = {7,2,0,4};

    /* Toggle LEDs. */
     while (true)
    {
        // Iterate through each LED
        for (int i = 0; i < LEDS_NUMBER; i++)
        {
            // Blink the LED based on the pattern
            for (int j = 0; j < led_blink_pattern[i]; j++)
            {
                bsp_board_led_on(i);     // Turn on LED
                nrf_delay_ms(200);       // Short delay
                bsp_board_led_off(i);    // Turn off LED
                nrf_delay_ms(200);       // Short delay between blinks
            }
            
            // Longer delay between LED patterns
            nrf_delay_ms(1000);
        }
    }}

/**
 *@}
 **/

