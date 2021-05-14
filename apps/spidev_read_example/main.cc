// Copyright (C) 2021 twyleg
#include "spidev_impl.h"
#include "sys_gpio_impl.h"

#include <mfrc522/mfrc522.h>
#include <spidevpp/gpio.h>

#include <iostream>
#include <thread>
#include <chrono>

using namespace std::literals::chrono_literals;

int main(int argc, char *argv[]) {

	Spidev spi("/dev/spidev0.0");
	spi.mSpi.setBitsPerWord(8);
	spi.mSpi.setSpeed(488000);
	spi.mSpi.setMode(0);

	std::cout << spi.mSpi << std::endl;

	SysGpio resetPin(25, spidevpp::Gpio::Direction::OUTPUT, spidevpp::Gpio::Value::LOW);

	mfrc522::MFRC522 mfrc(spi, resetPin);
	mfrc.PCD_Init();

	std::cout << "Start read loop!" << std::endl;

	while (1){
		// Look for a card
		if (!mfrc.PICC_IsNewCardPresent()) {
			std::this_thread::sleep_for(1000ms);
			continue;
		}

		if (!mfrc.PICC_ReadCardSerial()) {
			continue;
		}

		// Print UID
		for (uint8_t i = 0; i < mfrc.uid.size; ++i) {
			if (mfrc.uid.uidByte[i] < 0x10) {
				printf(" 0");
				printf("%X",mfrc.uid.uidByte[i]);
			} else {
				printf(" ");
				printf("%X", mfrc.uid.uidByte[i]);
			}
		}
		printf("\n");
		std::this_thread::sleep_for(1000ms);
	}
	return 0;
}
