
#include "main.h"

void init_config(void)
{
    // to initialize timer 2
    init_timer2();
    // to initialize clcd
    init_clcd();
    // to initialize matrix keypad
    init_matrix_keypad();
    // to enable global interrupt
    GIE = 1;
    // to enable external peripheral interrupt
    PEIE = 1;
    // to direct RC1 as output and enable buzzer
    TRISC1 = 0;
    // to direct RC1 as output and enable fan
    TRISC2 = 0;
    // to call power up screen on reset/power on
    power_up();
}

void main(void)
{
    init_config();
    
    unsigned char key;
    unsigned char micr, gril, convec, strt;
    unsigned char control_flag = MENU_SCREEN, reset_flag = RESET_NOTHING;
    
    while(1)
    {
        key = read_matrix_keypad(STATE);
        
        if(control_flag == MENU_SCREEN && key != ALL_RELEASED)
        {
            if(key == 1)
            {
                control_flag = MICRO;
                clear_screen();
                clcd_print("Power = 900W", LINE2(2));
                __delay_ms(1000);
                clear_screen();
                reset_flag = RESET_MICRO;
            }
            else if(key == 2)
            {
                control_flag = GRILL;
                clear_screen();
                reset_flag = RESET_GRILL;
            }
            else if(key == 3)
            {
                control_flag = CONVECTION;
                clear_screen();
                reset_flag = RESET_CONVEC;
            }
            else if(key == 4)
            {
                control_flag = START;
                clear_screen();
                reset_flag = RESET_START;
            }
        }
        
        switch(control_flag)
        {
            // to display menu screen
            case MENU_SCREEN:
                menu_screen();
                break;
            // micro mode
            case MICRO:
                micr = micro(key, reset_flag);
                
                if(micr == RETURN_BACK)
                {
                    control_flag = MENU_SCREEN;
                    clear_screen();
                }
                break;
            // grill mode
            case GRILL:
                gril = grill(key, reset_flag);
                
                if(gril == RETURN_BACK)
                {
                    control_flag = MENU_SCREEN;
                    clear_screen();
                }
                break;
            // convection mode
            case CONVECTION:
                convec = convection(key, reset_flag);
                
                if(convec == RETURN_BACK)
                {
                    control_flag = MENU_SCREEN;
                    clear_screen();
                }
                break;
            // start mode
            case START:
                strt = start(key, reset_flag);
                
                if(strt == RETURN_BACK)
                {
                    control_flag = MENU_SCREEN;
                    clear_screen();
                }
                break;
        }
        
        reset_flag = RESET_NOTHING;
    }
    return;
}