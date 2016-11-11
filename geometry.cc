#include <cassert>
#include <iostream>
#include <typeinfo>
#include "geometry.h"

template
class AbstractPair<Position>;

template
class AbstractPair<Vector>;

template<class T>
AbstractPair<T>::~AbstractPair() {}

template<class T>
bool AbstractPair<T>::operator==(AbstractPair<T> const &other) const {
    return this->_x == other._x && this->_y == other._y;
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

Rectangle &Rectangle::operator=(Rectangle &&rect) {
    if (this == &rect) {
        return *this;
    }
    _pos = std::move(rect._pos);
    _width = rect._width;
    _height = rect._height;
    return *this;
}

bool Rectangle::operator==(Rectangle const &other) const {
    return this->_width == other._width && this->_height == other._height &&
           this->_pos == other._pos;
}

Rectangle &Rectangle::operator+=(Vector const &vec) {
    _pos += vec;
    return *this;
}

Rectangles::Rectangles(std::initializer_list<Rectangle> rects) {
    Rectangle test(0,0); // TODO: Czy sprawdzanie typu nie jest przegieciem?
    for (auto r : rects) {
        assert(typeid(r).name() == typeid(test).name());
        _rectangles.push_back(r);
    }
}

Rectangle &Rectangles::operator[](int i) {
    // TODO: sprawdzić, jak mają być numerowane prostokąty - od zera czy od jeden?
    assert(i < this->size() && i >= 0);
    return _rectangles.at(i);
}

bool Rectangles::operator==(Rectangles const &others) const {
    Rectangles const& thisRectangles = *this; // TODO: Czy tak jest ładnie?
    if (this->size() != others.size()) {
        return false;
    }
    for (int i = 0; i < this->size(); i++) {
        if (!(thisRectangles[i] == others[i])) {
            return false;
        }
    }
    return true;
}

Rectangles &Rectangles::operator+=(Vector const &vec) {
    for (int i = 0; i < this->size(); i++) {
        this->_rectangles.at(i) += vec; // TODO: Jak robie tutaj this[i] += vec to nie działa. WHY?!
    }
    return *this;
}
