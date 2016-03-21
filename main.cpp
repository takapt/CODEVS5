#ifndef LOCAL
#define NDEBUG
#endif

#ifndef NDEBUG
#define DEBUG
#endif

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <climits>
#include <cfloat>
#include <ctime>
#include <cassert>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include <numeric>
#include <list>
#include <iomanip>
#include <fstream>
#include <bitset>

using namespace std;

#define foreach(it, c) for (__typeof__((c).begin()) it=(c).begin(); it != (c).end(); ++it)
template <typename T> void print_container(ostream& os, const T& c) { const char* _s = " "; if (!c.empty()) { __typeof__(c.begin()) last = --c.end(); foreach (it, c) { os << *it; if (it != last) os << _s; } } }
template <typename T> ostream& operator<<(ostream& os, const vector<T>& c) { print_container(os, c); return os; }
template <typename T> ostream& operator<<(ostream& os, const set<T>& c) { print_container(os, c); return os; }
template <typename T> ostream& operator<<(ostream& os, const multiset<T>& c) { print_container(os, c); return os; }
template <typename T> ostream& operator<<(ostream& os, const deque<T>& c) { print_container(os, c); return os; }
template <typename T, typename U> ostream& operator<<(ostream& os, const map<T, U>& c) { print_container(os, c); return os; }
template <typename T, typename U> ostream& operator<<(ostream& os, const pair<T, U>& p) { os << "(" << p.first << ", " << p.second << ")"; return os; }
template <typename T, std::size_t N> ostream& operator<<(ostream& os, const array<T, N>& c) { print_container(os, vector<T>(c.begin(), c.end())); return os; }

template <typename T> void print(T a, int n, const string& split = " ") { for (int i = 0; i < n; i++) { cerr << a[i]; if (i + 1 != n) cerr << split; } cerr << endl; }
template <typename T> void print2d(T a, int w, int h, int width = -1, int br = 0) { for (int i = 0; i < h; ++i) { for (int j = 0; j < w; ++j) { if (width != -1) cerr.width(width); cerr << a[i][j] << ' '; } cerr << endl; } while (br--) cerr << endl; }
template <typename T> void input(T& a, int n) { for (int i = 0; i < n; ++i) cin >> a[i]; }
#define dump(v) (cerr << #v << ": " << v << endl)

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define erep(i, n) for (int i = 0; i <= (int)(n); ++i)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define clr(a, x) memset(a, x, sizeof(a))
#define sz(a) ((int)(a).size())
#define mp(a, b) make_pair(a, b)
#define ten(n) ((long long)(1e##n))

template <typename T, typename U> void upmin(T& a, const U& b) { a = min<T>(a, b); }
template <typename T, typename U> void upmax(T& a, const U& b) { a = max<T>(a, b); }
template <typename T> void uniq(T& a) { sort(a.begin(), a.end()); a.erase(unique(a.begin(), a.end()), a.end()); }
template <class T> string to_s(const T& a) { ostringstream os; os << a; return os.str(); }
template <class T> T to_T(const string& s) { istringstream is(s); T res; is >> res; return res; }
bool in_rect(int x, int y, int w, int h) { return 0 <= x && x < w && 0 <= y && y < h; }

typedef long long ll;
typedef pair<int, int> pint;
typedef unsigned long long ull;



template <typename T, int SIZE>
class Queue
{
private:
    T data[SIZE];
    int front_p, back_p;

public:
    Queue()
        : front_p(0), back_p(0)
    {
    }

    void push(T a)
    {
        assert(back_p < SIZE);
        data[back_p++] = a;
    }
    const T& front() const
    {
        return data[front_p];
    }
    void pop()
    {
        ++front_p;
    }
    int size() const
    {
        return back_p - front_p;
    }
    bool empty() const
    {
        return size() == 0;
    }
};

#ifdef _MSC_VER
#include <Windows.h>
    double get_ms() { return (double)GetTickCount64() / 1000; }
#else
#include <sys/time.h>
    double get_ms() { struct timeval t; gettimeofday(&t, NULL); return (double)t.tv_sec * 1000 + (double)t.tv_usec / 1000; }
#endif

class Timer
{
private:
    double start_time;
    double elapsed;

#ifdef USE_RDTSC
    double get_sec() { return get_absolute_sec(); }
#else
    double get_sec() { return get_ms() / 1000; }
#endif

public:
    Timer() {}

    void start() { start_time = get_sec(); }
    double get_elapsed() { return elapsed = get_sec() - start_time; }
};


const int8_t DX[] = { +0, +1, +0, -1 };
const int8_t DY[] = { +1, +0, -1, +0 };
const char* S_DIR = "DRUL";
const int DOWN = 0, RIGHT = 1, UP = 2, LEFT = 3;

string format_moves(const vector<int>& moves)
{
    assert(moves.size() <= 3);

    if (moves.size() == 0)
        return "N";

    string s;
    for (int dir : moves)
        s += S_DIR[dir];
    return s;
}

const int h = 17;
const int w = 14;
const int NINJAS = 2;
const array<int, 4> DOG_DIR_ORDER{2, 3, 1, 0};

int g_turn;


bool in_rect(int x, int y)
{
    return in_rect(x, y, w, h);
}


struct Pos
{
    int8_t x, y;
    Pos(int8_t x, int8_t y)
        : x(x), y(y)
    {
    }
    Pos()
        : x(0), y(0)
    {
    }

    bool operator==(const Pos& other) const
    {
        return x == other.x && y == other.y;
    }
    bool operator !=(const Pos& other) const
    {
        return x != other.x || y != other.y;
    }

    void operator+=(const Pos& other)
    {
        x += other.x;
        y += other.y;
    }
    void operator-=(const Pos& other)
    {
        x -= other.x;
        y -= other.y;
    }

    Pos operator+(const Pos& other) const
    {
        Pos res = *this;
        res += other;
        return res;
    }
    Pos operator-(const Pos& other) const
    {
        Pos res = *this;
        res -= other;
        return res;
    }
    Pos operator*(int a) const
    {
        return Pos(x * a, y * a);
    }

    bool operator<(const Pos& other) const
    {
        if (x != other.x)
            return x < other.x;
        else
            return y < other.y;
    }

    int dist(const Pos& p) const
    {
        return abs(p.x - x) + abs(p.y - y);
    }

    Pos next(int dir) const
    {
        assert(0 <= dir && dir < 4);
        return Pos(x + DX[dir], y + DY[dir]);
    }

    void move(int dir)
    {
        assert(0 <= dir && dir < 4);
        x += DX[dir];
        y += DY[dir];
    }

    int dir(const Pos& to) const
    {
        rep(dir, 4)
        {
            if (next(dir) == to)
                return dir;
        }
        assert(false);
        return -1;
    }
};
Pos operator*(int a, const Pos& pos)
{
    return pos * a;
}
ostream& operator<<(ostream& os, const Pos& pos)
{
    char buf[256];
    sprintf(buf, "(%2d, %2d)", pos.x, pos.y);
    os << buf;
    return os;
}

bool in_rect(const Pos& p)
{
    return in_rect(p.x, p.y);
}

bool in_field(int x, int y)
{
    return 0 < x && x < w - 1 && 0 < y && y < h - 1;
}
bool in_field(const Pos& p)
{
    return in_field(p.x, p.y);
}

template <typename T>
class Array2d
{
public:
    Array2d()
    {
    }

    Array2d(T init)
    {
        rep(y, h) rep(x, w)
            a[y][x] = init;
    }

    T get(int x, int y) const
    {
        assert(in_rect(x, y));
        return a[y][x];
    }
    T get(const Pos& p) const
    {
        return get(p.x, p.y);
    }
    T& get(int x, int y)
    {
        assert(in_rect(x, y));
        return a[y][x];
    }
    T& get(const Pos& p)
    {
        return get(p.x, p.y);
    }

    void set(int x, int y, const T& v)
    {
        assert(in_rect(x, y));
        a[y][x] = v;
    }
    void set(const Pos& pos, const T& v)
    {
        set(pos.x, pos.y, v);
    }

    void print() const
    {
        print2d(a, w, h, 3);
    }
private:
    int a[h][16];
};

