# Scripts and notes I'm creating while coding a Physics Engine in C/C++

In this repo, i will upload some scripts and some notes i wrote about the development of a Phyisics Engine
I'm still currently working on this. Let me know if you find some issues or maybe there are some improvement that could be made to make the code more efficient.


To compile rigid_body.c use the following command:

```bash
gcc -o rigid_body_sim rigid_body_sim lib/rigid_body.c lib/vector.h
```

To compile particle_simulation.c use the following command:

```bash
gcc -o particle_simulation particle_simulation.c lib/vector.c lib/particle.c
```