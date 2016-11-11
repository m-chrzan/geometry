#ifndef GEOMETRY_H_
#define GEOMETRY_H_

template <class T>
class AbstractPair {
public:
    AbstractPair(long long x, long long y) : _x(x), _y(y) {}
    virtual ~AbstractPair() = 0;
    long long x() const { return _x; }
    long long y() const { return _y; }
private:
    long long _x;
    long long _y;
};

class Position : public AbstractPair<Position> {
public:
    Position(long long x, long long y) : AbstractPair(x, y) {}
    ~Position() {}
};

class Vector : public AbstractPair<Vector> {
public:
    Vector(long long x, long long y) : AbstractPair(x, y) {}
    ~Vector() {}
};

#endif