// class BoolBoard
// {
// public:
//     BoolBoard() : f{}
//     {
//     }
//
//     bool get(int x, int y) const
//     {
//         assert(in_rect(x, y));
//         return f[y][x];
//     }
//     bool get(const Pos& p) const
//     {
//         return get(p.x, p.y);
//     }
//
//     void set(int x, int y, bool v)
//     {
//         assert(in_rect(x, y));
//         f[y][x] = v;
//     }
//     void set(const Pos& pos, bool v)
//     {
//         set(pos.x, pos.y, v);
//     }
//
//     bool operator<(const BoolBoard& other) const
//     {
//         for (int y = 1; y < h - 1; ++y)
// //             for (int x = 1; x < w - 1; ++x)
//             for (int x = w - 2; x > 0; --x)
//                 if (get(x, y) != other.get(x, y))
//                     return get(x, y) < other.get(x, y);
//         return false;
//     }
//
//     bool operator==(const BoolBoard& other) const
//     {
//         for (int y = 1; y < h - 1; ++y)
//             for (int x = 1; x < w - 1; ++x)
//                 if (get(x, y) != other.get(x, y))
//                     return false;
//         return true;
//     }
//
//     bool operator!=(const BoolBoard& other) const
//     {
//         return !(*this == other);
//     }
//
// private:
//     bool f[h][16];
// };
class BoolBoard
{
public:
    BoolBoard() : f{}
    {
    }

    bool get(int x, int y) const
    {
        assert(in_rect(x, y));
        return f[y] >> x & 1;
    }
    bool get(const Pos& p) const
    {
        return get(p.x, p.y);
    }

    void set(int x, int y, bool v)
    {
        assert(in_rect(x, y));
        f[y] = (f[y] & ~((unsigned short)1 << x)) | (v << x);
    }
    void set(const Pos& pos, bool v)
    {
        set(pos.x, pos.y, v);
    }

    bool operator<(const BoolBoard& other) const
    {
        for (int y = 1; y < h - 1; ++y)
            if (f[y] != other.f[y])
                return f[y] < other.f[y];
        return false;
    }

    bool operator==(const BoolBoard& other) const
    {
        for (int y = 1; y < h - 1; ++y)
            if (f[y] != other.f[y])
                return false;
        return true;
    }

    bool operator!=(const BoolBoard& other) const
    {
        return !(*this == other);
    }

private:
    unsigned short f[h];
};

const int SKILLS = 8;
struct Skill
{
public:
    Skill(int id, Pos pos_ = Pos(-1, -1)) :
        id(id), pos_(pos_)
    {
        assert(-1 <= id && id < SKILLS);
        assert((id <= 0 || id == 7) || in_field(pos_));
    }
    Skill() : id(-1) {}

    bool used() const
    {
        return id >= 0;
    }

    Pos pos() const
    {
        assert(1 <= id && id <= 6);
        return pos_;
    }

    int slash_ninja_id() const
    {
        assert(id == 7);
        return pos_.x;
    }

    int id;
    Pos pos_;
};
namespace Skills
{
const Skill NONE = Skill(-1);
const Skill ACC = Skill(0);
Skill my_rock(const Pos& p) { return Skill(1, p); }
Skill ene_rock(const Pos& p) { return Skill(2, p); }
Skill my_thunder(const Pos& p) { return Skill(3, p); }
Skill ene_thunder(const Pos& p) { return Skill(4, p); }
Skill my_shadow(const Pos& p) { return Skill(5, p); }
Skill ene_shadow(const Pos& p) { return Skill(6, p); }
Skill slash(int ninja_id) { return Skill(7, Pos(ninja_id, -1)); }
}
namespace SkillID
{
const int ACC = 0;
const int MY_ROCK = 1;
const int ENE_ROCK = 2;
const int MY_THUNDER = 3;
const int ENE_THUNDER = 4;
const int MY_SHADOW = 5;
const int ENE_SHADOW = 6;
const int SLASH = 7;
};

struct Action
{
public:
    Action(const array<vector<int>, NINJAS>& moves, const Skill& skill) :
        moves(moves), skill(skill)
    {
#ifdef DEBUG
        rep(i, NINJAS)
            assert(moves[i].size() <= (skill.id == 0 ? 3 : 2));
#endif
    }

    Action() : skill(Skills::NONE) {}

    string output_format() const
    {
        ostringstream os;
        if (skill.used())
        {
            os << 3 << endl;
            if (skill.id == 0)
                os << 0 << endl;
            else if (skill.id == 7)
                os << 7 << " " << (int)skill.pos_.x << endl;
            else
            {
                assert(1 <= skill.id && skill.id <= 6);
                assert(in_field(skill.pos()));
                os << skill.id << " " << (int)skill.pos().y << " " << (int)skill.pos().x << endl;
            }
        }
        else
            os << 2 << endl;

        rep(ninja_id, NINJAS)
        {
            os << format_moves(moves[ninja_id]);
            if (ninja_id < NINJAS - 1)
                os << endl;
        }
        return os.str();
    }

    array<vector<int>, NINJAS> moves;
    Skill skill;
};

struct Dog
{
    Pos pos;
    int id;

    bool operator<(const Dog& other) const
    {
        return pos < other.pos || (pos == other.pos && id < other.id);
    }
};
ostream& operator<<(ostream& os, const Dog& dog)
{
    os << "[" << dog.pos << ", " << dog.id << "]";
    return os;
}

Array2d<int> calc_dist(const vector<Pos>& starts, const BoolBoard& forbid)
{
    Array2d<int> dist(-1);

    queue<Pos> q;
    for (auto& p : starts)
    {
        if (!forbid.get(p))
        {
            q.push(p);
            dist.set(p, 0);
        }
    }
    assert(q.size() > 0);
    while (!q.empty())
    {
        Pos cur = q.front();
        q.pop();

        const int nd = dist.get(cur) + 1;
        rep(dir, 4)
        {
            Pos next = cur.next(dir);
            if (in_field(next) && !forbid.get(next) && dist.get(next) == -1)
            {
                dist.set(next, nd);
                q.push(next);
            }
        }
    }
    return dist;
}

struct State 
{
    int mp;
    array<Pos, NINJAS> ninjas;
    vector<Pos> souls;
    vector<Dog> dogs;
    BoolBoard rock;
};

struct SimulateNinjaMoveResult
{
    array<Pos, NINJAS> ninjas;
    BoolBoard rock;
    array<vector<int>, NINJAS> moves;
    int soul_mask;
};
template <bool USED_SHADOW = false>
vector<SimulateNinjaMoveResult> simulate_ninja_move(const array<Pos, NINJAS>& init_ninjas, const BoolBoard& init_rock, const vector<Dog>& dogs, const vector<Pos>& souls)
{
    const int MOVES = 2;

    BoolBoard is_dog, dead;
    for (auto& dog : dogs)
    {
        is_dog.set(dog.pos, true);

        dead.set(dog.pos, true);
        rep(dir, 4)
            dead.set(dog.pos.next(dir), true);
    }

    map<Pos, int> soul_index;
    rep(i, souls.size())
        soul_index[souls[i]] = i;

    using P = tuple<int, array<Pos, NINJAS>, BoolBoard>;
    map<P, array<vector<int>, NINJAS>> dp;

    vector<P> q, nq;
    dp[make_tuple(0, init_ninjas, init_rock)] = {};
    rep(ninja_id, NINJAS)
    {
        assert(q.empty());
        for (auto& it : dp)
            q.push_back(it.first);

        rep(move_i, MOVES)
        {
            nq.clear();
            for (const auto& key : q)
            {
                const int soul_mask = get<0>(key);
                const auto& ninjas = get<1>(key);
                const auto& rock = get<2>(key);
                const auto& moves = dp[key];

                rep(dir, 4)
                {
                    const Pos cur = ninjas[ninja_id];
                    const Pos next = cur.next(dir);
                    assert(!rock.get(cur));

                    if (!USED_SHADOW)
                    {
                        if (MOVES - 1 == move_i)
                        {
                            if (dead.get(next))
                                continue;
                        }
                        else if (MOVES - 1 - move_i <= 1)
                        {
                            if (is_dog.get(next))
                                continue;
                        }
                    }

                    auto can_move = [&]()
                    {
                        if (!in_field(next))
                            return false;

                        if (!rock.get(next))
                            return true;
                        else
                        {
                            Pos next2 = next.next(dir);
                            return in_field(next2)
                                && !rock.get(next2)
                                && !is_dog.get(next2)
                                && next2 != ninjas[ninja_id ^ 1];
                        }
                    };

                    if (can_move())
                    {
                        auto nninjas = ninjas;
                        auto nrock = rock;
                        nninjas[ninja_id] = next;
                        int nsoul_mask = soul_mask;
                        if (soul_index.count(next))
                            nsoul_mask |= 1 << soul_index[next];
                        if (rock.get(next))
                        {
                            nrock.set(next, false);
                            nrock.set(next.next(dir), true);
                        }

                        auto nkey = make_tuple(nsoul_mask, nninjas, nrock);
                        if (!dp.count(nkey))
                        {
                            auto nmoves = moves;
                            nmoves[ninja_id].push_back(dir);

                            dp[nkey] = nmoves;
                            if (move_i < MOVES - 1)
                                nq.push_back(nkey);
                        }
                    }
                }
            }
            q.swap(nq);
        }
    }

    vector<SimulateNinjaMoveResult> results;
    for (auto& it : dp)
        results.push_back(SimulateNinjaMoveResult{get<1>(it.first), get<2>(it.first), it.second, get<0>(it.first)});
    return results;
}

