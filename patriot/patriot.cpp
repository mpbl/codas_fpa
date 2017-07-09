// Adapted from V. Innocente's patriot example

#include<cstdio>

void patriot_naive()
{
    float tenth = 0.1f;
    float time_since_boot = 0.f;
    long long nsteps = 0;
    while (nsteps < 1000000) {
        time_since_boot += tenth;
        ++nsteps;
        if (nsteps < 21 || nsteps % 36000 == 0)
            printf("%lld %f %a\n", nsteps, time_since_boot, time_since_boot);
    }
}

float kahan_sum(float const* input, size_t n)
{
    float sum = input[0];
    float compensation = 0.0f; // A running compensation for lost low-order bits.

    for (size_t i = 1; i != n; ++i) {
        float y = input[i] - compensation; // so far, so good: t is zero.
        float s = sum + y; // Alas, sum is big, y small, so low-order digits of y are lost.
        compensation = (s - sum) - y; // ( s - sum) recovers the high-order part of y
        // subtracting y recovers -(low part of y)
        sum = s; //Algebraically, t should always be zero.
        // Beware eagerly optimising compilers!
    } //Next time around, the lost low part will be added to y in a fresh attempt.
    return sum;
}

void patriot_kahan()
{
  // Fill me...
}

int main()
{
    patriot_naive();
    patriot_kahan();
    return 0;
}
