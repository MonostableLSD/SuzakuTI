#include "userDefine.h"
//void ATT_Ctrl()
//{
//	flag.ct_att_hold=1;
//	flag.ct_alt_hold=0;
//	flag.ct_loc_hold=0;
//}
//void ATL_Ctrl()
//{	
//	flag.ct_att_hold=0;
//	flag.ct_alt_hold=1;
//	flag.ct_loc_hold=0;
//}
//void LOC_Ctrl()
//{
//	flag.ct_att_hold=0;
//	flag.ct_alt_hold=0;
//	flag.ct_loc_hold=1;
//}

//ͨ������FLAG.ATT//ALT(TAR_HEIGHT)//LOC_HOLD
void Auto_take_off()	//����̬�Զ���� tarHeight increase
{
//	if(OF_ALT2<7)
//	{

//		//ATT_Ctrl();

//	
//	}
}				

//�ж��Զ�����flag ���жϸ߶� ���С��20 ��ôflag stop �� ͣ������
void Auto_land()			//����̬�Զ�����
{
		static u8 i=0;
		if((tarHeight-2)<OF_ALT2)//��������һ����־λ�ж� �����������tar_height-5 6�� ��ô�Զ�����flag�� 
						{	i++;
							if(i>20)
								{
								//	printf("flag.landing=1");
									flag.landing=1;
									i=0;
								}
						}
					if(flag.landing==1&&OF_ALT2<20)
					{
//							flag.all_stop=1;
			redLed();//Red LED means "all stop"
			motoRefresh(MIN_PWMPULSE,MIN_PWMPULSE,MIN_PWMPULSE,MIN_PWMPULSE);
			ROM_IntMasterDisable();
					}
					
					//ATT_Ctrl();
	//if(OF_ALT2>2) TAR_HEIGHT--; ���ܻ��ͺ�
	//else if(OF_ALT2<=2) 
	//			
	//			motoRefresh(MIN_PWMPULSE,MIN_PWMPULSE,MIN_PWMPULSE,MIN_PWMPULSE);
		
}
void Auto_hover()			//��ͣ tarHeight=30
{
		//ATT_Ctrl();
		//Height_Ctrl();
		//Loc_Ctrl();
}

void safetyCheck()		//��ȫ��� ����ֹͣ
{ static u8 i=0;
	if(fabs(roll)>30||fabs(pitch)>30||OF_ALT2>120||flag.all_stop==1)
	{
//		printf("sc");
		i++;
		if(i==3)
		{
			i=0;
		//	printf("stop");
			redLed();//Red LED means "all stop"
			motoRefresh(MIN_PWMPULSE,MIN_PWMPULSE,MIN_PWMPULSE,MIN_PWMPULSE);
			ROM_IntMasterDisable();
		}
	}
	
}
