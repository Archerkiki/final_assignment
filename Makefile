main:main.o dijkstra.o backstp.o tree.o
    gcc main.o dijkstra.o backstp.o tree.o -o main
main.o:main.c
    gcc -c main.c
dijkstra.o:dijkstra.c
    gcc -c dijkstra.c
backstp.0:backstp.c 
    gcc -c backstp.c
tree.o:tree.c 
    gcc -c tree.c

clean:
    rm main *.o

