#ifndef GEOMETRY_H_
#define GEOMETRY_H_

#include <cstddef>
#include <utility>
#include <vector>

class Vector;

template<class T>
class AbstractPair {
public:
    AbstractPair(long x, long y) : _x(x), _y(y) {}

    virtual ~AbstractPair() = 0;

    long x() const { return _x; }

    long y() const { return _y; }

    bool operator==(AbstractPair<T> const &other) const;

    T &operator+=(Vector const &v);

    T reflection() const { return T(_y, _x); }

private:
    long _x;
    long _y;
};

class Position : public AbstractPair<Position> {
public:
    Position(long x, long y) : AbstractPair(x, y) {}

    ~Position() {}

    static Position const &origin();
};

class Vector : public AbstractPair<Vector> {
public:
    Vector(long x, long y) : AbstractPair(x, y) {}

    ~Vector() {}
};

class Rectangle {
public:
    Rectangle(long width, long height, Position pos) :
            _width(width), _height(height), _pos(pos) {}

    Rectangle(long width, long height) : _width(width),
                                                   _height(height),
                                                   _pos(Position::origin()) {}

    Rectangle(Rectangle const &rect) : _width(rect._width),
                                       _height(rect._height), _pos(rect._pos) {}

    Rectangle(Rectangle &&rect) : _width(rect._width), _height(rect._height),
                                  _pos(std::move(rect._pos)) {}

    Rectangle &operator=(Rectangle &&rect);

    long width() const { return _width; }

    long height() const { return _height; }

    Position pos() const { return _pos; }

    bool operator==(Rectangle const &other) const;

    Rectangle reflection() const {
        return Rectangle(_height, _width, _pos.reflection());
    }

    Rectangle &operator+=(Vector const &vec);

    long area() const { return _width * _height; }

    std::pair <Rectangle, Rectangle> split_horizontally(int place);

    std::pair <Rectangle, Rectangle> split_vertically(int place);

    ~Rectangle() {}

private:
    long _width;
    long _height;
    Position _pos;
};

class Rectangles {
public:
    Rectangles(std::initializer_list <Rectangle> rects) : _rectangles(rects) {}

    Rectangles(Rectangles const &rs) : _rectangles(rs._rectangles) {}

    Rectangles(Rectangles &&rs) : _rectangles(std::move(rs._rectangles)) {}

    Rectangles() {}

    size_t size() const { return _rectangles.size(); };

    Rectangle &operator[](size_t i);

    bool operator==(Rectangles const &others) const;

    Rectangles &operator+=(Vector const &vec);

    void split_horizontally(size_t idx, int place);

    void split_vertically(size_t idx, int place);

    ~Rectangles() {}

private:
    std::vector <Rectangle> _rectangles;

    Rectangle operator[](size_t i) const { return _rectangles.at(i); };

    void replace_with_pair(size_t idx,
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
