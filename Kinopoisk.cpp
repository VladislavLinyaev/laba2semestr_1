#include "Kinopoisk.h"
using namespace std;

//Getters Setters
string Kinopoisk::getTitle() const {
	return _title;
}
void Kinopoisk::setTitle(string title) {
		_title = title;
}


int Kinopoisk::getYear() {
	return _year;
}
void Kinopoisk::setYear(int year) {
		_year = year;
}


int Kinopoisk::getLength() {
	return _length;
}
void Kinopoisk::setLength(int length) {
		_length = length;
}


string Kinopoisk::getCountry() const {
	return _country;
}
void Kinopoisk::setCountry(string country) {
	_country = country;
}


string Kinopoisk::getGenre() const {
	return _genre;
}
void Kinopoisk::setGenre(string genre) {
	_genre = genre;
}

string Kinopoisk::getDirector() const {
	return _director;
}
void Kinopoisk::setDirector(string director) {
	_director = director;
}

int Kinopoisk::getRank() {
	return _rank;
}
void Kinopoisk::setRank(int rank) {
	_rank = rank;
}

int Kinopoisk::getId() {
	return _id;
}
void Kinopoisk::setId(int id) {
	_id = id;
}








