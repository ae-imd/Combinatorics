#include <stdexcept>
#include <ostream>
#include <stack>
#include <tuple>
#include "../include/combinatorics.h"

IMD::arithmetic_progression::arithmetic_progression(element_type start, element_type step)
    : __start(start), __curr(start), __step(step), __curr_index(0) {}

IMD::arithmetic_progression::arithmetic_progression(const IMD::arithmetic_progression &other)
    : __start(other.__start), __step(other.__step), __curr(other.__curr), __curr_index(other.__curr_index) {}

IMD::arithmetic_progression::arithmetic_progression(IMD::arithmetic_progression &&other) noexcept
    : __start(std::move(other.__start)), __step(std::move(other.__step)), __curr(std::move(other.__curr)), __curr_index(std::move(other.__curr_index)) {}

IMD::arithmetic_progression &IMD::arithmetic_progression::operator=(const IMD::arithmetic_progression &other)
{
    if (this != &other)
    {
        this->__start = other.__start;
        this->__step = other.__step;
        this->__curr = other.__curr;
        this->__curr_index = other.__curr_index;
    }
    return *this;
}

IMD::arithmetic_progression &IMD::arithmetic_progression::operator=(IMD::arithmetic_progression &&other) noexcept
{
    this->__start = std::move(other.__start);
    this->__step = std::move(other.__step);
    this->__curr = std::move(other.__curr);
    this->__curr_index = std::move(other.__curr_index);
    return *this;
}

bool IMD::arithmetic_progression::operator==(const arithmetic_progression &other)
{
    return this->__curr_index == other.__curr_index;
}
bool IMD::arithmetic_progression::operator!=(const arithmetic_progression &other)
{
    return !this->operator==(other);
}

IMD::arithmetic_progression::element_type IMD::arithmetic_progression::current() const noexcept
{
    return this->__curr;
}
IMD::arithmetic_progression::element_type IMD::arithmetic_progression::start() const noexcept
{
    return this->__start;
}
IMD::arithmetic_progression::element_type IMD::arithmetic_progression::step() const noexcept
{
    return this->__step;
}
IMD::arithmetic_progression::index_type IMD::arithmetic_progression::index() const noexcept
{
    return this->__curr_index;
}

void IMD::arithmetic_progression::next() noexcept
{
    this->__curr += this->__step;
    ++this->__curr_index;
}
void IMD::arithmetic_progression::previous() noexcept
{
    if (this->__curr_index == 0)
        return;

    this->__curr -= this->__step;
    --this->__curr_index;
}
void IMD::arithmetic_progression::forward(index_type offset) noexcept
{
    this->__curr += this->__step * offset;
    this->__curr_index += offset;
}
void IMD::arithmetic_progression::back(index_type offset) noexcept
{
    if (this->__curr_index == 0)
        return;

    if (offset > this->__curr_index)
        offset = this->__curr_index;

    this->__curr -= this->__step * offset;
    this->__curr_index -= offset;
}

void IMD::arithmetic_progression::reset() noexcept
{
    this->__curr = this->__start;
    this->__curr_index = 0;
}

IMD::geometric_progression::geometric_progression(element_type start, element_type ratio)
    : __start(start), __curr(start), __ratio(ratio), __curr_index(0)
{
    if (this->__ratio == 0)
        throw std::invalid_argument("The argument 'ratio' is zero");
}
IMD::geometric_progression::geometric_progression(const geometric_progression &other)
    : __start(other.__start), __ratio(other.__ratio), __curr(other.__curr), __curr_index(other.__curr_index) {}

IMD::geometric_progression::geometric_progression(geometric_progression &&other) noexcept
    : __start(std::move(other.__start)), __ratio(std::move(other.__ratio)), __curr(std::move(other.__curr)), __curr_index(std::move(other.__curr_index)) {}

IMD::geometric_progression &IMD::geometric_progression::operator=(const IMD::geometric_progression &other)
{
    if (this != &other)
    {
        this->__start = other.__start;
        this->__ratio = other.__ratio;
        this->__curr = other.__curr;
        this->__curr_index = other.__curr_index;
    }
    return *this;
}

