#ifndef GEOMETRY_H_
#define GEOMETRY_H_

#include <utility>
#include <vector>

class Vector;

template<class T>
class AbstractPair {
public:
    AbstractPair(long long x, long long y) : _x(x), _y(y) {}

    virtual ~AbstractPair() = 0;

    long long x() const { return _x; }

    long long y() const { return _y; }

    bool operator==(AbstractPair<T> const &other) const;

    T &operator+=(Vector const &v);

    T reflection() const { return T(_y, _x); }

private:
    long long _x;
    long long _y;
};

class Position : public AbstractPair<Position> {
public:
    Position(long long x, long long y) : AbstractPair(x, y) {}

    ~Position() {}

    static Position const &origin();
};

class Vector : public AbstractPair<Vector> {
public:
    Vector(long long x, long long y) : AbstractPair(x, y) {}

    ~Vector() {}
};

class Rectangle {
public:
    Rectangle(long long width, long long height, Position pos) :
            _width(width), _height(height), _pos(pos) {}

    Rectangle(long long width, long long height) : _width(width),
                                                   _height(height),
                                                   _pos(Position::origin()) {}

    Rectangle(Rectangle const &rect) : _width(rect._width),
                                       _height(rect._height), _pos(rect._pos) {}

    Rectangle(Rectangle &&rect) : _width(rect._width), _height(rect._height),
                                  _pos(std::move(rect._pos)) {}

    Rectangle &operator=(Rectangle &&rect);

    long long width() const { return _width; }

    long long height() const { return _height; }

    Position pos() const { return _pos; }

    bool operator==(Rectangle const &other) const;

    Rectangle reflection() const {
        return Rectangle(_height, _width, _pos.reflection());
    }

    Rectangle &operator+=(Vector const &vec);

    long long area() const { return _width * _height; }

    std::pair <Rectangle, Rectangle> split_horizontally(int place);

    std::pair <Rectangle, Rectangle> split_vertically(int place);

    ~Rectangle() {}

private:
    long long _width;
    long long _height;
    Position _pos;
};

class Rectangles {
public:
    Rectangles(std::initializer_list <Rectangle> rects) : _rectangles(rects) {}

    Rectangles(Rectangles const &rs) : _rectangles(rs._rectangles) {}

    Rectangles(Rectangles &&rs) : _rectangles(std::move(rs._rectangles)) {}

    Rectangles() {}

    long long size() const { return _rectangles.size(); };

    Rectangle &operator[](int i);

    bool operator==(Rectangles const &others) const;

    Rectangles &operator+=(Vector const &vec);

    void split_horizontally(int idx, int place);

    void split_vertically(int idx, int place);

    ~Rectangles() {}

private:
    std::vector <Rectangle> _rectangles;

    Rectangle operator[](int i) const { return _rectangles.at(i); };

    void replace_with_pair(int idx,
                           std::pair <Rectangle, Rectangle> const &pair);
};

Vector operator+(Vector v1, Vector const &v2);
Position operator+(Position p, Vector const &v);
Position operator+(Vector const &v, Position p);
Rectangle operator+(Rectangle r, Vector const &v);
Rectangle operator+(Vector const &v, Rectangle r);
Rectangles operator+(Rectangles rs, Vector const &v);
Rectangles operator+(Vector const &v, Rectangles rs);

#endif
