     bool isBuffer4Processed = false;       


/*========================Faz a leitura da Serial da tela===============================*/


         void buffer_check (uint16_t buffer4, uint16_t buffer5){
     
            if (buffer4 == Buffer04_Relay){                                             /* Se for botão do relé, executa o comando unico */
              relay_on ();
            }
            
            else {
              for (int i = 0; i <= arraySize_bt_tela; i++) {                            /* Incrementa i enquanto não chegar no tamanho maximo do array */
                                                                                        /* Buffer [5] 0x5A 0x00 0x00 0x00 0x51 [0x00]  */
                    if (buffer5 == array_bt_tela[i]){                                   /* Checa qual botão do array foi apertado, então cruza com o buffer4 para executar a função respectiva.*/ 
                      Serial.println(buffer5,HEX);
                      switch (buffer4) {
                                  
                        case Buffer04_TV:
                        //(array_bt_controle_TV [i],eeprom_array[i])                                  //send_save_IR  (array_bt_controle_TV [i],eeprom_array[i]);         /* Função que executa o envio do hexa via IR e gravação na EEPROM*/
                        IrSender.sendNECRaw(array_bt_controle_TV [i],0);
                        Serial.println     (array_bt_controle_TV [i], HEX);
                        break ;                                                           /* Envia a posição do botão no array e o endereço da EEPROM */
    
                        case Buffer04_AC:
                        //send_save_IR  (array_bt_controle_AC [i],eeprom_array[i]);           /* Função que executa o envio do hexa via IR e gravação na EEPROM*/
                        break ;                                                             /* Envia o valor do botão do controle e o endereço da EEPROM */   
    
    
                        case Buffer04_Radio:

                        radio_actions (array_bt_controle_radio[i]); 
                        break;
    
                        case Buffer04_SD:
                        radio.setVolume(0);
                        radio.setMute(1);
                        send_SD_serial (array_bt_sd [i]);
                        break;     

                        case Buffer04_Bluetooth:
                        //send_bluetooth_serial (array_command_bluetooth[i]);
                        radio.setMute(1);
                        Serial.print (array_command_bluetooth[i]);
                        Serial2.print (array_command_bluetooth[i]);
                        break;
                        }
                   
                   break;
                        } 
                     }     
                }
              isBuffer4Processed = true;
            }


         
        
        void onHMIEvent(String address,int lastByte,String message,String response){  
          Serial.println("OnEvent : [ A : " + address + " | D : "+String (lastByte, DEC)+ " | M : "+message+" | R : "+response+ " ]"); 
    
           buffer04_value = strtol((address.substring(0, 2)).c_str(), NULL, 16); // Converte para uint16_t a partir da string em hexadecimal
           buffer05_value = strtol((address.substring(2, 4)).c_str(), NULL, 16); // Converte para uint16_t a partir da string em hexadecimal
           buffer08_value = lastByte; 
           
           buffer_check(buffer04_value, buffer05_value);
        }   

        
