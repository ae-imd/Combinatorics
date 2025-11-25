#ifndef __IMD_COMBINATORICS_
#define __IMD_COMBINATORICS_

#include <cmath>
#include <iostream>

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
    size_t Pascal_binomial_coefficient(size_t k, size_t n);
    // Warning: if the methods is called, then dinamic memory will be allocated - don't forget to free it
    size_t iterative_binomial_coefficient(size_t k, size_t n);

    size_t Josephus_recursive_problem(size_t k, size_t n);
    size_t Josephus_iterative_problem(size_t k, size_t n);

    constexpr size_t recursive_factorial(size_t num)
    {
        if (num == 0 || num == 1)
            return 1;
        return num * recursive_factorial(num - 1);
    }
    constexpr size_t iterative_factorial(size_t num)
    {
        size_t res(1);
        for (size_t i(2); i <= num; ++i)
            res *= i;
        return res;
    }

    void Hanoi_classic_recursive_problem(int n, char from, char to, char aux, int &moves, std::ostream &os = std::cout, const char *sep = " ");
    void Hanoi_classic_iterative_problem(int n, char from, char to, char aux, int &moves, std::ostream &os = std::cout, const char *sep = " ");
    void Hanoi_restricted_recursive_problem(int n, char from, char to, char aux, int &moves, std::ostream &os = std::cout, const char *sep = " ");

}

#endif
