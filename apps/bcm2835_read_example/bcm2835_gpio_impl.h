// Copyright (C) 2021 twyleg
#pragma once

#include "bcm2835.h"

#include <mfrc522/igpio.h>

#include <iostream>

class BcmGpio : public mfrc522::IGpio{

public:
	BcmGpio(unsigned int pin)
		: mPin(pin)
	{
		bcm2835_gpio_fsel(pin, BCM2835_GPIO_FSEL_OUTP);
		bcm2835_gpio_write(pin, 0x00);
	}

	void setValue(Value value) final {
		switch (value) {
		case mfrc522::IGpio::Value::LOW:
			bcm2835_gpio_write(mPin, 0x00);
			break;
		case mfrc522::IGpio::Value::HIGH:
			bcm2835_gpio_write(mPin, 0x01);
			break;
		}

	}

	Value getValue() final {
		return mfrc522::IGpio::Value::LOW;
	}

private:

	const unsigned int mPin;

};
