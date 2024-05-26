# GDMonkey

*"The infinite monkey theorem states that a monkey hitting keys at random on a typewriter keyboard for an infinite amount of time will almost surely type any given text, including the complete works of William Shakespeare."*

Under this pretext, it may also state that a monkey clicking a mouse at random for an infinite amount of time will almost surely beat any given level, including the complete lists of Pointercrate.

GDMonkey is a program that simulates many attempts of the first 33% of the first main Geometry Dash level, Stereo Madness, with completely random inputs. The amount of attempts simulated per second depends on your system's CPU and current workload, it may be hundreds of thousands, it may be millions!

Currently the program is coded in such a way that it will only really work with specific cube parts, and the first part of Stereo Madness fits that category.

## Setup

The C code comes with the first part of Stereo Madness' information hardcoded and ready to go

If you wish to get your own Stereo Madness-playing-monkey, you must consider a few options:
- __Downloading the source code and compiling it yourself:__ Will be most optimized for your specific CPU's arquitechture and will run slightly faster, it's not very hard and you can make changes to the code if you wish.
- __Downloading the binary for your specific OS:__ You can go to the "bin" folder and get the .bin file named after your system and run it, but I recommend the first option.