vector<SimulateNinjaMoveResult> simulate_ninja_move_using_acc(const array<Pos, NINJAS>& init_ninjas, const BoolBoard& init_rock, const vector<Dog>& dogs, const vector<Pos>& souls)
{
    const int MOVES = 3;

    BoolBoard is_dog, dead;
    for (auto& dog : dogs)
    {
        is_dog.set(dog.pos, true);

        dead.set(dog.pos, true);
        rep(dir, 4)
            dead.set(dog.pos.next(dir), true);
    }

    map<Pos, int> soul_index;
    rep(i, souls.size())
        soul_index[souls[i]] = i;

    using P = tuple<int, array<Pos, NINJAS>, BoolBoard>;
    map<P, array<vector<int>, NINJAS>> dp;

    vector<P> q, nq;
    dp[make_tuple(0, init_ninjas, init_rock)] = {};
    rep(ninja_id, NINJAS)
    {
        assert(q.empty());
        for (auto& it : dp)
            q.push_back(it.first);

        rep(move_i, MOVES)
        {
            nq.clear();
            for (const auto& key : q)
            {
                const int soul_mask = get<0>(key);
                const auto& ninjas = get<1>(key);
                const auto& rock = get<2>(key);
                const auto& moves = dp[key];

                rep(dir, 4)
                {
                    const Pos cur = ninjas[ninja_id];
                    const Pos next = cur.next(dir);
                    assert(!rock.get(cur));

                    if (move_i == 0 && !is_dog.get(next))
                        continue;
                    if (MOVES - 1 == move_i)
                    {
                        if (dead.get(next))
                            continue;
                    }
                    else if (MOVES - 1 - move_i <= 1)
                    {
                        if (is_dog.get(next))
                            continue;
                    }

                    auto can_move = [&]()
                    {
                        if (!in_field(next))
                            return false;

                        if (!rock.get(next))
                            return true;
                        else
                        {
                            Pos next2 = next.next(dir);
                            return in_field(next2)
                                && !rock.get(next2)
                                && !is_dog.get(next2)
                                && next2 != ninjas[ninja_id ^ 1];
                        }
                    };

                    if (can_move())
                    {
                        auto nninjas = ninjas;
                        auto nrock = rock;
                        nninjas[ninja_id] = next;
                        int nsoul_mask = soul_mask;
                        if (soul_index.count(next))
                            nsoul_mask |= 1 << soul_index[next];
                        if (rock.get(next))
                        {
                            nrock.set(next, false);
                            nrock.set(next.next(dir), true);
                        }

                        auto nkey = make_tuple(nsoul_mask, nninjas, nrock);
                        if (!dp.count(nkey))
                        {
                            auto nmoves = moves;
                            nmoves[ninja_id].push_back(dir);

                            dp[nkey] = nmoves;
                            if (move_i < MOVES - 1)
                                nq.push_back(nkey);
                        }
                    }
                }
            }
            q.swap(nq);
        }
    }

    vector<SimulateNinjaMoveResult> results;
    for (auto& it : dp)
        if (max(it.second[0].size(), it.second[1].size()) == 3)
            results.push_back(SimulateNinjaMoveResult{get<1>(it.first), get<2>(it.first), it.second, get<0>(it.first)});
    return results;
}

vector<Dog> simulate_dog_move(const vector<Dog>& init_dogs, const vector<Pos>& ninjas, const BoolBoard& rock)
{
    assert(0 < ninjas.size() && ninjas.size() <= 2);
    if (init_dogs.empty())
        return {};

    BoolBoard is_dog;
    for (auto& dog : init_dogs)
    {
        assert(!rock.get(dog.pos));
        is_dog.set(dog.pos, true);
    }

    const int inf = 810;
    Array2d<int> dist;
    rep(y, h) rep(x, w)
        dist.set(x, y, rock.get(x, y) ? -inf : inf);
    rep(x, w)
    {
        dist.set(x, 0, -inf);
        dist.set(x, h - 1, -inf);
    }
    rep(y, h)
    {
        dist.set(0, y, -inf);
        dist.set(w - 1, y, -inf);
    }

    Queue<Pos, w * h> q;
    int reach = 0;
    for (auto& p : ninjas)
    {
        if (!rock.get(p))
        {
            dist.set(p, 0);
            q.push(p);
        }
    }
    assert(q.size() > 0);
    while (!q.empty() && reach < init_dogs.size())
    {
        const Pos& cur = q.front();
        q.pop();

        const int nd = dist.get(cur) + 1;
        rep(dir, 4)
        {
            const Pos next = cur.next(dir);
            auto& d = dist.get(next);
            if (d == inf)
            {
                reach += is_dog.get(next);

                d = nd;
                q.push(next);
            }
        }
    }

    vector<Dog> order = init_dogs;
    const auto cmp = [&](const Dog& a, const Dog& b)
    {
        const int ad = dist.get(a.pos), bd = dist.get(b.pos);
        return ad < bd || (ad == bd && a.id < b.id);
    };
    sort(all(order), cmp);

    for (auto& dog : order)
    {
        assert(is_dog.get(dog.pos));
        assert(!rock.get(dog.pos));

        const Pos p = dog.pos;
        if (dist.get(p) == inf)
            continue;

        for (int dir : DOG_DIR_ORDER)
        {
            const Pos next = p.next(dir);
            if (!is_dog.get(next)
                && dist.get(p) == dist.get(next) + 1)
            {
                dog.pos = next;
                is_dog.set(p, false);
                is_dog.set(next, true);
                break;
            }
        }
    }
    return order;
}
vector<Dog> simulate_dog_move(const vector<Dog>& init_dogs, const array<Pos, NINJAS>& ninjas, const BoolBoard& rock)
{
    return simulate_dog_move(init_dogs, vector<Pos>(all(ninjas)), rock);
}

vector<Pos> simulate_sent_dogs_pos(int num_sent_dogs, const array<Pos, NINJAS>& ninjas, const BoolBoard& rock, const vector<Dog>& dogs)
{
    BoolBoard f = rock;
    for (auto& p : ninjas)
        f.set(p, true);

    // bugppoi
//     for (auto& dog : dogs)
//         f.set(dog.pos, true);

    const int inf = 810;
    Array2d<int> dist(inf);
    queue<Pos> q;
    for (auto& p : ninjas)
    {
        dist.set(p, 0);
        q.push(p);
    }
    while (!q.empty())
    {
        Pos cur = q.front();
        q.pop();

        const int nd = dist.get(cur) + 1;
        rep(dir, 4)
        {
            Pos next = cur.next(dir);
            if (in_field(next) && !f.get(next) && dist.get(next) == inf)
            {
                dist.set(next, nd);
                q.push(next);
            }
        }
    }

    // bugppoi
    for (auto& dog : dogs)
        f.set(dog.pos, true);

    vector<tuple<int, int, int>> order;
    for (int y = 1; y < h - 1; ++y)
        for (int x = 1; x < w - 1; ++x)
            if (dist.get(x, y) != inf && !f.get(x, y))
                order.push_back(make_tuple(-dist.get(x, y), y, x));
    sort(all(order));

    vector<Pos> sent_dogs;
    rep(i, min<int>(num_sent_dogs, order.size()))
        sent_dogs.push_back(Pos(get<2>(order[i]), get<1>(order[i])));
    return sent_dogs;
}

