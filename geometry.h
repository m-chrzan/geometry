#ifndef GEOMETRY_H_
#define GEOMETRY_H_

#include <cassert>
#include <cstddef>
#include <cstdint>
#include <utility>
#include <vector>

class Vector;

template<class T>
class AbstractPair {
public:
    AbstractPair(int32_t x, int32_t y) : _x(x), _y(y) {}

    AbstractPair(AbstractPair const &pair) = default;

    virtual ~AbstractPair() = 0;

    int32_t x() const { return _x; }

    int32_t y() const { return _y; }

    bool operator==(AbstractPair<T> const &other) const;

    T &operator+=(Vector const &v);

    T reflection() const { return T(_y, _x); }

private:
    int32_t _x;
    int32_t _y;
};

class Position : public AbstractPair<Position> {
public:
    Position(int32_t x, int32_t y) : AbstractPair(x, y) {}

    Position &operator=(Position const &pos) = default;

    ~Position() {}

    static Position const &origin();
};

class Vector : public AbstractPair<Vector> {
public:
    Vector(int32_t x, int32_t y) : AbstractPair(x, y) {}

    Vector &operator=(Vector const &vect) = default;

    ~Vector() {}
};

class Rectangle {
public:
    Rectangle(int32_t width, int32_t height, Position pos) : _width(width),
                                                             _height(height),
                                                             _pos(pos) {
        assert(width > 0);
        assert(height > 0);
    }

    Rectangle(int32_t width, int32_t height) : Rectangle(width,
                                                         height,
                                                         Position::origin()) {}

    Rectangle(Rectangle const &rect) = default;

    Rectangle &operator=(Rectangle const &rect) = default;

    int32_t width() const { return _width; }

    int32_t height() const { return _height; }

    Position pos() const { return _pos; }

    bool operator==(Rectangle const &other) const;

    Rectangle reflection() const {
        return Rectangle(_height, _width, _pos.reflection());
    }

    Rectangle &operator+=(Vector const &vec);

    int32_t area() const { return _width * _height; }

    std::pair<Rectangle, Rectangle> split_horizontally(int32_t place);

    std::pair<Rectangle, Rectangle> split_vertically(int32_t place);

    ~Rectangle() {}

private:
    int32_t _width;
    int32_t _height;
    Position _pos;
};

class Rectangles {
public:
    Rectangles(std::initializer_list<Rectangle> rects) : _rectangles(rects) {}

    Rectangles() {}

    Rectangles(Rectangles const &rects) = default;

    Rectangles(Rectangles &&rects) = default;

    Rectangles &operator=(Rectangles const &rects) = default;

    Rectangles &operator=(Rectangles &&rects) = default;

    size_t size() const { return _rectangles.size(); };

    Rectangle &operator[](size_t i);

    bool operator==(Rectangles const &others) const;

    Rectangles &operator+=(Vector const &vec);

    void split_horizontally(size_t i, int32_t place);

    void split_vertically(size_t i, int32_t place);

    ~Rectangles() {}

private:
    std::vector<Rectangle> _rectangles;
    void replace_with_pair(size_t i, std::pair<Rectangle, Rectangle> const &pair);
};

const Vector operator+(Vector v1, Vector const &v2);

const Position operator+(Position p, Vector const &v);

const Position operator+(Vector const &v, Position p);

const Rectangle operator+(Rectangle r, Vector const &v);

const Rectangle operator+(Vector const &v, Rectangle r);

const Rectangles operator+(Rectangles rs, Vector const &v);

const Rectangles operator+(Vector const &v, Rectangles rs);

Rectangle merge_horizontally(Rectangle const &rect1, Rectangle const &rect2);

Rectangle merge_vertically(Rectangle const &rect1, Rectangle const &rect2);

#endif
