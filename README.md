# Lemin
Ant algorithm project
Must be able to handle up to 10000 nodes

## How To Run
```
make re  
usage: ./lem-in < [map]
```
you can find maps in the map folder

## Program Description

- The goal of this project is to find the quickest way to get n ants across the farm.
- Quickest way means the solution with the least number of lines, respecting the output format requested below.
- Obviously, there are some basic constraints. To be the first to arrive, ants will need to take the shortest path (and that isn’t necessarily the simplest). They will also need to avoid traffic jams as well as walking all over their fellow ants.
- At the beginning of the game, all the ants are in the room ##start. The goal is to bring them to the room ##end with as few turns as possible. Each room can only contain one ant at a time. (except at ##start and ##end which can contain as many ants as necessary.)
- We consider that all the ants are in the room ##start at the beginning of the game.
- At each turn you will only display the ants that moved.
- At each turn you can move each ant only once and through a tube (the room at the receiving end must be empty).
- You must to display your results on the standard output in the following format:
```
number_of_ants
the_rooms
the_links

Lx-y Lz-w Lr-o ...
```

## Map Format
- Your program will receive the data describing the ant farm from the standard output in the following format:
```
number_of_ants
the_rooms
the_links
```
- The ant farm is defined by the following links:
```
##start
1 23 3
2 16 7
#comment
3 16 3
4 16 5
5 9 3
6 1 5
7 4 8
##end
0 9 5
0-4
0-6
1-3
4-3
5-2
3-5
#another comment
4-2
2-1
7-6
7-2
7-4
6-5
#another comment
```
- Which corresponds to the following representation:
```
           _______________
          /               \ 
  ______[5]----[3]----[1] |
 /              |    /    |
[6]-----[0]----[4]  /     |
 \    _________/|  /      |
  \ /          [2]/_______/
  [7]__________/
```
