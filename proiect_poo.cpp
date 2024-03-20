#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string.h>

using namespace std;

//TEAM BUILDING

class Cazare {

private:
	string locatie="Necunoscuta";
	char* denumireCazare=NULL;
	float pretTotal=0;
	int nrCamere=0;
	float* preturiCamere=NULL;
	static float pretMinimCamera;
public:

	Cazare(const char* denumireCazare)
	{
		cout << "\nApel constructor cu un parametri !";

		this->denumireCazare = new char[strlen(denumireCazare) + 1];
		strcpy(this->denumireCazare, denumireCazare);
	}

	Cazare(string locatie, const char* denumireCazare,float pretTotal, int nrCamere, float* preturiCamere)
	{
		cout << "\nApel constructor cu toti parametri !";

		this->locatie = locatie;
		if (strlen(denumireCazare) > 1)
		{
			this->denumireCazare = new char[strlen(denumireCazare) + 1];
			strcpy(this->denumireCazare, denumireCazare);
		}
		this->pretTotal = pretTotal;
		if (nrCamere >0 && preturiCamere != NULL)
		{
			this->nrCamere = nrCamere;
			this->preturiCamere = new float[this->nrCamere];
			for (int i = 0; i < this->nrCamere; i++)
				this->preturiCamere[i] = preturiCamere[i];
		}
	}
	Cazare(const Cazare& c)
	{
		cout << "\nApel constructor COPY !";
		
		this->locatie = c.locatie;
        this->denumireCazare = new char[strlen(c.denumireCazare) + 1];
		strcpy(this->denumireCazare, c.denumireCazare);

		this->pretTotal = c.pretTotal;
		if (c.nrCamere >0 && c.preturiCamere != NULL)
		{
			this->nrCamere = c.nrCamere;
			this->preturiCamere = new float[this->nrCamere];
			for (int i = 0; i < this->nrCamere; i++)
				this->preturiCamere[i] = c.preturiCamere[i];
		}
	}
	Cazare& operator=(const Cazare& c)
	{
		cout << "\nApel constructor egal !";

		if (this != &c)
		{
			delete[] this->denumireCazare;
			delete[] this->preturiCamere;

			this->locatie = c.locatie;
			this->denumireCazare = new char[strlen(c.denumireCazare) + 1];
			strcpy(this->denumireCazare, c.denumireCazare);

			this->pretTotal = c.pretTotal;
			if (c.nrCamere != 0 && c.preturiCamere != NULL)
			{
				this->nrCamere = c.nrCamere;
				this->preturiCamere = new float[this->nrCamere];
				for (int i = 0; i < this->nrCamere; i++)
					this->preturiCamere[i] = c.preturiCamere[i];
			}
		}
		return *this;
	}

	static float getPretMinimCamera()
	{
		return Cazare::pretMinimCamera;
	}
	void setPretMinimCamera(float pretMinimCamera)
	{
		if (pretMinimCamera > 0)
			Cazare::pretMinimCamera = pretMinimCamera;
	}
	string getLocatie()
	{
		return this->locatie;
	}
	void setLocatie(string locatie)
	{
		if (locatie.length() > 1)
			this->locatie = locatie;
	}
	char* getDenumireCazare()
	{
		return this->denumireCazare;
	}
	void setDenumireCazare(const char* denumireCazare)
	{
		if (strlen(denumireCazare) > 1)
		{
			delete[] this->denumireCazare;
			this->denumireCazare = new char[strlen(denumireCazare) + 1];
			strcpy(this->denumireCazare, denumireCazare);
		}
	}
	int getNrCamere()
	{
		return this->nrCamere;
	}
	void setNrCamere(int nrCamere)
	{
		if (nrCamere > 0)
			this->nrCamere = nrCamere;
	}
	float getPretTotal()
	{
		return this->pretTotal;
	}
	void setPretTotal(float pretTotal)
	{
		if (pretTotal > 0)
			this->pretTotal = pretTotal;
	}
	float* getPreturiCamere()
	{
		return this->preturiCamere;
	}
	void setPreturiCamere(float* preturiCamere)
	{
		if (preturiCamere != NULL)
		{
			delete[] this->preturiCamere;
			this->preturiCamere = new float[this->nrCamere];
			for (int i = 0; i < this->nrCamere; i++)
			{
				this->preturiCamere[i] = preturiCamere[i];
			}
		}
	}

	float& operator[](int index)
	{
		if (index > 0 && index < nrCamere)
			return this->preturiCamere[index];
	}

	bool operator>(Cazare c)
	{
		return this->pretTotal > c.pretTotal;
	}

	// pre incrementare
	Cazare& operator++()
	{
		this->pretTotal++;
		return *this;
	}

	// post incrementare 
	Cazare operator++(int)
	{
		Cazare copie = *this;
		this->pretTotal++;
		return copie;
	}

	operator float()
	{
		return this->pretTotal;
	}

	Cazare& operator+(float pretCameraNoua)
	{
		Cazare c = *this;

		delete[] this->preturiCamere;
		this->nrCamere++;

		this->preturiCamere = new float[this->nrCamere];
		for (int i = 0; i < this->nrCamere-1; i++)
		{
			this->preturiCamere[i] = c.preturiCamere[i];
		}
		this->preturiCamere[this->nrCamere - 1] = pretCameraNoua;

		return *this;
	}

	bool operator==(const Cazare& c)
	{
		bool ok = true;
		if(strcmp(this->denumireCazare,c.denumireCazare)!=0)
		{
			ok = false;
		}
		if (this->pretTotal != c.pretTotal)
		{
			ok = false;
		}
		if (this->nrCamere != c.nrCamere)
		{
			ok = false;
		}
		else
		{
			for (int i = 0; i < this->nrCamere; i++)
			{
				if (this->preturiCamere[i] != c.preturiCamere[i])
					ok = false;
			}
		}
		return ok;
	}

	bool operator !=(const Cazare& c)
	{
		return !((*this) == c);
	}

