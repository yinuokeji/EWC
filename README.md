# Smart socket Project


## Illustrate
MCU:ESP32

SDK:ESP-IDF4.4.1

IDE:VSCode

## Configure the project
Open the project configuration menu (`idf.py menuconfig`).

In the `Serial flasher config` menu:

* Set the `Flash size` to 4MB

In the `Component config` menu:

* Set the `Bluetooth` menu:

    * Set the `Bluedroid Options`

        * Set the `Include blufi function`

* Set the `ESP32-Specific` menu:

    * Unset the `Hardeare brownout detect&reset` 


## Build and Flash
* [ESP-IDF Getting Started Guide on ESP32](https://docs.espressif.com/projects/esp-idf/en/latest/esp32/get-started/index.html)

## DEBUG FINISH
* BLUFI
* MQTT
* BL0937交流电能芯片