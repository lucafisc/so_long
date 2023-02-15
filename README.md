<h1 align="center">so_long</h1>

<p align="center">
<img src="https://i.imgur.com/MboIxvN.png" alt="drawing" width="120"/>
</p>

This project is a simple 2D game where a player must collect all the items on a map and then reach the exit. The game is built using the mlx library, which is a simple graphics library designed for use in creating 2D games and other visual applications. 

External functions: [`open`](https://man7.org/linux/man-pages/man2/open.2.html), [`close`](https://man7.org/linux/man-pages/man2/close.2.html), [`read`](https://man7.org/linux/man-pages/man2/read.2.html), [`write`](https://man7.org/linux/man-pages/man2/write.2.html), [`malloc`](https://man7.org/linux/man-pages/man3/malloc.3.html), [`free`](https://man7.org/linux/man-pages/man3/free.3.html), [`exit`](https://man7.org/linux/man-pages/man3/exit.3.html), and all functions of the [`minilibx`](https://github.com/42Paris/minilibx-linux).

## How to Play

The player starts at the beginning of the map and must collect all the items before reaching the exit. The player can move up, down, left, and right. The game is won when the player collects all the items and reaches the exit. The game is lost if the player collides with an enemy.

### Available Commands

The game supports the following commands:

Command | Description
--------|------------
W or ↑  | Move the player up
A or ←  | Move the player left
S or ↓  | Move the player down
D or →  | Move the player right
ESC     | Quit the game

## Map Format

The map is represented by a file with a .ber extension. The map must have a rectangular shape and can only contain the following characters:

Character | Description
----------|------------
1         | Wall
0         | Floor
P         | Player
E         | Exit
C         | Collectible

The map must have at one player, one exit, and at least one collectible. All collectibles must be reachable and the map must be surrounded by walls.

Here's an example of a valid map file:
```
111111111
1P00000C1
10000C001
111111001
100C00001
10C111111
100C00001
1000000E1
111111111
```
This file will generate the following map:

<img src="https://i.imgur.com/PKRKAL7.png" width="30%">

## How to use

Before building and running the game, you should first clone this repository and the `minilibx` library, which is required to compile the project. You can do this with the following commands:

```
git clone git@github.com:lucafisc/so_long.git
cd so_long
git clone https://github.com/42Paris/minilibx-linux.git mlx
```

For Mac, use the following commands instead:

```
git clone git@github.com:username/so_long.git
cd so_long
git clone https://github.com/42Paris/minilibx-opengl.git mlx
``` 

After cloning the `minilibx` repository, you will need to run the `configure` script to build the `minilibx` library:

```
cd mlx
./configure
cd ..
``` 

Now you can compile and run the game. To compile the game, run the following command in the project directory:

```
make
``` 

To start the game, run the following command with a `.ber` file as argument:


```
./so_long maps/map.ber
``` 

To clean the compiled files, run the following command:


```
make clean
```
