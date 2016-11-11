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

//Rectangle &Rectangle::operator=(Rectangle &&rect) {
//    _pos = std::move(rect._pos);
//    _width = rect._width;
//    _height = rect._height;
//    return *this;
//}

bool Rectangle::operator==(Rectangle const &other) const {
    return this->_width == other._width && this->_height == other._height &&
           this->_pos == other._pos;
}

Rectangle &Rectangle::operator+=(Vector const &vec) {
    _pos += vec;
    return *this;
}

//Rectangle& Rectangles::operator[](int i) {
//    assert(i <= this.size());
//    return this->_rectangles[i - 1]; // TODO: sprawdzić, jak mają być numerowane prostokąty - od zera czy od jeden?
//}
//
//bool Rectangles::operator==(Rectangles const& others) const {
//    if (this->size() != others.size()) {
//        return false;
//    }
//    for (int i = 0; i < this->size(); i++) {
//        if (!(this[i] == others[i])) {
//            return false;
//        }
//    }
//    return true;
//}
