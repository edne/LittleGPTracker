# LittleGPTracker

LittleGPTracker (a.k.a 'The piggy') is a music tracker optimised to run on portable game consoles.


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
docker run -it -v.:/LittleGPTracker lgpt-psp
```
