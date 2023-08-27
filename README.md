# ApproximatingPi

A project where multiple methods for approximating the constant $\pi$ are implemented. This is done in `C++` using `SFML 2.6.0`, with the `mingw32` compiler.

## Installing and running

1. Ensure `SFML 2.6.0` has been installed and statically linked.
2. Navigate to the desired implementations directory and open a terminal.
3. Type `mingw32-make all` to create an executable.
4. Open the executable.

## Implementations

### CircleRatioCounter

This uses the method as discussed in [The Coding Train](https://www.youtube.com/@TheCodingTrain)'s video [*Coding Challenge 95: Approximating the Value of Pi*](https://www.youtube.com/watch?v=5cNnf_7e92Q&ab_channel=TheCodingTrain). 

Take the area of a circle with radius $r$: $\pi r^2$. Now the area of a square with side length $r$: $4 r^2$. The ratio of these is $\frac{\pi r^2}{4 r^2} = \frac{\pi}{4}$. Now imagine the circle is inside the center of the square (so that its top, bottom, left and right just about touch its sides), If we randomly place a point in the square, it may or may not be in the circle. If we randomly place many points in the square, and take count of how many are in the circle, we can get a ratio of the number of points in the circle to the number of points in the square (total). Thus, we find that: $\frac{\pi}{4} = \frac{\mathrm{circle points}}{\mathrm{total points}} \Rightarrow \pi = 4 \times \frac{\mathrm{circle points}}{\mathrm{total points}}$. This allows us to approximate $\pi$. A picture of this implementation is as follows:

![approximatingpi](https://github.com/seanie5011/ApproximatingPi/assets/72211395/0e080d22-e1bb-4977-9fe9-6903d6a9acef)
