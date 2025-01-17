#include "stm32f10x.h"
#include "sys.h" 

float Pitch,Roll,Yaw;						//角度
short gyrox,gyroy,gyroz;				//陀螺仪--角速度
short aacx,aacy,aacz;						//加速度
int Encoder_Left,Encoder_Right;	//编码器数据（速度）

int PWM_MAX=7200,PWM_MIN=-7200;	//PWM限幅变量
int MOTO1,MOTO2;								//电机装载变量

extern int Vertical_out,Velocity_out,Turn_out;
int main(void)	
{
	delay_init();
	NVIC_Config();       //中断优先级
	uart1_init(115200);
	
	OLED_Init();
	OLED_Clear();
	
	MPU_Init();
	mpu_dmp_init();
	MPU6050_EXTI_Init();
	
	Encoder_TIM2_Init();
	Encoder_TIM4_Init();
	Motor_Init();
	PWM_Init_TIM1(0,7199);  //设置占空比周期
							//(1 + 7199)/72MH = 7200/72000000 = 10ms即总占空比周期为10ms
	while(1)	
	{
		OLED_Float(0,55,Pitch,1);
		OLED_ShowString(0,0,"Pitch:",1);
		
		OLED_Float(3,55,Roll,1);
		OLED_ShowString(0,3,"Roll:",1);
		
		OLED_Float(6,55,Yaw,1);
		OLED_ShowString(0,6,"Yaw:",1);
		
  //	OLED_Float(50,50,Velocity_out,1);
//		OLED_ShowNumber(30,0,Velocity_out,3,16);//OK
	} 	
}

