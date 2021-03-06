# Lemin
Ant Farm Algorithm Project

## How To Run
```
make re  
usage: ./lem-in < [map]
```
you can find maps in the map folder

## Program Objectives
```
number_of_ants
the_rooms
the_links

Lx-y Lz-w Lr-o ...
```

* Your program will receive the data describing the ant farm from the standard output in the following format:
```
number_of_ants
the_rooms
the_links
```
* The ant farm is defined by the following links:
```
10                    => first digit will determine ant amount
##start
1 23 3                => this will be the starting node ants come out from
2 16 7                => room define: name coor_x coor_y (coor used for visuals)
#comment              => comments can be written anywhere      
3 16 3
4 16 5
5 9 3
6 1 5
7 4 8
##end
0 9 5                 => ants final destination
0-4                   => links define: name1-name2
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
SNAIL GRAPH
           _______________
          /               \ 
  ______[5]----[3]----[1] |
 /              |    /    |
[6]-----[0]----[4]  /     |
 \    _________/|  /      |
  \ /          [2]/_______/
  [7]__________/
```
* The goal of this project is to find the quickest way to get n ants across the farm.
* Quickest way means the solution with the least number of lines, respecting the output format requested below.
* Obviously, there are some basic constraints. To be the first to arrive, ants will need to take the shortest path (and that isn’t necessarily the simplest). They will also need to avoid traffic jams as well as walking all over their fellow ants.
* At the beginning of the game, all the ants are in the room ##start. The goal is to bring them to the room ##end with as few turns as possible. Each room can only contain one ant at a time. (except at ##start and ##end which can contain as many ants as necessary.)
* We consider that all the ants are in the room ##start at the beginning of the game.
* At each turn you will only display the ants that moved.
* At each turn you can move each ant only once and through a tube (the room at the receiving end must be empty).
* You must to display your results on the standard output in the following format:

## Result Display
* For your final output follow this format:
```
number_of_ants          => Simply display the farm format
the_rooms
the_links
Lx-y Lz-w Lr-o ...      => ants walk through result by turn
```
* Following the example above:
```
5                          
##start            
1 23 3          
2 16 7       
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
 
L1-2 L2-3
L1-4 L2-5 L3-2 L4-3
L1-0 L2-6 L3-4 L4-5 L5-2
L2-0 L3-0 L4-6 L5-4
L4-0 L5-0
turn: 5
```
## My Solution
### Parsing
* Since rooms are defined by (name, x, y) coordinates only need to be used for a visualizer which I didn't use so I ignored them.
* I stored the names inside a queue (you can find my own personal queue in libft) since the amount of rooms is indefinite.
* That allows me to store an indefinite numbers of room.
* Since the names of the rooms are random and are used to see which points are linked I used a [**dictionary**](./dictionary.h) to access them in O(1) time and not use strcmp which would be O(n) very slow in case there was 10,000 nodes.
* I used [**adjacency lists**](./adjlist.h) for graph representation.
### Solving
* My teammate and I thought about many different ways to solve this problem, our initial attempt was just a shortest path algorithm which would work for finding only one path and delete the already found path and run the algorithm again for n paths found.
```
    / A - ... \
S - - B - ... - - E
    \ C - ... /
    
lets say we find path A to be the shortest then we store it and then delete it from our adjacency list.

    / XXXXXXX \
S - - B - ... - - End
    \ C - ... /
    
and we keep doing this until we have no more paths to find
```
* However this is technically wrong since we are trying to push ants as fast as possible which wouldn't work in the following example:
```
        [1]--[2]
      /         \
[S]--[0]--[3]--[E]
  \       /
   [4]--[5]
NOTE: in a shortest path algorith I will find the following path first S-0-3-E without considering that there
are 2 possible paths in this example, if I were to send 100 ants it will take my ants 104 turns to flow throught
the graph, however if I were to use both paths its going to take my ants a bit over 50 turns to reach the end.
```
* So my teamate and I found out about max flow algorithms which solves this exact problem and ended up implementing [**Edmund Karps**](./algorithms.c) max flow algorithm.
  * References used:
    * https://en.wikipedia.org/wiki/Edmonds–Karp_algorithm
    * https://www.youtube.com/watch?v=RppuJYwlcI8
    * https://cp-algorithms.com/graph/edmonds_karp.html
* Each path was stored inside a queue.
### Displaying
* Reminder: Display format is L(ant_number)-(goes to room_name)
* This was the hardest part of the problem but my solution involved using a list of [**decks**](./deck.h), I changed from queue to deck because working on a queue didnt allow me to have the flexibility I needed to print this info.
* Taking the Snail Graph example above as consideration my list of decks would be:
  * 1-2-4-0
  * 1-3-5-6-0  
* Each node of the deck has:
  * A boolean that represents if the current node has an ant, 
  * An int that represented the room number of the path,
  * The next and previous nodes.
* We also had to figure out a small algorithm to know how many ants to send in each path.
* Finally, I printed everything out by going right to left on the deck, and once I reached the start node I would send an ant if it was necessary according to the amount of ants left and our small algorithm.

## The Team
julee  
kradoste

