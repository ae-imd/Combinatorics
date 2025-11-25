#include <cmath>

namespace IMD
{
    constexpr double EPSILON(1e-12);

    struct arithmetic_progression;
    struct geometric_progression;

    size_t **Pascal_triangle(size_t rows);
    size_t *IMD::Pascal_triangle_row(size_t row_index);
}
