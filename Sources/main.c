#include "uart_lcd.c"

int main(){
  led_uart0_interface_init();
  char temp[] = "Hello World!";
  led_print_string(temp);
  return 0;
}