vector<Dog> simulate_sent_dogs(int num_sent_dogs, const array<Pos, NINJAS>& ninjas, const BoolBoard& rock, const vector<Dog>& dogs)
{
    auto pos = simulate_sent_dogs_pos(num_sent_dogs, ninjas, rock, dogs);

    int max_id = 0;
    for (auto& dog : dogs)
        upmax(max_id, dog.id);

    vector<Dog> sent_dogs;
    rep(i, pos.size())
        sent_dogs.push_back(Dog{pos[i], max_id + (i + 1)});
    return sent_dogs;
}

struct PlayerInfo
{
    State state;
    array<int, SKILLS> skill_count;
};
PlayerInfo input_player_info()
{
    PlayerInfo info;
    State& state = info.state;
    cin >> state.mp;

    int h_, w_;
    cin >> h_ >> w_;
    assert(h_ == h);
    assert(w_ == w);

    rep(y, h)
    {
        string s;
        cin >> s;
        rep(x, w)
        {
            if (s[x] == 'O')
                state.rock.set(x, y, true);
            else if (s[x] == '_')
                state.rock.set(x, y, false);
            else
            {
                assert(in_rect(x, y) && !in_field(x, y));
            }
        }
    }

    int num_ninjas;
    cin >> num_ninjas;
    assert(num_ninjas == NINJAS);
    rep(i, NINJAS)
    {
        int id;
        int x, y;
//         cin >> id >> p.y >> p.x;
        cin >> id >> y >> x;
        Pos p(x, y);
//         dump(make_pair(p.x, p.y));
        assert(in_field(p));
        state.ninjas[id] = p;
    }
    assert(in_field(state.ninjas[0]) && in_field(state.ninjas[1]));

    int num_dogs;
    cin >> num_dogs;
    rep(i, num_dogs)
    {
        Dog dog;
        int x, y;
//         cin >> dog.id >> dog.pos.y >> dog.pos.x;
        cin >> dog.id >> y >> x;
        dog.pos = Pos(x, y);
        assert(in_field(dog.pos));
        state.dogs.push_back(dog);
    }

    int num_souls;
    cin >> num_souls;
    assert(num_souls <= 8);
    rep(i, num_souls)
    {
//         Pos p;
//         cin >> p.y >> p.x;
        int x, y;
        cin >> y >> x;
        Pos p(x, y);
        assert(in_field(p));
        state.souls.push_back(p);
    }

    rep(i, SKILLS)
        cin >> info.skill_count[i];

    return info;
}

struct InputInfo
{
    int ms;
    array<int, SKILLS> skill_costs;
    PlayerInfo my_info, enemy_info;
};
InputInfo input()
{
    InputInfo input_info;
    if (!(cin >> input_info.ms))
    {
        input_info.ms = -1;
        return input_info;
    }

    int skills_;
    cin >> skills_;
    assert(skills_ == SKILLS);

    rep(i, SKILLS)
        cin >> input_info.skill_costs[i];

    input_info.my_info = input_player_info();
    input_info.enemy_info = input_player_info();

    return input_info;
}

bool check_dead(const array<Pos, NINJAS>& ninjas, const vector<Dog>& dogs)
{
    rep(ninja_id, NINJAS)
        for (auto& dog : dogs)
            if (dog.pos == ninjas[ninja_id])
                return true;
    return false;
}

struct SimulationResult
{
    State state;
    Action action;
};
vector<SimulationResult> simulate_next_state(const State& my_state)
{
    set<Pos> soul_set(all(my_state.souls));

    auto move_results = simulate_ninja_move(my_state.ninjas, my_state.rock, my_state.dogs, my_state.souls);
    vector<SimulationResult> simulation_results;
    for (const auto& move_result : move_results)
    {
        set<Pos> got_souls;
        rep(ninja_id, NINJAS)
        {
            Pos p = my_state.ninjas[ninja_id];
            for (int dir : move_result.moves[ninja_id])
            {
                p.move(dir);
                if (soul_set.count(p))
                    got_souls.insert(p);
            }
            assert(p == move_result.ninjas[ninja_id]);
        }

        auto check_dead_fast = [&]()
        {
            rep(ninja_id, NINJAS)
            {
                for (auto& dog : my_state.dogs)
                    if (move_result.ninjas[ninja_id].dist(dog.pos) <= 1)
                        return true;
            }
            return false;
        };
        if (check_dead_fast())
            continue;


//         auto dogs = simulate_dog_move(my_state.dogs, move_result.ninjas, move_result.rock);
//         if (!check_dead(move_result.ninjas, dogs))
        {
            vector<Pos> rem_souls;
            for (auto& p : my_state.souls)
                if (!got_souls.count(p))
                    rem_souls.push_back(p);

            State nstate;
            nstate.mp = my_state.mp + 2 * got_souls.size();
            nstate.ninjas = move_result.ninjas;
            nstate.rock = move_result.rock;
//             nstate.dogs = dogs;
            nstate.dogs = my_state.dogs;
            nstate.souls = rem_souls;

            Action action(move_result.moves, Skills::NONE);

            simulation_results.push_back(SimulationResult{nstate, action});
        }
    }
    return simulation_results;
}

vector<SimulationResult> simulate_next_state_using_acc(const State& my_state, const int acc_cost)
{
    set<Pos> soul_set(all(my_state.souls));

    auto move_results = simulate_ninja_move_using_acc(my_state.ninjas, my_state.rock, my_state.dogs, my_state.souls);
    vector<SimulationResult> simulation_results;
    for (const auto& move_result : move_results)
    {
        set<Pos> got_souls;
        rep(ninja_id, NINJAS)
        {
            Pos p = my_state.ninjas[ninja_id];
            for (int dir : move_result.moves[ninja_id])
            {
                p.move(dir);
                if (soul_set.count(p))
                    got_souls.insert(p);
            }
            assert(p == move_result.ninjas[ninja_id]);
        }

        auto check_dead_fast = [&]()
        {
            rep(ninja_id, NINJAS)
            {
                for (auto& dog : my_state.dogs)
                    if (move_result.ninjas[ninja_id].dist(dog.pos) <= 1)
                        return true;
            }
            return false;
        };
        if (check_dead_fast())
            continue;


//         auto dogs = simulate_dog_move(my_state.dogs, move_result.ninjas, move_result.rock);
//         if (!check_dead(move_result.ninjas, dogs))
        {
            vector<Pos> rem_souls;
            for (auto& p : my_state.souls)
                if (!got_souls.count(p))
                    rem_souls.push_back(p);

            State nstate;
            nstate.mp = my_state.mp + 2 * got_souls.size() - acc_cost;
            nstate.ninjas = move_result.ninjas;
            nstate.rock = move_result.rock;
//             nstate.dogs = dogs;
            nstate.dogs = my_state.dogs;
            nstate.souls = rem_souls;

            Action action(move_result.moves, Skills::ACC);

            simulation_results.push_back(SimulationResult{nstate, action});
        }
    }
    return simulation_results;
}

void print(const BoolBoard& rock, const vector<Dog>& dogs)
{
    bool is_dog[h][w]{};
    for (auto& d : dogs)
        is_dog[d.pos.y][d.pos.x] = true;

    string s[h];
    rep(y, h)
    {
        rep(x, w)
        {
            if (y == 0 || y == h - 1 || x == 0 || x == w - 1)
                s[y] += 'W';
            else if (rock.get(x, y))
                s[y] += 'O';
            else if (is_dog[y][x])
                s[y] += 'd';
            else
                s[y] += '_';
        }
        cerr << s[y] << endl;
    }
}

