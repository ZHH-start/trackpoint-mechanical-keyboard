#ifndef CONFIG_H
#define CONFIG_H

#include "config_common.h"

/* Device */
#define VENDOR_ID       0xDE34
#define PRODUCT_ID      0x7324
#define DEVICE_VER      0x0001
#define MANUFACTURER    XCL
#define PRODUCT         TA1021
#define DESCRIPTION     Alice + TrackPoint

/* Command */
#define IS_COMMAND() ( keyboard_report->mods == (MOD_BIT(KC_LSHIFT) | MOD_BIT(KC_RSHIFT)) )

/* Matrix */
#define MATRIX_ROWS 9
#define MATRIX_COLS 10
#define MATRIX_ROW_PINS { F1, F0, D4, F5, F4, F6, F7, E6, C7 }
#define MATRIX_COL_PINS {B6, D6, D7, B4, B5, B0, B1, B2, B3, B7 }
#define DIODE_DIRECTION COL2ROW // COL2ROW or ROW2COL

#define DEBOUNCE 5
#define TAP_CODE_DELAY 10
#define PREVENT_STUCK_MODIFIERS


/* BLE */
// #define AdafruitBleResetPin B4
// #define AdafruitBleCSPin B5
// #define AdafruitBleIRQPin B6
// #define BATTERY_LEVEL_PIN D7

/* WS2812 RGB */
#define RGB_DI_PIN C6
#define RGBLED_NUM 90
#define RGBLIGHT_SPLIT
#define RGBLIGHT_ANIMATIONS
#define RGBLIGHT_HUE_STEP 8
#define RGBLIGHT_SAT_STEP 8
#define RGBLIGHT_VAL_STEP 8

/* PS/2 Mouse */
#ifdef PS2_USE_USART
#define PS2_CLOCK_PORT  PORTD
#define PS2_CLOCK_PIN   PIND
#define PS2_CLOCK_DDR   DDRD
#define PS2_CLOCK_BIT   5
#define PS2_DATA_PORT   PORTD
#define PS2_DATA_PIN    PIND
#define PS2_DATA_DDR    DDRD
#define PS2_DATA_BIT    2

/* synchronous, odd parity, 1-bit stop, 8-bit data, sample at falling edge */
/* set DDR of CLOCK as input to be slave */
#define PS2_USART_INIT() do {   \
  PS2_CLOCK_DDR &= ~(1<<PS2_CLOCK_BIT);   \
  PS2_DATA_DDR &= ~(1<<PS2_DATA_BIT);     \
  UCSR1C = ((1 << UMSEL10) |  \
            (3 << UPM10)   |  \
            (0 << USBS1)   |  \
            (3 << UCSZ10)  |  \
            (0 << UCPOL1));   \
  UCSR1A = 0;                 \
  UBRR1H = 0;                 \
  UBRR1L = 0;                 \
} while (0)
#define PS2_USART_RX_INT_ON() do {  \
  UCSR1B = ((1 << RXCIE1) |       \
            (1 << RXEN1));        \
} while (0)
#define PS2_USART_RX_POLL_ON() do { \
  UCSR1B = (1 << RXEN1);          \
} while (0)
#define PS2_USART_OFF() do {    \
  UCSR1C = 0;                 \
  UCSR1B &= ~((1 << RXEN1) |  \
              (1 << TXEN1));  \
} while (0)
#define PS2_USART_RX_READY      (UCSR1A & (1<<RXC1))
#define PS2_USART_RX_DATA       UDR1
#define PS2_USART_ERROR         (UCSR1A & ((1<<FE1) | (1<<DOR1) | (1<<UPE1)))
#define PS2_USART_RX_VECT       USART1_RX_vect

//#define PS2_MOUSE_SCROLL_BTN_MASK (1<<PS2_MOUSE_BTN_MIDDLE)
#define PS2_MOUSE_SCROLL_BTN_SEND 300
#define PS2_MOUSE_ROTATE 180
// #define PS2_MOUSE_X_MULTIPLIER 1
// #define PS2_MOUSE_Y_MULTIPLIER 1
//#define PS2_MOUSE_V_MULTIPLIER 0.1
#define PS2_MOUSE_X_MULTIPLIER 1
#define PS2_MOUSE_Y_MULTIPLIER 1
#define PS2_MOUSE_V_MULTIPLIER 1
#define PS2_MOUSE_SCROLL_DIVISOR_H 5
#define PS2_MOUSE_SCROLL_DIVISOR_V 5
// 在config.h 设置
#define PS2_MOUSE_SCROLL_BTN_MASK 0

#endif
//换层屏蔽中键滚轮功能，需要的话让群主帮你刷一个吧
#endif