	void afisare()
	{
		cout << "\n-------------";

		cout << "\nLocatie cazare: " << this->locatie;
		cout << "\nDenumire cazare: " << this->denumireCazare;
		cout << "\nPretul total: " << this->pretTotal;
		cout << "\nNumar camere: " << this->nrCamere;
		cout << "\nPret pe camera: ";
		for (int i = 0; i < this->nrCamere; i++)
			cout << "\nPret camera " << i + 1 << " : " << this->preturiCamere[i];

		cout << "\n-------------";
	}

	friend ostream& operator<<(ostream& out, Cazare c)
	{
		out << "\n*************";
		out << "\nLocatie: " << c.locatie;
		out << "\nDenumire cazare: " << c.denumireCazare;
		out << "\nPret total: " << c.pretTotal;
		out << "\nNumar camere: " << c.nrCamere;
		cout << "\nPret camere: ";
		for (int i = 0; i < c.nrCamere; i++)
			out << "\nPret camera " << i + 1 << " : " << c.preturiCamere[i];
		out << "\n*************";

		return out;
	}

	friend istream& operator>>(istream& in, Cazare& c)
	{

		delete[] c.denumireCazare;
		delete[] c.preturiCamere;

		cout << "\nDenumire cazare: ";
		char buffer[200];
		in >> buffer;
		c.denumireCazare = new char[strlen(buffer) + 1];
		strcpy(c.denumireCazare, buffer);
		in >> c.denumireCazare;

		cout << "\nLocatie: ";
		in.ignore();
		in >> c.locatie;
		cout << "\nPret total: ";
		in >> c.pretTotal;
		cout << "\nNumar camere: ";
		in >> c.nrCamere;
		cout << "\nPret camere: ";
		c.preturiCamere = new float[c.nrCamere];
		for (int i = 0; i < c.nrCamere; i++)
		{
			cout << "\nPret camera " << i + 1<<" : ";
			in >> c.preturiCamere[i];
		}
		return in;
	}

	~Cazare()
	{
		cout << "\nApel destructor !";
		delete[] this->denumireCazare;
		delete[] this->preturiCamere;
	}
};

float Cazare::pretMinimCamera = 0;

class Activitati {

private:
	char* denumireActivitate=NULL;
	float durata=0;
	int nrEchipe=0;
	string* denumireEchipe=NULL;
public:

	Activitati(const char* denumireActivitate)
	{
		cout << "\nApel constructor cu un parametri !";

		this->denumireActivitate= new char[strlen(denumireActivitate) + 1];
		strcpy(this->denumireActivitate, denumireActivitate);
	}
	Activitati(const char* denumireActivitate, float durata, int nrEchipe, string* denumireEchipe)
	{
		cout << "\nApel constructor cu toti parametri !";

		if (strlen(denumireActivitate) > 1)
		{
			this->denumireActivitate = new char[strlen(denumireActivitate) + 1];
			strcpy(this->denumireActivitate, denumireActivitate);
		}
		this->durata = durata;
		if (nrEchipe > 0 && denumireEchipe != NULL)
		{
			this->nrEchipe = nrEchipe;
			this->denumireEchipe = new string[this->nrEchipe];
			for (int i = 0; i < this->nrEchipe; i++)
				this->denumireEchipe[i] = denumireEchipe[i];
		}
	}
	Activitati(const Activitati& a)
	{
		cout << "\nApel constructor COPY !";

		if (strlen(a.denumireActivitate) > 1)
		{
			this->denumireActivitate = new char[strlen(a.denumireActivitate) + 1];
			strcpy(this->denumireActivitate, a.denumireActivitate);
		}
		this->durata = a.durata;
		if (a.nrEchipe > 0 && a.denumireEchipe != NULL)
		{
			this->nrEchipe = a.nrEchipe;
			this->denumireEchipe = new string[this->nrEchipe];
			for (int i = 0; i < this->nrEchipe; i++)
				this->denumireEchipe[i] = a.denumireEchipe[i];
		}
	}
	Activitati& operator=(const Activitati& a)
	{
		cout << "\nApel constructor egal !";

		if (this != &a)
		{
			delete[] this->denumireActivitate;
			delete[] this->denumireEchipe;

			this->denumireActivitate = new char[strlen(a.denumireActivitate) + 1];
			strcpy(this->denumireActivitate, a.denumireActivitate);
			this->durata = a.durata;

			this->nrEchipe = a.nrEchipe;
			if (a.nrEchipe != 0 && a.denumireEchipe != NULL)
			{
				this->nrEchipe= a.nrEchipe;
				this->denumireEchipe = new string[this->nrEchipe];
				for (int i = 0; i < this->nrEchipe; i++)
					this->denumireEchipe[i] = a.denumireEchipe[i];
			}
		}
		return *this;
	}

	char* getDenumireActivitate()
	{
		return this->denumireActivitate;
	}
	void setDenumireActivitate(const char* denumireActivitate)
	{
		if (strlen(denumireActivitate) > 1)
		{
			delete[] this->denumireActivitate;
			this->denumireActivitate = new char[strlen(denumireActivitate) + 1];
			strcpy(this->denumireActivitate, denumireActivitate);
		}
	}
	float getDurata()
	{
		return this->durata;
	}
	void setDurata(float durata)
	{
		if (durata > 0)
			this->durata = durata;
	}
	int getNrEchipe()
	{
		return this->nrEchipe;
	}
	void setNrEchipe(int nrEchipe)
	{
		if (nrEchipe > 0)
			this->nrEchipe = nrEchipe;
	}
	string* getDenumireEchipe()
	{
		return this->denumireEchipe;
	}
	void setDenumireEchipe(string* denumireEchipe)
	{
		if (this->denumireEchipe != NULL)
		{
			delete[] this->denumireEchipe;
			this->denumireEchipe = new string[this->nrEchipe];
			for (int i = 0; i < this->nrEchipe; i++)
				this->denumireEchipe[i] = denumireActivitate[i];
		}
	}

