#pragma once
#include "Kinopoisk.h"
namespace Func {
	void save(Kinopoisk* arr, int n);
	Kinopoisk* read(int& n);
	Kinopoisk* add(Kinopoisk* arr, int& n);
	void deleted(Kinopoisk* arr, int n);
	Kinopoisk* edit(Kinopoisk* arr, int n);
	void search(Kinopoisk* arr, int n);
	void print(Kinopoisk* arr, int n);
	}

