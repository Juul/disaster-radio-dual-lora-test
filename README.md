
LoRa test for dual-lora disaster.radio board.

# Setup

Install Arduino IDE.

Go to `File -> Options` then click the button to the right of `Additional Boards Manager Urls` and add `https://dl.espressif.com/dl/package_esp32_index.json` on a new line. Click OK and then OK again.

Go to `Tools -> Board -> Boards Manager` then search for "esp32" and install the only result.

Go to `Sketch -> Include Library -> Manage Libraries` then search for "lora" and install the one called "LoRa by Sandeep Mistry".

Now open `main.ino` from this repository.

In `Tools` select the following:

* Board: ESP32 Dev Module
* Upload speed: Upload speed 115200
* CPU Frequency: 80 MHz
* Flash mode: DIO
* Flash size; 4 MB
* Port: Whatever /dev/ttyUSB? it comes up as

Hook the board to 3.3 V and USB.

Now you should be able to upload.

Go to `Tools -> Serial Monitor` to see the output after uploading.