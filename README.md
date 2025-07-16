# Cub3D

**Cub3D** is a 3D raycasting project developed as part of the 42 curriculum. This bonus version extends the mandatory project by introducing animated walls and a dynamic game mechanic: walls cycle through colors until the player reaches a specific point in the map — the black spot — which stabilizes the environment. This is a group project and I had the pleasure of working with Gabriel [https://github.com/gabrielrial]. While Gabril tackled the raycasting logic, I focused on parsing and validation. 

---

## 🔑 Key Learnings

- Raycasting logic for rendering 3D environments
- Texture handling and dynamic color updates
- Handling special map elements and game triggers
- Real-time animation effects using frame updates
- Game state management and transitions

---

## 🎯 Learning Objectives

- Deepen understanding of 2D-to-3D rendering techniques in C
- Master use of the MiniLibX graphics library
- Implement animation and real-time visual changes
- Handle advanced map parsing and interaction logic
- Practice event handling and custom game mechanics

---

## 🎮 Gameplay (Bonus Version)

- Walls **cycle through colors** to create a surreal, animated experience.
- A special tile on the map — the **black spot** — ends the animation when crossed.
- Player moves freely through the map using `WASD.`
- Mini-map and door mechanics are also implemented.
  
---

## 🛠️ Usage

1. **Compile** the bonus version:  
   From the project root directory, simply run:  
    make bonus
2. ./cub3D_bonus maps/passing/bonus2.cub

Note: Playing the game requires the MiniLibX graphics library. The project includes a local copy that is used during compilation.

[ezgif-1615db326c0e32.webm](https://github.com/user-attachments/assets/1efc9034-9c49-4970-a2ee-f316d1261cfb)


