#ifndef GEOMETRY_H_
#define GEOMETRY_H_

class Vector;

template <class T>
class AbstractPair {
public:
    AbstractPair(long long x, long long y) : _x(x), _y(y) {}
    virtual ~AbstractPair() = 0;
    long long x() const { return _x; }
    long long y() const { return _y; }
    bool operator==(AbstractPair<T> const& other) const;
    T& operator+=(Vector const& v);
    T reflection() const { return T(_y, _x); }
private:
    long long _x;
    long long _y;
};

class Position : public AbstractPair<Position> {
public:
    Position(long long x, long long y) : AbstractPair(x, y) {}
    ~Position() {}
    static Position const& origin();
};

class Vector : public AbstractPair<Vector> {
public:
    Vector(long long x, long long y) : AbstractPair(x, y) {}
    ~Vector() {}
};

#endif
