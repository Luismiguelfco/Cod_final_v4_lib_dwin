/*--- Pagina para definir variaveis de botões de todos os dispositivos----*/
  
  
  #define DEBAG 1               // Debugging: 1 - on, 0 - off
  #define config_button 0    //Botão de config do admin
  
  #define DGUS_BAUD     115200
  #define DGUS_SERIAL   Serial1
  DWIN hmi(DGUS_SERIAL, 43, 44, DGUS_BAUD);
  

  /* Variaveis do Buffer [4] */
  
  #define Buffer04_Relay      0x50
  #define Buffer04_TV         0x51
  #define Buffer04_SD         0x52
  #define Buffer04_Radio      0x53
  #define Buffer04_AC         0x54
  #define Buffer04_Bluetooth  0x55
  
 
  
  uint32_t  leitura;                  /*------- Variavel que armazena leitura do led do controle-------*/
  uint16_t  buffer04_value;
  uint16_t  buffer05_value;
  uint8_t   buffer08_value;


  /* Valores gerais dos botões das telas Dwin - Envia da tela para o ESP (Input)Buffer [5] */
  #define bt1_t1    0x00   //Botão 1
  #define bt2_t1    0x01   //Botão 2
  #define bt3_t1    0x02   //Botão 3
  #define bt4_t1    0x03   //Botão 4
  #define bt5_t1    0x04
  #define bt6_t1    0x05
  #define bt7_t1    0x06
  #define bt8_t1    0x07
  #define bt9_t1    0x08
  #define bt10_t1   0x09
  #define bt11_t1   0x010
  #define bt12_t1   0x011
  #define bt13_t1   0x012
  #define bt14_t1   0x013
  #define bt15_t1   0x014
  #define bt16_t1   0x016


 

/*Valores do botão do controle da TV - Output(Envia do Esp para a IR TV*/
  uint32_t out_bt1_tv = 0x0000FF00;   //Botão Canal +
  uint32_t out_bt2_tv = 0xF20DFF00;   //Botão Canal -
  uint32_t out_bt3_tv = 0xF10EFF00;   //Botão On
  uint32_t out_bt4_tv = 0xE718FF00;   //Botão <
  uint32_t out_bt5_tv = 0xEA15FF00;   //Botão Sair
  uint32_t out_bt6_tv = 0xEB14FF00;   //Botão ^ (seta p/ cima)
  uint32_t out_bt7_tv = 0xE916FF00;   //Botão v (seta p/ baixo)   
  uint32_t out_bt8_tv = 0xE619FF00;   //Botão ok
  uint32_t out_bt9_tv = 0xE619FF00;   //Botão Off
  uint32_t out_bt10_tv = 0xE619FF00;   //Botão >
  uint32_t out_bt11_tv = 0xE619FF00;   //Botão Voltar
  uint32_t out_bt12_tv = 0xE619FF00;   //Botão Smart
  uint32_t out_bt13_tv = 0xE619FF00;   //Botão Vol +
  uint32_t out_bt14_tv = 0xE619FF00;   //Botão Vol -


  

  /*Valores do botão do controle do AC - Output (Envia do ESP para o IR AC*/
  uint32_t out_bt1_ac = 0x0000;       //Botão On
  uint32_t out_bt2_ac = 0xF20D;       //Botão Off
  uint32_t out_bt3_ac = 0xF10E;       //Botão Temp +
  uint32_t out_bt4_ac = 0xE718;       // Botão Temp -
  uint32_t out_bt5_ac = 0xEA15;
  uint32_t out_bt6_ac = 0xEB14;
  uint32_t out_bt7_ac = 0xE916;
  uint32_t out_bt8_ac = 0xE619;
  uint32_t out_bt9_ac = 0xE619;
  uint32_t out_bt10_ac = 0xE619;
  uint32_t out_bt11_ac = 0xE619;
  uint32_t out_bt12_ac = 0xE619;
  uint32_t out_bt13_ac = 0xE619;
  uint32_t out_bt14_ac = 0xE619; 





  
  /*Valores da tela Dwin para enviar ao modulo de radio - Output(Envia do ESP para o modulo do radio)*/
  #define bt_radio_previous   0x00    // Botão <
  #define bt_radio_next       0x01    // Botão >
  #define bt_radio_on         0x02   // Botão On/Off  
  #define bt_radio_vol_mais   0x03    // Botão Vol +
  #define bt_radio_vol_menos  0x04    // Botão Vol -
  #define bt_radio_find_down  0x05    // Procurar estações a esquerda
  #define bt_radio_find_up    0x06    // Procurar estações a direita
  #define bt_radio_add_fav    0x07    // Salva estação atual nas estações favoritas




  /*Valores para acionamento modulo Bluetooth - Output(Envia do ESP para o modulo bluetooth)*/
  String  bt1_blth   = "COM+PWOS\r\n" ;  //Botão Liga
  String  bt2_blth   = "COM+PWDS\r\n" ;  //Botão Desliga
  String  bt3_blth   = "COM+PV\r\n" ;    //Botão faixa anterior
  String  bt4_blth   = "COM+PP\r\n" ;    //Botão Play/pause
  String  bt5_blth   = "COM+PN\r\n" ;    //Botão Proxima faixa
  String  bt6_blth   = "COM+VP\r\n" ;    //Botão Volume +
  String  bt7_blth   = "COM+VD\r\n" ;    //Botão Volume -
  



  /*Valores para acionamento modulo SD - Output(Envia do ESP para selecionar a musica no SD)*/
  String  out_bt1_SD   = "COM+MSD\r\n" ;   //Botão Mode
  String  out_bt2_SD   = "COM+PP\r\n" ;    //Botão Play/pause
  String  out_bt3_SD   = "COM+VP\r\n" ;    //Botão Volume +
  String  out_bt4_SD   = "COM+VD\r\n" ;    //Botão Volume -
  






  /*Arrays do Buffer[5]*/
  
  uint16_t array_bt_tela[] =             {bt1_t1,         bt2_t1,     bt3_t1,     bt4_t1,   bt5_t1,   bt6_t1,   bt7_t1,   bt8_t1,   bt9_t1,   bt10_t1, bt11_t1, bt12_t1, bt13_t1, bt14_t1, bt15_t1, bt16_t1,};                                           /* Array de Valores hexadecimais dos botões da tela no Buffer 5 -  Input*/
  
  uint32_t array_bt_controle_TV[] =      {out_bt1_tv,     out_bt2_tv, out_bt3_tv, out_bt4_tv, out_bt5_tv};                                    /* Array de Valores hexadecimais dos botões do controle da TV - Output */
  
  uint32_t array_bt_controle_AC[] =      {out_bt1_ac,     out_bt2_ac, out_bt3_ac, out_bt4_ac, out_bt5_ac};                                    /* Array de Valores hexadecimais dos botões do controle da AC - Output*/
  
  uint32_t array_bt_controle_radio[] =   {bt_radio_previous, bt_radio_next, bt_radio_on, bt_radio_vol_mais, bt_radio_vol_menos};           /* Array de Valores hexadecimais dos botões da Radio - Output */
  
  String   array_command_bluetooth[] =   {bt1_blth,   bt2_blth,   bt3_blth,   bt4_blth, bt5_blth, bt6_blth, bt7_blth};                        /* Array de Strings dos controles dos botões do bluetooth    - utput*/

  String   array_bt_sd []  =             {out_bt1_SD, out_bt2_SD, out_bt3_SD, out_bt4_SD};

  int arraySize_bt_tela = sizeof(array_bt_tela) / sizeof(array_bt_tela[0]);
