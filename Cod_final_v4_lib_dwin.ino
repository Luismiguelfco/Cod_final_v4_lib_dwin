/*============ Código para controle de automação residencial v_1 =================*/
/*============ Autor: Luis Miguel - Manual Maker                 =================*/

/* Add IRremote.hpp ===> EEPROM.h ===> 01_Variables ===> 02_IR_Pin_Def ===> 03_EEPROM_Address ===> 04_Functions 
 *  
 *    void setup (){ 
  
 *    load_values ()                                    (Carrega valores EEPROM) 
 *    
 *      ===> Define Pinos Relés em Output }
 *  
 *  
 *    user Control {
 *      serial_read()                                   //Le a tela através da serial)
 *      
 *      0x5A 0x00 0x00 0x00 [0x50] 0x00 0x00 0x00 [0x00]
 *      
 *     void read_bt_tela (){                            // Função que le os botões pressionados na tela      
 *       serial_read() {                                // Função que le os valores na serial
 *       
 *       if (flag == true && Buffer[0] == 0X5A )        // Confirma Buffer [0]0x5A
 *      
 *      
 *        switch (Buffer[4]){                           // Compara o Buffer [4]
 *        
 *           Buffer04_Relay     = 0x50;
 *           Buffer04_TV        = 0x51;
 *           Buffer04_AC        = 0x52;
 *           Buffer04_Radio     = 0x53;
 *           Buffer04_SD        = 0x54;
 *           Buffer04_Bluetooth = 0x55;
 *        
 *           void buffer_check ()                         // Chama a função de leitura do Buffer [5] 
 *           
 *            for (int i = 0; i <= arraySize_bt_tela; i++)  // Incrementa até chegar no valor do buffer 05    
 *            
 *              
 *           
 *           Chama a Função respectiva ao Buffer [5] lido, comparando com o Buffer [4], i indica qual botão foi apertado dentro do primeiro Array, e chama o botão respectivo no segundo array
 *           Envia o hexa respectivo daquele botão através do IR
 *          
 *          Buffer[4]0X50
 *          Buffer[5]0X00 - 0X14 
 *          Buffer[4]0X51
 *          
 *          
 */


#include <EEPROM.h>
#include <IRremote.hpp>
#include <DWIN.h>

/*-------------- Carrega as paginas auxiliares ---------*/
#include "01_Variables.h"
#include "03_EEPROM.h"
#include "02_IR_Pin_Def.h"
#include "05_Functions_Relay.h"
#include "06_Functions_Radio.h"
#include "08_Functions_SD.h"
#include "09_Gen_Functions.h"


      void setup() {
          setup_relay();
          setup_radio();
          setup_SD();
          pinMode(config_button, INPUT);
          
          Serial.begin(115200);
          Serial1.begin   (115200, SERIAL_8N1, 43, 44);
          Serial2.begin   (9600, SERIAL_8N1, 18, 17);
          Serial.println("DWIN HMI ~ Hello World");

          
          hmi.echoEnabled(false);
          hmi.hmiCallBack(onHMIEvent);
          hmi.setPage(1);
          IrSender.begin(IR_SEND_PIN);
               }



        void loop() {
          hmi.listen();
          audio.loop();

                }

   

    
