

/*-------------- Pinout ------------------------------ */

#define RL1 42      //Relé 1
#define RL2 41      //Relé 2
#define RL3 40      //Relé 3
#define RL4 39      //Relé 4
#define RL5 13      //Relé 5
#define RL6 12      //Relé 6

/*------------ Variavés de controle dos réles ---------------*/


const bool relayState = 0;                                 // 1 - Relé High, 0 - Relé Low
const byte relays_num = 6;                            // Numero de relés
byte relays[relays_num] = {RL1,RL2,RL3,RL4,RL5,RL6};   // Pinos dos relés


/*===============Função que seta os relés como output===================*/

        void setup_relay (){    /* Função para setar relés como output */
          for (byte i = 0; i < relays_num; i++){
            pinMode(relays[i], OUTPUT);
            digitalWrite(relays[i], LOW); 
            }
        }


/*===============Função que aciona os relés===================*/
        void relay_on() {
         for (byte i = 0; i < relays_num; i++) {
            bool relayState = bitRead(buffer08_value, i);
            digitalWrite(relays[i], relayState);
          }
        }
