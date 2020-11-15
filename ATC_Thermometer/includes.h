#ifndef _INCLUDES_H_
#define _INCLUDES_H_

//void app_enter_ota_mode(void);

// from battery.c
uint16_t get_battery_mv(void);
uint8_t get_battery_level(uint16_t battery_mv);

// from ble.c
void init_ble(void);
bool ble_get_connected(void);
void ble_send_temp(uint16_t temp);
void set_adv_data(int16_t temp);
void blt_pm_proc(void);

// from sensor.c
void init_sensor(void);

// from lcd.c
void init_lcd(void);
void send_to_lcd_long(uint8_t byte1, uint8_t byte2, uint8_t byte3, uint8_t byte4, uint8_t byte5, uint8_t byte6);
void show_atc_mac(void);
void show_big_number(int16_t number, bool point);
void show_temp_symbol(uint8_t symbol);
void show_dashes(void);
void show_smiley(uint8_t state);
void show_battery_symbol(bool state);
void show_ble_symbol(bool state);
void update_lcd(void);

// from flash.c
void init_flash(void);

// from i2c.c
void init_i2c(void);
void send_i2c(uint8_t device_id, const uint8_t *buffer, int dataLen);

// from cmd_parser.c
void cmd_parser(void * p);

#endif /* _INCLUDES_H */