	friend ostream& operator<<(ostream& out, const Activitati& a)
	{
		out << "\n*************";
		out << "\nDenumire activitate: " << a.denumireActivitate;
		out << "\nDurata activitate: " << a.durata;
		out << "\nNumar echipe: " << a.nrEchipe;
		cout << "\nDenumire echipe: ";
		for (int i = 0; i < a.nrEchipe; i++)
			out << "\nDenumire echipa " << i + 1 << " : " << a.denumireEchipe[i];
		out << "\n*************";

		return out;
	}
	friend istream& operator>>(istream& in, Activitati& a)
	{

		delete[] a.denumireActivitate;
		delete[] a.denumireEchipe;

		cout << "\nDenumire activitate: ";
		char buffer[200];
		in >> buffer;
		a.denumireActivitate = new char[strlen(buffer) + 1];
		strcpy(a.denumireActivitate, buffer);
		in >> a.denumireActivitate;

		cout << "\nDurata: ";
		in >> a.durata;
		cout << "\nNumar echipe: ";
		in >> a.nrEchipe;
		cout << "\nNDenumire echipe: ";
		a.denumireEchipe = new string[a.nrEchipe];
		for (int i = 0; i < a.nrEchipe; i++)
		{
			cout << "\nDenumire echipa " << i + 1 << " : ";
			in.ignore();
			in >> a.denumireEchipe[i];
		}
		return in;
	}
	void afisare()
	{
		cout << "\n-------------";

		cout << "\nDenumire activitate: " << this->denumireActivitate;
		cout << "\nDurata activitate: " << this->durata;
		cout << "\nNumar echipe: " << this->nrEchipe;
		cout << "\nDenumire echipe: ";
		for (int i = 0; i < this->nrEchipe; i++)
			cout << "\nDenumire echipa " << i + 1 << " : " << this->denumireEchipe[i];

		cout << "\n-------------";
	}

	string& operator[](int index)
	{
		if (index > 0 && index < nrEchipe)
			return this->denumireEchipe[index];
	}

	Activitati& operator+(string echipaNoua)
	{
		Activitati a = *this;
		delete[] this->denumireEchipe;
		this->nrEchipe++;

		this->denumireEchipe = new string[this->nrEchipe];
		for (int i = 0; i < this->nrEchipe-1; i++)
		{
			this->denumireEchipe[i] = a.denumireEchipe[i];
		}
		this->denumireEchipe[this->nrEchipe - 1] = echipaNoua;

		return *this;
	}
	
	bool operator<(Activitati a)
	{
		return this->durata < a.durata;
	}

	// pre incrementare
	Activitati& operator++()
	{
		this->nrEchipe++;
		return *this;
	}

	// post incrementare 
	Activitati operator++(int)
	{
		Activitati copie = *this;
		this->nrEchipe++;
		return copie;
	}

	operator float()
	{
		return this->durata;
	}

	bool operator==(const Activitati& a)
	{
		bool ok = true;
		if (strcmp(this->denumireActivitate, a.denumireActivitate) != 0)
		{
			ok = false;
		}
		if (this->durata != a.durata)
		{
			ok = false;
		}
		if (this->nrEchipe != a.nrEchipe)
		{
			ok = false;
		}
		else
		{
			for (int i = 0; i < this->nrEchipe; i++)
			{
				if (this->denumireEchipe[i] != a.denumireEchipe[i])
					ok = false;
			}
		}
		return ok;
	}

	bool operator !=(const Activitati& a)
	{
		return !((*this) == a);
	} 

	~Activitati()
	{
		cout << "\nApel destructor !";
		delete[] this->denumireActivitate;
		delete[] this->denumireEchipe;
	}
};

class Sponsori {

private:
	const int numarContract;
	float suma=0;
	int nrSponsori=0;
	string* numeSponsori=NULL;
	int* sumaSponsor=NULL;
public:

	Sponsori(int numarContract) :numarContract(numarContract)
	{
		cout << "\nApel constructor cu 1 parametru !";
	}
	Sponsori(int numarContract, float suma, int nrSponsori, string* numeSponsori, int* sumaSponsor) :numarContract(numarContract)
	{
		cout << "\nApel constructor cu toti parametri !";

		this->suma = suma;
		if (nrSponsori > 0 && numeSponsori != NULL && sumaSponsor!=NULL)
		{
			this->nrSponsori = nrSponsori;
			this->numeSponsori = new string[this->nrSponsori];
			this->sumaSponsor = new int[this->nrSponsori];
			for (int i = 0; i < this->nrSponsori; i++)
			{
				this->numeSponsori[i] = numeSponsori[i];
				this->sumaSponsor[i] = sumaSponsor[i];
			}
		}
	}
	Sponsori(const Sponsori& s) : numarContract(s.numarContract)
	{
		cout << "\nApel constructor de copiere !";

		this->suma = s.suma;
		this->nrSponsori = s.nrSponsori;
		this->numeSponsori = new string[this->nrSponsori];
		this->sumaSponsor = new int[this->nrSponsori];
		for (int i = 0; i < this->nrSponsori; i++)
		{
			this->numeSponsori[i] = s.numeSponsori[i];
			this->sumaSponsor[i] = s.sumaSponsor[i];
		}
	}
	Sponsori& operator=(const Sponsori& s)
	{
		cout << "\nApel operator egal !";
		if (this != &s)
		{
			delete[] this->numeSponsori;

			this->suma = s.suma;
			if (s.nrSponsori > 0 && s.numeSponsori != NULL)
			{
				this->nrSponsori = s.nrSponsori;
				this->numeSponsori = new string[this->nrSponsori];
				this->sumaSponsor = new int[this->nrSponsori];
				for (int i = 0; i < this->nrSponsori; i++)
				{
					this->numeSponsori[i] = s.numeSponsori[i];
					this->sumaSponsor[i] = s.sumaSponsor[i];
				}
			}
		}
		return *this;
	}
	void afisare()
	{
		cout << "\n-------------";

		cout << "\nNumar contract: " << this->numarContract;
		cout << "\nSuma: " << this->suma;
		cout << "\nNumar sponsori: " << this->nrSponsori;
		cout << "\nDenumire sponsori: ";
		for (int i = 0; i < this->nrSponsori; i++)
			cout << "\nNume sponsor " << i + 1 << " : " << this->numeSponsori[i];
		cout << "\nSume sponsori: ";
		for (int i = 0; i < this->nrSponsori; i++)
			cout << "\nSuma sponsor " << i + 1 << " : " << this->sumaSponsor[i];
		cout << "\n-------------";
	}