IMD::geometric_progression &IMD::geometric_progression::operator=(IMD::geometric_progression &&other) noexcept
{
    this->__start = std::move(other.__start);
    this->__ratio = std::move(other.__ratio);
    this->__curr = std::move(other.__curr);
    this->__curr_index = std::move(other.__curr_index);
    return *this;
}

bool IMD::geometric_progression::operator==(const geometric_progression &other)
{
    return this->__curr_index == other.__curr_index;
}
bool IMD::geometric_progression::operator!=(const geometric_progression &other)
{
    return !this->operator==(other);
}

IMD::geometric_progression::element_type IMD::geometric_progression::current() const noexcept
{
    return this->__curr;
}
IMD::geometric_progression::element_type IMD::geometric_progression::start() const noexcept
{
    return this->__start;
}
IMD::geometric_progression::element_type IMD::geometric_progression::ratio() const noexcept
{
    return this->__ratio;
}
IMD::geometric_progression::index_type IMD::geometric_progression::index() const noexcept
{
    return this->__curr_index;
}

void IMD::geometric_progression::next() noexcept
{
    this->__curr *= this->__ratio;
    ++this->__curr_index;
}
void IMD::geometric_progression::previous() noexcept
{
    if (this->__curr_index == 0)
        return;

    this->__curr /= this->__ratio;
    --this->__curr_index;
}
void IMD::geometric_progression::forward(index_type offset) noexcept
{
    this->__curr *= std::pow(this->__ratio, offset);
    this->__curr_index += offset;
}
void IMD::geometric_progression::back(index_type offset) noexcept
{
    if (this->__curr_index == 0)
        return;
    if (offset > this->__curr_index)
        offset = this->__curr_index;

    this->__curr /= std::pow(this->__ratio, offset);
    this->__curr_index -= offset;
}
void IMD::geometric_progression::reset() noexcept
{
    this->__curr = this->__start;
    this->__curr_index = 0;
}

IMD::Fibonacci_numbers::Fibonacci_numbers(index_type start_index)
    : __curr_index(0), __curr(0), __next(1)
{
    this->goto_index(start_index);
}

IMD::Fibonacci_numbers::Fibonacci_numbers(const Fibonacci_numbers &other)
    : __curr_index(other.__curr_index), __curr(other.__curr), __next(other.__next) {}

IMD::Fibonacci_numbers::Fibonacci_numbers(Fibonacci_numbers &&other) noexcept
    : __curr_index(std::move(other.__curr_index)),
      __curr(std::move(other.__curr)),
      __next(std::move(other.__next)) {}

IMD::Fibonacci_numbers &IMD::Fibonacci_numbers::operator=(const Fibonacci_numbers &other)
{
    if (this != &other)
    {
        this->__curr_index = other.__curr_index;
        this->__curr = other.__curr;
        this->__next = other.__next;
    }
    return *this;
}

IMD::Fibonacci_numbers &IMD::Fibonacci_numbers::operator=(Fibonacci_numbers &&other) noexcept
{
    this->__curr_index = std::move(other.__curr_index);
    this->__curr = std::move(other.__curr);
    this->__next = std::move(other.__next);
    return *this;
}

bool IMD::Fibonacci_numbers::operator==(const Fibonacci_numbers &other)
{
    return this->__curr_index == other.__curr_index;
}
bool IMD::Fibonacci_numbers::operator!=(const Fibonacci_numbers &other)
{
    return !this->operator==(other);
}

IMD::Fibonacci_numbers::element_type IMD::Fibonacci_numbers::current() const noexcept
{
    return this->__curr;
}
void IMD::Fibonacci_numbers::next() noexcept
{
    element_type tmp = this->__next;
    this->__next += this->__curr;
    this->__curr = tmp;
    ++this->__curr_index;
}
void IMD::Fibonacci_numbers::previous() noexcept
{
    if (this->__curr_index == 0)
        return;

    element_type tmp = this->__next - this->__curr;
    this->__next = this->__curr;
    this->__curr = tmp;
    --this->__curr_index;
}
IMD::Fibonacci_numbers::index_type IMD::Fibonacci_numbers::index() const noexcept
{
    return this->__curr_index;
}

