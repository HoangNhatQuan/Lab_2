/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2022 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "software_timer.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
TIM_HandleTypeDef htim2;

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_TIM2_Init(void);
/* USER CODE BEGIN PFP */
void updateClockBuffer(int hour, int minute);
void display7SEG(int num);
void update7SEG(int index);

void selectCOL(int col);
void clearCOL(int col);
void displayDOT(uint8_t num, int row);
void clearAllPins();
void clearDOT(uint8_t num, int row);
void updateLEDMatrix (int row);
void updateMatrixBuffer(uint8_t matrix[8]);
/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
int led_buffer[4] = {1,1,2,3};
int index_led = 0;

const int MAX_LED_MATRIX = 8;
int index_led_matrix = 0;
uint8_t matrix_buffer[8] = {0x18,0x24,0x42,0x42,0x7E,0x42,0x42,0x42};	// hex display 'A'
/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_TIM2_Init();
  /* USER CODE BEGIN 2 */

  HAL_TIM_Base_Start_IT (& htim2 );
  /* USER CODE END 2 */
  setTimer3(2);
  int first = 1;
  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */
	  if(first == 1){	// set led 8x8 matrix off
		  clearAllPins();
		  first = 0;
	  }
		  updateLEDMatrix(index_led_matrix);	// call func updateLEDMatrix
		  if(timer_flag3==1){
			  clearDOT(matrix_buffer[index_led_matrix],index_led_matrix);	// set row off and col disable when a loop
			  ++index_led_matrix;
			  if(index_led_matrix>8){		//set index = 0 when index > 8
				  index_led_matrix = 0;
			  }
			  setTimer3(2);
		  }
    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief TIM2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM2_Init(void)
{

  /* USER CODE BEGIN TIM2_Init 0 */

  /* USER CODE END TIM2_Init 0 */

  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};

  /* USER CODE BEGIN TIM2_Init 1 */

  /* USER CODE END TIM2_Init 1 */
  htim2.Instance = TIM2;
  htim2.Init.Prescaler = 7999;
  htim2.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim2.Init.Period = 9;
  htim2.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim2.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim2) != HAL_OK)
  {
    Error_Handler();
  }
  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim2, &sClockSourceConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim2, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM2_Init 2 */

  /* USER CODE END TIM2_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, ENM0_Pin|ENM1_Pin|DOT_Pin|LED_Pin
                          |EN0_Pin|EN1_Pin|EN2_Pin|EN3_Pin
                          |ENM2_Pin|ENM3_Pin|ENM4_Pin|ENM5_Pin
                          |ENM6_Pin|ENM7_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, SEG_0_Pin|SEG_1_Pin|SEG_2_Pin|ROW2_Pin
                          |ROW3_Pin|ROW4_Pin|ROW5_Pin|ROW6_Pin
                          |ROW7_Pin|SEG_3_Pin|SEG_4_Pin|SEG_5_Pin
                          |SEG_6_Pin|ROW0_Pin|ROW1_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : ENM0_Pin ENM1_Pin DOT_Pin LED_Pin
                           EN0_Pin EN1_Pin EN2_Pin EN3_Pin
                           ENM2_Pin ENM3_Pin ENM4_Pin ENM5_Pin
                           ENM6_Pin ENM7_Pin */
  GPIO_InitStruct.Pin = ENM0_Pin|ENM1_Pin|DOT_Pin|LED_Pin
                          |EN0_Pin|EN1_Pin|EN2_Pin|EN3_Pin
                          |ENM2_Pin|ENM3_Pin|ENM4_Pin|ENM5_Pin
                          |ENM6_Pin|ENM7_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : SEG_0_Pin SEG_1_Pin SEG_2_Pin ROW2_Pin
                           ROW3_Pin ROW4_Pin ROW5_Pin ROW6_Pin
                           ROW7_Pin SEG_3_Pin SEG_4_Pin SEG_5_Pin
                           SEG_6_Pin ROW0_Pin ROW1_Pin */
  GPIO_InitStruct.Pin = SEG_0_Pin|SEG_1_Pin|SEG_2_Pin|ROW2_Pin
                          |ROW3_Pin|ROW4_Pin|ROW5_Pin|ROW6_Pin
                          |ROW7_Pin|SEG_3_Pin|SEG_4_Pin|SEG_5_Pin
                          |SEG_6_Pin|ROW0_Pin|ROW1_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

}

