
/*Endereços da EEPROM */

/* Endereços do controle remoto da TV */
uint16_t array_addr_TV [] = {0,2,4,6,8,10,14,16,18,20,22,24,26,28};
uint16_t array_addr_AC [] = {0,2,4,6,8,10,14,16,18,20,22,24,26,28};

int addr_bt1 = 0;
int addr_bt2 = 2;
int addr_bt3 = 4;
int addr_bt4 = 6;
int addr_bt5 = 8;
int addr_bt6 = 10;
int addr_bt7 = 14;
int addr_bt8 = 16;
int addr_bt9 = 18;
int addr_bt10 = 20;
int addr_bt11 = 22;
int addr_bt12 = 24;
int addr_bt13 = 26;
int addr_bt14 = 28;

/* Endereços das estações de radio */
int addr_radio1 = 0;
int addr_radio2 = 2;
int addr_radio3 = 4;
int addr_radio4 = 6;
int addr_radio5 = 8;
int addr_radio6 = 10;
int addr_radio7 = 14;
int addr_radio8 = 16;
int addr_radio9 = 18;
int addr_radio10 = 20;



unsigned int eeprom_array[] =    {addr_bt1, addr_bt2, addr_bt3, addr_bt4, addr_bt5};       /* Valores dos endereços da EEPROM que salva os valores do controle da TV */
int arraySize_eeprom_array = sizeof(eeprom_array) / sizeof(eeprom_array[0]); 


      /* Função para gravar o botão na EEPROM */
      
            void gravarEEPROM(uint16_t bt_eeprom, int addr ){
              
                byte hiByte = highByte(bt_eeprom);
                byte loByte = lowByte(bt_eeprom);
                EEPROM.write(addr, hiByte);
                EEPROM.write(addr+1, loByte);
                Serial.print("Gravado - ");
                Serial.print("botão = "); 
                Serial.println(bt_eeprom, HEX);  
    
          }





        
  
      /* Função para ler o botão gravado na EEPROM */
      
           uint16_t lerEEPROM(int addr) {
                byte hiByte;
                byte loByte;
                EEPROM.get(addr,hiByte);
                EEPROM.get(addr+1,loByte);
                leitura  = word(hiByte, loByte);
                return leitura;
      
      }



    
    
    /* Função que carrega o endereço dos botões da EEPROM */
    
      void load_values(){
          for (int i = 0; i < 30; i++){
              array_bt_controle_TV[i] = array_addr_TV [i];
              array_bt_controle_AC[i] = array_addr_AC [i];
          }

    }
