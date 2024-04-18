#pragma once
#include <iostream>
#include <string>

class Kinopoisk {
private:
    int _id; // главный индекс для добавления, редактирования, удаления, поиска.
    std::string _title;
    int _year;
    int _length;
    std::string _country;
    std::string _genre;
    std::string _director;
    int _rank;
public:
    //Getters Setters
    std::string getTitle() const;
    void setTitle(std::string title);

    int getYear();
    void setYear(int year);

    int getLength();
    void setLength(int length);

    std::string getCountry() const;
    void setCountry(std::string country);

    std::string getGenre() const;
    void setGenre(std::string genre);

    std::string getDirector() const;
    void setDirector(std::string director);

    int getRank();
    void setRank(int rank);

    int getId();
    void setId(int id);

    //динамический массив (конструктор и диструктор)
    Kinopoisk(int n) {
//        _arr = new Kinopoisk[n];
    }

    ~Kinopoisk() {
  //      delete _arr;;
    }

    Kinopoisk() {
        _title = "";
        _year = 0;
        _length = 0;
        _country = "";
        _genre = "";
        _director = "";
        _rank = 0;
      }
      Kinopoisk(Kinopoisk* film);

    friend std::ostream& operator<<(std::ostream& os, const Kinopoisk& film);
    friend std::istream& operator>>(std::istream& is, Kinopoisk& film);
};
