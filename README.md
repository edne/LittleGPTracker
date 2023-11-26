# LittleGPTracker

LittleGPTracker is a music tracker optimised to run on portable game consoles.

Official site:  
https://littlegptracker.com/

Original repo (discontinued):  
https://github.com/Mdashdotdashn/LittleGPTracker

This repository is based on the [@djdiskmachine
fork](https://github.com/djdiskmachine/LittleGPTracker/), active at least till
the beginning of 2023. All the features introduced here are on [separate
branches](https://github.com/edne/LittleGPTracker/branches/all?query=feature%2F)
based on its `master` and can be merged separately on any other fork starting
from the same base (like [this
one](https://github.com/subnixr/LittleGPTracker/)).

Right now I am testing only on Ubuntu and PSP and I have no intention to
support other platforms. Everything should still work on the other targets, if
you find (and fix) some bug on them pull requests are welcome.


## Changes

- ~~Custom font, based on [@subnixr pull
  request](https://github.com/djdiskmachine/LittleGPTracker/pull/50). The font
is taken from
[here](https://int10h.org/oldschool-pc-fonts/fontlist/font?ibm_cgathin) with
some minor adjustments
[🔗](https://github.com/edne/LittleGPTracker/tree/feature/ibm_font)~~

- Load font directly from a `.bmp` at startup[^1], the file should be in [this
  format](https://github.com/edne/LittleGPTracker/blob/master/sources/Resources/original.bmp),
in the same path as your config file and the name can be set in the
configuration with the `FONTBITMAP` key, if not defined or not found it will
try to load a file called `font.bmp` and if it fails will use the default one
[🔗](https://github.com/edne/LittleGPTracker/tree/feature/load_custom_font)

- Build system with dockerfiles
  [🔗](https://github.com/edne/LittleGPTracker/tree/feature/docker_build)

- Color row numbers in two different colors (`ROWCOLOR` and `ROWCOLOR2` values
  in configuration) alternating each N rows (`ALTROWNUMBER` in configuration)
[🔗](https://github.com/edne/LittleGPTracker/tree/feature/alternate_row_number_color)

- Display the `00` chain and phrases in a different color (`ZEROCOLOR` in
  configuration)
[🔗](https://github.com/edne/LittleGPTracker/tree/feature/00_color)

- When inserting or cloning a new chain or phrase use the first one free just
  after the current one and not from the beginning
[🔗](https://github.com/edne/LittleGPTracker/tree/feature/next_from_current)

- Add command reverse `REVS`, takes the same parameters as `PLOF` but play the
  sample backwards, the instrument has to bee in `loop` mode
[🔗](https://github.com/edne/LittleGPTracker/tree/feature/reverse_command)

[^1]: This feature is supported only on Linux and PSP, on other platforms
could either: already work out of the box (like probably on Windows and Mac),
be supported with minimal changes (like for CAANOO and GP2X, you will need to
copy-paste the `LoadFont` methods in you implementation class and replacing the
occurrences of the global `font` variable with a local `font_` attribute), or
not being possible at all (like for the NDS that doesn't seem to even use SDL,
there isn't a `Makefile` for it so I don't know if the platform is even
supported)

Example of `config.xml`
```xml
<CONFIG>
    <BACKGROUND  value="000000"/>
    <FOREGROUND  value="E0D0D0"/>
    <HICOLOR1    value="2080F0"/>
    <HICOLOR2    value="30D0D0"/>
    <CURSORCOLOR value="00F080"/>

    <ZEROCOLOR   value="808080"/>

    <ROWCOLOR    value="20A0F0"/>
    <ROWCOLOR2   value="30D0D0"/>

    <ALTROWNUMBER value="2"/>

    <FONTBITMAP value="custom_font.bmp"/>
</CONFIG>
```


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
