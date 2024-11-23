# FDF 42

## Description

FDF is a 42 School project that creates a simplified 3D graphic representation of a relief landscape. This project introduces concepts of graphics programming, including how to position points in space, connect them with segments, and observe the scene from different viewpoints.

## Compatibility

FDF is compatible with:
- **MacOS**
- **Linux**

## Features

- Render a 3D map from a 2D representation.
- **Zooming**: Zoom in and out for different perspectives.
- **Translation**: Shift the map in all directions.
- **Multiple Views**: Switch between predefined viewing angles.
- **Movement**: Navigate through the 3D space.
- **Color Gradient**: Altitude-based color representation.

![Rendered Map](pictures/t1.jpg)

![Rendered Map](pictures/whole_world.jpg)

## How to Use on Linux

### Prerequisites

1. Install the required dependencies:
   ```bash
   sudo apt-get update -y
   sudo apt-get install build-essential -y
   sudo apt-get install xorg libxext-dev zlib1g-dev libbsd-dev -y
   ```
2. Clone the repository:
   ```bash
   git clone https://github.com/jesuismarie/FdF.git
   ```
3. Compile the program:
   ```bash
   make
   ```
4. Run FDF with a map from **test_maps**:
   ```bash
   ./fdf maps/[map-name.fdf]
   ```

---

## How to Use on MacOS

1. Clone the repository:
   ```bash
   git clone https://github.com/jesuismarie/FdF.git
   ```
2. Compile the program:
   ```bash
   make
   ```
3. Run FDF with a map from **test_maps**:
   ```bash
   ./fdf maps/[map-name.fdf]
   ```

---

## Controls

- **Arrow Keys**: Move the map.
- **+/-**: Zoom in and out.
- **T**: Top view.
- **I**: Isometric view.
- **P**: Horizontal view.
- **A/D**: Rotate the map.
- **W/S**: Z-axis translation.

---

### Demonstration of Controls
![Demonstration of Controls](pictures/controls.gif)
