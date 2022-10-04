/*
 * software_timer.c
 *
 *  Created on: Sep 23, 2022
 *      Author: Asus
 */

#include "software_timer.h"

int timer_counter1 = 0;
int timer_flag1 = 0;

int timer_counter2 = 0;
int timer_flag2 = 0;

int timer_counter3 = 0;
int timer_flag3 = 0;

void setTimer1(int duration){
	timer_counter1 = duration;
	timer_flag1 = 0;
}
void setTimer2(int duration){
	timer_counter2 = duration;
	timer_flag2 = 0;
}
void setTimer3(int duration){
	timer_counter3 = duration;
	timer_flag3 = 0;
}
void timerRun(){
	if(timer_counter1 > 0){
		timer_counter1--;
		if(timer_counter1 == 0){
			timer_flag1 = 1;
		}
	}
	if(timer_counter2 > 0){
		timer_counter2--;
		if(timer_counter2 == 0){
			timer_flag2 = 1;
		}
	}
	if(timer_counter3 > 0){
		timer_counter3--;
		if(timer_counter3 == 0){
			timer_flag3 = 1;
		}
	}
}
