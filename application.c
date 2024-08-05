/* 
 * File:   application.c
 * Author: Abdelrahman Mansour
 *
 * Created on August 5, 2024, 1:33 AM
 */

#include "application.h"

void tmr0_isr(void);
void init(void);



Std_ReturnType ret = E_NOT_OK;
uint8 number = 0;

segment_t seven_seg_obj = {
.segment_type = SEGMENT_COMMON_ANODE,
.segment_pin[0].port = PORTA_INDEX,
.segment_pin[0].pin = PIN0,
.segment_pin[0].direction = GPIO_OUTPUT,
.segment_pin[0].logic = LOW,
.segment_pin[1].port = PORTA_INDEX,
.segment_pin[1].pin = PIN1,
.segment_pin[1].direction = GPIO_OUTPUT,
.segment_pin[1].logic = LOW,
.segment_pin[2].port = PORTA_INDEX,
.segment_pin[2].pin = PIN2,
.segment_pin[2].direction = GPIO_OUTPUT,
.segment_pin[2].logic = LOW,
.segment_pin[3].port = PORTA_INDEX,
.segment_pin[3].pin = PIN3,
.segment_pin[3].direction = GPIO_OUTPUT,
.segment_pin[3].logic = LOW,
};

timer0_t timer0_obj ={
 .Timer0_InterruptHandler = tmr0_isr,
 .prescaler_enable = TIMER0_PRESCALER_ENABLE,
 .prescaler_val = TIMER0_PRESCALER_VALUE_DIV_BY_32,
 .timer0_mode = TIMER0_TIMER_MODE,
 .timer0_reg_size = TIMER0_REGESTER_SIZE_16BIT,
 .timer0_preload_val = 3036,
 
 };

pin_config_t ones = {
   .port = PORTC_INDEX,
   .pin = PIN0,
   .direction = GPIO_OUTPUT,
   .logic = LOW,
 };
  pin_config_t tens = {
   .port = PORTC_INDEX,
   .pin = PIN1,
   .direction = GPIO_OUTPUT,
   .logic = LOW,
 };

int main() {
    init();
    while(1){
            ret = gpio_port_write_logic(PORTC_INDEX, 0x01); // 0000 0001
            ret = gpio_port_write_logic(PORTA_INDEX, ((uint8)(number/10)));
            __delay_ms(10);
            ret = gpio_port_write_logic(PORTC_INDEX, 0x02); // 0000 0010
            ret = gpio_port_write_logic(PORTA_INDEX, ((uint8)(number%10)));
            __delay_ms(10);
            if(number == 21){
                number = 0;
            }
            else{/*Nothing*/}
    }
    
    return (EXIT_SUCCESS);
}

void init(void){
    ret = seven_segment_init(&seven_seg_obj);
    ret = Timer0_Init(&timer0_obj);
    ret = gpio_pin_direction_init(&ones);
    ret = gpio_pin_direction_init(&tens);
}

 void tmr0_isr(void){ 
     number++;
 }
