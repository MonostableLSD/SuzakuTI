#ifndef __DEFINE_H
#define	__DEFINE_H

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <math.h>

#include "IQmath/IQmathLib.h"

#include "inc/hw_memmap.h"	//�����ַ�궨��
#include "inc/hw_types.h"   //λ�������ĺ궨�� 
#include "inc/hw_ints.h"		

#include "driverlib/sysctl.h"
#include "driverlib/systick.h"
#include "driverlib/rom.h"
#include "driverlib/debug.h"
#include "driverlib/interrupt.h"
#include "driverlib/pin_map.h"

#include "driverlib/fpu.h"
#include "driverlib/gpio.h"
#include "driverlib/uart.h"
#include "driverlib/pwm.h"
#include "driverlib/eeprom.h"

typedef uint32_t u32;
typedef uint16_t u16;
typedef uint8_t  u8;

#define SysTickPeriod 200																							//ÿ(1/SysTickPeriod)==5MS�����SysTick�ж� 

#define	MIN_PWMPULSE  4000
#define	MAX_PWMPULSE  11000

#define UART0Baud     115200
#define UART1Baud     115200
#define UART5Baud			500000


#define MIN_THROTTLE	100
#define MAX_THROTTLE	5000




typedef struct
{
	//����״̬/������
	u8 start_ok;
	u8 sensor_ok;
	
	u8 angle_ok;
	u8 gyro_ok;
	u8 OF_loc_ok;  		//ȷ���յ�������ͬ���Ĺ�����Ϣ
	u8 OF_height_ok;	

	
	
//	//����״̬
//	u8 manual_locked;
//	u8 unlock_en;
//	u8 fly_ready;		//unlocked
//	u8 thr_low;
//	u8 locking;

	u8 set_yaw;
	
	u8 ct_att_hold;		//��̬������
	u8 ct_alt_hold;		//�߶Ȼ�����
	u8 ct_loc_hold;		//λ�û�����
	
	u8 taking_off;  //����̬���
	u8 landing;			//����̬����
	u8 all_stop;		//����ֹͣ

}_flag;
extern _flag flag;

typedef struct
{
	u8 gyro_ok;
	u8 acc_ok;
	u8 mag_ok;
	u8 baro_ok;
	u8 gps_ok;
	u8 sonar_ok;
	u8 tof_ok;
	u8 of_ok;
	
} _sensor_hd_check_st; //Hardware
extern _sensor_hd_check_st sens_hd_check;

extern u16 throttle;
extern float offsetRoll,offsetPitch;

extern float kp_roll, kp_g_roll;																	//pid����
extern float kp_pitch,kp_g_pitch;
extern float kp_yaw,  kp_g_yaw;
extern float ki_roll, ki_g_roll;
extern float ki_pitch,ki_g_pitch;
extern float ki_yaw,  ki_g_yaw;
extern float kd_g_roll;
extern float kd_g_pitch;
extern float kd_g_yaw;
extern float kp_h,ki_h,kd_h;
extern float kp_x,ki_x,kd_x;
extern float kp_y,ki_y,kd_y;

void saveEEPROMData(void);
extern struct EEPROMData e2prom_value;
struct EEPROMData
{
	float offsetRoll;
	float offsetPitch;
	float kp_roll;
	float kp_pitch;
	float kp_yaw;
	float ki_roll;
	float ki_pitch;
	float ki_yaw;
	float kd_roll;
	float kd_pitch;
	float kd_yaw;
	float kp_g_roll;
	float kp_g_pitch;
	float kp_g_yaw;
	float ki_g_roll;
	float ki_g_pitch;
	float ki_g_yaw;	
	float kd_g_roll;
	float kd_g_pitch;
	float kd_g_yaw;
	float kp_h;
	float ki_h;
	float kd_h;
	float kp_x,ki_x,kd_x;
	float kp_y,ki_y,kd_y;
};



//��ʼ��
u8 All_init(void);
void initLED(void);
void initClock(void);
void initSysTick(void);
void initPWM(void);
void initUART(void);
void initEEPROM(void);
void initKey(void);
void initFlag(void);


//�ж�
void SysTickIntHandler(void);
void UART0_Handler(void);													
void UART1_Handler(void);
void UART5_Handler(void);

int fputc(int ch, FILE *f);	


//JY901
extern float roll,pitch,yaw;																							//�ֱ��ӦYXZ��ĽǶ�
extern float accX,accY,accZ;																							//���ٶ�XYZ����
extern float gyrX,gyrY,gyrZ;																							//���ٶ�XYZ����
													
void JY901_GetOneByte(uint8_t data);


//���
extern u32 moto1,moto2,moto3,moto4;
void motoRefresh(u32 moto11,u32 moto22,u32 moto33,u32 moto44);

//LED
void redLed(void);
void blueLed(void);
void greenLed(void);
void landLed(void);
void turnoffled(void);


//PID
extern float tarYaw;
extern u16 tarHeight;

extern float att_cal1,att_cal2,att_cal3,att_cal4;
extern float alt_cal1,alt_cal2,alt_cal3,alt_cal4;
extern float loc_cal1,loc_cal2,loc_cal3,loc_cal4;


void ATT_PID(void);
void LOC_PID(void);
void ALT_PID(void);




//���п���
void Auto_take_off(void);
void Auto_land(void);
void Auto_hover(void);
void safetyCheck(void);


//����
extern float roll_temp,pitch_temp,yaw_temp;																		//�ֱ��ӦYXZ��ĽǶ�

void motoCal(void);
void ATT_TEMP(void);



//����
extern uint8_t 	OF_QUA,OF_LIGHT;//������Ϣ������QUA ����ǿ�ȣ�LIGHT

extern int8_t	OF_DX,OF_DY;//ԭʼ������Ϣ���������������ģ���ֲ�

extern int16_t	OF_DX2,OF_DY2,OF_DX2FIX,OF_DY2FIX;//�ںϺ�Ĺ�����Ϣ���������������ģ���ֲ�

extern uint16_t	OF_ALT,OF_ALT2;//ԭʼ�߶���Ϣ���ںϺ�߶���Ϣ

extern int16_t	OF_GYR_X,OF_GYR_Y,OF_GYR_Z;//ԭʼ����������

extern int16_t	OF_GYR_X2,OF_GYR_Y2,OF_GYR_Z2;//�˲�������������

extern int16_t	OF_ACC_X,OF_ACC_Y,OF_ACC_Z;//ԭʼ���ٶ�����

extern int16_t	OF_ACC_X2,OF_ACC_Y2,OF_ACC_Z2;	//�˲�����ٶ�����

extern float	OF_ATT_ROL,OF_ATT_PIT,OF_ATT_YAW;	//ŷ���Ǹ�ʽ����̬����

extern float	OF_ATT_S1,OF_ATT_S2,OF_ATT_S3,OF_ATT_S4;	//��Ԫ����ʽ����̬����


void AnoOF_GetOneByte(uint8_t data);//��������Ψһһ����Ҫ�ⲿ���õĺ�������Ϊ����ģ���Ǵ����������
																		//���Ա�������Ҫ�ڴ��ڽ����ж��е��ã�ÿ����һ�ֽ����ݣ����ñ�����һ��
void AnoOF_DataAnl_Task(u8 dT_ms);
void AnoOF_Check(u8 dT_ms);


#endif
