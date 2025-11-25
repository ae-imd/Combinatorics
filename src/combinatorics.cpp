#include <stdexcept>
#include <ostream>
#include <stack>
#include <tuple>
#include "../include/combinatorics.h"

IMD::arithmetic_progression::arithmetic_progression(double start, double step)
    : __start(start), __curr(start), __step(step) {}

IMD::arithmetic_progression::arithmetic_progression(const IMD::arithmetic_progression &other)
    : __start(other.__start), __step(other.__step), __curr(other.__curr) {}

IMD::arithmetic_progression::arithmetic_progression(IMD::arithmetic_progression &&other) noexcept
    : __start(std::move(other.__start)), __step(std::move(other.__step)), __curr(std::move(other.__curr)) {}

IMD::arithmetic_progression &IMD::arithmetic_progression::operator=(const IMD::arithmetic_progression &other)
{
    if (this != &other)
    {
        this->__start = other.__start;
        this->__step = other.__step;
        this->__curr = other.__curr;
    }
    return *this;
}

IMD::arithmetic_progression &IMD::arithmetic_progression::operator=(IMD::arithmetic_progression &&other) noexcept
{
    this->__start = std::move(other.__start);
    this->__step = std::move(other.__step);
    this->__curr = std::move(other.__curr);
    return *this;
}

double IMD::arithmetic_progression::current() const noexcept
{
    return this->__curr;
}
double IMD::arithmetic_progression::start() const noexcept
{
    return this->__start;
}
double IMD::arithmetic_progression::step() const noexcept
{
    return this->__step;
}

void IMD::arithmetic_progression::next() noexcept
{
    this->__curr += this->__step;
}
void IMD::arithmetic_progression::previous() noexcept
{
    if (std::abs(this->__curr - this->__start) < EPSILON)
        return;

    this->__curr -= this->__step;
}
void IMD::arithmetic_progression::forward(size_t offset)
{
    while (offset != 0)
    {
        this->next();
        --offset;
    }
}
void IMD::arithmetic_progression::back(size_t offset)
{
    while (offset != 0)
    {
        this->previous();
        --offset;
    }
}
void IMD::arithmetic_progression::move(long offset)
{
    if (offset < 0)
        back(-offset);
    else
        forward(offset);
}

void IMD::arithmetic_progression::reset() noexcept
{
    this->__curr = this->__start;
}

IMD::geometric_progression::geometric_progression(double start, double ratio)
    : __start(start), __curr(start), __ratio(ratio) {}

IMD::geometric_progression::geometric_progression(const geometric_progression &other)
    : __start(other.__start), __ratio(other.__ratio), __curr(other.__curr) {}

IMD::geometric_progression::geometric_progression(geometric_progression &&other) noexcept
    : __start(other.__start), __ratio(other.__ratio), __curr(other.__curr) {}

IMD::geometric_progression &IMD::geometric_progression::operator=(const IMD::geometric_progression &other)
{
    if (this != &other)
    {
        this->__start = other.__start;
        this->__ratio = other.__ratio;
        this->__curr = other.__curr;
    }
    return *this;
}

IMD::geometric_progression &IMD::geometric_progression::operator=(IMD::geometric_progression &&other) noexcept
{
    this->__start = std::move(other.__start);
    this->__ratio = std::move(other.__ratio);
    this->__curr = std::move(other.__curr);
    return *this;
}

double IMD::geometric_progression::current() const noexcept
{
    return this->__curr;
}
double IMD::geometric_progression::start() const noexcept
{
    return this->__start;
}
double IMD::geometric_progression::ratio() const noexcept
{
    return this->__ratio;
}
void IMD::geometric_progression::next() noexcept
{
    this->__curr *= this->__ratio;
}
void IMD::geometric_progression::previous() noexcept
{
    if (std::abs(this->__curr - this->__start) < EPSILON)
        return;

    this->__curr /= this->__ratio;
}
void IMD::geometric_progression::forward(size_t offset)
{
    while (offset != 0)
    {
        this->next();
        --offset;
    }
}
void IMD::geometric_progression::back(size_t offset)
{
    while (offset != 0)
    {
        this->previous();
        --offset;
    }
}
void IMD::geometric_progression::move(long offset)
{
    if (offset < 0)
        back(-offset);
    else
        forward(offset);
}
void IMD::geometric_progression::reset() noexcept
{
    this->__curr = this->__start;
}

