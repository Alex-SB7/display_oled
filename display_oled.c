#include <stdlib.h>
#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/i2c.h"
#include "inc/ssd1306.h"
#include "inc/font.h"
#include "hardware/adc.h"      

#define I2C_PORT i2c1
#define I2C_SDA 14
#define I2C_SCL 15
#define endereco 0x3C

float v_max = 3.3, v_out = 0.0, 
      v_min = 0.0, js_max = 4096.0, 
      js_in = 0.0, js_min = 0.0;

char var_string[20];


int main()
{
  stdio_init_all();
  sleep_ms(200);

  //Configuração do canal AD
  adc_init();
  adc_gpio_init(26);
  adc_select_input(0);


  // I2C Initialisation. Using it at 400Khz.
  i2c_init(I2C_PORT, 400 * 1000);

  gpio_set_function(I2C_SDA, GPIO_FUNC_I2C); // Set the GPIO pin function to I2C
  gpio_set_function(I2C_SCL, GPIO_FUNC_I2C); // Set the GPIO pin function to I2C
  gpio_pull_up(I2C_SDA); // Pull up the data line
  gpio_pull_up(I2C_SCL); // Pull up the clock line
  ssd1306_t ssd; // Inicializa a estrutura do display
  ssd1306_init(&ssd, WIDTH, HEIGHT, false, endereco, I2C_PORT); // Inicializa o display
  ssd1306_config(&ssd); // Configura o display
  ssd1306_send_data(&ssd); // Envia os dados para o display

  // Limpa o display. O display inicia com todos os pixels apagados.
  ssd1306_fill(&ssd, false);
  ssd1306_send_data(&ssd);

  bool cor = true;
  while (true)
  {
    js_in = adc_read();
            
    if (js_in < js_min)
      {
        v_out = v_min;
      }
      else if(js_in > js_max)
      {
        v_out = v_max;
      }
      else
      {
        v_out = ((js_in - js_min)*(v_max - v_min))/(js_max - js_min) + v_min;   
      }

    
    sprintf(var_string, "%.2f", v_out);

    
    // Atualiza o conteúdo do display
    ssd1306_fill(&ssd, !cor); // Limpa o display
    ssd1306_rect(&ssd, 0, 0, 128, 63, !cor, !cor); 
    ssd1306_draw_string(&ssd, "UNIVASF   ELET", 8, 10); 
    ssd1306_draw_string(&ssd, "MICRO", 40, 20); 
    ssd1306_draw_string(&ssd, var_string, 40, 45);
    ssd1306_pixel(&ssd, 49, 51, cor);
    ssd1306_draw_string(&ssd, "V", 75, 45);
    ssd1306_send_data(&ssd); // Atualiza o display

    sleep_ms(100);
  }
}