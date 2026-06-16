#pragma once

#define MOUNT_POINT "/sdcard"

// SPI bus pins — adjust for your board
#define PIN_CLK  36
#define PIN_MISO 37
#define PIN_MOSI 35
#define PIN_CS   34


void sdinit();
FILE* sdopen(const char *filePath, const char *mode);
template <typename t>
bool sdwrite(const char *path, const t& data)
