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

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

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

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
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

  int index = 0;	//   set chuyển đèn 7segs
  void updateClockBuffer(int hour , int minute){
	  int h1 = hour / 10;		// lấy ra số để hiển thị đèn 7seg thứ nhất
	  int h2 = hour % 10;		// lấy ra số để hiển thị đèn 7seg thứ hai
	  int m1 = minute / 10;		// lấy ra số để hiển thị đèn 7seg thứ ba
	  int m2 = minute % 10;		// lấy ra số để hiển thị đèn 7seg thứ tư
	  int led_buffer[4] = {h1, h2, m1, m2};
	    switch (index){
	        case 0:		//Display the first 7SEG with led_buffer[0]
		  	  	  HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, RESET);			// set den 7segs thu nhat bat
		  	  	  HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, SET);			// set den 7set thu hai tat
		  	  	  HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, SET);			// set den 7segs thu ba tat
		  	  	  HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, SET);			// set den 7set thu tu tat
	        	display7SEG(led_buffer[0]);  	// Hien thi led_buffer[0]
	        	index = 1;
	            break;
	        case 1:		//Display the second 7SEG with led_buffer[1]
		  	  	  HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, SET);			// set den 7segs thu nhat tat
		        	display7SEG(led_buffer[1]);  	// Hien thi led_buffer[1]
		  	  	  HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, RESET);			// set den 7set thu hai bat
		        	index = 2;
	            break;

	        case 2:     //Display the third 7SEG with led_buffer[2]
		  	  	  HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, SET);			// set den 7set thu hai tat
		        	display7SEG(led_buffer[2]);  	// Hien thi led_buffer[2]
		  	  	  HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, RESET);			// set den 7segs thu ba bat
		        	index = 3;
	            break;
	        case 3:		//Display the forth 7SEG with led_buffer[3]
		  	  	  HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, SET);			// set den 7segs thu ba tat
		        	display7SEG(led_buffer[3]);  	// Hien thi led_buffer[3]
		  	  	  HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, RESET);			// set den 7set thu tu bat
		        	index = 0;
	            break;
	        default:
	            break;
	    }
  }

  int hour = 15, minute = 8, second = 50;
  setTimer1(100);	// set thoi gian 1s
  setTimer2(100);
  while(1){
	  if(timer_flag1 == 1){
		  second++;
		  if (second >= 60){
			  second = 0;
			  minute++;
		  }
		  if(minute >= 60){
			  minute = 0;
			  hour++;
		  }
		  if(hour >=24){
			  hour = 0;
		  }
		  HAL_GPIO_TogglePin(DOT_GPIO_Port, DOT_Pin);	// Den DOT nhap nhay trong 1s
		  updateClockBuffer(hour,minute);		// Ham giong voi bai 5
		  setTimer1(100);	// set thoi gian 1s
	  }
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
  HAL_GPIO_WritePin(GPIOA, DOT_Pin|LED_Pin|EN0_Pin|EN1_Pin
                          |EN2_Pin|EN3_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, SEG_0_Pin|SEG_1_Pin|SEG_2_Pin|SEG_3_Pin
                          |SEG_4_Pin|SEG_5_Pin|SEG_6_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : DOT_Pin LED_Pin EN0_Pin EN1_Pin
                           EN2_Pin EN3_Pin */
  GPIO_InitStruct.Pin = DOT_Pin|LED_Pin|EN0_Pin|EN1_Pin
                          |EN2_Pin|EN3_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : SEG_0_Pin SEG_1_Pin SEG_2_Pin SEG_3_Pin
                           SEG_4_Pin SEG_5_Pin SEG_6_Pin */
  GPIO_InitStruct.Pin = SEG_0_Pin|SEG_1_Pin|SEG_2_Pin|SEG_3_Pin
                          |SEG_4_Pin|SEG_5_Pin|SEG_6_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

}

/* USER CODE BEGIN 4 */

//const int MAX_LED = 4;
//int index_led = 0;
//int led_buffer[4] = {5, 6, 7, 8};
//void update7SEG(int index){
//    switch (index){
//        case 0:		//Display the first 7SEG with led_buffer[0]
//	  	  	  HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, RESET);			// set den 7segs thu nhat bat
//	  	  	  HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, SET);			// set den 7set thu hai tat
//	  	  	  HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, SET);			// set den 7segs thu ba tat
//	  	  	  HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, SET);			// set den 7set thu tu tat
//        	display7SEG(led_buffer[0]);  	// Hien thi led_buffer[0]
//            break;
//        case 1:		//Display the second 7SEG with led_buffer[1]
//	  	  	  HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, SET);			// set den 7segs thu nhat tat
//	        	display7SEG(led_buffer[1]);  	// Hien thi led_buffer[1]
//	  	  	  HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, RESET);			// set den 7set thu hai bat
//            break;
//        case 2:     //Display the third 7SEG with led_buffer[2]
//	  	  	  HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, SET);			// set den 7set thu hai tat
//	        	display7SEG(led_buffer[2]);  	// Hien thi led_buffer[2]
//	  	  	  HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, RESET);			// set den 7segs thu ba bat
//            break;
//        case 3:		//Display the forth 7SEG with led_buffer[3]
//	  	  	  HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, SET);			// set den 7segs thu ba tat
//	        	display7SEG(led_buffer[3]);  	// Hien thi led_buffer[3]
//	  	  	  HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, RESET);			// set den 7set thu tu bat
//
//            break;
//        default:
//            break;
//    }
//}
//int counter1 = 0; 	// set bien dem 25 lan tuong duong voi 250ms cho 7segs
//int counter2 = 0;	// set bien dem 100 lan tuong duong voi 1000ms cho DOT
void HAL_TIM_PeriodElapsedCallback ( TIM_HandleTypeDef * htim ){
	timerRun();
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