	float getSuma()
	{
		return this->suma;
	}
	void setSuma(float suma)
	{
		if (suma > 0)
			this->suma = suma;
	}
	int getNrsponsori()
	{
		return this->nrSponsori;
	}
	void setNrSponsori(int nrSponsori)
	{
		if (nrSponsori > 0)
			this->nrSponsori = nrSponsori;
	}
	string* getNumeSponsori()
	{
		return this->numeSponsori;
	}
	void setNumeSponsori(string* numeSponsori)
	{
		if (numeSponsori->length() > 1)
		{
			this->numeSponsori = numeSponsori;
		}
	}
	int* getSumaSponsor()
	{
		return this->sumaSponsor;
	}
	void setSumaSponsor(int* sumaSponsor)
	{
		if (suma > 0)
			this->suma = suma;
	}

	bool operator==(const Sponsori& s)
	{
		bool ok = true;

		if (this->numarContract != s.numarContract)
		{
			ok = false;
		}

		if (this->suma != s.suma)
		{
			ok = false;
		}

		if (this->nrSponsori != s.nrSponsori)
		{
			ok = false;
		}
		else
		{
			for (int i = 0; i < s.nrSponsori; i++)
			{
				if (this->numeSponsori[i] != s.numeSponsori[i])
				{
					ok = false;
				}
			}
			for (int i = 0; i < s.nrSponsori; i++)
			{
				if (this->sumaSponsor[i] != s.sumaSponsor[i])
				{
					ok = false;
				}
			}
		}

		return ok;
	}
	float medieSumaSponsor()
	{
		float medie = 0;
		if (this->nrSponsori != 0)
		{
			for (int i = 0; i < this->nrSponsori; i++)
				medie += this->sumaSponsor[i];
		}
		medie /= this->nrSponsori;
		return medie;
	}
	operator float ()
	{
		return this->suma;
	}

	bool operator !=(const Sponsori& s)
	{
		return !((*this) == s);
	}

	bool operator<=(Sponsori s)
	{
		return this->nrSponsori <= s.nrSponsori;
	}

	int& operator[](int index)
	{
		if (index > 0 && index < nrSponsori)
			return this->sumaSponsor[index];
	}

	Sponsori& operator+(string sponsorNou)
	{
		Sponsori s = *this;
		delete[] this->numeSponsori;
		this->nrSponsori++;

		this->numeSponsori = new string[this->nrSponsori];
		for (int i = 0; i < this->nrSponsori - 1; i++)
		{
			this->numeSponsori[i] = s.numeSponsori[i];
		}
		this->numeSponsori[this->nrSponsori - 1] = sponsorNou;
		this->sumaSponsor[this->nrSponsori - 1] = 0;

		return *this;
	}
	
	friend ostream& operator<<(ostream& out, Sponsori s)
	{
		out << "\n*************";
		out << "\nNumar contract: " << s.numarContract;
		out << "\nSuma totala: " << s.suma;
		out << "\nNumar sponsori: " << s.nrSponsori;
		cout << "\nDenumire sponsori: ";
		for (int i = 0; i < s.nrSponsori; i++)
			out << "\nDenumire sponsor " << i + 1 << " : " << s.numeSponsori[i];
		for (int i = 0; i < s.nrSponsori; i++)
			out << "\nSuma sponsor " << i + 1 << " : " << s.sumaSponsor[i];
		out << "\n*************";

		return out;
	}
	friend istream& operator>>(istream& in, Sponsori& s)
	{

		delete[] s.numeSponsori;
		delete[] s.sumaSponsor;

		cout << "\nSuma: ";
		in >> s.suma;
		cout << "\nNumar sponsori: ";
		in >> s.nrSponsori;
		cout << "\nDenumire sponsor: ";
		s.numeSponsori = new string[s.nrSponsori];
		for (int i = 0; i < s.nrSponsori; i++)
		{
			cout << "\nDenumire sponsor" << i + 1 << " : ";
			in.ignore();
			in >> s.numeSponsori[i];
		}
		s.sumaSponsor = new int[s.nrSponsori];
		for (int i = 0; i < s.nrSponsori; i++)
		{
			cout << "\nsuma sponsor" << i + 1 << " : ";
			in.ignore();
			in >> s.sumaSponsor[i];
		}
		return in;
	}
	~Sponsori()
	{
		cout << "\nApel destructor !";
		delete[] this->numeSponsori;
	}
};

class Transport {

private:
	char* mijlocTransport=NULL;
	float pretBilet=0;
	float durata=0;
	int nrSoferi = 0;
	string* numeSoferi = NULL;
public:

	Transport(const char* mijlocTransport)
	{
		cout << "\nApel constructor cu 1 parametru !";

		this->mijlocTransport = new char[strlen(mijlocTransport) + 1];
		strcpy(this->mijlocTransport, mijlocTransport);
	}
	Transport(const char* mijlocTransport, float pretBilet, float durata, int nrSoferi, string* numeSoferi)
	{
		cout << "\nApel constructor cu toti parametri !";
		
		if (strlen(mijlocTransport) > 1)
		{
			this->mijlocTransport = new char[strlen(mijlocTransport) + 1];
			strcpy(this->mijlocTransport, mijlocTransport);
		}
		this->pretBilet = pretBilet;
		this->durata = durata;
		if (nrSoferi > 0 && numeSoferi != NULL)
		{
			this->nrSoferi = nrSoferi;
			this->numeSoferi = new string[this->nrSoferi];
			for (int i = 0; i < this->nrSoferi; i++)
			{
				this->numeSoferi[i] = numeSoferi[i];
			}
			
		}
	}
	Transport(const Transport& t)
	{
		cout << "\nApel constructor de copiere !";

		if (strlen(t.mijlocTransport) > 1)
		{
			this->mijlocTransport = new char[strlen(t.mijlocTransport) + 1];
			strcpy(this->mijlocTransport, t.mijlocTransport);
		}
		this->pretBilet = t.pretBilet;
		this->durata = t.durata;
		if (t.nrSoferi > 0 && t.numeSoferi != NULL)
		{
			this->nrSoferi = t.nrSoferi;
			this->numeSoferi = new string[this->nrSoferi];
			for (int i = 0; i < this->nrSoferi; i++)
			{
				this->numeSoferi[i] = t.numeSoferi[i];
			}
		}
	}
	Transport& operator=(const Transport& t)
	{
		cout << "\nApel operatoe egal !";

		if (this != &t)
		{
			delete[] numeSoferi;
			delete[] mijlocTransport;

			if (strlen(t.mijlocTransport) > 1)
			{
				this->mijlocTransport = new char[strlen(t.mijlocTransport) + 1];
				strcpy(this->mijlocTransport, t.mijlocTransport);
			}
			this->pretBilet = t.pretBilet;
			this->durata = t.durata;
			if (t.nrSoferi > 0 && t.numeSoferi != NULL)
			{
				this->nrSoferi = t.nrSoferi;
				this->numeSoferi = new string[this->nrSoferi];
				for (int i = 0; i < this->nrSoferi; i++)
				{
					this->numeSoferi[i] = t.numeSoferi[i];
				}
			}
		}
	}

	char* getMijlocTransport()
	{
		return this->mijlocTransport;
	}
	void setMijlocTransport(const char* mijlocTransport)
	{
		if (strlen(mijlocTransport) > 1)
		{
			delete[] this->mijlocTransport;
			this->mijlocTransport = new char[strlen(mijlocTransport) + 1];
			strcpy(this->mijlocTransport, mijlocTransport);
		}
	}
	float getPretBilet()
	{
		return this->pretBilet;
	}
	void setPretBilet(float pretBilet)
	{
		if (pretBilet > 0)
			this->pretBilet = pretBilet;
	}
	float getDurata()
	{
		return this->durata;
	}
	void setDurata(float durata)
	{
		if (durata > 0)
			this->durata = durata;
	}
	int getNrSoferi()
	{
		return this->nrSoferi;
	}
	void setNrSoferi(int nrSoferi)
	{
		if (nrSoferi > 0)
			this->nrSoferi = nrSoferi;
	}
	string* getNumeSoferi()
	{
		return this->numeSoferi;
	}
	void setNumeSoferi(string* numeSoferi)
	{
		if (numeSoferi->length() > 1)
		{
			delete[] this->numeSoferi;
			this->numeSoferi = new string[this->nrSoferi];
			for (int i = 0; i < this->nrSoferi; i++)
				this->numeSoferi[i] = numeSoferi[i];
		}
	}
	string& operator[](int index)
	{
		if (index > 0 && index < nrSoferi)
			return this->numeSoferi[index];
	}

	bool operator==(const Transport& t)
	{
		bool ok = true;

		if (strcmp(this->mijlocTransport, t.mijlocTransport) != 0)
		{
			ok = false;
		}
		if (this->pretBilet!=t.pretBilet)
		{
			ok = false;
		}
		if (this->durata != t.durata)
		{
			ok = false;
		}
		if (this->nrSoferi != t.nrSoferi)
		{
			ok = false;
		}
		else
		{
			for (int i = 0; i < this->nrSoferi; i++)
			{
				if (this->numeSoferi[i] != t.numeSoferi[i])
					ok = false;
			}
		}
		return ok;
	}

	bool operator !=(const Transport& t)
	{
		return !((*this) == t);
	}

	bool operator>(Transport t)
	{
		return this-> pretBilet> t.pretBilet;
	}

	Transport& operator+=(string soferNou)
	{
		Transport t = *this;
		delete[] this->numeSoferi;
		this->nrSoferi++;

		this->numeSoferi = new string[this->nrSoferi];
		for (int i = 0; i < this->nrSoferi-1; i++)
		{
			this->numeSoferi[i] = t.numeSoferi[i];
		}
		this->numeSoferi[this->nrSoferi - 1] = soferNou;

		return *this;
	}
	void afisare()
	{
		cout << "\n-------------";

		cout << "\nMijloc de transport: " << this->mijlocTransport;
		cout << "\nPret bilet: " << this->pretBilet;
		cout << "\nDurata calatorie: " << this->durata;
		cout << "\nNumar soferi: "<<this->nrSoferi;
		cout << "\nNume soferi: ";
		for (int i = 0; i < this->nrSoferi; i++)
			cout << "\nNume sofer " << i + 1 << " : " << this->numeSoferi[i];
		cout << "\n-------------";
	}

	friend ostream& operator<<(ostream& out, Transport t)
	{
		out << "\n*************";
		out << "\nMijloc de transport: " << t.mijlocTransport;
		out << "\nSuma bilet: " << t.pretBilet;
		out << "\nDurata: " << t.durata;
		out << "\nNumar soferi: " << t.nrSoferi;
		cout << "\nnume soferi: ";
		for (int i = 0; i < t.nrSoferi; i++)
			out << "\nNume sofer " << i + 1 << " : " << t.numeSoferi[i];
		out << "\n*************";

		return out;
	}
	friend istream& operator>>(istream& in, Transport& t)
	{

		delete[] t.mijlocTransport;
		delete[] t.numeSoferi;

		cout << "\nMijloc de transport: ";
		char buffer[200];
		in >> buffer;
		t.mijlocTransport = new char[strlen(buffer) + 1];
		strcpy(t.mijlocTransport, buffer);
		in >> t.mijlocTransport;

		cout << "\nPret bilet: ";
		in >> t.pretBilet;
		cout << "\nDurata: ";
		in >> t.durata;
		cout << "\nNumar soferi: ";
		in >> t.nrSoferi;
		cout << "\nNume soferi: ";
		t.numeSoferi = new string[t.nrSoferi];
		for (int i = 0; i < t.nrSoferi; i++)
		{
			cout << "\nNume sofer " << i + 1 << " : ";
			in.ignore();
			in >> t.numeSoferi[i];
		}
		return in;
	}
	// pre incrementare
	Transport& operator++()
	{
		this->nrSoferi++;
		return *this;
	}

