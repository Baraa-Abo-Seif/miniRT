#include "check.h"

void check_color(t_color color)
{
    if (color.r < 0 || color.r > 255
        || color.g < 0 || color.g > 255
        || color.b < 0 || color.b > 255)
    {
        error_msg("RGB values must be between 0 and 255");
        exit(EXIT_FAILURE);
    }
}