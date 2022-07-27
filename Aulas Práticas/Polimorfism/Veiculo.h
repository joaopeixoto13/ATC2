#pragma once


class Veiculo
{
public:
	virtual void appendKm(int dx) = 0;
	virtual int km() = 0;
};


class Automovel : public Veiculo
{
	const int K = 10;
	int _km;
public:
	Automovel() : _km(0) { }
	void appendKm(int dx) {
		_km += dx * K;
	}
	int km() {
		return _km;
	}
};


class Camiao : public Veiculo
{
	const int K = 20;
	int _km;
public:
	Camiao() : _km(0) { }
	void appendKm(int dx) {
		_km += dx * K;
	}
	int km() {
		return _km;
	}
};



class Mota : public Veiculo
{
	const int K = 5;
	int _km;
public:
	Mota() : _km(0) { }
	void appendKm(int dx) {
		_km += dx * K;
	}
	int km() {
		return _km;
	}
};



