#define DEBUG

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

const int DX[] = { +0, +1, +0, -1 };
const int DY[] = { +1, +0, -1, +0 };
const char* S_DIR = "DRUL";
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


bool in_rect(int x, int y)
{
    return in_rect(x, y, w, h);
}


struct Pos
{
    int x, y;
    Pos(int x, int y)
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
    os << "(" << pos.x << ", " << pos.y << ")";
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
        assert(in_field(x, y));
        return a[y][x];
    }
    T get(const Pos& p) const
    {
        return get(p.x, p.y);
    }

    void set(int x, int y, const T& v)
    {
        assert(in_field(x, y));
        a[y][x] = v;
    }
    void set(const Pos& pos, const T& v)
    {
        set(pos.x, pos.y, v);
    }

private:
    int a[h][16];
};

class BoolBoard
{
public:
    BoolBoard() : f{}
    {
    }

    bool get(int x, int y) const
    {
        assert(in_field(x, y));
        return f[y][x];
    }
    bool get(const Pos& p) const
    {
        return get(p.x, p.y);
    }

    void set(int x, int y, bool v)
    {
        assert(in_field(x, y));
        f[y][x] = v;
    }
    void set(const Pos& pos, bool v)
    {
        set(pos.x, pos.y, v);
    }

    bool operator<(const BoolBoard& other) const
    {
        for (int y = 1; y < h - 1; ++y)
            for (int x = 1; x < w - 1; ++x)
                if (get(x, y) != other.get(x, y))
                    return get(x, y) < other.get(x, y);
        return false;
    }

    bool operator==(const BoolBoard& other) const
    {
        for (int y = 1; y < h - 1; ++y)
            for (int x = 1; x < w - 1; ++x)
                if (get(x, y) != other.get(x, y))
                    return false;
        return true;
    }

    bool operator!=(const BoolBoard& other) const
    {
        return !(*this == other);
    }

private:
//     bitset<80> f[80];
    bool f[h][16];
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

    bool is_skill() const
    {
        return id >= 0;
    }

    Pos pos() const
    {
        assert(1 <= id && id <= 6);
        return pos_;
    }

    int slash_ninja_id() const { return pos_.x; }

    int id;
    Pos pos_;
};
namespace Skills
{
const Skill FAST = Skill(0, Pos(-1, -1));
Skill my_rock(const Pos& p) { return Skill(1, p); }
Skill ene_rock(const Pos& p) { return Skill(2, p); }
Skill my_thunder(const Pos& p) { return Skill(3, p); }
Skill ene_thunder(const Pos& p) { return Skill(4, p); }
Skill my_shadow(const Pos& p) { return Skill(5, p); }
Skill ene_shadow(const Pos& p) { return Skill(6, p); }
Skill slash(int ninja_id) { return Skill(7, Pos(ninja_id, -1)); }
}

class Action
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

private:
    array<vector<int>, NINJAS> moves;
    Skill skill;
};

struct Dog
{
    Pos pos;
    int id;

    bool operator<(const Dog& other) const
    {
        return pos < other.pos || id < other.id;
    }
};
ostream& operator<<(ostream& os, const Dog& dog)
{
    os << "[" << dog.pos << ", " << dog.id << "]";
    return os;
}

struct State 
{
    int mp;
    array<Pos, NINJAS> ninjas;
    vector<Pos> souls;
    vector<Dog> dogs;
    BoolBoard rock;
};

struct SimulateMoveResult
{
    array<Pos, NINJAS> ninjas;
    BoolBoard rock;
    array<vector<int>, NINJAS> moves;
};
vector<SimulateMoveResult> simulate_move(const array<Pos, NINJAS>& init_ninjas, const BoolBoard& init_rock, const vector<Dog>& dogs)
{
    BoolBoard is_dog;
    for (auto& dog : dogs)
        is_dog.set(dog.pos, true);

    using P = pair<array<Pos, NINJAS>, BoolBoard>;
    map<P, array<vector<int>, NINJAS>> dp;

    vector<P> q;
    q.push_back(make_pair(init_ninjas, init_rock));
    dp[q.front()] = {};
    rep(ninja_id, NINJAS)
    {
        rep(moves, 2)
        {
            vector<P> nq;
            for (const auto& key : q)
            {
                const auto& ninjas = key.first;
                const auto& rock = key.second;
                const auto& moves = dp[key];

                rep(dir, 4)
                {
                    Pos cur = ninjas[ninja_id];
                    Pos next = cur.next(dir);
                    assert(!rock.get(cur));

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
                        if (rock.get(next))
                        {
                            nrock.set(next, false);
                            nrock.set(next.next(dir), true);
                        }

                        auto nkey = make_pair(nninjas, nrock);
                        if (!dp.count(nkey))
                        {
                            auto nmoves = moves;
                            nmoves[ninja_id].push_back(dir);

                            dp[nkey] = nmoves;
                            nq.push_back(nkey);
                        }
                    }
                }
            }
            q.swap(nq);
        }
    }

    vector<SimulateMoveResult> results;
    for (auto& it : dp)
        results.push_back(SimulateMoveResult{it.first.first, it.first.second, it.second});
    return results;
}

