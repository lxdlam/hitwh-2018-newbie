#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include <sstream>

using namespace std;

const int EXIT_AC = 42;
const int EXIT_WA = 43;

ifstream judgein, judgeans;

void wrong_answer(const string &err)
{
    cerr << err << endl;
    exit(EXIT_WA);
}

vector<long long> parseLongs(string input)
{
    stringstream ss(input);
    vector<long long> ret;
    long long v;
    while (ss >> v)
        ret.push_back(v);

    return ret;
}

long long calc(long long a, long long b, long long c, long long d)
{
    return min(abs(a - b), abs(c - d)) ^ a ^ b ^ c ^ d;
}

void checkAns(long long N, vector<long long> v)
{
    if (v.size() != 4)
    {
        stringstream err_stream;
        err_stream << "The contestant given not exactly 4 numbers. ";
        err_stream << v.size();
        err_stream << " numbers are given.";
        wrong_answer(err_stream.str());
    }

    long long ret = calc(v[0], v[1], v[2], v[3]);

    if (ret != N)
    {
        stringstream err_stream;
        err_stream << N;
        err_stream << " required, but ";
        err_stream << ret;
        err_stream << " are given.";
        wrong_answer(err_stream.str());
    }
}

int main(int argv, char **args)
{
    judgein.open(args[1]);

    int T, lines = 0;
    long long N;
    judgein >> T;
    string input;

    for (; getline(cin, input); lines++)
    {
        judgein >> N;
        auto inputs = parseLongs(input);

        checkAns(N, inputs);
    }

    if (lines != T)
    {
        stringstream err_stream;
        err_stream << T;
        err_stream << " lines required, but ";
        err_stream << lines;
        err_stream << " lines are given.";
        wrong_answer(err_stream.str());
    }

    exit(EXIT_AC);
}