/* USER CODE BEGIN 4 */

//const int MAX_LED = 4;
//int index_led = 0;
//int led_buffer[4] = {5, 6, 7, 8};
void update7SEG(int index){
    switch (index){
        case 0:		//Display the first 7SEG with led_buffer[0]
	  	  	  HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, RESET);			// set den 7segs thu nhat bat
	  	  	  HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, SET);			// set den 7set thu hai tat
	  	  	  HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, SET);			// set den 7segs thu ba tat
	  	  	  HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, SET);			// set den 7set thu tu tat
        	display7SEG(led_buffer[0]);  	// Hien thi led_buffer[0]
            break;
        case 1:		//Display the second 7SEG with led_buffer[1]
	  	  	  HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, SET);			// set den 7segs thu nhat tat
	        	display7SEG(led_buffer[1]);  	// Hien thi led_buffer[1]
	  	  	  HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, RESET);			// set den 7set thu hai bat
            break;
        case 2:     //Display the third 7SEG with led_buffer[2]
	  	  	  HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, SET);			// set den 7set thu hai tat
	        	display7SEG(led_buffer[2]);  	// Hien thi led_buffer[2]
	  	  	  HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, RESET);			// set den 7segs thu ba bat
            break;
        case 3:		//Display the forth 7SEG with led_buffer[3]
	  	  	  HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, SET);			// set den 7segs thu ba tat
	        	display7SEG(led_buffer[3]);  	// Hien thi led_buffer[3]
	  	  	  HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, RESET);			// set den 7set thu tu bat
            break;
        default:
            break;
    }
}
int counter1 = 0; 	// set bien dem 25 lan tuong duong voi 250ms cho 7segs
//int counter2 = 0;	// set bien dem 100 lan tuong duong voi 1000ms cho DOT
void HAL_TIM_PeriodElapsedCallback ( TIM_HandleTypeDef * htim ){
	timerRun();

}

