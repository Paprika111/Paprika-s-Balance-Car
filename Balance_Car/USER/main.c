/************************************************************************************
Write By Paprika 
*************************************************************************************/
#include "stm32f10x.h"
#include "delay.h"
#include "LED.h"
#include "sys.h"//�������� ����
#include "DataScope_DP.h"
int Encoder_Left,Encoder_Right;             //���ұ��������������
int Moto1,Moto2;                            //���PWM���� Ӧ��Motor�� ��Moto�¾�	
float Angle_Balance,Gyro_Balance;           //ƽ����� ƽ�������� ת��������
u8 Way_Angle=2;														//�˲��㷨
int main(void)
{ 
	MY_NVIC_PriorityGroupConfig(2);
	Stm32_Clock_Init(9);            //=====ϵͳʱ������
	delay_init(72);                 //=====��ʱ��ʼ��
	LED_Init();                     //=====���ʹ��
	uart_init(128000);           //=====��ʼ������1
  MiniBalance_PWM_Init(7199,0);   //=====��ʼ��PWM 10KHZ������������� �����ʼ������ӿ� ��ΪMiniBalance_PWM_Init(9999,35) 200HZ
	Encoder_Init_TIM2();            //=====�������ӿ�
	Encoder_Init_TIM4();            //=====��ʼ��������2 
	IIC_Init();                     //=====ģ��IIC��ʼ��+++++
  MPU6050_initialize();           //=====MPU6050��ʼ��	
  DMP_Init();                     //=====��ʼ��DMP     
  MPU6050_EXTI_Init();                    //=====MPU6050 5ms��ʱ�жϳ�ʼ��
	while(1)
		{     
				
				  //printf("ƽ�� ���  %f \r\n���ֱ�����%d \r\n���ֱ�����%d \r\n",Angle_Balance,Encoder_Left,Encoder_Right);//�򴮿ڵ������ַ�������
					Send (Angle_Balance,1);
		} 
}