vector<Pos> think_my_shadow_cand_pos(const State& my_state)
{
    BoolBoard forbid_shadow;
    rep(y, h) rep(x, w)
        if (my_state.rock.get(x, y))
            forbid_shadow.set(x, y, true);
    vector<Pos> cand_pos(all(my_state.ninjas));
    Pos unreach_pos(-1, -1);
    rep(_, 1)
    {
        auto dist = calc_dist(cand_pos, forbid_shadow);
        int max_d = -1;
        Pos max_pos;
        rep(y, h) rep(x, w)
        {
            int d = dist.get(x, y);
            if (!forbid_shadow.get(x, y) && d == -1)
                unreach_pos = Pos(x, y);
            else if (d > max_d)
            {
                max_d = d;
                max_pos = Pos(x, y);
            }
        }
        if (max_d == 0)
            break;

        cand_pos.push_back(max_pos);
    }
    if (in_field(unreach_pos))
        cand_pos.push_back(unreach_pos);
//     auto dist = calc_dist(vector<Pos>(all(my_state.ninjas)), forbid_shadow);
//     vector<pair<int, Pos>> order;
//     Pos unreach_pos(-1, -1);
//     int max_d = -1;
//     Pos max_pos;
//     rep(y, h) rep(x, w)
//     {
//         if (dist.get(x, y) > max_d)
//         {
//             max_d = dist.get(x, y);
//             max_pos = Pos(x, y);
//         }
//         else if (dist.get(x, y) == -1 && !my_state.rock.get(x, y))
//             unreach_pos = Pos(x, y);
//     }
//
//     vector<Pos> cand_pos(all(my_state.ninjas));
//     if (in_field(unreach_pos))
//         cand_pos.push_back(unreach_pos);
//     cand_pos.push_back(max_pos);
//
//     vector<Pos> starts(all(my_state.ninjas));
//     starts.push_back(max_pos);
//     rep(i, min((int)order.size(), 2))
//     {
//     }
    return cand_pos;
}
vector<SimulationResult> simulate_next_state_using_shadow(const State& my_state, int shadow_mp)
{
    assert(my_state.mp >= shadow_mp);
    assert(my_state.dogs.size());

    const auto my_shadow_pos = think_my_shadow_cand_pos(my_state);

    set<Pos> soul_set(all(my_state.souls));

    auto move_results = simulate_ninja_move<true>(my_state.ninjas, my_state.rock, my_state.dogs, my_state.souls);
    vector<SimulationResult> simulation_results;
    for (const auto& move_result : move_results)
    {
        set<Pos> got_souls;
        rep(ninja_id, NINJAS)
        {
            Pos p = my_state.ninjas[ninja_id];
            for (int dir : move_result.moves[ninja_id])
            {
                p.move(dir);
                if (soul_set.count(p))
                    got_souls.insert(p);
            }
            assert(p == move_result.ninjas[ninja_id]);
        }

        vector<Pos> rem_souls;
        for (auto& p : my_state.souls)
            if (!got_souls.count(p))
                rem_souls.push_back(p);

        for (auto& shadow_pos : my_shadow_pos)
        {
            assert(!my_state.rock.get(shadow_pos));
            if (move_result.rock.get(shadow_pos))
                continue;

//             auto dogs = simulate_dog_move(my_state.dogs, vector<Pos>{shadow_pos}, move_result.rock);
//             if (!check_dead(move_result.ninjas, dogs))
            {
                State nstate;
                nstate.mp = my_state.mp + 2 * got_souls.size() - shadow_mp;
                nstate.ninjas = move_result.ninjas;
                nstate.rock = move_result.rock;
//                 nstate.dogs = dogs;
                nstate.dogs = my_state.dogs;
                nstate.souls = rem_souls;

                Action action(move_result.moves, Skills::my_shadow(shadow_pos));

                simulation_results.push_back(SimulationResult{nstate, action});
            }
        }
    }
    return simulation_results;
}

vector<Pos> think_my_thunder_cand_pos(const State& my_state)
{
    BoolBoard obs = my_state.rock;
//     for (auto& ninja : my_state.ninjas)
//         obs.set(ninja, true);
//     for (auto& dog : my_state.dogs)
//         obs.set(dog.pos, true);

    vector<Pos> cand_pos;
    for (auto& ninja : my_state.ninjas)
    {
        for (int dy = -2; dy <= 2; ++dy)
        {
            for (int dx = -2; dx <= 2; ++dx)
            {
                if (abs(dx) + abs(dy) <= 2)
                {
                    const Pos p = ninja + Pos(dx, dy);
                    if (in_field(p) && my_state.rock.get(p))
                    {
                        bool any_obs = false;
                        rep(dir, 4)
                        {
                            const Pos next = p.next(dir);
                            any_obs |= !in_field(next) || obs.get(next);
                        }
                        if (any_obs)
                            cand_pos.push_back(p);
                    }
                }
            }
        }
    }
    uniq(cand_pos);
    return cand_pos;
}
vector<SimulationResult> simulate_next_state_using_my_thunder(const State& my_state, const int my_thunder_mp)
{
    assert(my_state.mp >= my_thunder_mp);

    vector<SimulationResult> results;
    for (auto& thunder_pos : think_my_thunder_cand_pos(my_state))
    {
        assert(my_state.rock.get(thunder_pos));

        auto s = my_state;
        s.mp -= my_thunder_mp;
        s.rock.set(thunder_pos, false);
        assert(s.mp >= 0);

        auto ress = simulate_next_state(s);
        for (auto& res : ress)
            res.action.skill = Skills::my_thunder(thunder_pos);
        results.insert(results.end(), all(ress));
    }
    return results;
}

vector<SimulationResult> simulate_next_state_using_slash(const State& my_state, const int slash_mp)
{
    assert(my_state.mp >= slash_mp);

    Array2d<int> dog_id(-1);
    for (auto& dog : my_state.dogs)
        dog_id.set(dog.pos, dog.id);

    vector<SimulationResult> results;
    rep(ninja_id, NINJAS)
    {
        set<int> killed_dog_id;
        for (int dy = -1; dy <= 1; ++dy)
        {
            for (int dx = -1; dx <= 1; ++dx)
            {
                Pos p = my_state.ninjas[ninja_id] + Pos(dx, dy);
                if (dog_id.get(p) != -1)
                    killed_dog_id.insert(dog_id.get(p));
            }
        }
        if (killed_dog_id.size() > 0)
        {
            auto s = my_state;
            s.mp -= slash_mp;

            vector<Dog> dogs;
            for (auto& dog : my_state.dogs)
                if (!killed_dog_id.count(dog.id))
                    dogs.push_back(dog);

            assert(dogs.size() + killed_dog_id.size() == my_state.dogs.size());
            s.dogs = dogs;

            auto ress = simulate_next_state(s);
            for (auto& res : ress)
                res.action.skill = Skills::slash(ninja_id);
            results.insert(results.end(), all(ress));
        }
    }
    return results;
}

template <typename T>
vector<T> subtract(const vector<T>& a, const vector<T>& b)
{
    set<T> bb(all(b));
    vector<T> aa;
    for (auto& t : a)
        if (!bb.count(t))
            aa.push_back(t);
    assert(aa.size() + b.size() == a.size());
    return aa;
}


struct ShadowKillJudger
{
    void add_turn_info(const PlayerInfo& cur_info, const PlayerInfo& prev_info)
    {
        if (cur_info.skill_count[SkillID::MY_SHADOW] > prev_info.skill_count[SkillID::MY_SHADOW])
        {
            vector<Pos> got_souls;
            for (auto& p : prev_info.state.souls)
                if (!count(all(cur_info.state.souls), p))
                    got_souls.push_back(p);

            rep(ninja_id, NINJAS)
            {
                const auto& prev_ninja = prev_info.state.ninjas[ninja_id];
                const auto& cur_ninja = cur_info.state.ninjas[ninja_id];
                assert(prev_ninja.dist(cur_ninja) <= 2);

                bool got_soul = false;
                for (auto& soul : got_souls)
                    got_soul |= soul.dist(prev_ninja) <= 2 && soul.dist(cur_ninja) <= 1;

                if (got_soul)
                {
                    for (auto& prev_dog : prev_info.state.dogs)
                    {
                        int d = prev_dog.pos.dist(cur_ninja);
                        if (d == 0)
                            ++soul_on_dog;
                        else if (d == 1)
                            ++soul_next_to_dog;
                    }
                }
            }
        }
//         fprintf(stderr, "%3d, %3d\n", soul_on_dog, soul_next_to_dog);
    }

