

// Adapted from (https://github.com/robvanbentem/pic-1wire) 

#include "mcc_generated_files/mcc.h"
#include "onewire.h"
#include <xc.h>



/**
 * Drive bus low, delay 480 ?s.
 * Release bus, delay 70 ?s.
 * Sample bus: 0 = device(s) present, 1 = no device present
 * Delay 410 ?s.
 */
char ow_reset() {
    OWOUT;
    DELAY_microseconds(480); // wait for 480us+

    OWIN;
    DELAY_microseconds(70);

    short response = (OWPIN == 0);
    DELAY_microseconds(410);

    return response;
}

/*
 * Drive bus low.
 * Write 1: delay 6 ?s. Release bus, delay 64 ?s.
 * Write 0: delay 60 ?s. Release bus, delay 10 ?s.
 */
void ow_write_bit(char b) {
    OWOUT;

    if (b) {
        DELAY_microseconds(6);
        OWIN;
        DELAY_microseconds(64);
    } else {
        DELAY_microseconds(60);
        OWIN;
        DELAY_microseconds(10);
    }
}

/*
 * Drive bus low, delay 6 ?s.
 * Release bus, delay 9 ?s.
 * Sample bus to read bit from slave.
 * Delay 55 ?s.
 */
char ow_read_bit() {
    OWOUT;
    DELAY_microseconds(6);

    OWIN;
    DELAY_microseconds(8);

    char response = OWPIN;

    DELAY_microseconds(55);

    return response;
}

char ow_read_byte() {
    char c, r = 0;

    for (c = 0; c < 8; c++) {
        
        if (ow_read_bit()) {
            r |= 1 << c;
        }
    }

    return r;
}

void ow_write_byte(char B) {
    char c;

    for (c = 0; c < 8; c++) {
        ow_write_bit((B >> c) & 1);
    }
}


