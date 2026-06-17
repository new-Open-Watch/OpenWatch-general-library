#pragma once
#include "esp_log.h"
#include "esp_vfs_fat.h"
#include "driver/sdspi_host.h"
#include "driver/spi_common.h"
#include "sd_protocol_defs.h"

#include <stdio.h>
#include <string.h>

#define MOUNT_POINT "/sdcard"

// SPI bus pins — adjust for your board
#define PIN_CLK  36
#define PIN_MISO 37
#define PIN_MOSI 35
#define PIN_CS   34

static const char *TAG = "sd_spi";
static sdmmc_card_t *card = nullptr;

void sdinit();
FILE* sdopen(const char *filePath, const char *mode);
template <typename t>
bool sdwrite(const char *path, const t& data)
