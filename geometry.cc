#include "geometry.h"

template
class AbstractPair<Position>;

template
class AbstractPair<Vector>;

template<class T>
AbstractPair<T>::~AbstractPair() {}

template<class T>
bool AbstractPair<T>::operator==(AbstractPair<T> const &other) const {
    return _x == other._x && _y == other._y;
}

template<class T>
T &AbstractPair<T>::operator+=(Vector const &v) {
    _x += v.x();
    _y += v.y();
    return *static_cast<T *>(this);
}

Position const &Position::origin() {
    static Position o(0, 0);
    return o;
}

bool Rectangle::operator==(Rectangle const &other) const {
    return _width == other._width &&
           _height == other._height &&
           _pos == other._pos;
}

Rectangle &Rectangle::operator+=(Vector const &vec) {
    _pos += vec;
    return *this;
}

std::pair<Rectangle, Rectangle> Rectangle::split_horizontally(int32_t place) const {
    assert(place > 0 && place < _height);
    Rectangle r1(_width, place, _pos);
    Rectangle r2(_width, _height - place, _pos + Vector(0, place));
    return std::make_pair(r1, r2);
}

std::pair<Rectangle, Rectangle> Rectangle::split_vertically(int32_t place) const {
    assert(place > 0 && place < _width);
    Rectangle r1(place, _height, _pos);
    Rectangle r2(_width - place, _height, _pos + Vector(place, 0));
    return std::make_pair(r1, r2);
}


Rectangle &Rectangles::operator[](size_t i) {
    assert(i < size());
    return _rectangles[i];
}

bool Rectangles::operator==(Rectangles const &others) const {
    return _rectangles == others._rectangles;
}

Rectangles &Rectangles::operator+=(Vector const &vec) {
    for (size_t i = 0; i < size(); i++) {
        (*this)[i] += vec;
    }
    return *this;
}

void Rectangles::replace_with_pair(size_t i, std::pair<Rectangle, Rectangle> const &pair) {
    (*this)[i] = pair.first;
    auto it = _rectangles.begin();
    _rectangles.insert(it + i + 1, pair.second);
}

void Rectangles::split_horizontally(size_t i, int32_t place) {
    Rectangle r = _rectangles[i];
    std::pair<Rectangle, Rectangle> splitted = r.split_horizontally(place);
    replace_with_pair(i, splitted);
}

void Rectangles::split_vertically(size_t i, int32_t place) {
    Rectangle r = _rectangles[i];
    std::pair<Rectangle, Rectangle> splitted = r.split_vertically(place);
    replace_with_pair(i, splitted);
}

const Vector operator+(Vector v1, Vector const &v2) {
    return (v1 += v2);
}

const Position operator+(Position p, Vector const &v) {
    return (p += v);
}

const Position operator+(Vector const &v, Position p) {
    return (p += v);
}

const Rectangle operator+(Rectangle r, Vector const &v) {
    return (r += v);
}

const Rectangle operator+(Vector const &v, Rectangle r) {
    return (r += v);
}

const Rectangles operator+(Rectangles rs, Vector const &v) {
    return (rs += v);
}

const Rectangles operator+(Vector const &v, Rectangles rs) {
    return (rs += v);
}

Rectangle merge_horizontally(Rectangle const &rect1, Rectangle const &rect2) {
    assert(rect1.pos() + Vector(0, rect1.height()) == rect2.pos() &&
           rect1.width() == rect2.width());
    return Rectangle(rect1.width(),
                     rect1.height() + rect2.height(),
                     rect1.pos());
}

Rectangle merge_vertically(Rectangle const &rect1, Rectangle const &rect2) {
    assert(rect1.pos() + Vector(rect1.width(), 0) == rect2.pos() &&
           rect1.height() == rect2.height());
    return Rectangle(rect1.width() + rect2.width(),
                     rect1.height(),
                     rect1.pos());
}