// Warning: if the methods is called, then dinamic memory will be allocated - don't forget to free it
size_t **IMD::Pascal_triangle(size_t rows_amount)
{
    size_t **res = new size_t *[rows_amount];
    for (size_t i(0); i < rows_amount; ++i)
    {
        res[i] = new size_t[i + 1];

        // Borders
        res[i][0] = res[i][i] = 1;

        // Internal elements
        for (size_t j = 1; j < i; ++j)
            res[i][j] = res[i - 1][j - 1] + res[i - 1][j];
    }
    return res;
}
// Warning: if the methods is called, then dinamic memory will be allocated - don't forget to free it
size_t *IMD::Pascal_triangle_row(size_t row_index)
{
    size_t *res = new size_t[row_index + 1];
    res[0] = (1);

    for (size_t i(1); i <= row_index; ++i)
    {
        res[i] = (1);
        for (size_t j(i - 1); j > 0; --j)
            res[j] = res[j] + res[j - 1];
    }

    return res;
}

size_t IMD::Pascal_binomial_coefficient(size_t k, size_t n)
{
    if (k > n)
        throw std::invalid_argument("The argument 'k' is more than the argument 'n'");
    if (k == 0 || k == n)
        return 1;
    if (k == 1)
        return n;
    if (k > n - k) // Optimization
        k = n - k;

    size_t *tmp = IMD::Pascal_triangle_row(n);
    size_t res = tmp[k];
    delete[] tmp;
    return res;
}
size_t IMD::iterative_binomial_coefficient(size_t k, size_t n)
{
    if (k > n)
        throw std::invalid_argument("The argument 'k' is more than the argument 'n'");
    if (k == 0 || k == n)
        return 1;
    if (k == 1)
        return n;
    if (k > n - k) // Optimization
        k = n - k;

    size_t res(1);
    for (size_t i(1); i <= k; ++i)
    {
        res *= (n - k + i);
        res /= i;
    }
    return res;
}

size_t IMD::Josephus_recursive_problem(size_t k, size_t n)
{
    if (n == 1)
        return 0;
    return (Josephus_recursive_problem(k, n - 1) + k) % n;
}
size_t IMD::Josephus_iterative_problem(size_t k, size_t n)
{
    size_t res(0);
    for (size_t i(2); i <= n; ++i)
        res = (res + k) % i;
    return res;
}

void IMD::Hanoi_classic_recursive_problem(int n, char from, char to, char aux, int &moves, std::ostream &os, const char *sep)
{
    if (n == 1)
    {
        os << "Move the " << n << " disk from " << from << " to " << to << sep;
        ++moves;
        return;
    }
    Hanoi_classic_recursive_problem(n - 1, from, aux, to, moves, os, sep);
    os << "Move the " << n << " disk from " << from << " to " << to << sep;
    ++moves;
    Hanoi_classic_recursive_problem(n - 1, aux, to, from, moves, os, sep);
}
void IMD::Hanoi_classic_iterative_problem(int n, char from, char to, char aux, int &moves, std::ostream &os, const char *sep)
{
    std::stack<std::tuple<int, char, char, char>> st; // n, from, to, aux
    st.emplace(n, from, to, aux);

    while (!st.empty())
    {
        auto [curr_n, curr_from, curr_to, curr_aux] = st.top();
        st.pop();

        if (curr_n == 1)
        {
            os << "Move disk from " << curr_from << " to " << curr_to << sep;
            ++moves;
        }
        else
        {
            st.emplace(curr_n - 1, curr_aux, curr_to, curr_from);
            st.emplace(1, curr_from, curr_to, curr_aux);
            st.emplace(curr_n - 1, curr_from, curr_aux, curr_to);
        }
    }
}
void IMD::Hanoi_restricted_recursive_problem(int n, char from, char to, char aux, int &moves, std::ostream &os, const char *sep)
{
    if (n == 1)
    {
        os << "Move the " << n << " disk from " << from << " to " << aux << sep;
        os << "Move the " << n << " disk from " << aux << " to " << to << sep;
        moves += 2;
        return;
    }

    Hanoi_restricted_recursive_problem(n - 1, from, to, aux, moves, os, sep);
    os << "Move the " << n << " disk from " << from << " to " << aux << sep;
    ++moves;
    Hanoi_restricted_recursive_problem(n - 1, to, from, aux, moves, os, sep);
    os << "Move the " << n << " disk from " << aux << " to " << to << sep;
    ++moves;
    Hanoi_restricted_recursive_problem(n - 1, from, to, aux, moves, os, sep);
}