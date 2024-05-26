# GDMonkey

*"The infinite monkey theorem states that a monkey hitting keys at random on a typewriter keyboard for an infinite amount of time will almost surely type any given text, including the complete works of William Shakespeare."*

Under this pretext, it may also state that a monkey clicking a mouse at random for an infinite amount of time will almost surely beat any given level, including the complete lists of Pointercrate.

GDMonkey is a program that simulates many attempts of the first 33% of the first main Geometry Dash level, Stereo Madness, with completely random inputs. The amount of attempts simulated per second depends on your system's CPU and current workload, it may be hundreds of thousands, it may be millions!

Currently the program is coded in such a way that it will only really work with specific cube parts, and the first part of Stereo Madness fits that category.

## Setup & Instructions

If you wish to get your own Stereo Madness-playing-monkey, the source C code comes with the first part of Stereo Madness' information hardcoded and ready to go
the .sh file automatically compiles the C code, but not before installing any dependencies in case they're missing (GCC and cURL), and in Mac, it even installs the homebrew packet manager TO install the dependecies, how cool is that?

### Windows 
Windows makes it extra annoying to do this, so in this tutorial here's how to download a Linux simulator to do it there instead! You need like 100MB of free disk space, if you don't have that or this isn't working out, skip to Windows (Alternative) on this doc
1. Determine if your system is 32 of 64 bits, if you already know this then skip this step, if you're too lazy to find out, it's probably 64 bits.
  - Press Win + R (or search "execute" in the search bar)
  - Type "msinfo32" and press OK
  - Check the "System Type" item's value in the list, it should say if it's 32 or 64 bits.
2. Download Git Bash [here](https://git-scm.com/download/win)
  - Git for Windows Setup (32 or 64 bit, whichever your system is)
3. Install Git Bash
  - Open the .exe and press run
  - In the setup window you can just spam "Next" until installation is complete, how nifty
4. Download GDMonkey
  - Go to [this link](https://github.com/GDNacho/gdmonkey/releases/tag/1.0.1), then click on "Source code (zip)" to download
  - Unzip the zip file wherever you like
5. Run GDMonkey
  - Open file explorer and open the DIY folder
  - Right click on the window, then click on "Git Bash here", this will open Git Bash
  - Type "./gdmonkey.sh" and press enter to run GDMonkey
  - Closing the window or pressing CTRL+C will terminate the program
  - Furthermore copy something from the window you can't use CTRL+C, select text, right click, then click Copy
  - You can open another terminal to run another monkey, but be mindful, you only have so much CPU

### Windows (Alternative, currently not availible)
I recommend you try the other version first and only try this if it doesn't work out, you probably shouldn't be running some rando's .exe files and running em after all (except mine, because i'm so trustworthy)
1. Determine if your system is 32 of 64 bits, if you already know this then skip this step, if you're too lazy to find out, it's probably 64 bits.
  - Press Win + R (or search "execute" in the search bar)
  - Type "msinfo32" and press OK
  - Check the "System Type" item's value in the list, it should say if it's 32 or 64 bits.
2. Download GDMonkey
  - Go to [this link](https://github.com/GDNacho/gdmonkey/releases/tag/1.0.1), then click on "Source code (zip)" to download
  - Unzip the zip file wherever you like
3. Run GDMonkey
  - Open file explorer and open the Windows folder
  - Run GDMonkey64.exe if your system is 64 bits, or GDMonkey32.exe if your system is 32 bits

### Macintosh
1. Make life a bit easier
  - Go to System Preferences
  - Go to Keyboard > Shortcuts > Services
  - Find and turn on "New Terminal at Folder"
2. Download GDMonkey
  - Go to [this link](https://github.com/GDNacho/gdmonkey/releases/tag/1.0.1), then click on "Source code (zip)" to download
  - Unzip the zip file wherever you like
3. Run GDMonkey
  - Open file explorer and right click DIY folder
  - Click on "New Terminal at Folder"
  - Type "./gdmonkey.sh" and press enter to run GDMonkey
  - On first run it might ask you if you want to install packets, just type "y" press enter and move on
  - Closing the window will terminate the program
  - I have no clue how terminal works on Mac, you're better off screenshotting the damn thing
  - You can open another terminal to run another monkey, but be mindful, you only have so much CPU

### Linux
You're a Linux user, you know what to do, right?
The .sh auto package installer supports distros based on Debian, Red Hat, SUSE, Pacman (Arch), Gentoo, Slackware, Solus and Tiny Core, which covers 95% of distros under the sun.
1. Download GDMonkey
  - Open a terminal
  - Clone the repo with "git clone ```https://github.com/gdnacho/gdmonkey.git```
2. Run GDMonkey
  - cd into gdmonkey/DIY ```cd cdmonkey/DIY```
  - Type "./gdmonkey.sh" and press enter to run GDMonkey
  - Closing the window or pressing CTRL+C will terminate the program
  - Furthermore copy something from the window you can't use CTRL+C, select text, right click, then click Copy
  - You can open another terminal to run another monkey, but be mindful, you only have so much CPU

### Other OSs (Like ChromeOS)
You're on your own! Though at this point I wonder how you even run Geometry Dash in the first place...