	// post incrementare 
	Transport operator++(int)
	{
		Transport copie = *this;
		this->nrSoferi++;
		return copie;
	}
	operator float()
	{
		return this->durata;
	}
	~Transport()
	{
		cout << "\nApel destructor !";
		delete[] mijlocTransport;
		delete[] numeSoferi;
	}
};

class Echipa {

private:
	char* numeLider=NULL;
	string denumireDepartament="Necunoscut";
	int nrPersoane=0;
	int nrJocuriJucate=0;
	int* puncteObtinute=NULL;
public:

	Echipa(const char* numeLider)
	{
		cout << "\nApel constructor fara paramtri !";
		this->numeLider = new char[strlen(numeLider) + 1];
		strcpy(this->numeLider, numeLider);
	}
	Echipa(const char* numeLider, string denumireDepartament, int nrPersoane, int nrJocuriJucate, int* puncteObtinute)
	{
		cout << "\nApel constructor cu toti parametru !";

		if (strlen(numeLider) > 1)
		{
			this->numeLider = new char[strlen(numeLider) + 1];
			strcpy(this->numeLider, numeLider);
		}
		if (denumireDepartament.length() > 1)
		{
			this->denumireDepartament = denumireDepartament;
		}
		if (nrPersoane > 0)
		{
			this->nrPersoane = nrPersoane;
			if (nrJocuriJucate > 0 && puncteObtinute != NULL)
			{
				this->nrJocuriJucate = nrJocuriJucate;
				this->puncteObtinute = new int[this->nrJocuriJucate];
				for (int i = 0; i < this->nrJocuriJucate; i++)
				{
					this->puncteObtinute[i] = puncteObtinute[i];
				}
			}
		}
	}
	Echipa(const Echipa& e)
	{
		cout << "\nApel constructor de copiere !";

		if (strlen(e.numeLider) > 1)
		{
			this->numeLider = new char[strlen(e.numeLider) + 1];
			strcpy(this->numeLider, e.numeLider);
		}
		if (e.denumireDepartament.length() > 1)
		{
			this->denumireDepartament = e.denumireDepartament;
		}
		if (e.nrPersoane > 0)
		{
			this->nrPersoane = e.nrPersoane;
			if (e.nrJocuriJucate > 0 && e.puncteObtinute != NULL)
			{
				this->nrJocuriJucate = e.nrJocuriJucate;
				this->puncteObtinute = new int[this->nrJocuriJucate];
				for (int i = 0; i < this->nrJocuriJucate; i++)
				{
					this->puncteObtinute[i] = e.puncteObtinute[i];
				}
			}
		}
	}
	Echipa& operator=(const Echipa& e)
	{
		cout << "\nApel operator = !";
		if (this != &e)
		{
			delete[] this->numeLider;
			delete[] puncteObtinute;

			if (strlen(e.numeLider) > 1)
			{
				this->numeLider = new char[strlen(e.numeLider) + 1];
				strcpy(this->numeLider, e.numeLider);
			}
			if (e.denumireDepartament.length() > 1)
			{
				this->denumireDepartament = e.denumireDepartament;
			}
			if (e.nrPersoane > 0)
			{
				this->nrPersoane = e.nrPersoane;
				if (e.nrJocuriJucate > 0 && e.puncteObtinute != NULL)
				{
					this->nrJocuriJucate = e.nrJocuriJucate;
					this->puncteObtinute = new int[this->nrJocuriJucate];
					for (int i = 0; i < this->nrJocuriJucate; i++)
					{
						this->puncteObtinute[i] = e.puncteObtinute[i];
					}
				}
			}
		}
		return *this;
	}
	char* getNumeLider()
	{
		return this->numeLider;
	}
	void setNumeLider(const char* numeLider)
	{
		if (strlen(numeLider) > 1)
		{
			delete[] this->numeLider;
			this->numeLider = new char[strlen(numeLider) + 1];
			strcpy(this->numeLider, numeLider);
		}
	}
	string getDenumireDepartament()
	{
		return this->denumireDepartament;
	}
	void setDenumireDepartament(string denumireDepartament)
	{
		if (denumireDepartament.length() > 1)
			this->denumireDepartament = denumireDepartament;
	}
	int getNrPersoane()
	{
		return this->nrPersoane;
	}
	void setNrPersoane(int nrPersoane)
	{
		if (nrPersoane > 0)
			this->nrPersoane = nrPersoane;
	}
	int getNrJocuriJucate()
	{
		return this->nrJocuriJucate;
	}
	void setNrJocuriJucate(int nrJocuriJucate)
	{
		if (nrJocuriJucate > 0)
			this->nrJocuriJucate = nrJocuriJucate;
	}
	int* getPuncteObtinute()
	{
		return this->puncteObtinute;
	}
	void setPuncteObtinute(int* puncteObtinute)
	{
		if (puncteObtinute != NULL)
		{
			delete[] this->puncteObtinute;
			this->puncteObtinute = new int[this->nrJocuriJucate];
			for (int i = 0; i < this->nrJocuriJucate; i++)
				this->puncteObtinute[i] = puncteObtinute[i];
		}
	}
	int& operator[](int index)
	{
		if (index > 0 && index < nrJocuriJucate)
			return this->puncteObtinute[index];
	}

