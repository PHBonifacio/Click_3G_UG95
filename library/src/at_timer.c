/******************************************************************************
* Title                 :   AT PARSER
* Filename              :   at_timer.c
* Author                :   MSV
* Origin Date           :   10/03/2016
* Notes                 :   None
*******************************************************************************/
/**************************CHANGE LIST ****************************************
*
*    Date    Software Version    Initials   Description
*  10/03/16        1.0.0           MSV      Interface Created.
*
*******************************************************************************/
/**
 * @file at_timer.c
 * @brief AT Timer
 */
/******************************************************************************
* Includes
*******************************************************************************/
#include "at_timer.h"
#include "at_config.h"
/******************************************************************************
* Module Preprocessor Constants
*******************************************************************************/

/******************************************************************************
* Module Preprocessor Macros
*******************************************************************************/

/******************************************************************************
* Module Typedefs
*******************************************************************************/

/******************************************************************************
* Module Variable Definitions
*******************************************************************************/
static volatile bool            timer_f;
static volatile uint32_t        timer_c;
static volatile uint32_t        timer;
/******************************************************************************
* Function Prototypes
*******************************************************************************/

/******************************************************************************
* Private Function Definitions
*******************************************************************************/

/******************************************************************************
* Public Function Definitions
*******************************************************************************/
void at_timer_init()
{
    uint8_t c;

    timer       = 0;
    timer_c     = 0;
    timeout_f   = false;
    timer_f     = false;
}

void at_tick_isr( void )
{
    if( timer_f )
        if( timer_c++ > timer )
            timeout_f = true;
}

void at_timer_start( void )
{
    timer_f = true;
    timer_c = 0;
}

void at_timer_restart( void )
{
    timer_c = 0;
}

void at_timer_stop( void )
{
    timer_f = false;
    timer_c = 0;
}

void at_timer_load( uint32_t timeout )
{
    timer = timeout;
}
/*************** END OF FUNCTIONS *********************************************/
