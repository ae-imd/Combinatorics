#ifndef __IMD_COMBINATORICS_
#define __IMD_COMBINATORICS_

#include <cmath>

namespace IMD
{
    constexpr double EPSILON(1e-12);

    struct arithmetic_progression
    {
    private:
        double __start;
        double __curr;
        double __step;

    public:
        arithmetic_progression(double start, double step);
        arithmetic_progression(const arithmetic_progression &other);
        arithmetic_progression(arithmetic_progression &&other) noexcept;

        arithmetic_progression &operator=(const arithmetic_progression &other);
        arithmetic_progression &operator=(arithmetic_progression &&other) noexcept;

        double current() const noexcept;
        double start() const noexcept;
        double step() const noexcept;

        void next() noexcept;
        void previous() noexcept;

        void forward(size_t offset);
        void back(size_t offset);

        void move(long offset);

        void reset() noexcept;
    };

    struct geometric_progression
    {
    private:
        double __start;
        double __curr;
        double __ratio;

    public:
        geometric_progression(double start, double ratio);
        geometric_progression(const geometric_progression &other);
        geometric_progression(geometric_progression &&other) noexcept;

        geometric_progression &operator=(const geometric_progression &other);
        geometric_progression &operator=(geometric_progression &&other) noexcept;

        double current() const noexcept;
        double start() const noexcept;
        double ratio() const noexcept;

        void next() noexcept;
        void previous() noexcept;

        void forward(size_t offset);
        void back(size_t offset);

        void move(long offset);

        void reset() noexcept;
    };

    size_t **Pascal_triangle(size_t rows);
    size_t *Pascal_triangle_row(size_t row_index);

    // Warning: if the methods is called, then dinamic memory will be allocated - don't forget to free it
    size_t binomial_coefficient_Pascal(size_t k, size_t n);
    // Warning: if the methods is called, then dinamic memory will be allocated - don't forget to free it
    size_t binomial_coefficient_iterative(size_t k, size_t n);
}

#endif