    Pos search_best_pos_to_kill_risky_soul(const State& enemy_state) const
    {
        auto move_results = simulate_ninja_move(enemy_state.ninjas, enemy_state.rock, enemy_state.dogs, enemy_state.souls);

        int max_got_souls = 0;
        for (auto& result : move_results)
            upmax(max_got_souls, __builtin_popcount(result.soul_mask));
        if (max_got_souls == 0)
                return Pos(-1, -1);

        vector<SimulateNinjaMoveResult> good_results;
        for (auto& result : move_results)
            if (__builtin_popcount(result.soul_mask) == max_got_souls)
                good_results.push_back(result);

        int and_soul_mask = (1 << enemy_state.souls.size()) - 1;
        for (auto& result : good_results)
            and_soul_mask &= result.soul_mask;

        bool is_target_ninja[NINJAS]{};
        vector<Pos> got_souls;
        rep(i, enemy_state.souls.size())
        {
            if (and_soul_mask >> i & 1)
            {
                got_souls.push_back(enemy_state.souls[i]);
                rep(ninja_id, NINJAS)
                {
                    if (enemy_state.ninjas[ninja_id].dist(enemy_state.souls[i]) <= 2)
                        is_target_ninja[ninja_id] = true;
                }
            }
        }

        Pos best_pos(-1, -1);
        int best_score = good_results.size() * 10000 * 0.7;
        for (auto& shadow_pos : list_attack_shadow_cand_pos(enemy_state))
        {
            auto dogs = simulate_dog_move(enemy_state.dogs, vector<Pos>{shadow_pos}, enemy_state.rock);
            BoolBoard is_dog;
            for (auto& dog : dogs)
                is_dog.set(dog.pos, true);

            int score = 0;
            for (auto& result : good_results)
            {
//                 bool kill = false;
                rep(ninja_id, NINJAS)
                {
                    if (is_target_ninja[ninja_id] && is_dog.get(result.ninjas[ninja_id]))
                        score += 1;
                    if (is_target_ninja[ninja_id])
                        score += 0.5;
                }
//                 if (kill)
//                     score += 1;
            }
            score *= 10000;
            for (auto& soul : got_souls)
                score += (w + h) - shadow_pos.dist(soul);
            if (score > best_score)
            {
                best_score = score;
                best_pos = shadow_pos;
            }
        }
        return best_pos;
    }
    vector<Pos> list_attack_shadow_cand_pos(const State& enemy_state) const
    {
        vector<Pos> cand_pos;
        rep(y, h) rep(x, w)
        {
            if (in_field(x, y) && !enemy_state.rock.get(x, y))
            {
                int min_d = 100;
                for (auto& p : enemy_state.ninjas)
                    upmin(min_d, Pos(x, y).dist(p));
                if (min_d <= 2)
                    cand_pos.push_back(Pos(x, y));
            }
        }
        return cand_pos;
    }

    bool should_attack() const
    {
        return soul_on_dog * 2 + soul_next_to_dog * 1 > 2 * attack_tries;
    }

    int soul_on_dog = 0;
    int soul_next_to_dog = 0;

    int attack_tries = 0;
};

vector<int> predict_ene_num_sent_dogs(const State& state)
{
    // とりあえず1ターンだけ
    vector<int> sent_dogs(333);
    auto results = simulate_next_state(state);
    for (auto& result : results)
    {
        int got_souls = (int)state.souls.size() - (int)result.state.souls.size();
        assert(got_souls >= 0);
        upmax(sent_dogs[0], got_souls);
    }
    return sent_dogs;
}

