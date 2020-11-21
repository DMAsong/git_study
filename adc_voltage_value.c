#include <stdio.h>
#define uint8_t unsigned char
#define uint16_t unsigned short
#define uint32_t unsigned int

#define TEST_V 3300
#define ADC_MAX 4095

enum
{
	ADC_TO_V = 0,
	V_TO_ADC,
};
uint32_t voltage_adc(uint16_t data , uint8_t mode)
{
	uint32_t buf;
	if(mode)
	{
		buf = data * ADC_MAX/ TEST_V;
		printf("adc_vlaue = 0x%x \n",buf);
	}
	else
	{
		buf = data * TEST_V/ ADC_MAX;
		printf("dianya = %d mv\n",buf);		
	}
	return buf;
}

int main(void)
{
	uint32_t vv;
	uint32_t add;
	uint32_t dec;
	uint16_t inc = 500; 
	vv = voltage_adc(0x707,ADC_TO_V);
	add = vv+inc;
	voltage_adc(add,V_TO_ADC);
	dec = vv-inc;
	voltage_adc(dec,V_TO_ADC);
	printf("ok\n");
	return 0;
}