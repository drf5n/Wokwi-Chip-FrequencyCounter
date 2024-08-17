// freqCount.chip.c -- frequency counter and inverter
// Copied from https://wokwi.com/projects/327458636089524820
// For information and examples see:
// https://docs.wokwi.com/chips-api/getting-started
// See also https://github.com/wokwi/inverter-chip
// 
// Original by Uri Shaked, counter mods by David Forrest
/*
This code is built from the inverter example and adds a counter and a timer to
to build a frequency counter.
*/

#include "wokwi-api.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct {
  pin_t pin_in;
  pin_t pin_out;
  pin_t pin_enable;
  timer_t timer;
} chip_state_t;

uint32_t count = 0;

static void chip_pin_change(void *user_data, pin_t pin, uint32_t value) {
  if(value==0) ++count; // count falls
  chip_state_t *chip = (chip_state_t*)user_data;
 // printf("Pin change: %d %d %u\n", pin, value, count);
  pin_write(chip->pin_out, !value);
}

void chip_timer_event(void *user_data) {
  chip_state_t *chip = (chip_state_t*)user_data;
  if(pin_read(chip->pin_enable)){
    printf("Pin change count: %u/sec\n", count);
    count = 0;
  }
}

void chip_init(void) {
  chip_state_t *chip = malloc(sizeof(chip_state_t));
  chip->pin_in = pin_init("IN", INPUT);
  chip->pin_out = pin_init("OUT", OUTPUT);
  chip->pin_enable = pin_init("ENA", INPUT_PULLUP);
  pin_write(chip->pin_out, !pin_read(chip->pin_in));

  const pin_watch_config_t config = {
    .edge = BOTH,
    .pin_change = chip_pin_change,
    .user_data = chip,
  };
  pin_watch(chip->pin_in, &config);  



  // https://docs.wokwi.com/chips-api/time
  const timer_config_t timer_config = {
    .callback = chip_timer_event,
    .user_data = chip,
  };
  chip->timer = timer_init(&timer_config);
  timer_start(chip->timer, 1000000, true); // every second


}

