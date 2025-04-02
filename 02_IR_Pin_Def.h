#include <Arduino.h>

#define IR_RECEIVE_PIN 2  // GPIO2
#define IR_SEND_PIN    1  // GPIO4






          /*========================Função para ler e gravar botão do controle através de IR===============================*/   

      uint32_t  ler_botao(){
        uint32_t leitura2 = 0;    //Segunda leitura para conferencia do valor do led do controle
        
        while (leitura == 0) {  // Le a primeira vez o IR
          if (IrReceiver.decode()) { 
            leitura = ((IrReceiver.decodedIRData.decodedRawData));
            
            if (leitura != 0){
              Serial.println(leitura, HEX);}    
              IrReceiver.resume();}                
              Serial.println("Pressione o botão");
              }
  
            while (leitura2 == 0) {  // Le a segunda vez o IR
              if (IrReceiver.decode()) { 
                leitura2 = ((IrReceiver.decodedIRData.decodedRawData));  
                           
                if (leitura2 != 0){                   
                  leitura2 = ((IrReceiver.decodedIRData.decodedRawData));
                  Serial.println(leitura2, HEX);}   
                  IrReceiver.resume();}  
                  Serial.println("Pressione Novamente");
                }
      
        if (leitura == leitura2) 
         {                                  //Se as duas leituras forem iguais, grava o valor na variavel leitura 
          return leitura; 
         }
        else {
           ler_botao ();   
        
    }
   }



      /*========================Função que executa o envio do hexa via IR e gravação na EEPROM===============================*/

        void send_save_IR (uint32_t bt_value, uint16_t eeprom_addr){                    
//           //if (digitalRead(config_button) == LOW){
//              Serial.println(bt_value,HEX);
//              IrSender.sendNECRaw(bt_value,IR_SEND_PIN);                                  /* Se o user mode estiver ativado, só envia o valor do botão via IR */
//              void loop ();
////                }                   
////           else{                                                                         /* Se o Config mode estiver ativado, lê o valor do botão e grava na eeprom */
////               bt_value = ler_botao();
////               gravarEEPROM(bt_value,eeprom_addr);  
////                      }                  
                  } 
