2017.8.13  ���
2018.3.18  Aemaeth2501
//			SysCtlDelay(10 * (SysCtlClockGet() / 300));
uart1���ݴ����Ż�
FPU����
������λ�����ܴ����
NVIC�ж����ȼ����Ż�
�������ʹ��Ż�

����TM4C123GH6PM�����������������ϵͳ

APP: Ӧ�ò�

BSP: ����Ӳ����صĴ����װ��bsp�У�APP��ֻ���ýӿ�  

Lib: ����tiva��    include: driverlib
							utils 
							IQmath..
							
C/C++->DEFINE:  rvmdk PART_TM4C123GH6PM 
				TARGET_IS_TM4C123_RB1	//Ϊ��ʹ��ROM_FUNCTION();

Target: >Use MicroLib (fputc()printf())


UART0 (PA0 RX PA1 TX) for HC05/Simulation debugger to detect data,send command or adjust parameters;

UART1 (PB0 RX PB1 TX) for JY901 to get attitude;

UART5 () for ANO_LightFlow;


//UART3 (PC6 RX PC7 TX) for US100
//								  to get height;
//IIC1  (PA6 SCL PA7 SDA) for GY530 
//
//UART2 (PD6 RX PD7 TX)for navigation device;



[PF0 PD7 PC0 ע�����]http://bbs.21ic.com/forum.php?mod=viewthread&tid=1571214


PWM0 				PB6
PWM1				PB7
PWM2				PB4
PWM3				PB5

PWMperiod 4ms frequency 250hz 20000

����Ķ�: 

BSP:	http://blog.csdn.net/qsj8362234/article/details/6325761							