void display7SEG(int num){ 		// ham hien thi den 7seg
 	  if(num == 0){	// set number 0
 		  HAL_GPIO_WritePin(SEG_0_GPIO_Port, SEG_0_Pin, RESET);
 		  HAL_GPIO_WritePin(SEG_1_GPIO_Port, SEG_1_Pin, RESET);
 		  HAL_GPIO_WritePin(SEG_2_GPIO_Port, SEG_2_Pin, RESET);
 		  HAL_GPIO_WritePin(SEG_3_GPIO_Port, SEG_3_Pin, RESET);
 		  HAL_GPIO_WritePin(SEG_4_GPIO_Port, SEG_4_Pin, RESET);
 		  HAL_GPIO_WritePin(SEG_5_GPIO_Port, SEG_5_Pin, RESET);
 		  HAL_GPIO_WritePin(SEG_6_GPIO_Port, SEG_6_Pin, SET);
 	  }
 	  if(num == 1){	// set number 1
 		  HAL_GPIO_WritePin(SEG_0_GPIO_Port, SEG_0_Pin, SET);
 		  HAL_GPIO_WritePin(SEG_1_GPIO_Port, SEG_1_Pin, RESET);
 		  HAL_GPIO_WritePin(SEG_2_GPIO_Port, SEG_2_Pin, RESET);
 		  HAL_GPIO_WritePin(SEG_3_GPIO_Port, SEG_3_Pin, SET);
 		  HAL_GPIO_WritePin(SEG_4_GPIO_Port, SEG_4_Pin, SET);
 		  HAL_GPIO_WritePin(SEG_5_GPIO_Port, SEG_5_Pin, SET);
 		  HAL_GPIO_WritePin(SEG_6_GPIO_Port, SEG_6_Pin, SET);
 	  }
 	  if(num == 2){	// set number 2
 		  HAL_GPIO_WritePin(SEG_0_GPIO_Port, SEG_0_Pin, RESET);
 		  HAL_GPIO_WritePin(SEG_1_GPIO_Port, SEG_1_Pin, RESET);
 		  HAL_GPIO_WritePin(SEG_2_GPIO_Port, SEG_2_Pin, SET);
 		  HAL_GPIO_WritePin(SEG_3_GPIO_Port, SEG_3_Pin, RESET);
 		  HAL_GPIO_WritePin(SEG_4_GPIO_Port, SEG_4_Pin, RESET);
 		  HAL_GPIO_WritePin(SEG_5_GPIO_Port, SEG_5_Pin, SET);
 		  HAL_GPIO_WritePin(SEG_6_GPIO_Port, SEG_6_Pin, RESET);
 	  }
 	  if(num == 3){	// set number 3
 		  HAL_GPIO_WritePin(SEG_0_GPIO_Port, SEG_0_Pin, RESET);
 		  HAL_GPIO_WritePin(SEG_1_GPIO_Port, SEG_1_Pin, RESET);
 		  HAL_GPIO_WritePin(SEG_2_GPIO_Port, SEG_2_Pin, RESET);
 		  HAL_GPIO_WritePin(SEG_3_GPIO_Port, SEG_3_Pin, RESET);
 		  HAL_GPIO_WritePin(SEG_4_GPIO_Port, SEG_4_Pin, SET);
 		  HAL_GPIO_WritePin(SEG_5_GPIO_Port, SEG_5_Pin, SET);
 		  HAL_GPIO_WritePin(SEG_6_GPIO_Port, SEG_6_Pin, RESET);
 	  }
 	  if(num == 4){	// set number 4
 		  HAL_GPIO_WritePin(SEG_0_GPIO_Port, SEG_0_Pin, SET);
 		  HAL_GPIO_WritePin(SEG_1_GPIO_Port, SEG_1_Pin, RESET);
 		  HAL_GPIO_WritePin(SEG_2_GPIO_Port, SEG_2_Pin, RESET);
 		  HAL_GPIO_WritePin(SEG_3_GPIO_Port, SEG_3_Pin, SET);
 		  HAL_GPIO_WritePin(SEG_4_GPIO_Port, SEG_4_Pin, SET);
 		  HAL_GPIO_WritePin(SEG_5_GPIO_Port, SEG_5_Pin, RESET);
 		  HAL_GPIO_WritePin(SEG_6_GPIO_Port, SEG_6_Pin, RESET);
 	  }
 	  if(num == 5){	// set number 5
 		  HAL_GPIO_WritePin(SEG_0_GPIO_Port, SEG_0_Pin, RESET);
 		  HAL_GPIO_WritePin(SEG_1_GPIO_Port, SEG_1_Pin, SET);
 		  HAL_GPIO_WritePin(SEG_2_GPIO_Port, SEG_2_Pin, RESET);
 		  HAL_GPIO_WritePin(SEG_3_GPIO_Port, SEG_3_Pin, RESET);
 		  HAL_GPIO_WritePin(SEG_4_GPIO_Port, SEG_4_Pin, SET);
 		  HAL_GPIO_WritePin(SEG_5_GPIO_Port, SEG_5_Pin, RESET);
 		  HAL_GPIO_WritePin(SEG_6_GPIO_Port, SEG_6_Pin, RESET);
 	  }
 	  if(num == 6){	// set number 6
 		  HAL_GPIO_WritePin(SEG_0_GPIO_Port, SEG_0_Pin, RESET);
 		  HAL_GPIO_WritePin(SEG_1_GPIO_Port, SEG_1_Pin, SET);
 		  HAL_GPIO_WritePin(SEG_2_GPIO_Port, SEG_2_Pin, RESET);
 		  HAL_GPIO_WritePin(SEG_3_GPIO_Port, SEG_3_Pin, RESET);
 		  HAL_GPIO_WritePin(SEG_4_GPIO_Port, SEG_4_Pin, RESET);
 		  HAL_GPIO_WritePin(SEG_5_GPIO_Port, SEG_5_Pin, RESET);
 		  HAL_GPIO_WritePin(SEG_6_GPIO_Port, SEG_6_Pin, RESET);
 	  }
 	  if(num == 7){	// set number 7
 		  HAL_GPIO_WritePin(SEG_0_GPIO_Port, SEG_0_Pin, RESET);
 		  HAL_GPIO_WritePin(SEG_1_GPIO_Port, SEG_1_Pin, RESET);
 		  HAL_GPIO_WritePin(SEG_2_GPIO_Port, SEG_2_Pin, RESET);
 		  HAL_GPIO_WritePin(SEG_3_GPIO_Port, SEG_3_Pin, SET);
 		  HAL_GPIO_WritePin(SEG_4_GPIO_Port, SEG_4_Pin, SET);
 		  HAL_GPIO_WritePin(SEG_5_GPIO_Port, SEG_5_Pin, SET);
 		  HAL_GPIO_WritePin(SEG_6_GPIO_Port, SEG_6_Pin, SET);
 	  }
 	  if(num == 8){	// set number 8
 		  HAL_GPIO_WritePin(SEG_0_GPIO_Port, SEG_0_Pin, RESET);
 		  HAL_GPIO_WritePin(SEG_1_GPIO_Port, SEG_1_Pin, RESET);
 		  HAL_GPIO_WritePin(SEG_2_GPIO_Port, SEG_2_Pin, RESET);
 		  HAL_GPIO_WritePin(SEG_3_GPIO_Port, SEG_3_Pin, RESET);
 		  HAL_GPIO_WritePin(SEG_4_GPIO_Port, SEG_4_Pin, RESET);
 		  HAL_GPIO_WritePin(SEG_5_GPIO_Port, SEG_5_Pin, RESET);
 		  HAL_GPIO_WritePin(SEG_6_GPIO_Port, SEG_6_Pin, RESET);
 	  }
 	  if(num == 9){	// set number 9
 		  HAL_GPIO_WritePin(SEG_0_GPIO_Port, SEG_0_Pin, RESET);
 		  HAL_GPIO_WritePin(SEG_1_GPIO_Port, SEG_1_Pin, RESET);
 		  HAL_GPIO_WritePin(SEG_2_GPIO_Port, SEG_2_Pin, RESET);
 		  HAL_GPIO_WritePin(SEG_3_GPIO_Port, SEG_3_Pin, RESET);
 		  HAL_GPIO_WritePin(SEG_4_GPIO_Port, SEG_4_Pin, SET);
 		  HAL_GPIO_WritePin(SEG_5_GPIO_Port, SEG_5_Pin, RESET);
 		  HAL_GPIO_WritePin(SEG_6_GPIO_Port, SEG_6_Pin, RESET);
 	  }
   }
