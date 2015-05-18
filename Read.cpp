#include "MFRC522.h"

MFRC522::MIFARE_Key key;

int main(){
  MFRC522 mfrc;

  mfrc.PCD_Init();

  while(1){
    // Look for a card
    if(!mfrc.PICC_IsNewCardPresent())
      continue;

    if( !mfrc.PICC_ReadCardSerial())
      continue;

    // Print UID
    for(byte i = 0; i < mfrc.uid.size; ++i){
      if(mfrc.uid.uidByte[i] < 0x10){
	printf(" 0");
	printf("%X",mfrc.uid.uidByte[i]);
      }
      else{
	printf(" ");
	printf("&X", mfrc.uid.uidByte[i]);
      }
      
    }
    
  }
  return 0;
}
