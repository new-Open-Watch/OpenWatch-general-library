#include "FS.hpp"




void sdinit()
{
    spi_bus_config_t bus_cfg = {};
    bus_cfg.mosi_io_num = PIN_MOSI;
    bus_cfg.miso_io_num = PIN_MISO;
    bus_cfg.sclk_io_num = PIN_CLK;
    bus_cfg.quadwp_io_num = -1;
    bus_cfg.quadhd_io_num = -1;
    bus_cfg.max_transfer_sz = 4096;
    ESP_ERROR_CHECK(spi_bus_initialize(SPI2_HOST, &bus_cfg, SPI_DMA_CH_AUTO));

    sdspi_device_config_t slot_cfg = SDSPI_DEVICE_CONFIG_DEFAULT();
    slot_cfg.gpio_cs = (gpio_num_t)PIN_CS;
    slot_cfg.host_id = SPI2_HOST;

    esp_vfs_fat_sdmmc_mount_config_t mount_cfg = {};
    mount_cfg.format_if_mount_failed = false;
    mount_cfg.max_files = 5;
    mount_cfg.allocation_unit_size = 16 * 1024;

    sdmmc_host_t host = SDSPI_HOST_DEFAULT();

    esp_err_t ret = esp_vfs_fat_sdspi_mount("/sdcard", &host, &slot_cfg, &mount_cfg, &card);
    if (ret != ESP_OK)
    {
        ESP_LOGE(TAG, "Mount failed: %s", esp_err_to_name(ret));
        return;
    }
    ESP_LOGI(TAG, "SD mounted");
}
FILE* sdopen(const char *filePath, const char *mode){
    char path[256];
    snprintf(path, sizeof(path), "%s%s", MOUNT_POINT, filePath);

    FILE *f = fopen(path, mode);
    return f;
}


