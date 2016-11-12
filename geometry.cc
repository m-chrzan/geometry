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
    return _width == other._width && _height == other._height &&
           _pos == other._pos;
}

Rectangle &Rectangle::operator+=(Vector const &vec) {
    _pos += vec;
    return *this;
}

std::pair <Rectangle, Rectangle> Rectangle::split_horizontally(int place) {
    assert(place < _height);
    Rectangle r1(_width, place, _pos);

    Position upperPos(_pos.x(), _pos.y() + place);
    Rectangle r2(_width, _height - place, upperPos);
    return std::make_pair(r1, r2);
}

std::pair <Rectangle, Rectangle> Rectangle::split_vertically(int place) {
    assert(place < _width);
    Rectangle r1(place, _height, _pos);

    Position rightPos(_pos.x() + place, _pos.y());
    Rectangle r2(_width - place, _height, rightPos);
    return std::make_pair(r1, r2);
}


Rectangles::Rectangles(std::initializer_list <Rectangle> rects) {
    Rectangle test(0, 0); // TODO: Czy sprawdzanie typu nie jest przegieciem?
    for (auto r : rects) {
        assert(typeid(r).name() == typeid(test).name());
        _rectangles.push_back(r);
    }
}

Rectangle &Rectangles::operator[](int i) {
    // TODO: Ta funkcja robi coś dziwnego - zwraca Rectangles zamiast Rectangle
    // TODO: sprawdzić, jak mają być numerowane prostokąty - od zera czy od jeden?
    assert(i < this->size() && i >= 0);
    return _rectangles[i];
}

bool Rectangles::operator==(Rectangles const &others) const {
    Rectangles const &thisRectangles = *this; // TODO: Czy tak jest ładnie?
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
        _rectangles.at(i) += vec; // TODO: Jak robie tutaj this[i] += vec to nie działa. WHY?!
    }
    return *this;
}

void Rectangles::replace_rectangle_with_split(int idx,
                                              std::pair <Rectangle, Rectangle> const &splitted) {
    auto it = _rectangles.begin();
    _rectangles.erase(it + idx);
    _rectangles.insert(it + idx, splitted.second);
    _rectangles.insert(it + idx, splitted.first);
}

void Rectangles::split_horizontally(int idx, int place) {
    Rectangle r = _rectangles[idx];
    std::pair <Rectangle, Rectangle> splitted = r.split_horizontally(place);
    replace_rectangle_with_split(idx, splitted);
}

void Rectangles::split_vertically(int idx, int place) {
    Rectangle r = _rectangles[idx];
    std::pair <Rectangle, Rectangle> splitted = r.split_vertically(place);
    replace_rectangle_with_split(idx, splitted);

}