	bool operator==(const Echipa& e)
	{
		bool ok = true;
		if (strcmp(this->numeLider, e.numeLider) != 0)
		{
			ok = false;
		}
		if (this->denumireDepartament != e.denumireDepartament)
		{
			ok = false;
		}
		if (this->nrPersoane != e.nrPersoane)
		{
			ok = false;
		}
		if (this->nrJocuriJucate != e.nrJocuriJucate)
		{
			ok = false;
		}
		for (int i = 0; i < this->nrJocuriJucate; i++)
		{
			if (this->puncteObtinute[i] != e.puncteObtinute[i])
			{
				ok = false;
			}
		}
		return ok;
	}

	bool operator !=(const Echipa& e)
	{
		return !((*this) == e);
	}

	bool operator>(Echipa e)
	{
		return this->nrJocuriJucate > e.nrJocuriJucate;
	}

	// pre incrementare
	Echipa& operator++()
	{
		this->nrPersoane++;
		return *this;
	}

	// post incrementare 
	Echipa operator++(int)
	{
		Echipa copie = *this;
		this->nrPersoane++;
		return copie;
	}

	Echipa& operator+=(int puncteJocNou)
	{
		cout << "\nOperator+=";
		Echipa e = *this;

		delete[] this->puncteObtinute;
		this->nrJocuriJucate++;

		this->puncteObtinute = new int[this->nrJocuriJucate];
		for (int i = 0; i < this->nrJocuriJucate; i++)
			this->puncteObtinute[i] = e.puncteObtinute[i];
		this->puncteObtinute[this->nrJocuriJucate - 1] = puncteJocNou;

		return *this;
	}

	float sumaPuncteTotale()
	{
		float sumPuncte=0;
		if (this->nrJocuriJucate > 0)
		{
			for (int i = 0; i < this->nrJocuriJucate; i++)
			{
				sumPuncte += this->puncteObtinute[i];
			}
		}
		return sumPuncte;
	}
	void afisare()
	{
		cout << "\n-------------";

		cout << "\nNume lider: " << this->numeLider;
		cout << "\nDenumire departament: " << this->denumireDepartament;
		cout << "\nNumar persoane : " << this->nrPersoane;
		cout << "\nNumar jocuri jucate : " << this->nrJocuriJucate;
		cout << "\nPuncte obtinute: ";
		for (int i = 0; i < this->nrJocuriJucate; i++)
			cout << "\npuncte obtinute la jocul " << i + 1 << " : " << this->puncteObtinute[i];
		cout << "\n-------------";
	}

	friend ostream& operator<<(ostream& out, Echipa e)
	{
		out << "\n*************";
		out << "\nNume lider: " << e.numeLider;
		out << "\nDenumireDepartament: " << e.denumireDepartament;
		out << "\nNumar persoane: " << e.nrPersoane;
		out << "\nNumar jocuri jucate: " << e.nrJocuriJucate;
		cout << "\nPuncte obtinute: ";
		for (int i = 0; i < e.nrJocuriJucate; i++)
			out << "\nPuncte obtinute la jocul " << i + 1 << " : " << e.puncteObtinute[i];
		out << "\n*************";

		return out;
	}
	friend istream& operator>>(istream& in, Echipa& e)
	{

		delete[] e.numeLider;
		delete[] e.puncteObtinute;

		cout << "\nNume lider: ";
		char buffer[200];
		in >> buffer;
		e.numeLider = new char[strlen(buffer) + 1];
		strcpy(e.numeLider, buffer);
		in >> e.numeLider;

		cout << "\nDenumire departament: ";
		in >> e.denumireDepartament;
		cout << "\nNumar persoane: ";
		in >> e.nrPersoane;
		cout << "\nNumar jocuri jucate: ";
		in >> e.nrJocuriJucate;
		cout << "\nPuncte obtinute: ";
		e.puncteObtinute = new int[e.nrJocuriJucate];
		for (int i = 0; i < e.nrJocuriJucate; i++)
		{
			cout << "\nPuncte obtinute " << i + 1 << " : ";
			in.ignore();
			in >> e.puncteObtinute[i];
		}
		return in;
	}

