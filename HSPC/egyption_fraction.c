#include <stdio.h>

struct Fraction
{
    int num, den;
};
typedef struct Fraction Frac;

struct EgyptianFraction
{
    int noOfFractions;
    Frac fractions[100];
    Frac sum;
};
typedef struct EgyptianFraction EFrac;

EFrac input_one_fraction()
{
    EFrac inp;
    scanf("%d", &inp.noOfFractions);

    for (int i = 0; i < inp.noOfFractions; i++)
    {
        inp.fractions[i].num = 1;
        scanf("%d", &inp.fractions[i].den);
    }

    return inp;
}

void input_n_fractions(int n, EFrac eFracs[n])
{
    for (int i = 0; i < n; i++)
        eFracs[i] = input_one_fraction();
}

int computeGCD(int num, int den)
{
    int div;

    for (int i = 1; i <= num && i <= den; i++)
    {
        if (num % i == 0 && den % i == 0)
            div = i;
    }

    return div;
}

void compute_one_frac(EFrac *eFrac)
{
    eFrac->sum.num = 0;
    eFrac->sum.den = 1;

    for (int i = 0; i < eFrac->noOfFractions; i++)
    {
        eFrac->sum.num = (eFrac->sum.num * eFrac->fractions[i].den) + (eFrac->fractions[i].num * eFrac->sum.den);
        eFrac->sum.den = eFrac->sum.den * eFrac->fractions[i].den;
    }

    int divisor = computeGCD(eFrac->sum.num, eFrac->sum.den);

    eFrac->sum.num /= divisor;
    eFrac->sum.den /= divisor;
}

void compute_n_frac(int n, EFrac eFracs[n])
{
    for (int i = 0; i < n; i++)
        compute_one_frac(&eFracs[i]);
}

void output_one_frac(EFrac eFraction)
{
    for (int i = 0; i < eFraction.noOfFractions-1; i++)
        printf("%d/%d = %d/%d", eFraction.fractions[i].num, eFraction.fractions[i].den, eFraction.sum.num, eFraction.sum.den);
}

void output_n_fracs(int n, EFrac eFractions[n])
{
    for (int i = 0; i < n; i++)
        output_one_frac(eFractions[i]);
}

int main()
{
    int n;
    scanf("%d", &n);
    EFrac eFractions[n];
    input_n_fractions(n, eFractions);
    compute_n_frac(n, eFractions);
    output_n_fracs(n, eFractions);

    return 0;
}