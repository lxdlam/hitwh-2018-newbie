#include <stdio.h>
#include <math.h>

const double EPS = 0.5;
#define MaxL 22
#define SIZE 4000

typedef long long ll;

typedef struct comp
{
    double real;
    double imag;
} Complex;

Complex eps[1 << MaxL], inv[1 << MaxL];
Complex f[1 << MaxL], g[1 << MaxL];

Complex multi(Complex a, Complex b)
{
    Complex ret;
    ret.real = a.real * b.real - a.imag * b.imag;
    ret.imag = a.real * b.imag + a.imag * b.real;

    return ret;
}

void init_eps(int p)
{
    double pi = acos(-1);
    double angle = 2.0 * pi / p;
    for (int i = 0; i < p; i++)
    {
        eps[i].real = cos(i * angle);
        eps[i].imag = sin(i * angle);
        inv[i].real = eps[i].real;
        inv[i].imag = -eps[i].imag;
    }
}

void transform(int n, Complex *x, Complex *w)
{
    Complex t;
    for (int i = 0, j = 0; i != n; ++i)
    {
        if (i > j)
        {
            t.real = x[i].real;
            t.imag = x[i].imag;
            x[i].real = x[j].real;
            x[i].imag = x[j].imag;
            x[j].real = t.real;
            x[j].imag = t.imag;
        }
        for (int l = n >> 1; (j ^= l) < l; l >>= 1)
            ;
    }

    for (int i = 2; i <= n; i <<= 1)
    {
        int m = i >> 1;
        for (int j = 0; j < n; j += i)
        {
            for (int k = 0; k != m; ++k)
            {
                Complex z = multi(x[j + m + k], w[n / i * k]);
                x[j + m + k].real = x[j + k].real - z.real;
                x[j + m + k].imag = x[j + k].imag - z.imag;
                x[j + k].real = x[j + k].real + z.real;
                x[j + k].imag = x[j + k].imag + z.imag;
            }
        }
    }
}

int vis[SIZE];
ll ans[SIZE];

int main()
{
    int n, t, k;
    Complex a, b;
    ll val;

    scanf("%d", &n);

    int st = 2 * n * n - 1;
    int p = 1;
    while (p < st)
        p <<= 1;

    p <<= 1;

    init_eps(p);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            t = 2 * i * n + j;
            scanf("%d", &k);
            if (k)
            {
                f[t].real += k;
                f[st - t].imag += k;
                if (k > 1)
                    ans[0] += k * (k - 1) / 2;
            }
        }
    }

    transform(p, f, eps);

    for (int i = 1; i < p; i++)
    {
        double x1 = f[i].real, y1 = f[i].imag;
        double x2 = f[p - i].real, y2 = f[p - i].imag;
        a.real = (x1 + x2) * 0.5;
        a.imag = (y1 - y2) * 0.5;
        b.real = (y1 + y2) * 0.5;
        b.imag = -(x1 - x2) * 0.5;
        g[i] = multi(a, b);
    }

    g[0].real = f[0].imag * f[0].real;

    transform(p, g, inv);

    int cnt = 0;

    for (int i = st + 1; i < p; i++)
    {
        t = i - st;
        val = g[i].real / p + EPS;

        if (val)
        {
            int y = t % (2 * n);
            int x = t / (2 * n);

            if (y >= n)
            {
                y = 2 * n - y;
                x++;
            }

            int d = x + y;
            if (!vis[d])
            {
                cnt++;
                vis[d] = 1;
            }

            ans[d] += val;
        }
    }

    if (ans[0])
        cnt++;

    printf("%d\n", cnt);

    for (int i = 0; i < SIZE; i++)
        if (ans[i])
            printf("%d %lld\n", i, ans[i]);

    return 0;
}
