#include <stdint.h>
#include "tl_common.h"
#include "stack/ble/ble.h"
#include "vendor/common/blt_common.h"

extern bool advertising_type;
extern bool temp_C_or_F;
extern bool blinking_smiley;
extern bool show_batt_enabled;
extern uint8_t advertising_interval;
extern int8_t temp_offset;
extern int8_t humi_offset;
extern uint8_t temp_alarm_point;
extern uint8_t humi_alarm_point;
void cmd_parser(void * p){
	rf_packet_att_data_t *req = (rf_packet_att_data_t*)p;
	uint8_t inData = req->dat[0];
    if(inData == 0xB1){
		show_batt_enabled = true;//Enable battery on LCD
	}else if(inData == 0xB0){
		show_batt_enabled = false;//Disable battery on LCD
	}else if(inData == 0xFE){
		advertising_interval = req->dat[1];//Set advertising interval with second byte, value*10second / 0=main_delay
	}else if(inData == 0xFC){
		temp_alarm_point = req->dat[1];//Set temp alarm point value divided by 10 for temp in °C
		if(temp_alarm_point==0)temp_alarm_point = 1;
	}
}