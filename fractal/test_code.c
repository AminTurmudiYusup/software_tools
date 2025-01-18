#include <stdio.h>
#include "utest.h"
#include "image.h"
#include "fractal.h"

struct ImageTestFixture {
    image_p i;
};

UTEST_F_SETUP(ImageTestFixture) {
    utest_fixture->i = create_image(300, 300);
    ASSERT_NE((void *) utest_fixture->i, NULL);
}

UTEST_F_TEARDOWN(ImageTestFixture) {
    free_image(utest_fixture->i);
}

UTEST_F(ImageTestFixture, Set_Get_Pixel1){
    set_pixel(utest_fixture->i, 10, 10, 10);
    ASSERT_EQ(10, get_pixel(utest_fixture->i, 10, 10));
}

UTEST_F(ImageTestFixture, ClearImage2){
    clear_image(utest_fixture->i);
    ASSERT_EQ(0, get_pixel(utest_fixture->i, 10, 10));
}
struct FractalTestFixture {
    image_p i;
};

UTEST_F_SETUP(FractalTestFixture) {
    utest_fixture->i = create_image(300, 300);
    ASSERT_NE((void *) utest_fixture->i, NULL);
}

UTEST_F_TEARDOWN(FractalTestFixture) {
    free_image(utest_fixture->i);
}

UTEST_F(FractalTestFixture, FractalImageSize) {
    // Generate fractal
    empty_fractal(utest_fixture->i);
    
    // Verify that some pixels have been set
    int count = 0;
    for (pixel_coord y = 0; y < utest_fixture->i->height; ++y) {
        for (pixel_coord x = 0; x < utest_fixture->i->width; ++x) {
            if (get_pixel(utest_fixture->i, x, y) == 255) {
                ++count;
            }
        }
    }

    // There should be at least a few pixels set (since it's a fractal)
    ASSERT_GT(count, 100);  // Adjust the threshold based on expected fractal density
}


UTEST_F(FractalTestFixture, FractalPixelOutOfBounds) {
    // Generate fractal
    empty_fractal(utest_fixture->i);
    
    // Check a pixel that should definitely not be set (outside the fractal area)
    ASSERT_EQ(0, get_pixel(utest_fixture->i, 0, 0));  // Top-left corner
    ASSERT_EQ(0, get_pixel(utest_fixture->i, utest_fixture->i->width - 1, utest_fixture->i->height - 1));  // Bottom-right corner
}

UTEST_MAIN();