void IMD::Fibonacci_numbers::goto_index(index_type index) noexcept
{
    if (index == this->__curr_index)
        return;

    if (index < this->__curr_index)
    {
        const index_type steps_backward = this->__curr_index - index;
        const index_type reset_threshold = this->__curr_index / 2;

        if (steps_backward > reset_threshold)
            this->reset();
        else
        {
            while (this->__curr_index > index)
                this->previous();
            return;
        }
    }

    index_type remaining_steps = index - this->__curr_index;
    const index_type double_step_threshold = 2;

    while (remaining_steps > 0)
    {
        if (remaining_steps >= double_step_threshold)
        {
            // Double step: advance two positions in one operation
            element_type tmp1 = this->__curr + this->__next;
            element_type tmp2 = this->__next + tmp1;
            this->__curr = tmp1;
            this->__next = tmp2;
            this->__curr_index += 2;
            remaining_steps -= 2;
        }
        else
        {
            this->next();
            --remaining_steps;
        }
    }
}

void IMD::Fibonacci_numbers::reset() noexcept
{
    this->__curr = 0;
    this->__next = 1;
    this->__curr_index = 0;
}

IMD::Luka_numbers::Luka_numbers(index_type start_index)
    : __curr_index(0), __curr(2), __next(1)
{
    this->goto_index(start_index);
}

IMD::Luka_numbers::Luka_numbers(const Luka_numbers &other)
    : __curr_index(other.__curr_index), __curr(other.__curr), __next(other.__next) {}

IMD::Luka_numbers::Luka_numbers(Luka_numbers &&other) noexcept
    : __curr_index(std::move(other.__curr_index)),
      __curr(std::move(other.__curr)),
      __next(std::move(other.__next)) {}

IMD::Luka_numbers &IMD::Luka_numbers::operator=(const Luka_numbers &other)
{
    if (this != &other)
    {
        this->__curr_index = other.__curr_index;
        this->__curr = other.__curr;
        this->__next = other.__next;
    }
    return *this;
}

IMD::Luka_numbers &IMD::Luka_numbers::operator=(Luka_numbers &&other) noexcept
{
    this->__curr_index = std::move(other.__curr_index);
    this->__curr = std::move(other.__curr);
    this->__next = std::move(other.__next);
    return *this;
}
bool IMD::Luka_numbers::operator==(const Luka_numbers &other)
{
    return this->__curr_index == other.__curr_index;
}
bool IMD::Luka_numbers::operator!=(const Luka_numbers &other)
{
    return !this->operator==(other);
}

IMD::Luka_numbers::element_type IMD::Luka_numbers::current() const noexcept
{
    return this->__curr;
}
void IMD::Luka_numbers::next() noexcept
{
    element_type tmp = this->__next;
    this->__next += this->__curr;
    this->__curr = tmp;
    ++this->__curr_index;
}
void IMD::Luka_numbers::previous() noexcept
{
    if (this->__curr_index == 0)
        return;
    element_type tmp = this->__next - this->__curr;
    this->__next = this->__curr;
    this->__curr = tmp;
    --this->__curr_index;
}
IMD::Luka_numbers::index_type IMD::Luka_numbers::index() const noexcept
{
    return this->__curr_index;
}

void IMD::Luka_numbers::goto_index(index_type index) noexcept
{
    if (index == this->__curr_index)
        return;

    if (index < this->__curr_index)
    {
        const index_type steps_backward = this->__curr_index - index;
        const index_type reset_threshold = this->__curr_index / 2;

        if (steps_backward > reset_threshold)
            this->reset();
        else
        {
            while (this->__curr_index > index)
                this->previous();
            return;
        }
    }

    index_type remaining_steps = index - this->__curr_index;
    index_type double_step_threshold = 2;

    while (remaining_steps > 0)
    {
        if (remaining_steps >= double_step_threshold)
        {
            // Double step: advance two positions in one operation
            element_type tmp1 = this->__curr + this->__next;
            element_type tmp2 = this->__next + tmp1;
            this->__curr = tmp1;
            this->__next = tmp2;
            this->__curr_index += 2;
            remaining_steps -= 2;
        }
        else
        {
            this->next();
            --remaining_steps;
        }
    }
}

