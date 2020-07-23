#ifndef __KEY_H
#define __KEY_H	 
#include "sys.h"
#include "stm32f10x.h"
#include "stm32f10x_gpio.h" 
typedef struct // ���찴����ʼ����
{
	GPIOMode_TypeDef GPIO_Mode; // ��ʼ������ģʽ
	GPIO_TypeDef* GPIOx; // ��ʼ��������
	uint16_t GPIO_Pin_x; // ��ʼ���������ź�
	uint32_t RCC_APB2Periph_GPIOx; // ��ʼ��ʱ��
}Key_Init;

typedef enum _KEY_STATUS_LIST // ����״̬
{
	KEY_NULL = 0x00, // �޶���
	KEY_SURE = 0x01, // ȷ��״̬
	KEY_UP   = 0x02, // ����̧��
	KEY_DOWN = 0x04, // ��������
	KEY_LONG = 0x08, // ����
}KEY_STATUS_LIST;

typedef struct _KEY_COMPONENTS // ״̬����
{
    FunctionalState KEY_SHIELD; //�������Σ�DISABLE(0):���Σ�ENABLE(1):������
	uint8_t KEY_COUNT;        	//������������
    BitAction KEY_LEVEL;        //���հ���״̬������Bit_SET(1)��̧��Bit_RESET(0)
    BitAction KEY_DOWN_LEVEL;   //����ʱ������IOʵ�ʵĵ�ƽ
    KEY_STATUS_LIST KEY_STATUS;       //����״̬
    KEY_STATUS_LIST KEY_EVENT;        //�����¼�
    BitAction (*READ_PIN)(Key_Init Key);//��IO��ƽ����
}KEY_COMPONENTS;


typedef struct // ������
{
	Key_Init Key; // �̳г�ʼ������
	KEY_COMPONENTS Status; // �̳�״̬������
}Key_Config;


typedef enum // ����ע���
{
	CH1Left,
	CH1Right,
	CH2Up,
	CH2Down,
	CH4Left,
	CH4Right,// �û����ӵİ�ť����
	KEY_NUM, // ����Ҫ�еļ�¼��ť���������������
}KEY_LIST;


void KEY_Init(void);//IO��ʼ��
void Creat_Key(Key_Init* Init); // ��ʼ����ť����
void ReadKeyStatus(void); // ״̬������
void TIM3_Init(u16 arr,u16 psc);
#endif