	~Echipa()
	{
		cout << "\nApel destructor !";
		delete[] numeLider;
		delete[] puncteObtinute;
	}
};
int main()
{
	//CAZARE
	//const fara parametri
	Cazare c1("Necunoscut");
	c1.afisare();

	//const cu toti parametri
	float preturiCamere[4] = { 490.5, 500,610.3,330 };
	Cazare c2("Brasov", "Belvedere", 34567.8, 4, preturiCamere);
	c2.afisare();

	//constructor de Copiere
	Cazare c3(c2);
	c3.afisare();

	//metode de tip accesor
	for (int i = 0; i < c3.getNrCamere(); i++)
	{
		cout << "\n" << c3.getPreturiCamere()[i] << " ";
	}
	cout << "\n" << c3.getDenumireCazare();
	cout << "\n" << Cazare::getPretMinimCamera();

	c3.setDenumireCazare("Sinaia");
	cout << "\n" << c3.getDenumireCazare();

	float preturi2[] = { 220,310,480,760.6 };
	c2.setPreturiCamere(preturi2);
	c2.afisare();

	//supraincarcarea >> /  <<
	cout << c2;
	cin >> c3;

	//operator de indexare
	cout << "\n Pret camera 3: " << c3[2];

	//operator conditional;
	if (c2 > c3)
		cout << "\nExcursia c2 este mai scumpa !";
	else
		cout << "\nExcursia c3 este mai scumpa !";

	//operator +;
	c3 =c3 + (float)340;
	c3.afisare();

	//++;
	c2 = c3++;
	c2.afisare();

	//operator ==
	if (c2 == c3)  cout << "\nCazarile sunt la fel !";
	else cout << "\nCazarile sunt diferite !";

	//operator negatie
	if (c2 != c3) cout << "\nSunt diferite";
	else  cout << "\nSunt la fel";

	

	//ACTIVITATI
	//const cu 1 parametru
	Activitati a1("Necunoscut");
	a1.afisare();

	//const cu toti parametri
	string denumireEchipa[] = { "Sportivii", "Fluturii muzicali", "Albinele"};
	Activitati a2("Cuvintele", 2.30, 3, denumireEchipa);
	a2.afisare();

	//operator egal
	Activitati a3=a2;
	a3.afisare();

	// supraincarcarea >> && <<
	cout << a2;
	cin >> a3;

	//metode accesor
	cout << "\n" << a2.getDenumireActivitate()<<"\n"<<a2.getDurata()<<"\n";
	for (int i = 0; i < a2.getNrEchipe(); i++)
	{
		cout <<"Echipa "<<i+1<<": "<<a2.getDenumireEchipe()[i] << "\n";
	}
	a2.setDenumireActivitate("Memorie");
	cout << "\n" << a2.getDenumireActivitate();
	a2.setDurata(3.5);
	cout << "\n" << a2;

	//operator de indexare
	cout << "\nDenumirea echipei 2 este :" << a2[1];

	//operator +
	 a2=a2 + (string)"Zurli";
	 cout <<"\nOperator +"<< a2;

	 // operator <
	 if (a2 < a3)
		 cout << "\nDurata jocului din activitatea 2 este mai mica !";
	 else
		 cout << "\nDurata jocului din activitatea 3 este mai mica !";

	 //operator ==
	 if (a2 == a3)
		 cout << "\nCele doua activitati sunt la fel!";
	 else
		 cout << "\nCele doua activitati sunt diferite !";

	// operator !=
	 if (a2 != a3) cout << "\nSunt diferite";
	 else  cout << "\nSunt la fel !";
	 
	

	//CLASA SPONSORI

	//apel const 1 parametru
	Sponsori s1(123);
	s1.afisare();

	//apel const cu toti parametri
	string nume5[] = { "emag","lidl","glovo" };
	int sume[] = { 1500,3500,15000 };
	Sponsori s2(301, 20000, 3, nume5,sume);
	s2.afisare();
	
	//operator egal
	Sponsori s3(s2);
	s3.afisare();
	
	//supraincarcarea << si >>
	cout << s3;
	cin >> s3;

	//metode accesor
	for (int i = 0; i < s3.getNrsponsori(); i++)
	{
		cout << "\n" << s3.getNumeSponsori()[i];
	}

	s3.setSuma(90000);
	cout << s3;

	//operator ==
	if (s2 == s3) cout << "\nSunt la fel !";
	else cout << "\nSunt diferite !";

	//operator !=
	if(s2!=s3) cout << "\nSumele sunt diferite !";
	else cout << "\nSumele sunt egale !";

	//operator conditional <=
	if (s2 <= s3) cout << "\nS3 are mai multi sponsori !";
	else cout << "\nS2 are mai multi sponsoro !";

	//operator de indexare
	cout << "\nSuma acordata de sponsorul 2 este : " << s2[1];

	//functie medie
	cout << "\nMedia sumelor primite de catre sponsori :" << s3.medieSumaSponsor();

	//operator +;

	s2=s2 + (string)"Amazon";
	cout << s2;

	float test = s2;
	cout << test;

	//TRANSPORT

	//apel const cu 1 para
	Transport t1("Necunoscut");
	t1.afisare();

	//apel const cu toti parametri
	string nume[] = { "Mihai","Aurel","Costel" };
	Transport t2("Autocar", 120, 2.3, 3, nume);
	t2.afisare();

	//opertor =
	Transport t3(t2);
	t3.afisare();

	//supraincarcarea >> && <<
	cout << t3;
	cin >> t3;

	//operator de indexare
	//cout << "\nAl 3 lea sofer este: " << t3[2];

	//metode de tip accesor
	cout <<"\n"<< t3.getMijlocTransport();
	for (int i = 0; i <t3.getNrSoferi(); i++)
	{
		cout << "\n" << t3.getNumeSoferi()[i];
	}

	t3.setMijlocTransport("Tren");
	string num[] = { "Marcel","Dorel","Cristi" };
	t3.setNumeSoferi(num);
	cout << t3;

	//operator ==
	if (t2 == t3) cout << "\nAu acelasi numar de soferi !";
	else cout << "\nNu au acelasi nume de soferi !";

	//operator !=
	if (t3 != t2) cout << "\nSunt diferite !";
	else cout << "\nSunt la fel !";

	//operator conditional >=
	if (t3 > t2) cout << "\nPretul unui bilet t3 este mai mare !";
	else cout << "\nPretul biletului t2 este mai mare !";

	//operator +=
	t2 += (string)"Vlad";
	cout << t2;


	//ECHIPA
	//const cu 1 parametru
	Echipa e1("Necunoscut");
	e1.afisare();

	//const cu toti parametri
	int puncte[] = {70,40,93,37,55};
	Echipa e2("Popescu Andrei", "IT", 10, 5, puncte);
	e2.afisare();

	//operator =
	Echipa e3 = e2;
	e3.afisare();

	int puncte1[] = { 100,23,89,46 };
	Echipa e4("Bucur David", "Marketing", 12, 4, puncte1);
	e4.afisare();

	//supraincarcarea >> && <<
	cout << e4;
	//cin >> e3;

	//operator de indexare
	cout << "\nPunctele obtinute de e4 la jocul al 3 lea: " << e4[2];

	//operator == 
	if (e3 == e4)
		cout << "\nSunt la fel!";
	else
		cout << "\nSunt diferite !";

	//metode de tip accesor
	cout << "\nNumele lider echipa 3: " << e3.getNumeLider();

	int puncteNoi[] = { 45,99,78,89,65 };
	e3.setPuncteObtinute(puncteNoi);
	cout << e3;

	//operator +=

	e3 += 89.0;
	e3.afisare();

	//functie suma puncte totale

	cout<<"\nSuma punctelor obtinute la toate jocurile: "<<e3.sumaPuncteTotale();
	
    
	return 0;
}