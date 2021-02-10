# opentyrian-nx
Port of OpenTryian to the Nintendo Switch - going against standard practice, rather than just making the original source compilable for the Switch I've been removing code that is irrelevant to it. With the personal goal of gaining better knowledge of SDL2 and have simpler code specifically for the Switch. 

![Open Tyrian on Switch Hardware](switch_001.jpg)  
  
![Open Tyrian on Switch Hardware](switch_002.jpg)

Project: https://bitbucket.org/opentyrian/opentyrian/  
Original source: https://bitbucket.org/opentyrian/opentyrian/branch/sdl2

## Setup

##### Install DevKitPro 
* Follow the instructions to install on your system https://devkitpro.org/wiki/devkitPro_pacman
* Execute `sudo (dkp-)pacman -S switch-dev` to install the tools and libraries for switch development, where (dkp-) is the path to pacman on your system
* Note: if installing on macOS Catalina, may need to follow these steps: https://github.com/devkitPro/pacman/issues/15
* Install switch-sdl2 packages: `sudo (dkp-)pacman -S switch-sdl2`

#### Compiling
* Execute `make` in the source folder

#### Installation
* Copy `opentyrian.nro` and the `data` folder to your `switch` folder on your microSD card.

## Controls
Left Stick / D-Pad - Ship movement  
A - Fire weapons (select in menus)  
B - Toggle rear weapon mode (back in menus)  
X / Right Trigger - Fire right sidekick  
Y / Left Trigger - Fire left sidekick  
Plus - Pause  
Minus - In Game Menu

## Contributors
* bladeSk: https://github.com/bladeSk
