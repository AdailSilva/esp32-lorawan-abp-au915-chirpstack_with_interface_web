/*
 * node_build.h — build options and FACTORY DEFAULTS of this node.
 *
 * Everything below is only the value used on the first boot (or after
 * "Restaurar padrão de fábrica"). After that the values live in the NVS
 * of the ESP32 and are changed from the web page (http://<ip>/ or
 * http://<nome>.local/) — no need to recompile.
 *
 * This file is the ONLY difference between the ABP and the OTAA project:
 * the other node_*.h / node_*.cpp files are identical in both.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef NODE_BUILD_H
#define NODE_BUILD_H

/* ------------------------------------------------------------------ */
/* Activation of this firmware (exactly one of them = 1)              */
/* ABP  -> MCCI LMiC 3.3.0  (LoRaWAN 1.0.x, see README)               */
/* OTAA -> MCCI LMiC 6.0.1                                            */
/* ------------------------------------------------------------------ */
#define NODE_ACTIVATION_ABP     1
#define NODE_ACTIVATION_OTAA    0

#define NODE_FW_NAME            "LoRaWAN Node ABP"
#define NODE_FW_VERSION         "1.1"
#define NODE_LMIC_VERSION       "MCCI LMiC 3.3.0"

/* Device name: hostname (<nome>.local), Soft AP SSID and page title. */
#define DEF_NODE_NAME           "lorawan-node-abp"

/* ---------------------------- Wi-Fi --------------------------------- */
/* 0 = Station (falls back to Soft AP), 1 = Soft AP only, 2 = Wi-Fi off */
#define DEF_WIFI_MODE           0
#define DEF_WIFI_SSID           ""
#define DEF_WIFI_PASS           ""
#define DEF_AP_PASS             "lorawan123"     /* min. 8 characters  */
#define DEF_AP_CHANNEL          6
/* Soft AP addressing (fixed at build time). DHCP leases start at IP+1. */
#define DEF_AP_IP               192, 168, 101, 101
#define DEF_AP_GATEWAY          192, 168, 101, 1
#define DEF_AP_MASK             255, 255, 255, 0
#define DEF_STA_TIMEOUT_S       30   /* s without connection -> Soft AP */
#define DEF_BOOT_PIN            0    /* hold LOW 3 s (any time) -> Soft AP;
                                        GPIO 0 = BOOT button of the DevKit */

/* ------------------------- Web page login -------------------------- */
#define DEF_WEB_USER            "admin"
#define DEF_WEB_PASS            "lorawan"

/* ---------------------- ABP credentials (MSB) ---------------------- */
/* ChirpStack -> Devices -> device -> Activation (ABP)                 */
#define DEF_DEVADDR             0x00aa88caUL
#define DEF_NWKSKEY             { 0x15, 0x1F, 0x77, 0x79, 0xD7, 0xAA, 0xEE, 0x42, \
                                  0x2A, 0x74, 0x56, 0x83, 0x80, 0xDB, 0x70, 0x45 }
#define DEF_APPSKEY             { 0xFD, 0x91, 0xD5, 0x5D, 0xCE, 0x3A, 0xF1, 0x02, \
                                  0x30, 0x93, 0xE2, 0x89, 0xA1, 0xD9, 0xF3, 0xDF }
#define DEF_NETID               0x000000UL  /* ChirpStack; TTN = 0x000013 */
#define DEF_RX1_DELAY_S         1

/* OTAA fields are kept in the config (only shown as reference in ABP). */
#define DEF_DEVEUI              { 0x08, 0xFD, 0xBE, 0x4B, 0xC6, 0x04, 0xE8, 0xF8 }
#define DEF_JOINEUI             { 0, 0, 0, 0, 0, 0, 0, 0 }
#define DEF_APPKEY              { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }

/* Byte order of DevEUI/JoinEUI handed to the LMiC (OTAA only).
 * 0 = as typed (MSB), exactly like the original firmware did. The LMiC
 *     sends these bytes as they are, and LoRaWAN reads EUIs LSB first, so
 *     the network server sees the EUI REVERSED (the page shows how).
 * 1 = reversed (LSB first, as MCCI documents) -> the network server sees
 *     exactly the value typed on the page / shown in ChirpStack.          */
#define DEF_EUI_REVERSE         0

/* ------------------------- Radio / channels ------------------------ */
#define DEF_SUBBAND             1      /* AU915 sub-band 1 = ch 8–15   */
#define DEF_CH500               1      /* + 500 kHz ch 64+sub-band (65) */
#define DEF_ADR                 0
#define DEF_DR                  5      /* DR5 = SF7/BW125 (AU915)       */
#define DEF_TXPOW               14     /* dBm                           */
#define DEF_LINKCHECK           0
#define DEF_CLOCK_ERR_PCT       1      /* % of MAX_CLOCK_ERROR          */
#define DEF_RX2_DR              8      /* DR8 = SF12/BW500 (AU915)      */
#define DEF_RX2_FREQ            0      /* 0 = region default 923.3 MHz  */

/* ----------------------------- Uplink ------------------------------ */
#define DEF_TX_INTERVAL_S       10
#define DEF_FPORT               101
#define DEF_CONFIRMED           0
#define DEF_PAYLOAD             "AdailSilva-IoT"

/* --------------- Remote reset command (downlink) ------------------- */
#define DEF_RST_ENABLE          1
#define DEF_RST_PORT            101
#define DEF_RST_CMD             { 0xAD, 0xA1, 0xDE, 0xAD, 0xBE, 0xEF, 0x0D, 0x0A }
#define DEF_RST_DELAY_MS        2000

/* --------------------- Hardware — ESP32 + RFM95W ------------------- */
#define DEF_PIN_SCLK            18
#define DEF_PIN_MISO            19
#define DEF_PIN_MOSI            23
#define DEF_PIN_NSS             5
#define DEF_PIN_RESET           14
#define DEF_PIN_DIO0            34
#define DEF_PIN_DIO1            35
#define DEF_PIN_DIO2            -1     /* not connected (39 = reference) */
#define DEF_SPI_FREQ            0      /* 0 = LMiC default              */
#define DEF_SERIAL_BAUD         9600
#define DEF_VERBOSE             1      /* session dump on every TX      */

#endif
