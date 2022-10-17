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
int TIMER_CYCLE = 1;

void setTimer1(int duration){
	timer_counter1 = duration;
	timer_flag1 = 0;
}
void setTimer2(int duration){
	timer_counter2 = duration;
	timer_flag2 = 0;
}
void setTimer3(int duration){
	timer_counter3 = duration ;
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

//int timer0_counter = 0;
//int segcount = 0;
//int timer1_flag = 0;
//int timer0_flag = 0;
//int TIMER_CYCLE = 10;
//const int MAX_LED = 4;
//void setTimer0(int duration) {
//	timer0_counter = duration / TIMER_CYCLE ;
//	timer0_flag = 0;
//}
//void setTimer1(int duration) {
//	segcount = duration / (MAX_LED *10) ;
//	timer1_flag = 0;
//}
//void timer_run () {
//	if(timer0_counter > 0) {
//		timer0_counter--;
//		if(timer0_counter == 0) timer0_flag = 1;
//	}
//	if(segcount > 0) {
//		segcount--;
//		if(segcount == 0) timer1_flag = 1;
//	}
//}

