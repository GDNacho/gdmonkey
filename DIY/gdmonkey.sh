#!/bin/bash

# Function to check if a command exists
command_exists() {
    command -v "$1" >/dev/null 2>&1
}

# Function to install packages on Debian-based systems
install_debian() {
    sudo apt-get update
    sudo apt-get install -y "$1"
}

# Function to install packages on Red Hat-based systems
install_redhat() {
    sudo yum install -y "$1"
}

# Function to install packages on SUSE-based systems
install_suse() {
    sudo zypper install -y "$1"
}

# Function to install packages on Arch Linux-based systems
install_arch() {
    sudo pacman -Syu --noconfirm "$1"
}

# Function to install packages on TinyCore Linux
install_tinycore() {
    tce-load -wi "$1"
}

# Function to install packages on macOS
install_macos() {
    brew install "$1"
}

# Function to install packages based on the detected package manager
install_package() {
    if command_exists apt-get; then
        install_debian "$1"
    elif command_exists yum; then
        install_redhat "$1"
    elif command_exists zypper; then
        install_suse "$1"
    elif command_exists pacman; then
        install_arch "$1"
    elif command_exists tce-load; then
        install_tinycore "$1"
    elif command_exists brew; then
        install_macos "$1"
    else
        echo "Unsupported package manager. Please install $1 manually."
        exit 1
    fi
}

# Check if GCC is installed
if command_exists gcc; then
    echo "GCC is already installed."
else
    echo "GCC is not installed. Installing GCC..."
    install_package gcc
fi

# Check if cURL is installed
if command_exists curl; then
    echo "cURL is already installed."
else
    echo "cURL is not installed. Installing cURL..."
    install_package curl
fi

# Compile gdmonkey.c with command "gcc -Ofast -march=native -o gdmonkey gdmonkey.c -lcurl"
echo "Compiling gdmonkey.c..."
if [ -f "gdmonkey.c" ]; then
    gcc -Ofast -march=native -o gdmonkey gdmonkey.c -lcurl
    if [ $? -eq 0 ]; then
        echo "Compilation successful. Running gdmonkey..."
        ./gdmonkey
    else
        echo "Compilation failed."
        exit 1
    fi
else
    echo "File gdmonkey.c not found."
    exit 1
fi
