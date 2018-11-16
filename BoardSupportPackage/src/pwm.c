/*
 *
 */

#include "pwm.h"
#include "timer_a.h"
#include "gpio.h"

/*
 * Initialize PWM
 */
void PWM_INIT_MOTOR(uint32_t timerBase, uint_fast16_t dutyCycle, uint_fast16_t timerPeriod, uint_fast16_t compareRegister,
              uint_fast8_t selectedPort, uint_fast16_t selectedPins, uint8_t GPIO_function)
{
    GPIO_setAsPeripheralModuleFunctionOutputPin(selectedPort, selectedPins, GPIO_function);

    Timer_A_PWMConfig timerA_config;
    timerA_config.clockSource = TIMER_A_CLOCKSOURCE_SMCLK;
    timerA_config.clockSourceDivider = TIMER_A_CLOCKSOURCE_DIVIDER_1;
    timerA_config.compareOutputMode = TIMER_A_OUTPUTMODE_RESET_SET;
    timerA_config.compareRegister = compareRegister;
    timerA_config.dutyCycle = dutyCycle;
    timerA_config.timerPeriod = timerPeriod;
    Timer_A_generatePWM(timerBase, &timerA_config);

}

void PWM_INIT_SERVO(uint32_t timerBase, uint_fast16_t dutyCycle, uint_fast16_t timerPeriod, uint_fast16_t compareRegister,
                    uint_fast8_t selectedPort, uint_fast16_t selectedPins, uint8_t GPIO_function)
  {
      GPIO_setAsPeripheralModuleFunctionOutputPin(selectedPort, selectedPins, GPIO_function);

      Timer_A_PWMConfig timerA_config;
      timerA_config.clockSource = TIMER_A_CLOCKSOURCE_SMCLK;
      timerA_config.clockSourceDivider = TIMER_A_CLOCKSOURCE_DIVIDER_12;
      timerA_config.compareOutputMode = TIMER_A_OUTPUTMODE_RESET_SET;
      timerA_config.compareRegister = compareRegister;
      timerA_config.dutyCycle = dutyCycle;
      timerA_config.timerPeriod = timerPeriod;
      Timer_A_generatePWM(timerBase, &timerA_config);
  }

void Stop_Timer(Timer_A_Type * timer, uint_fast16_t compareRegister)
{
    timer -> CTL &= ~(BIT5|BIT4);
    timer -> CCTL[compareRegister] &= ~(BIT7|BIT6|BIT5);
    timer -> CCTL[compareRegister] &= ~(BIT2);
    timer -> CTL |= BIT4;

}

void Restart_Timer(Timer_A_Type * timer, uint_fast16_t compareRegister)
{
    timer -> CCTL[compareRegister] |= (BIT7|BIT6|BIT5);
    timer -> CTL |= BIT4;
}

