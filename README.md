# geometry
Zadanie polega na zaimplementowaniu obiektów geometrycznych:
Position - punktu (pozycji) na płaszczyźnie,
Vector - wektora na płaszczyźnie,
Rectangle  - prostokąta,
Rectangles - kolekcji prostokątów.

Position:

- Position można stworzyć, przekazując współrzędne, np. Position(100, 200). Nie
  powinno być możliwe skonstruowanie obiektu Position bez podawania argumentów
  (t.j.  Position()).
- Position można porównywać za pomocą operatora ==.
- Position ma metody x() i y(), które wyciągają odpowiednie współrzędne.
- Position ma metodę reflection(), która zwraca pozycję odbitą względem osi
  x = y.
- Position implementuje operator "+=(vec)", gdzie vec jest wektorem. Operator
  powinien zwrócić referencję do wołanego obiektu.
- Position implementuje statyczną metodę origin(), która zwraca
  niemodyfikowalny obiekt Position(0, 0).

Vector:

- Vector można stworzyć, przekazując współrzędne, np. Vector(100, 200). Nie
  powinno być możliwe skonstruowanie obiektu Vector bez podawania argumentów
  (t.j.  Vector()).
- Vector można porównywać za pomocą operatora ==.
- Vector ma metody x() i y(), które wyciągają odpowiednie współrzędne.
- Vector ma metodę reflection(), która zwraca wektor odbity względem osi x = y.
- Vector implementuje operator "+=(vec)", gdzie vec jest wektorem. Operator
  powinien zwrócić referencję do wołanego obiektu.

Rectangle:

- Rectangle można stworzyć, przekazując jego rozmiar i pozycję lewego dolnego
  rogu: Rectangle(width, height, pos) lub Rectangle(width, height) - wtedy
  pozycja jest ustalona na (0, 0). Nie powinno być możliwe skonstruowanie
  obiektu Rectangle bez podawania argumentów (t.j.Rectangle()).
- Rectangle można porównywać za pomocą operatora ==.
- Rectangle ma metody width(),  height() i pos(), które wyciągają odpowiednie
  współrzędne i pozycję lewego dolnego rogu.
- Rectangle ma metodę reflection(), która zwraca prostokąt odbity względem osi
  x = y.
- Rectangle implementuje operator "+=(vec)", gdzie vec jest wektorem. Operator
  powinien zwrócić referencję do wołanego obiektu.
- Rectangle implementuje metodę area(), która wylicza jego pole powierzchni.
- Rectangle implementuje metodę split_horizontally(place), która zwraca
  parę prostokątów powstałą z rozcięcia prostokąta wzdłuż osi X, tak że
  pierwszy prostokąt ma wysokość place, np. prostokąt Rectangle(100, 200)
  rozcięty z wartością place = 20 da nam dwa prostokąty:
   * pierwszy o lewym dolnym rogu (0, 0), szerokości 100 i wysokości 20,
   * drugi o lewym dolnym rogu (0, 20), szerokości 100 i  wysokości 180.
- Rectangle implementuje metodę split_vertically(place) działającą
  analogicznie do split_horizontally().

Rectangles:

- Kolekcję Rectangles można stworzyć w następujący sposób:
  Rectangles({rect1, rect2, ..., rectn}). Powinno być możliwe skonstruowanie
  pustej kolekcji Rectangles, jeśli nie podano argumentów (t.j.Rectangles()).
- wywołanie recs[i] zwraca referencję do i-tego prostokąta w kolekcji.
- Metoda size() zwraca liczbę prostokątów w kolekcji.
- Rectangles można porównywać za pomocą operatora ==.
- Rectangles implementuje operator "+=(vec)", gdzie vec jest wektorem. Operator
  powinien zwrócić referencję do wołanego obiektu.
- Rectangles implementuje metodę split_horizontally(idx, place), która rozcina
  prostokąt nr idx. Prostokąty powstałe z rozcięcia powinny zająć miejsce
  rozciętego prostokąta. Na przykład rozcięcie prostokąta rec2 w kolekcji
  (rec1, rec2, rec3) powinno zamienić kolekcje na (rec1, rec2a, rec2b, rec3),
  gdzie rec2a i rec2b to prostokąty powstałe z rozcięcia rec2. Ta metoda może
  działać liniowo ze względu na liczbę prostokątów.
- Rectangles implementuje metodę split_vertically(idx, place) działającą
  analogicznie do split_horizontally().

Dodatkowo powinny być możliwe są następujące operacje arytmetyczne:

  Position = Position + Vector
  Position = Vector + Position
  Vector = Vector + Vector
  Rectangle = Rectangle + Vector
  Rectangle = Vector + Rectangle
  Rectangles = Rectangles + Vector
  Rectangles = Vector + Rectangles

z naturalną semantyką. Jeżeli jeden z argumentów jest przekazany przez r-value,
należy wykorzystać przekazaną pamięć zaalokowaną dynamicznie do stworzenia
obiektu wynikowego.

Operacje

- merge_horizontally(rect1, rect2)
- merge_vertically(rect1, rect2)

łączą dwa prostokąty odpowiednio wzdłuż osi X i Y. Przykładowo
merge_horizontally łączy dwa prostokąty ze wspólną krawędzią (górną krawędzią
pierwszego prostokąta i dolną krawędzią drugiego prostokąta). Jeżeli dało się
skleić dwa prostokąty r1 i r2, to odpowiednia operacja split na wynikowym
prostokącie powinna dać z powrotem r1 i r2.

Wszystkie klasy powinny umieć się kopiować i przypisywać na siebie w efektywny
sposób. Można przyjąć, że wszystkie współrzędne figur będą liczbami
całkowitymi. Wyniki prostych operacji całkowitoliczbowych na współrzędnych nie
będą przekraczać 2^31 - 1. Należy sprawdzać poprawność argumentów.
Nieprawidłowe argumenty powinny powodować zakończenie programu z błędem.

Rozwiązanie powinno zawierać pliki geometry.h oraz geometry.cc. Pliki te należy
umieścić w repozytorium w katalogu

grupaN/zadanie3/ab123456+cd123456

lub

grupaN/zadanie3/ab123456+cd123456+ef123456

gdzie N jest numerem grupy, a ab123456, cd123456, ef123456 są identyfikatorami
członków zespołu umieszczającego to rozwiązanie.
Katalog z rozwiązaniem nie powinien zawierać innych plików, ale może zawierać
podkatalog private, gdzie można umieszczać różne pliki, np. swoje testy. Pliki
umieszczone w tym podkatalogu nie będą oceniane.
