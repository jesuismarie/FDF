# FDF 42

## Description

FDF is a 42 School project which aims to create a simplified 3D graphic representation of a relief landscape. This project introduces concepts of graphics programming, and in particular how to place points in space, how to join them with segments, and most importantly how to observe the scene from a particular viewpoint.

## Compatibility

FDF is compatible with:
- MacOS
- Linux

## Features

- Render a 3D map from a 2D representation.
- **Zooming**: Zoom in and out to get a closer look or a broader view of the map.
- **Translation**: Shift the map in different directions.
- **Multiple Views**: Switch between different predefined viewing angles.
- **Movement**: Navigate around the 3D space.
- Color gradient based on altitude.

## How to Use

1. Clone the repository:

   ```
   git clone https://github.com/jesuismarie/FdF.git
   ```
2. Compile the program:

   ```
   make
   ```

3. Run MiniShell with a map from **test_maps**:

   ```
   ./minishell test_maps/[map-name.fdf]
   ```

## Controls

- **Left, Right, Up, Down Arrows**: Move the map.
- **+/- Key**: Zoom in and out.
- **T Key**: Top view.
- **I Key**: Isometric view.
- **P Key**: Horizontal view.
- **A/D Keys**: Rotate the map.
- **W/S Keys**: Z-axis translation.
