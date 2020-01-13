 #include "./esppl_functions.h"

/*
 * variable to time in millisecons waiting 
 */
int period = 10000;
int time_now = 0;
/*
 * Define you friend's list size here
 */
#define LIST_SIZE 2
/*
 * This is your friend's MAC address list
 */
uint8_t friendmac[LIST_SIZE][ESPPL_MAC_LEN] = {
   {0x3C, 0x71, 0xBF, 0x39, 0xAB, 0x4C}
  ,{0x84, 0x0D, 0x8E, 0x83, 0xF2, 0x16}
  };

/*
 * This is your friend's name list
 * put them in the same order as the MAC addresses
 */
String friendname[LIST_SIZE] = {
   "WEMOS1"
  ,"WEMOS2"
  };

/*
 * Define you the Relay pin
 */
const int PinRelay = 5;
boolean PinRelayStatus = false;

bool maccmp(uint8_t *mac1, uint8_t *mac2) {
  for (int i=0; i < ESPPL_MAC_LEN; i++) {
    if (mac1[i] != mac2[i]) {
      return false;
    }
  }
  return true;
}

void cb(esppl_frame_info *info) {
  for (int i=0; i<LIST_SIZE; i++) {
    if (maccmp(info->sourceaddr, friendmac[i]) || maccmp(info->receiveraddr, friendmac[i])) {
      Serial.printf("\n%s is here! :)", friendname[i].c_str());
//      digitalWrite(PinRelay, HIGH );
//      Serial.println("Relay on");      
      PinRelayStatus = true; 
    }
  }
}

void setup() {
  Serial.begin(115200);
  esppl_init(cb);

  /* Initialize RELAY */
  pinMode(PinRelay , OUTPUT);
}

void loop() {
  esppl_sniffing_start();
  PinRelayStatus = false;
  while (true) {
    for (int i = ESPPL_CHANNEL_MIN; i <= ESPPL_CHANNEL_MAX; i++ ) {
      esppl_set_channel(i);
      while (esppl_process_frames()) {
        //
      }
    }
    if (PinRelayStatus) {
      digitalWrite(PinRelay, HIGH );
      Serial.println("Relay on");        
      delay(1000);
      digitalWrite(PinRelay, LOW );
      Serial.println("Relay off");      
      delay(30000);
      Serial.println("Scanning...");
      PinRelayStatus = false;
    }
  }  
}