Action beam_search(const InputInfo& input_info, ShadowKillJudger& shadow_kill_judger)
{
    const int predicted_rem_turns = max(20, 90 - g_turn);
#ifdef NO_TIMER
    const double LOOSE_TL_SEC = 100000;
    const double ABSOLUTE_TL_SEC = 100000;
#else
    const double LOOSE_TL_SEC = min<double>(16.0, input_info.ms / 1000.0 / predicted_rem_turns);
    const double ABSOLUTE_TL_SEC = min<double>(LOOSE_TL_SEC, input_info.ms / 1000.0 * 0.25);
#endif
    Timer timer;
    timer.start();
    const auto& skill_costs = input_info.skill_costs;
    const auto predicted_num_sent_dogs = predict_ene_num_sent_dogs(input_info.enemy_info.state);

    struct SearchState
    {
        State state;
        Action first_action;
        Skill last_skill;

        int got_souls;
        int diff_mp;
        int summon_dogs;

        int used_skills;
        int thunders;
        int accs;

        int death_risk;
        double dog_can_attack;

        double score;

        bool lazy_dog;
        bool simulate_dog_ret_is_dead()
        {
            if (lazy_dog)
            {
                lazy_dog = false;
                if (last_skill.id == SkillID::MY_SHADOW)
                    state.dogs = simulate_dog_move(state.dogs, vector<Pos>{last_skill.pos()}, state.rock);
                else
                    state.dogs = simulate_dog_move(state.dogs, state.ninjas, state.rock);
                return check_dead(state.ninjas, state.dogs);
            }
            return false;
        }

        bool operator<(const SearchState& other) const
        {
            return score < other.score;
        }
    };

        // 敵がmp足りない時どうするかは後で決める
    static const auto calc_rock_attack_risk = [](const int turn, const State& prev_state, const SimulationResult& simulation_result)
    {
        BoolBoard forbid_rock_attack = prev_state.rock;
        for (auto& ninja : prev_state.ninjas)
            forbid_rock_attack.set(ninja, true);
        for (auto& dog : prev_state.dogs)
            forbid_rock_attack.set(dog.pos, true);
        for (auto& soul : prev_state.souls)
            forbid_rock_attack.set(soul, true);
        if (simulation_result.action.skill.id == SkillID::MY_THUNDER)
            forbid_rock_attack.set(simulation_result.action.skill.pos(), true);

        BoolBoard is_dog;
        for (auto& dog : prev_state.dogs)
            is_dog.set(dog.pos, true);

        int death_risk = 0;

        BoolBoard rock = prev_state.rock;
        auto ninjas = prev_state.ninjas;
        rep(ninja_id, NINJAS)
        {
            auto& p = ninjas[ninja_id];
            const auto& moves = simulation_result.action.moves[ninja_id];
            rep(move_i, moves.size())
            {
                assert(!rock.get(p));

                const int dir = moves[move_i];
                const Pos next = p.next(dir);
                const Pos next2 = next.next(dir);

                const int obs = rock.get(next)
                    + (!in_field(next2) || rock.get(next2)
                      || is_dog.get(next2) || next2 == ninjas[ninja_id ^ 1]);
                assert(obs <= 1);
                if (obs == 1)
                {
                    Pos stop = p;
                    auto temp_rock = rock;
                    if (!temp_rock.get(next))
                    {
                        if (!forbid_rock_attack.get(next))
                            temp_rock.set(next, true);
                    }
                    else if (!temp_rock.get(next2))
                    {
                        if (!forbid_rock_attack.get(next2))
                            temp_rock.set(next2, true);
                    }
                    const auto can_move = [&temp_rock, &is_dog, &ninjas, ninja_id](const Pos& p , int dir)
                    {
                        const Pos next = p.next(dir);
                        if (!in_field(next))
                            return false;

                        if (!temp_rock.get(next))
                            return true;
                        else
                        {
                            Pos next2 = next.next(dir);
                            return in_field(next2)
                                && !temp_rock.get(next2)
                                && !is_dog.get(next2)
                                && next2 != ninjas[ninja_id ^ 1];
                        }
                    };
                    for (int i = move_i + 1; i < moves.size(); ++i)
                    {
                        if (can_move(stop, moves[i]))
                        {
                            stop.move(moves[i]);
                            if (temp_rock.get(stop))
                            {
                                temp_rock.set(stop, false);
                                temp_rock.set(stop.next(moves[i]), true);
                            }
                            assert(in_field(stop));
                        }
                    }

                    bool death = is_dog.get(stop);
                    rep(d, 4)
                        death |= is_dog.get(stop.next(d));
                    if (death)
                        ++death_risk;
                }

                if (rock.get(next))
                {
                    rock.set(next, false);
                    rock.set(next2, true);
                }
                p.move(dir);
            }
        }
        return death_risk;
    };
    static const auto count_danger_ninjas = [](const array<Pos, NINJAS>& cur_ninjas, const vector<Dog>& prev_dogs)
    {
        int danger_ninjas = 0;
        rep(ninja_id, NINJAS)
        {
            for (auto& dog : prev_dogs)
            {
                if (cur_ninjas[ninja_id].dist(dog.pos) <= 1)
                {
                    ++danger_ninjas;
                    break;
                }
            }
        }
        return danger_ninjas;
    };

    const auto eval = [&](const int turn, const State& prev_state, const SearchState& search_state, const SimulationResult& simulation_result)
    {
        const auto& state = search_state.state;


        double score = 0;

        score -= search_state.death_risk;
        score -= search_state.dog_can_attack;
        score *= 100;

        score += 6 * search_state.got_souls;
        score += 4 * search_state.summon_dogs;
//         score += search_state.diff_mp;
        score -= 2 * search_state.used_skills;
        score -= search_state.accs;
        if (search_state.state.mp < skill_costs[SkillID::MY_SHADOW] * 4)
            score -= 4;

        score *= 100;

        int sum_min_d = 0;
        array<int, NINJAS> min_d;
        fill(all(min_d), w + h);
        for (auto& p : state.souls)
        {
            int a = state.ninjas[0].dist(p);
            int b = state.ninjas[1].dist(p);
            if (a < b)
                upmin(min_d[0], a);
            else
                upmin(min_d[1], b);

            sum_min_d += min(a, b);
        }
        rep(ninja_id, NINJAS)
            score += 6 * ((w + h) - min_d[ninja_id]);
        score += (w + h) * state.souls.size() - sum_min_d;
        score += state.ninjas[0].dist(state.ninjas[1]);

        return score;
    };

    const int NUM_LOWERS = 2;

    const int turns = 6;
    const int max_iters = 5;
    const int chokudai_width = 5;
    priority_queue<SearchState> beams[turns + 1][NUM_LOWERS];
    set<tuple<array<Pos, NINJAS>, BoolBoard, vector<Dog>>> visited[turns + 1];

    {
        SearchState init_state = {
            input_info.my_info.state,
            Action(),
            Skills::NONE,

            0,
            0,
            0,

            0,
            0,

            0,
            0,
            0,

            0,

            false
        };
        beams[0][0].push(init_state);
    }

    Action best_action;
    pair<int, double> best_score(0, 1e60);
    for (int iter = 0; iter < max_iters && timer.get_elapsed() < ABSOLUTE_TL_SEC; ++iter)
    {
        bool new_pop = false;
        for (int turn = 0; turn < turns; ++turn)
        {
            rep(lowers_mp_diff_i, NUM_LOWERS)
            {
                const int cur_width = lowers_mp_diff_i == 0 ? 2 * chokudai_width : chokudai_width;
                for (int cho = 0; cho < cur_width && !beams[turn][lowers_mp_diff_i].empty(); ++cho)
                {
                    if (timer.get_elapsed() > ABSOLUTE_TL_SEC)
                        goto END;

                    auto search_state = beams[turn][lowers_mp_diff_i].top();
                    beams[turn][lowers_mp_diff_i].pop();

                    if (search_state.simulate_dog_ret_is_dead())
                    {
                        --cho;
                        continue;
                    }

                    {
                        auto key = make_tuple(search_state.state.ninjas, search_state.state.rock, search_state.state.dogs);
                        if (visited[turn].count(key))
                        {
                            --cho;
                            continue;
                        }
                        visited[turn].insert(key);
                    }

                    new_pop = true;

                    {
                        auto score = make_pair(turn, search_state.score);
                        if (score > best_score)
                        {
                            best_score = score;
                            best_action = search_state.first_action;
                        }
                    }

                    if (turn > 0 && predicted_num_sent_dogs[turn - 1] > 0)
                    {
                        auto sent_dogs = simulate_sent_dogs(predicted_num_sent_dogs[turn - 1],
                                search_state.state.ninjas, search_state.state.rock, search_state.state.dogs);
                        search_state.state.dogs.insert(search_state.state.dogs.end(), all(sent_dogs));
                    }

                    auto results = simulate_next_state(search_state.state);
                    if (search_state.state.dogs.size() > 0 && search_state.state.mp >= skill_costs[5])
                    {
                        auto shadow_results = simulate_next_state_using_shadow(search_state.state, skill_costs[5]);
                        results.insert(results.end(), all(shadow_results));
                    }
                    if (search_state.state.mp >= skill_costs[SkillID::MY_THUNDER])
                    {
                        auto thunder_results = simulate_next_state_using_my_thunder(search_state.state, skill_costs[SkillID::MY_THUNDER]);
                        results.insert(results.end(), all(thunder_results));
                    }
                    if (search_state.state.dogs.size() > 0 && search_state.state.mp >= skill_costs[SkillID::SLASH])
                    {
                        auto slash_results = simulate_next_state_using_slash(search_state.state, skill_costs[SkillID::SLASH]);
                        results.insert(results.end(), all(slash_results));
                    }
                    if (/* skill_costs[SkillID::ACC] <= 2 && */search_state.state.mp >= skill_costs[SkillID::ACC])
                    {
                        auto acc_results = simulate_next_state_using_acc(search_state.state, skill_costs[SkillID::ACC]);
                        results.insert(results.end(), all(acc_results));
                    }

                    for (auto& result : results)
                    {
                        if (timer.get_elapsed() > ABSOLUTE_TL_SEC)
                            goto END;

                        SearchState nsearch_state;
                        nsearch_state.lazy_dog = true;
                        nsearch_state.state = result.state;
                        nsearch_state.first_action = turn == 0 ? result.action : search_state.first_action;
                        nsearch_state.last_skill = result.action.skill;

                        State state_before_moving = search_state.state;
                        if (result.action.skill.id == SkillID::MY_THUNDER)
                            state_before_moving.rock.set(result.action.skill.pos(), false);
                        else if (result.action.skill.id == SkillID::SLASH)
                        {
                            const int ninja_id = result.action.skill.slash_ninja_id();
                            const auto& ninja = search_state.state.ninjas[ninja_id];
                            vector<Dog> ndogs;
                            for (auto& dog : search_state.state.dogs)
                            {
                                Pos diff = dog.pos - ninja;
                                if (max(abs(diff.x), abs(diff.y)) > 1)
                                    ndogs.push_back(dog);
                            }
                            state_before_moving.dogs = ndogs;
                        }

                        const int got_souls = (int)search_state.state.souls.size() - (int)result.state.souls.size();
                        assert(got_souls >= 0);
                        nsearch_state.got_souls = search_state.got_souls + got_souls;

                        nsearch_state.diff_mp = search_state.diff_mp;
                        nsearch_state.diff_mp += 2 * got_souls;
                        nsearch_state.used_skills = search_state.used_skills;
                        if (result.action.skill.used())
                        {
                            nsearch_state.diff_mp -= skill_costs[result.action.skill.id];
                            ++nsearch_state.used_skills;
                        }

                        nsearch_state.summon_dogs = search_state.summon_dogs + got_souls;

                        nsearch_state.accs = search_state.accs;
                        nsearch_state.thunders = search_state.thunders;
                        if (result.action.skill.id == SkillID::SLASH)
                        {
                            const int killed_dogs = (int)search_state.state.dogs.size() - (int)result.state.dogs.size();
                            assert(killed_dogs > 0);
                            nsearch_state.summon_dogs += killed_dogs;
                        }
                        else if (result.action.skill.id == SkillID::MY_THUNDER)
                        {
                            ++nsearch_state.thunders;
                        }
                        else if (result.action.skill.id == SkillID::ACC)
                        {
                            ++nsearch_state.accs;
                        }
                        else
                        {
                            assert(result.state.dogs.size() == search_state.state.dogs.size());
                            assert(result.state.dogs.size() == nsearch_state.state.dogs.size());
                        }


                        nsearch_state.death_risk = search_state.death_risk
                            + calc_rock_attack_risk(turn, state_before_moving, result);

                        nsearch_state.dog_can_attack = search_state.dog_can_attack;
                        const int danger_ninjas = count_danger_ninjas(result.state.ninjas, state_before_moving.dogs);
                        if (result.action.skill.id == SkillID::MY_SHADOW)
                            nsearch_state.dog_can_attack += 0.5 * danger_ninjas;
                        else
                            nsearch_state.dog_can_attack += 1 * danger_ninjas;

                        nsearch_state.score = eval(turn, search_state.state, nsearch_state, result);

                        beams[turn + 1][min(nsearch_state.used_skills, NUM_LOWERS - 1)].push(nsearch_state);
                    }
                }
            }
        }
        if (!new_pop)
            break;

        {
            bool all_negative = true;
            bool skip_end = false;
            rep(lowers_mp_diff_i, NUM_LOWERS)
            {
                if (!beams[turns][lowers_mp_diff_i].empty() && beams[turns][lowers_mp_diff_i].top().score > 0)
                {
                    auto search_state = beams[turns][lowers_mp_diff_i].top();
                    beams[turns][lowers_mp_diff_i].pop();
                    if (search_state.simulate_dog_ret_is_dead())
                    {
                        --lowers_mp_diff_i;
                        continue;
                    }
                    beams[turns][lowers_mp_diff_i].push(search_state);
//                     if (beams[turns][lowers_mp_diff_i].top().got_souls >= 4)
//                         skip_end = true;

                    if (beams[turns][lowers_mp_diff_i].top().got_souls > 0)
                        all_negative = false;
                }
            }
//             if (all_negative)
//                 ++max_iters;
            if (!all_negative && timer.get_elapsed() > LOOSE_TL_SEC)
                break;
            if (skip_end)
                break;
        }
    }
END:

    if (input_info.enemy_info.state.mp >= skill_costs[SkillID::ENE_SHADOW] && shadow_kill_judger.should_attack() && !beams[turns][0].empty() && input_info.my_info.state.mp >= skill_costs[SkillID::ENE_SHADOW])
    {
        while (!beams[turns][0].empty() && beams[turns][0].top().score > 0)
        {
            auto ss = beams[turns][0].top();
            beams[turns][0].pop();
            if (!ss.simulate_dog_ret_is_dead())
            {
                beams[turns][0].push(ss);
                break;
            }
        }
        if (beams[turns][0].size() > 0)
        {
            auto& ss = beams[turns][0].top();
            if (ss.score > 0
                    && !ss.first_action.skill.used()
                    && ss.state.mp - skill_costs[SkillID::ENE_SHADOW] >= 4 * skill_costs[SkillID::MY_SHADOW])
            {
                Pos ene_shadow_pos = shadow_kill_judger.search_best_pos_to_kill_risky_soul(input_info.enemy_info.state);
                if (ene_shadow_pos.x != -1)
                {
                    ++shadow_kill_judger.attack_tries;

                    Action action = ss.first_action;
                    action.skill = Skills::ene_shadow(ene_shadow_pos);
                    return action;
                }
            }
        }
    }

    rep(lowers_mp_diff_i, NUM_LOWERS)
    {
        if (beams[turns][lowers_mp_diff_i].size() > 0 && make_pair(turns, beams[turns][lowers_mp_diff_i].top().score) > best_score)
        {
            auto search_state = beams[turns][lowers_mp_diff_i].top();
            beams[turns][lowers_mp_diff_i].pop();
            if (search_state.simulate_dog_ret_is_dead())
            {
                beams[turns][lowers_mp_diff_i].pop();
                --lowers_mp_diff_i;
                continue;
            }

            best_score = make_pair(turns, search_state.score);
            best_action = search_state.first_action;

#if 0
            dump(lowers_mp_diff_i);
            dump(search_state.death_risk);
            dump(search_state.dog_can_attack);
            dump(search_state.score);
            dump(search_state.diff_mp);
            dump(search_state.summon_dogs);
            cerr << endl;
#endif
        }
    }
//     dump(best_score);
    return best_action;
}

