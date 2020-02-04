gcc -c ll.c
gcc -c cycle1.c
gcc -c cycle2.c
gcc -o driver_ll_1 driver_ll.c cycle1.o ll.o
gcc -o driver_ll_2 driver_ll.c cycle2.o ll.o
gcc -o createCircular createCircular.c cycle1.o ll.o
