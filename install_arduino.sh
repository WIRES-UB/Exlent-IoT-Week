#!/usr/bin/env bash

# To give this installer permission and run it:
# chmod +x install_arduino.sh
# ./install_arduino.sh

set -e

# Configuration
INSTALL_DIR="$HOME/Applications"
DOWNLOAD_URL="https://downloads.arduino.cc/arduino-ide/arduino-ide_latest_Linux_64bit.AppImage"
APP_NAME="ArduinoIDE.AppImage"

echo "Creating installation directory..."
mkdir -p "$INSTALL_DIR"

echo "Downloading Arduino IDE..."
wget -O "$INSTALL_DIR/$APP_NAME" "$DOWNLOAD_URL"

echo "Making AppImage executable..."
chmod +x "$INSTALL_DIR/$APP_NAME"

echo ""
echo "Arduino IDE downloaded successfully!"
echo "Location: $INSTALL_DIR/$APP_NAME"
echo ""
echo "Run it with:"
echo "    $INSTALL_DIR/$APP_NAME"
