//3.13 
#include <iostream>
#include <stack>
#include <queue>
using namespace std;
int gstack(int n, int m)
{
    if (n == 0) 

        return 1;

    if (m == 0) 

        return gstack(n - 1, 1);

    return gstack(n, m - 1) + gstack(n - 1, m + 1);
}

//卡特兰公式法
long long bjc(long long n)

{

    if (n == 1)
        return 1;

    else
        return n * bjc(n - 1);
}

long long catalan(long long n)

{

    return (bjc(2 * n) / bjc(n + 1) / bjc(n));
}

int n, i, j;

int res;

stack<int> s;

queue<int> in, out;

void clear(stack<int> &s)

{

    while (!s.empty())

        s.pop();
}

void clear(queue<int> &s)

{

    while (!s.empty())

        s.pop();
}

void print(queue<int> i)

{

    while (!i.empty())

    {

        cout << i.front();

        i.pop();
    }

    cout << endl;
}

void dstack(queue<int> in, stack<int> s, queue<int> out)

{

    if (in.empty())

    {

        if (s.empty())

        {

            res++;

            print(out);
        }

        else

        {

            out.push(s.top());

            s.pop();

            dstack(in, s, out);
        }
    }

    else

    {

        if (!s.empty())

        {

            stack<int> ts;

            queue<int> tin, tout;

            tin = in;

            ts = s;

            tout = out;

            tout.push(ts.top());

            ts.pop();

            dstack(tin, ts, tout);
        }

        s.push(in.front());

        in.pop();

        dstack(in, s, out);
    }
}
int main()
{

    cout << "请输入末尾数字:";

    while (cin >> n)

    {

        res = 0;

        clear(in);

        clear(out);

        clear(s);

        for (i = n; i >= 1; i--)

            in.push(i);

        dstack(in, s, out);

        cout << "总数=" << res << endl;
    }
    cout << "总数:" << endl;
    for (i = 1; i < 15; i++)
        cout << "n=" << i << " " << gstack(i, 0) << endl;
    cout << endl
         << "总数:" << endl;
    for (i = 1; i < 15; i++)

        cout << "n=" << i << " " << catalan(i) << endl;
    return 0;
}