vector<Dog> simulate_dog(const vector<Dog>& init_dogs, const vector<Pos>& ninjas, const BoolBoard& rock)
{
    assert(0 < ninjas.size() && ninjas.size() <= 2);
    if (init_dogs.empty())
        return {};

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
            if (in_field(next) && !rock.get(next) && dist.get(next) == inf)
            {
                dist.set(next, nd);
                q.push(next);
            }
        }
    }

    vector<Dog> order = init_dogs;
    const auto cmp = [&](const Dog& a, const Dog& b)
    {
        return dist.get(a.pos) < dist.get(b.pos) || a.id < b.id;
    };
    sort(all(order), cmp);

    BoolBoard is_dog;
    for (auto& dog : order)
    {
        assert(!rock.get(dog.pos));
        is_dog.set(dog.pos, true);
    }

    for (auto& dog : order)
    {
        const Pos& p = dog.pos;
        if (dist.get(p) == inf)
            continue;

        for (int dir : DOG_DIR_ORDER)
        {
            const Pos next = p.next(dir);
            if (in_field(next)
                && !rock.get(next)
                && !is_dog.get(next)
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
vector<Dog> simulate_dog(const vector<Dog>& init_dogs, const array<Pos, NINJAS>& ninjas, const BoolBoard& rock)
{
    return simulate_dog(init_dogs, vector<Pos>(all(ninjas)), rock);
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
        Pos p;
        cin >> id >> p.y >> p.x;
        assert(in_field(p));
        state.ninjas[id] = p;
    }
    assert(in_field(state.ninjas[0]) && in_field(state.ninjas[1]));

    int num_dogs;
    cin >> num_dogs;
    rep(i, num_dogs)
    {
        Dog dog;
        cin >> dog.id >> dog.pos.y >> dog.pos.x;
        assert(in_field(dog.pos));
        state.dogs.push_back(dog);
    }

    int num_souls;
    cin >> num_souls;
    assert(num_souls <= 8);
    rep(i, num_souls)
    {
        Pos p;
        cin >> p.y >> p.x;
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
        exit(0);

    int skills_;
    cin >> skills_;
    assert(skills_ == SKILLS);

    rep(i, SKILLS)
        cin >> input_info.skill_costs[i];

    input_info.my_info = input_player_info();
    input_info.enemy_info = input_player_info();

    return input_info;
}

void test_simulate_move()
{
    cout << "takaptAI" << endl;
    cout.flush();

    rep(turn, 300)
    {
        InputInfo input_info = input();

        auto my_info = input_info.my_info;
        auto move_results = simulate_move(my_info.state.ninjas, my_info.state.rock, my_info.state.dogs);

        static State prev_state;
        //         dump(turn);
        if (turn > 0)
        {
            //             auto p = vector<Pos>(all(my_info.state.ninjas));
            //             auto q = vector<Pos>(all(prev_state.ninjas));
            //             dump(p);
            //             dump(q);
            if (my_info.state.ninjas != prev_state.ninjas || my_info.state.rock != prev_state.rock)
            {
                ofstream ng("damy_info");
                ng << "unko" << endl;
                ng.close();
            }
            assert(my_info.state.ninjas == prev_state.ninjas);
            assert(my_info.state.rock == prev_state.rock);
        }

        cout << 2 << endl;
        {
            set<Pos> soul_set(all(my_info.state.souls));
            SimulateMoveResult result;
            while (true)
            {
                int r = rand() % move_results.size();
                result = move_results[r];
                bool ok = true;
                rep(ninja_id, NINJAS)
                {
                    Pos p = my_info.state.ninjas[ninja_id];
                    for (int dir : result.moves[ninja_id])
                    {
                        p.move(dir);
                        if (soul_set.count(p))
                            ok = false;
                    }
                }
                if (ok)
                    break;
            }
            rep(i, NINJAS)
                cout << format_moves(result.moves[i]) << endl;

            prev_state.ninjas = result.ninjas;
            prev_state.rock = result.rock;
        }
        cout.flush();
    }
}

int main()
{
    cout << "takaptAI" << endl;
    cout.flush();

    rep(turn, 300)
    {
        InputInfo input_info = input();

        auto my_info = input_info.my_info;
        auto move_results = simulate_move(my_info.state.ninjas, my_info.state.rock, my_info.state.dogs);

        static State simu_state;
//         dump(turn);
        if (turn > 0)
        {
//             auto p = vector<Pos>(all(my_info.state.ninjas));
//             auto q = vector<Pos>(all(simu_state.ninjas));
//             dump(p);
//             dump(q);
            set<Dog> dog_set(all(my_info.state.dogs));
            bool ok_dog = true;
            for (auto& dog : simu_state.dogs)
                ok_dog &= dog_set.count(dog);
//             if (my_info.state.ninjas != simu_state.ninjas || my_info.state.rock != simu_state.rock || !ok_dog)
//             {
//                 dump(turn);
//                 dump(my_info.state.dogs);
//                 dump(simu_state.dogs);
//                 ofstream ng("damy_info");
//                 ng << "unko" << endl;
//                 ng.close();
//             }
            assert(my_info.state.ninjas == simu_state.ninjas);
            assert(my_info.state.rock == simu_state.rock);
        }

        {
            set<Pos> soul_set(all(my_info.state.souls));
            SimulateMoveResult result;
            int r = 91 % move_results.size();
            result = move_results[r];

            bool sha = my_info.state.mp >= input_info.skill_costs[5];
            Pos sha_pos = Pos(1 + rand() % (w - 2), 1 + rand() % (h - 2));
            assert(in_field(sha_pos));
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
            simu_state.dogs = simulate_dog(my_info.state.dogs, nin, result.rock);
        }
        cout.flush();
    }
}