void updateClockBuffer(int hour , int minute){
	  int h1 = hour / 10;		// lay ra so de hien thi den 7seg thu nhat
	  int h2 = hour % 10;		// lay ra so de hien thi den 7seg thu hai
	  int m1 = minute / 10;		// lay ra so de hien thi den 7seg thu ba
	  int m2 = minute % 10;		// lay ra so de hien thi den 7seg thu tu
	  led_buffer[0] = h1;		// truyen so vao phan tu led_buffer[0]
	  led_buffer[1] = h2;		// truyen so vao phan tu led_buffer[1]
	  led_buffer[2] = m1; 		// truyen so vao phan tu led_buffer[2]
	  led_buffer[3] = m2;		// truyen so vao phan tu led_buffer[3]
}

void selectCOL(int col){	//  func select col enable
	switch(col){
	case 0:				// col0 enable
		 HAL_GPIO_WritePin(ENM0_GPIO_Port, ENM0_Pin, GPIO_PIN_RESET);
			break;
	case 1:				// col1 enable
		 HAL_GPIO_WritePin(ENM1_GPIO_Port, ENM1_Pin, GPIO_PIN_RESET);
			break;
	case 2:				// col2 enable
		 HAL_GPIO_WritePin(ENM2_GPIO_Port, ENM2_Pin, GPIO_PIN_RESET);
			break;
	case 3:				// col3 enable
		 HAL_GPIO_WritePin(ENM3_GPIO_Port, ENM3_Pin, GPIO_PIN_RESET);
			break;
	case 4:				// col4 enable
		 HAL_GPIO_WritePin(ENM4_GPIO_Port, ENM4_Pin, GPIO_PIN_RESET);
			break;
	case 5:				// col5 enable
		 HAL_GPIO_WritePin(ENM5_GPIO_Port, ENM5_Pin, GPIO_PIN_RESET);
			break;
	case 6:				// col6 enable
		 HAL_GPIO_WritePin(ENM6_GPIO_Port, ENM6_Pin, GPIO_PIN_RESET);
			break;
	case 7:				// col7 enable
		 HAL_GPIO_WritePin(ENM7_GPIO_Port, ENM7_Pin, GPIO_PIN_RESET);
			break;
	default: break;
	}
}
void clearCOL(int col){		// func select col disable
	switch(col){
		case 0:			// col0 disable
			 HAL_GPIO_WritePin(ENM0_GPIO_Port, ENM0_Pin, GPIO_PIN_SET);
				break;
		case 1:			// col1 disable
			 HAL_GPIO_WritePin(ENM1_GPIO_Port, ENM1_Pin, GPIO_PIN_SET);
				break;
		case 2:			// col2 disable
			 HAL_GPIO_WritePin(ENM2_GPIO_Port, ENM2_Pin, GPIO_PIN_SET);
				break;
		case 3:			// col3 disable
			 HAL_GPIO_WritePin(ENM3_GPIO_Port, ENM3_Pin, GPIO_PIN_SET);
				break;
		case 4:			// col4 disable
			 HAL_GPIO_WritePin(ENM4_GPIO_Port, ENM4_Pin, GPIO_PIN_SET);
				break;
		case 5:			// col5 disable
			 HAL_GPIO_WritePin(ENM5_GPIO_Port, ENM5_Pin, GPIO_PIN_SET);
				break;
		case 6:			// col6 disable
			 HAL_GPIO_WritePin(ENM6_GPIO_Port, ENM6_Pin, GPIO_PIN_SET);
				break;
		case 7:			// col7 disable
			 HAL_GPIO_WritePin(ENM7_GPIO_Port, ENM7_Pin, GPIO_PIN_SET);
				break;
		default: break;
		}
}
void displayDOT(uint8_t num, int row){	// read hex and output in matrix_buffer[]
	switch(row){
	case 0:		// row0 on and col i enable
			for(int i = 0; i < 8; i++){
				if(num & 0x80){
					selectCOL(i);	// select col i
				}
				 num = num<<1;		// dich bit
			}
			HAL_GPIO_WritePin(ROW0_GPIO_Port, ROW0_Pin, GPIO_PIN_RESET);
			break;
	case 1:		// row1 on and col i enable
		for(int i = 0; i < 8; i++){
			if(num & 0x80){
				selectCOL(i);	// select col i
			}
			 num = num<<1;		// dich bit
		}
		HAL_GPIO_WritePin(ROW1_GPIO_Port, ROW1_Pin, GPIO_PIN_RESET);
			break;
	case 2:		// row2 on and col i enable
		for(int i = 0; i<8; i++){
			if(num&0x80){
				selectCOL(i);	// select col i
			}
			 num = num<<1;		// dich bit
		}
		HAL_GPIO_WritePin(ROW2_GPIO_Port, ROW2_Pin, GPIO_PIN_RESET);
			break;
	case 3:		// row3 on and col i enable
		for(int i = 0; i<8; i++){
			if(num&0x80){
				selectCOL(i);	// select col i
			}
			 num = num<<1;		// dich bit
		}
		HAL_GPIO_WritePin(ROW3_GPIO_Port, ROW3_Pin, GPIO_PIN_RESET);
			break;
	case 4:		// row4 on and col i enable
		for(int i = 0; i<8; i++){
			if(num&0x80){
				selectCOL(i);	// select col i
			}
			 num = num<<1;		// dich bit
		}
		HAL_GPIO_WritePin(ROW4_GPIO_Port, ROW4_Pin, GPIO_PIN_RESET);
			break;
	case 5:		// row5 on and col i enable
		for(int i = 0; i<8; i++){
			if(num&0x80){
				selectCOL(i);	// select col i
			}
			 num = num<<1;		// dich bit
		}
		HAL_GPIO_WritePin(ROW5_GPIO_Port, ROW5_Pin, GPIO_PIN_RESET);
			break;
	case 6:		// row6 on and col i enable
		for(int i = 0; i<8; i++){
			if(num&0x80){
				selectCOL(i);	// select col i
			}
			 num = num<<1;		// dich bit
		}
		HAL_GPIO_WritePin(ROW6_GPIO_Port, ROW6_Pin, GPIO_PIN_RESET);
			break;
	case 7:		// row7 on and col i enable
		for(int i = 0; i<8; i++){
			if(num&0x80){
				selectCOL(i);	// select col i
			}
			 num = num<<1;		// dich bit
		}
		HAL_GPIO_WritePin(ROW7_GPIO_Port, ROW7_Pin, GPIO_PIN_RESET);
			break;
	default: break;
	}
}
void clearAllPins(){	// all row off and col disable
	  HAL_GPIO_WritePin(ROW0_GPIO_Port, ROW0_Pin, GPIO_PIN_SET);
	  HAL_GPIO_WritePin(ROW1_GPIO_Port, ROW1_Pin, GPIO_PIN_SET);
	  HAL_GPIO_WritePin(ROW2_GPIO_Port, ROW2_Pin, GPIO_PIN_SET);
	  HAL_GPIO_WritePin(ROW3_GPIO_Port, ROW3_Pin, GPIO_PIN_SET);
	  HAL_GPIO_WritePin(ROW4_GPIO_Port, ROW4_Pin, GPIO_PIN_SET);
	  HAL_GPIO_WritePin(ROW5_GPIO_Port, ROW5_Pin, GPIO_PIN_SET);
	  HAL_GPIO_WritePin(ROW6_GPIO_Port, ROW6_Pin, GPIO_PIN_SET);
	  HAL_GPIO_WritePin(ROW7_GPIO_Port, ROW7_Pin, GPIO_PIN_SET);

	  HAL_GPIO_WritePin(ENM0_GPIO_Port, ENM0_Pin, GPIO_PIN_SET);
	  HAL_GPIO_WritePin(ENM1_GPIO_Port, ENM1_Pin, GPIO_PIN_SET);
	  HAL_GPIO_WritePin(ENM2_GPIO_Port, ENM2_Pin, GPIO_PIN_SET);
	  HAL_GPIO_WritePin(ENM3_GPIO_Port, ENM3_Pin, GPIO_PIN_SET);
	  HAL_GPIO_WritePin(ENM4_GPIO_Port, ENM4_Pin, GPIO_PIN_SET);
	  HAL_GPIO_WritePin(ENM5_GPIO_Port, ENM5_Pin, GPIO_PIN_SET);
	  HAL_GPIO_WritePin(ENM6_GPIO_Port, ENM6_Pin, GPIO_PIN_SET);
	  HAL_GPIO_WritePin(ENM7_GPIO_Port, ENM7_Pin, GPIO_PIN_SET);
}
void clearDOT(uint8_t num, int row){	// like displayDOT but select row off and col disable
	switch(row){
		case 0:
			HAL_GPIO_WritePin(ROW0_GPIO_Port, ROW0_Pin, GPIO_PIN_SET);
				for(int i = 0; i < 8; i++){
					if(num&0x80){
						clearCOL(i);
					}
					 num = num<<1;
				}
				break;
		case 1:
			HAL_GPIO_WritePin(ROW1_GPIO_Port, ROW1_Pin, GPIO_PIN_SET);
			for(int i = 0; i<8; i++){
				if(num&0x80){
					clearCOL(i);
				}
				 num = num<<1;
			}
				break;
		case 2:
			HAL_GPIO_WritePin(ROW2_GPIO_Port, ROW2_Pin, GPIO_PIN_SET);
			for(int i = 0; i<8; i++){
				if(num&0x80){
					clearCOL(i);
				}
				 num = num<<1;
			}
				break;
		case 3:
			HAL_GPIO_WritePin(ROW3_GPIO_Port, ROW3_Pin, GPIO_PIN_SET);
			for(int i = 0; i<8; i++){
				if(num&0x80){
					clearCOL(i);
				}
				 num = num<<1;
			}
				break;
		case 4:
			HAL_GPIO_WritePin(ROW4_GPIO_Port, ROW4_Pin, GPIO_PIN_SET);
			for(int i = 0; i<8; i++){
				if(num&0x80){
					clearCOL(i);
				}
				 num = num<<1;
			}
				break;
		case 5:
			HAL_GPIO_WritePin(ROW5_GPIO_Port, ROW5_Pin, GPIO_PIN_SET);
			for(int i = 0; i<8; i++){
				if(num&0x80){
					clearCOL(i);
				}
				 num = num<<1;
			}
				break;
		case 6:
			HAL_GPIO_WritePin(ROW6_GPIO_Port, ROW6_Pin, GPIO_PIN_SET);
			for(int i = 0; i<8; i++){
				if(num&0x80){
					clearCOL(i);
				}
				 num = num<<1;

			}
				break;
		case 7:
			HAL_GPIO_WritePin(ROW7_GPIO_Port, ROW7_Pin, GPIO_PIN_SET);
			for(int i = 0; i<8; i++){
				if(num&0x80){
					clearCOL(i);
				}
				 num = num<<1;

			}
				break;
		default: break;
		}
}
void updateLEDMatrix (int row) {	// display 'A' in led matrix
	 switch (row) {
		case 0:		// decode hex in matrix_buffer[0] and display row
			displayDOT(matrix_buffer[0],row);
			break ;
		case 1:		// decode hex in matrix_buffer[1] and display row
			 displayDOT(matrix_buffer[1],row);
			 break ;
		case 2:		// decode hex in matrix_buffer[2] and display row
			displayDOT(matrix_buffer[2],row);
			break ;
		case 3:		// decode hex in matrix_buffer[3] and display row
			 displayDOT(matrix_buffer[3],row);
			 break ;
		case 4:		// decode hex in matrix_buffer[4] and display row
			 displayDOT(matrix_buffer[4],row);
			 break ;
		case 5:		// decode hex in matrix_buffer[5] and display row
			 displayDOT(matrix_buffer[5],row);
			 break ;
		case 6:		// decode hex in matrix_buffer[6] and display row
			 displayDOT(matrix_buffer[6],row);
			 break ;
		case 7:		// decode hex in matrix_buffer[7] and display row
			 displayDOT(matrix_buffer[7],row);
			 break ;
		default :
			 break ;
	 }
 }

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