int test_simulation()
{
    cout << "takaptAI" << endl;
    cout.flush();

    for (g_turn = 0; ; ++g_turn)
    {
        InputInfo input_info = input();

        auto my_info = input_info.my_info;
        auto move_results = simulate_ninja_move(my_info.state.ninjas, my_info.state.rock, my_info.state.dogs, my_info.state.souls);
        dump(move_results.size());

        static State simu_state;
        if (g_turn > 0)
        {
            set<Dog> dog_set(all(my_info.state.dogs));
            bool ok_dog = true;
            for (auto& dog : simu_state.dogs)
            {
                if (!dog_set.count(dog))
                {
                    dump(dog);
                    Dog d;
                    for (auto& dd : my_info.state.dogs)
                        if (dd.id == dog.id)
                            d = dd;
                    dump(d);
                }

                ok_dog &= dog_set.count(dog);
            }
            if (my_info.state.ninjas != simu_state.ninjas || my_info.state.rock != simu_state.rock || !ok_dog)
            {
                dump(g_turn);
                dump(my_info.state.dogs);
                dump(simu_state.dogs);
//                 ofstream ng("damy_info");
//                 ng << "unko" << endl;
//                 ng.close();
            }
            assert(my_info.state.ninjas == simu_state.ninjas);
            assert(my_info.state.rock == simu_state.rock);
            assert(ok_dog);
        }

        {
            set<Pos> soul_set(all(my_info.state.souls));
            SimulateNinjaMoveResult result;
            int r = rand() % move_results.size();
            result = move_results[r];

            bool sha = my_info.state.mp >= input_info.skill_costs[5];
//             sha = false;
            Pos sha_pos;
            while (sha)
            {
                sha_pos = Pos(1 + rand() % (w - 2), 1 + rand() % (h - 2));
                if (!my_info.state.rock.get(sha_pos) && !result.rock.get(sha_pos))
                {
                    assert(in_field(sha_pos));
                    break;
                }
            }

            set<Pos> got_souls;
            rep(ninja_id, NINJAS)
            {
                Pos p = my_info.state.ninjas[ninja_id];
                for (int dir : result.moves[ninja_id])
                {
                    p.move(dir);
                    if (soul_set.count(p))
                        got_souls.insert(p);
                }
            }

            vector<Pos> nin = sha ? vector<Pos>{sha_pos} : vector<Pos>(all(result.ninjas));

            if(!sha)
            {
                cout << 2 << endl;
            }
            else
            {
                cout << 3 << endl;
                cout << 5 << " " << sha_pos.y << " " << sha_pos.x << endl;
            }
            rep(i, NINJAS)
                cout << format_moves(result.moves[i]) << endl;

            simu_state.ninjas = result.ninjas;
            simu_state.rock = result.rock;
            simu_state.dogs = simulate_dog_move(my_info.state.dogs, nin, result.rock);

            vector<Pos> sent_dogs_pos = simulate_sent_dogs_pos(got_souls.size(), result.ninjas, result.rock, simu_state.dogs);
            rep(i, sent_dogs_pos.size())
                simu_state.dogs.push_back(Dog{sent_dogs_pos[i], (int)simu_state.dogs.size()});
        }
        cout.flush();
    }
}

int main()
{
    cout << "takaptAI" << endl;
    cout.flush();

    vector<InputInfo> input_turn_log;
    ShadowKillJudger shadow_kill_judger;
    for (g_turn = 0; ; ++g_turn)
    {
        InputInfo input_info = input();
        if (input_info.ms < 0)
            break;

        Timer timer;
        timer.start();
        if (input_turn_log.size() > 0)
            shadow_kill_judger.add_turn_info(input_info.enemy_info, input_turn_log.back().enemy_info);
        input_turn_log.push_back(input_info);

        Action best_action = beam_search(input_info, shadow_kill_judger);

        cout << best_action.output_format() << endl;
        cout.flush();
//         dump(timer.get_elapsed());
    }
}
