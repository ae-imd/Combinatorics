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

        arithmetic_progression operator=(const arithmetic_progression &other)
        {
            if (this != &other)
            {
                this->__start = other.__start;
                this->__step = other.__step;
                this->__curr = other.__curr;
            }
            return *this;
        }

        arithmetic_progression operator=(arithmetic_progression &&other)
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

}
