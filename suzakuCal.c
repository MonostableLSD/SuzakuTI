#include "userDefine.h"

void ATT_TEMP()
{	
	static u8 cnt=0;
	static float sum_yaw=0;
	if(flag.set_yaw==0) 		//��ȡ��ʼyaw��
	{	
		cnt++;
		sum_yaw+=yaw;
		if(cnt==5)
		{
			tarYaw=sum_yaw/5;
			flag.set_yaw=1;
		}
	}
	roll_temp=roll-offsetRoll;
	pitch_temp=pitch-offsetPitch;
	yaw_temp=yaw-tarYaw;
	
}
void motoCal()		//��ʱ����ĳһ���� ȡ�����Ƿ���ֵ������moto�� ��tick��ı�flag�Դ˿��ƿ��Ƶ���������
{
	static u8 flightMode=0;
	if(flag.ct_att_hold&&!flag.ct_alt_hold&&!flag.ct_loc_hold)	flightMode=1;				//ֻ����̬����
	
	else if(flag.ct_att_hold && flag.ct_alt_hold&&!flag.ct_loc_hold) flightMode=2;	//��̬+�߶�
	
	else if(flag.ct_att_hold&&flag.ct_alt_hold&&flag.ct_loc_hold)	flightMode=3;			//��̬+�߶�+λ��
	
	else if(!flag.ct_att_hold&&flag.ct_alt_hold&&!flag.ct_loc_hold)flightMode=4; //ֻ�и߶ȿ��� Ŀ��߶�30cm
	else if(!flag.ct_att_hold&&!flag.ct_alt_hold&&flag.ct_loc_hold)	flightMode=5; //ֻ��λ�ÿ���
	else if(!flag.ct_att_hold&&!flag.ct_alt_hold&&!flag.ct_loc_hold) flightMode=6; //�������κο��� ������
	switch (flightMode)
	{
		case 1:		//ֻ����̬���� 41
					moto1=(u32)(MIN_PWMPULSE+att_cal1+throttle);
					moto2=(u32)(MIN_PWMPULSE+att_cal2+throttle);	
					moto3=(u32)(MIN_PWMPULSE+att_cal3+throttle);	
					moto4=(u32)(MIN_PWMPULSE+att_cal4+throttle);	
		
		break;
		
		case 2:	//��̬+�߶� 44
					moto1=(u32)(MIN_PWMPULSE+att_cal1+alt_cal1+throttle);
					moto2=(u32)(MIN_PWMPULSE+att_cal2+alt_cal2+throttle);
					moto3=(u32)(MIN_PWMPULSE+att_cal3+alt_cal3+throttle);
					moto4=(u32)(MIN_PWMPULSE+att_cal4+alt_cal4+throttle);	
		break;
		
		case 3://��̬+�߶�+λ�� 45
					moto1=(u32)(MIN_PWMPULSE+att_cal1+alt_cal1+loc_cal1+throttle);
					moto2=(u32)(MIN_PWMPULSE+att_cal2+alt_cal2+loc_cal2+throttle);
					moto3=(u32)(MIN_PWMPULSE+att_cal3+alt_cal3+loc_cal3+throttle);
					moto4=(u32)(MIN_PWMPULSE+att_cal4+alt_cal4+loc_cal4+throttle);	
		break;
		
		case 4://ֻ�и߶ȿ��� Ŀ��߶�30cm  42
					moto1=(u32)(MIN_PWMPULSE+alt_cal1+throttle);
					moto2=(u32)(MIN_PWMPULSE+alt_cal2+throttle);
					moto3=(u32)(MIN_PWMPULSE+alt_cal3+throttle);
					moto4=(u32)(MIN_PWMPULSE+alt_cal4+throttle);	
			break;
		
		case 5://ֻ��λ�ÿ��� 43
					moto1=(u32)(MIN_PWMPULSE+loc_cal1+throttle);
					moto2=(u32)(MIN_PWMPULSE+loc_cal2+throttle);
					moto3=(u32)(MIN_PWMPULSE+loc_cal3+throttle);
					moto4=(u32)(MIN_PWMPULSE+loc_cal4+throttle);	
			break;
		
		case 6:	//�������κο��� ������
					moto1=(u32)(MIN_PWMPULSE+throttle);	
					moto2=(u32)(MIN_PWMPULSE+throttle);	
					moto3=(u32)(MIN_PWMPULSE+throttle);	
					moto4=(u32)(MIN_PWMPULSE+throttle);	
		break;
			  
	}

}
