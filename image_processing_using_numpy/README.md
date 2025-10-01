# image_processing_using_numpy

# Image Negative Project

## Overview
This project demonstrates basic image processing using **PIL**, **NumPy**, and **Matplotlib**.  
It converts an uploaded image into its negative.

## Features
- Load an image (`.jpg`, `.png`, `.gif`)  
- Convert to negative image  
- Display original vs changed image side by side  
- Save the processed image to disk (`output.jpg`)  
- Extendable for cinematic color grading (warm, cool, desaturated looks)


# Complete Details
A pixel (short for picture element) is the smallest unit of a digital image or display. Each pixel is made of three sub-pixels: Red (R), Green (G), and Blue (B) - this is the RGB color model.

Each sub-pixel can shine with a brightness between 0 (off) and 255 (full brightness). Together, these three values define the final color we see on a screen.

For example:

Red → (255, 0, 0) → only the red sub-pixel is on
Green → (0, 255, 0)
Blue → (0, 0, 255)
White → (255, 255, 255) → all on at full brightness
Black → (0, 0, 0) → all off
Yellow → (255, 255, 0) → red + green together

When you load an image into NumPy, those pixels are arranged into a 3D array with shape:

(height, width, 3)
height → number of rows (pixels vertically)
width → number of columns (pixels horizontally)
3 → the RGB channels

So, a 200×300 image is stored as (200, 300, 3).

Using two indices (row, col) → you get a full pixel [R,G,B].
Using three indices (row, col, channel) → you get a single channel value.

But what about photographic film? 

Unlike screens, photo film doesn’t store RGB directly. Instead, it works in layers:

Top layer → sensitive to blue light
Middle layer → sensitive to green light (protected by a yellow filter so leftover blue doesn’t interfere)
Bottom layer → sensitive to red light

During development, each layer forms a dye complementary to the absorbed light:

Blue-sensitive layer → forms Yellow dye
Green-sensitive layer → forms Magenta dye
Red-sensitive layer → forms Cyan dye

This is called the subtractive color process (CMY). When the negative is printed, colors are inverted again, and the dyes recombine to reproduce the original scene.

To mimic this digitally, we invert pixel colors:

negative_pixel = 255 - original_pixel 
This gives the complementary color for each channel.

RGB is the additive model (used in screens)
CMY is the subtractive model (used in printing and film)

Together, they explain why negatives look the way they do and how both digital and analog images come to life.
