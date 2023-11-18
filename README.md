# LittleGPTracker

LittleGPTracker is a music tracker optimised to run on portable game consoles.

Official site:  
https://littlegptracker.com/

Original repo (discontinued):  
https://github.com/Mdashdotdashn/LittleGPTracker

This repository is based on the [@djdiskmachine
fork](https://github.com/djdiskmachine/LittleGPTracker/), active at least till
the beginning off 2023. All the features introduced here are on [separate
branches](https://github.com/edne/LittleGPTracker/branches/all?query=feature%2F)
based on its `master` and can be merged separately on any other fork starting
from the same base (like [this
one](https://github.com/subnixr/LittleGPTracker/)).

Right now I am testing only on Ubuntu and PSP and I have no intention to
support other platforms. Everything should still work on the other targets, if
you find (and fix) some bug on them pull requests are welcome.


## Changes

- Custom font, based on [@subnixr pull
  request](https://github.com/djdiskmachine/LittleGPTracker/pull/50). The font
is taken from
[here](https://int10h.org/oldschool-pc-fonts/fontlist/font?ibm_cgathin) with
some minor adjustments,
[branch](https://github.com/edne/LittleGPTracker/tree/feature/ibm_font)
- Build system with dockerfiles,
  [branch](https://github.com/edne/LittleGPTracker/tree/feature/docker_build)
- Color row numbers in two different colors (`ROWCOLOR` and `ROWCOLOR2` values
  in configuration) alternating each N rows (`ALTROWNUMBER` in configuration),
[branch](https://github.com/edne/LittleGPTracker/tree/feature/alternate_row_number_color)
- In song and live view display the `00` chain in a different color (`ZEROCOLOR` in configuration),
  [branch](https://github.com/edne/LittleGPTracker/tree/feature/chain_00_color)



# Building with docker

Build images:
```
docker build -t lgpt-deb -f projects/DockerfileDEB .
docker build -t lgpt-psp -f projects/DockerfilePSP .
```

Compiling for Linux:
```
docker run -v.:/LittleGPTracker lgpt-deb
```

Compiling for PSP:
```
docker run -v.:/LittleGPTracker lgpt-psp
```