void IMD::Luka_numbers::reset() noexcept
{
    this->__curr = 2;
    this->__next = 1;
    this->__curr_index = 0;
}

IMD::Catalan_numbers::Catalan_numbers(index_type start_index)
    : __curr_index(0), __curr(1)
{
    this->goto_index(start_index);
}

IMD::Catalan_numbers::Catalan_numbers(const Catalan_numbers &other)
    : __curr_index(other.__curr_index), __curr(other.__curr) {}

IMD::Catalan_numbers::Catalan_numbers(Catalan_numbers &&other) noexcept
    : __curr_index(std::move(other.__curr_index)),
      __curr(std::move(other.__curr)) {}

IMD::Catalan_numbers &IMD::Catalan_numbers::operator=(const Catalan_numbers &other)
{
    if (this != &other)
    {
        this->__curr_index = other.__curr_index;
        this->__curr = other.__curr;
    }
    return *this;
}

IMD::Catalan_numbers &IMD::Catalan_numbers::operator=(Catalan_numbers &&other) noexcept
{
    this->__curr_index = std::move(other.__curr_index);
    this->__curr = std::move(other.__curr);
    return *this;
}

bool IMD::Catalan_numbers::operator==(const Catalan_numbers &other)
{
    return this->__curr_index == other.__curr_index;
}
bool IMD::Catalan_numbers::operator!=(const Catalan_numbers &other)
{
    return !this->operator==(other);
}

IMD::Catalan_numbers::element_type IMD::Catalan_numbers::current() const noexcept
{
    return this->__curr;
}

IMD::Catalan_numbers::index_type IMD::Catalan_numbers::index() const noexcept
{
    return this->__curr_index;
}

void IMD::Catalan_numbers::next() noexcept
{
    this->__curr = (this->__curr * 2 * (2 * this->__curr_index + 1)) / (this->__curr_index + 2);
    ++this->__curr_index;
}

void IMD::Catalan_numbers::previous() noexcept
{
    if (this->__curr_index == 0)
        return;

    this->__curr = (this->__curr * (this->__curr_index + 1)) / (2 * (2 * this->__curr_index - 1));
    --this->__curr_index;
}

void IMD::Catalan_numbers::goto_index(index_type target_index) noexcept
{
    if (target_index == this->__curr_index)
        return;

    if (target_index < this->__curr_index)
    {
        const index_type steps_backward = this->__curr_index - target_index;
        const index_type reset_threshold = this->__curr_index / 2;

        if (steps_backward > reset_threshold)
            this->reset();
        else
        {
            while (this->__curr_index > target_index)
                this->previous();
            return;
        }
    }

    while (this->__curr_index < target_index)
        this->next();
}

void IMD::Catalan_numbers::reset() noexcept
{
    this->__curr = 1;
    this->__curr_index = 0;
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

void IMD::Hanoi_classic_recursive_problem(size_t n, char from, char to, char aux, int &moves, std::ostream &os, const char *sep)
{
    if (n == 0)
        return;

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
void IMD::Hanoi_classic_iterative_problem(size_t n, char from, char to, char aux, int &moves, std::ostream &os, const char *sep)
{
    if (n == 0)
        return;

    std::stack<std::tuple<int, char, char, char>> st; // n, from, to, aux
    st.emplace(n, from, to, aux);

    while (!st.empty())
    {
        auto [curr_n, curr_from, curr_to, curr_aux] = st.top();
        st.pop();

        if (curr_n == 1)
        {
            os << "Move the " << curr_n << " disk from " << curr_from << " to " << curr_to << sep;
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
void IMD::Hanoi_restricted_recursive_problem(size_t n, char from, char to, char aux, int &moves, std::ostream &os, const char *sep)
{
    if (n == 0)
        return;

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