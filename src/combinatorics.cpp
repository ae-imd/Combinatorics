#include "../include/combinatorics.h"

struct IMD::arithmetic_progression
{
private:
    double __start;
    double __curr;
    double __step;

public:
    arithmetic_progression(double start, double step)
    {
        this->__start = start;
        this->__step = step;
        this->__curr = start;
    }

    arithmetic_progression(const arithmetic_progression &ap)
    {
        this->__start = ap.__start;
        this->__step = ap.__step;
        this->__curr = ap.__curr;
    }

    arithmetic_progression(arithmetic_progression &&ap)
    {
        this->__start = std::move(ap.__start);
        this->__step = std::move(ap.__step);
        this->__curr = std::move(ap.__curr);
    }

    arithmetic_progression &operator=(const arithmetic_progression &other)
    {
        if (this != &other)
        {
            this->__start = other.__start;
            this->__step = other.__step;
            this->__curr = other.__curr;
        }
        return *this;
    }

    arithmetic_progression &operator=(arithmetic_progression &&other)
    {
        this->__start = std::move(other.__start);
        this->__step = std::move(other.__step);
        this->__curr = std::move(other.__curr);
        return *this;
    }

    double current() noexcept
    {
        return this->__curr;
    }
    void next() noexcept
    {
        this->__curr += this->__step;
    }
    void previous() noexcept
    {
        if (std::abs(this->__curr - this->__start) < EPSILON)
            return;

        this->__curr -= this->__step;
    }
    void forward(size_t offset)
    {
        while (offset != 0)
        {
            this->next();
            --offset;
        }
    }
    void back(size_t offset)
    {
        while (offset != 0)
        {
            this->previous();
            --offset;
        }
    }
    void move(long offset)
    {
        if (offset < 0)
            back(-offset);
        else
            forward(offset);
    }
};

struct IMD::geometric_progression
{
private:
    double __start;
    double __curr;
    double __step;

public:
    geometric_progression(double start, double step)
    {
        this->__start = start;
        this->__step = step;
        this->__curr = start;
    }

    geometric_progression(const geometric_progression &ap)
    {
        this->__start = ap.__start;
        this->__step = ap.__step;
        this->__curr = ap.__curr;
    }

    geometric_progression(geometric_progression &&ap)
    {
        this->__start = std::move(ap.__start);
        this->__step = std::move(ap.__step);
        this->__curr = std::move(ap.__curr);
    }

    geometric_progression &operator=(const geometric_progression &other)
    {
        if (this != &other)
        {
            this->__start = other.__start;
            this->__step = other.__step;
            this->__curr = other.__curr;
        }
        return *this;
    }

    geometric_progression &operator=(geometric_progression &&other)
    {
        this->__start = std::move(other.__start);
        this->__step = std::move(other.__step);
        this->__curr = std::move(other.__curr);
        return *this;
    }

    double current() noexcept
    {
        return this->__curr;
    }
    void next() noexcept
    {
        this->__curr *= this->__step;
    }
    void previous() noexcept
    {
        if (std::abs(this->__curr - this->__start) < EPSILON)
            return;

        this->__curr /= this->__step;
    }
    void forward(size_t offset)
    {
        while (offset != 0)
        {
            this->next();
            --offset;
        }
    }
    void back(size_t offset)
    {
        while (offset != 0)
        {
            this->previous();
            --offset;
        }
    }
    void move(long offset)
    {
        if (offset < 0)
            back(-offset);
        else
            forward(offset);
    }
};

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