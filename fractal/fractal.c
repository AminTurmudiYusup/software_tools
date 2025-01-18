#include "fractal.h"
#include <stdlib.h>

/**
 * @brief Generates a Sierpiński triangle fractal on the given image.
 *
 * @param picture The image to generate the fractal on.
 */
void empty_fractal(image_p picture) {
    // Vertices of the triangle
    pixel_coord x0 = picture->width / 2, y0 = 0;
    pixel_coord x1 = 0, y1 = picture->height - 1;
    pixel_coord x2 = picture->width - 1, y2 = picture->height - 1;

    // Starting point inside the triangle
    pixel_coord x = picture->width / 2, y = picture->height / 2;

    // Number of points to plot
    int num_points = 10000;  // Adjust this for more/less detail

    for (int i = 0; i < num_points; ++i) {
        // Randomly choose one of the three vertices
        int choice = rand() % 3;
        if (choice == 0) {
            x = (x + x0) / 2;
            y = (y + y0) / 2;
        } else if (choice == 1) {
            x = (x + x1) / 2;
            y = (y + y1) / 2;
        } else {
            x = (x + x2) / 2;
            y = (y + y2) / 2;
        }

        // Set pixel at (x, y)
        if (x >= 0 && x < picture->width && y >= 0 && y < picture->height) {
            set_pixel(picture, x, y, 255);  // Set the pixel to white (255)
        }
    }
}
