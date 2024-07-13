#include "stm32f10x.h"
#include "sys.h" 

float Pitch,Roll,Yaw;						//�Ƕ�
short gyrox,gyroy,gyroz;				//������--���ٶ�
short aacx,aacy,aacz;						//���ٶ�
int Encoder_Left,Encoder_Right;	//���������ݣ��ٶȣ�

int PWM_MAX=7200,PWM_MIN=-7200;	//PWM�޷�����
int MOTO1,MOTO2;								//���װ�ر���

extern int Vertical_out,Velocity_out,Turn_out;
int main(void)	
{
	delay_init();
	NVIC_Config();       //�ж����ȼ�
	uart1_init(115200);
	
	OLED_Init();
	OLED_Clear();
	
	MPU_Init();
	mpu_dmp_init();
	MPU6050_EXTI_Init();
	
	Encoder_TIM2_Init();
	Encoder_TIM4_Init();
	Motor_Init();
	PWM_Init_TIM1(0,7199);  //����ռ�ձ�����
							//(1 + 7199)/72MH = 7200/72000000 = 10ms����ռ�ձ�����Ϊ10ms
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
