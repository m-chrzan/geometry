#include "geometry.h"

template class AbstractPair<Position>;
template class AbstractPair<Vector>;

template <class T>
AbstractPair<T>::~AbstractPair() {}

template <class T>
bool AbstractPair<T>::operator==(AbstractPair<T> const& other) const {
    return this->_x == other._x && this->_y == other._y;
}

template <class T>
T& AbstractPair<T>::operator+=(Vector const& v) {
    _x += v.x();
    _y += v.y();
    return *static_cast<T*>(this);
}
