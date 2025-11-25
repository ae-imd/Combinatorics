#ifndef __IMD_COMBINATORICS_
#define __IMD_COMBINATORICS_

#include <cmath>
#include <string>
#include <iostream>

namespace IMD
{
    struct arithmetic_progression
    {
    public:
        using index_type = size_t;
        using element_type = double;

    private:
        element_type __start, __curr, __step;
        index_type __curr_index;

    public:
        arithmetic_progression(element_type start, element_type step);
        arithmetic_progression(const arithmetic_progression &other);
        arithmetic_progression(arithmetic_progression &&other) noexcept;

        arithmetic_progression &operator=(const arithmetic_progression &other);
        arithmetic_progression &operator=(arithmetic_progression &&other) noexcept;

        bool operator==(const arithmetic_progression &other);
        bool operator!=(const arithmetic_progression &other);

        element_type current() const noexcept;
        element_type start() const noexcept;
        element_type step() const noexcept;
        index_type index() const noexcept;

        void next() noexcept;
        void previous() noexcept;

        void forward(index_type offset) noexcept;
        void back(index_type offset) noexcept;

        void reset() noexcept;
    };

    struct geometric_progression
    {
    public:
        using index_type = size_t;
        using element_type = double;

    private:
        element_type __start, __curr, __ratio;
        index_type __curr_index;

    public:
        geometric_progression(element_type start, element_type ratio);
        geometric_progression(const geometric_progression &other);
        geometric_progression(geometric_progression &&other) noexcept;

        geometric_progression &operator=(const geometric_progression &other);
        geometric_progression &operator=(geometric_progression &&other) noexcept;

        bool operator==(const geometric_progression &other);
        bool operator!=(const geometric_progression &other);

        element_type current() const noexcept;
        element_type start() const noexcept;
        element_type ratio() const noexcept;
        index_type index() const noexcept;

        void next() noexcept;
        void previous() noexcept;

        void forward(index_type offset) noexcept;
        void back(index_type offset) noexcept;

        void reset() noexcept;
    };

    struct Fibonacci_numbers
    {
    public:
        using index_type = std::size_t;
        using element_type = long;

    private:
        index_type __curr_index;
        element_type __curr, __next;

    public:
        Fibonacci_numbers(index_type start_index = 0);

        Fibonacci_numbers(const Fibonacci_numbers &other);
        Fibonacci_numbers(Fibonacci_numbers &&other) noexcept;

        Fibonacci_numbers &operator=(const Fibonacci_numbers &other);
        Fibonacci_numbers &operator=(Fibonacci_numbers &&other) noexcept;

        bool operator==(const Fibonacci_numbers &other);
        bool operator!=(const Fibonacci_numbers &other);

        element_type current() const noexcept;
        index_type index() const noexcept;

        void next() noexcept;
        void previous() noexcept;
        void goto_index(index_type index) noexcept;

        void reset() noexcept;
    };

    struct Luka_numbers
    {
    public:
        using index_type = std::size_t;
        using element_type = long;

    private:
        index_type __curr_index;
        element_type __curr, __next;

    public:
        Luka_numbers(index_type start_index = 0);

        Luka_numbers(const Luka_numbers &other);
        Luka_numbers(Luka_numbers &&other) noexcept;

        Luka_numbers &operator=(const Luka_numbers &other);
        Luka_numbers &operator=(Luka_numbers &&other) noexcept;

        bool operator==(const Luka_numbers &other);
        bool operator!=(const Luka_numbers &other);

        element_type current() const noexcept;
        index_type index() const noexcept;

        void next() noexcept;
        void previous() noexcept;
        void goto_index(index_type index) noexcept;

        void reset() noexcept;
    };

    struct Catalan_numbers
    {
    public:
        using index_type = std::size_t;
        using element_type = long long; // Используем long long для больших чисел

    private:
        index_type __curr_index;
        element_type __curr;

    public:
        Catalan_numbers(index_type start_index = 0);

        Catalan_numbers(const Catalan_numbers &other);
        Catalan_numbers(Catalan_numbers &&other) noexcept;

        Catalan_numbers &operator=(const Catalan_numbers &other);
        Catalan_numbers &operator=(Catalan_numbers &&other) noexcept;

        bool operator==(const Catalan_numbers &other);
        bool operator!=(const Catalan_numbers &other);

        element_type current() const noexcept;
        index_type index() const noexcept;

        void next() noexcept;
        void previous() noexcept;
        void goto_index(index_type index) noexcept;

        void reset() noexcept;
    };

    // Warning: if the methods is called, then dinamic memory will be allocated - don't forget to free it
    unsigned long long **Pascal_triangle(size_t rows_amount);
    // Warning: if the methods is called, then dinamic memory will be allocated - don't forget to free it
    unsigned long long *Pascal_triangle_row(size_t row_index);

    unsigned long long Pascal_binomial_coefficient(size_t k, size_t n);
    unsigned long long iterative_binomial_coefficient(size_t k, size_t n);

    constexpr unsigned long long recursive_factorial(size_t num)
    {
        if (num == 0 || num == 1)
            return 1;
        return num * recursive_factorial(num - 1);
    }
    constexpr unsigned long long iterative_factorial(size_t num)
    {
        size_t res(1);
        for (size_t i(2); i <= num; ++i)
            res *= i;
        return res;
    }

    constexpr unsigned long long non_negative_power_of_two(long long power)
    {
        return 1 << power;
    }

    size_t Josephus_recursive_problem(size_t k, size_t n);
    size_t Josephus_iterative_problem(size_t k, size_t n);

    void Hanoi_classic_recursive_problem(size_t n, char from, char to, char aux, int &moves, std::ostream &os = std::cout, const char *sep = " ");
    void Hanoi_classic_iterative_problem(size_t n, char from, char to, char aux, int &moves, std::ostream &os = std::cout, const char *sep = " ");
    void Hanoi_restricted_recursive_problem(size_t n, char from, char to, char aux, int &moves, std::ostream &os = std::cout, const char *sep = " ");

    unsigned long long surjective_mappings_inclusion_exclusion(size_t n, size_t m);
    std::string binomial_formula(size_t n);

}

#endif
