#pragma once
#include<cmath>
#include<vector>
#include<fstream>
#include<iostream>
#include <locale.h>



#define PI 3.14159265358979323846
using namespace std;
using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::Runtime::InteropServices;

ifstream fin;
ofstream fout;

bool intersection(int Xstart1, int Ystart1, int Xend1, int Yend1, int Xstart2, int Ystart2, int Xend2, int Yend2)
{
	int Xdir1 = Xend1 - Xstart1;
	int Ydir1 = Yend1 - Ystart1;
	int Xdir2 = Xend2 - Xstart2;
	int Ydir2 = Yend2 - Ystart2;

	//считаем уравнения прямых проходящих через отрезки
	float a1 = -Ydir1;
	float b1 = +Xdir1;
	float d1 = -(a1*Xstart1 + b1*Ystart1);

	float a2 = -Ydir2;
	float b2 = +Xdir2;
	float d2 = -(a2*Xstart2 + b2*Ystart2);

	//подставляем концы отрезков, для выяснения в каких полуплоскотях они
	float seg1_line2_start = a2*Xstart1 + b2*Ystart1 + d2;
	float seg1_line2_end = a2*Xend1 + b2*Yend1 + d2;

	float seg2_line1_start = a1*Xstart2 + b1*Ystart2 + d1;
	float seg2_line1_end = a1*Xend2 + b1*Yend2 + d1;

	//если концы одного отрезка имеют один знак, значит он в одной полуплоскости и пересечения нет.
	if (seg1_line2_start * seg1_line2_end >= 0 || seg2_line1_start * seg2_line1_end >= 0)
		return false;
	return true;
}

double rast(int x1, int y1, int x2, int y2)
{
	return sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));
}

char * and_SysStringToChar(System::String^ string)
{
	return (char*)(void*)Marshal::StringToHGlobalAnsi(string);
}

class Gear
{
	vector<Gear*> v;
	string name;
public:
	
	int x, y, kol,n;
	float angle, u,r;
	bool canmove;
	bool spin;
	Gear()
	{
		name = "gear";
		n = 0;
		x = 0;
		y = 0;
		r = 0;
		spin = true;
		angle = 0;
		kol = 0;
		u = 0;
		canmove = true;
	}
	Gear(int X, int Y,int N)
	{
		name = "gear";
		n = N;
		x = X;
		y = Y;
		r = (10 * n) / (2 * PI);
		spin = true;
		angle = 0;
		kol = 0;
		u = 0;
		canmove = true;
	}
	string GetName()
	{
		return name;
	}
	void Connect(Gear* g,int m=0)
	{
		for (int i = 0; i < kol; i++)
			if (v[i] == g) return;
		kol++;
		v.push_back(g);
		canmove = false;
		if (m == 0)
		{
			int t = atan2((y - g->y), (x - g->x)) / PI * 180;
			int mod = t - g->angle;
			mod = mod % g->n;
			angle = 180 + t + ((360 - g->angle) / (2 * g->n) - mod);
			g->Connect(this, 1);
		}
	}
	void UnConnect(int i=0,Gear* G=NULL)
	{
		v.clear();
		kol = 0;
	}
	void Clear()
	{
		kol = 0;
		v.clear();
	}
	Gear* GetI(int i)
	{
		return v[i];
	}
	void GoConnect(float U)
	{
		u = U;
		for (int i = 0; i < kol; i++)
		{
			if (u*v[i]->u>0) spin = false;
			else if(v[i]->u==0)
				{
					v[i]->GoConnect((n*-1 * U)*1.0 / v[i]->n);
				}
		}
	}
	void Draw(Color c, Graphics^ GR)
	{
		Pen^ myPen = gcnew Pen(c, 4);
		Brush^ B = gcnew SolidBrush(c);
		int R = r;
		GR->FillEllipse(B, x - r, y - r, r * 2, r * 2);
		R = r+8;
		float X1, Y1;
		float A = angle;
		for (int i = 0; i < n; i++)
		{
			X1 = x + R*cos(A*(PI / 180));
			Y1 = y + R*sin(A*(PI / 180));
			GR->DrawLine(myPen, (float)x, (float)y, X1, Y1);
			A = A + 360*1.0 / n;
		}
		delete myPen;
	}
	void Save()
	{
		fout << x << " " << y << " " << angle << " " << n << endl;
	}
	void Load()
	{
		fin >> x>> y >> angle >>n;
		r = (10 * n) / (2 * PI);
		spin = true;
		kol = 0;
		u = 0;
	}
};

class Gears
{
	vector<Gear*> g;
	int k,selected;
	int d1,d2;
public:
	Gears()
	{
		k = 0;
		selected = 0;
		d1 = 6;
		d2 = 11;
	}
	void Add(int X, int Y,int N)
	{
		k++;
		Gear* G = new Gear(X, Y,N);
		g.push_back(G);
		int I = k - 1;
		for (int i = 0; i < k-1; i++)
		{
				double S = rast(g[I]->x, g[I]->y , g[i]->x, g[i]->y);
				if (S < (g[I]->r + g[i]->r + d1))
				{
					Deletei(I);
					return;
				}
				if (S < (g[I]->r + g[i]->r + d2))
				{
					g[I]->Connect(g[i]);
				}
		}
		Move(k - 1, 0, 0, 1000, 1000);
	}
	void Move(int I,int X,int Y,int W,int H)
	{
		int r = g[I]->r+8;
		if((g[I]->canmove)&&(k>0)&& ((g[I]->x+X - r>0) && (g[I]->x +X+ r<W) && (g[I]->y+Y - r>0) && (g[I]->y+Y + r<H)))
		{
			for (int i = 0; i < k; i++)
			{
				if (I != i)
				{
					double S = rast(g[I]->x+X, g[I]->y+Y, g[i]->x, g[i]->y);
					if (S < (g[I]->r + g[i]->r + d2))
					{
						g[I]->x += X;
						g[I]->y += Y;
						g[I]->Connect(g[i]);
					}
				}
			}
			g[I]->x += X;
			g[I]->y += Y;
		}
	}
	void Connect(int I,int U)
	{
		for (int i = 0; i < k; i++) g[i]->spin = true;
		for (int i = 0; i < k; i++) g[i]->u = 0;
		g[I]->GoConnect(U);
	}
	void Go()
	{
		bool b = true;
		for (int i = 0; i < k; i++)
		{
			if (g[i]->spin == false)
			{
				b = false;
				break;
			}
		}
		if (b)
		{
			for (int i = 0; i < k; i++)
			{
				g[i]->angle = g[i]->angle + g[i]->u;
				if (g[i]->angle > 360) g[i]->angle -= 360;
			}
		}
	}
	void Draw(Color c, Graphics^ GR)
	{
		for (int i = 0; i < k; i++)
		{
			if (i == selected)
				g[i]->Draw(Color::Blue, GR);
			else g[i]->Draw(c, GR);
		}
	}
	int Getk()
	{
		return k;
	}
	Gear* Geti(int i)
	{
		return g[i];
	}
	void SetSelected(int i)
	{
		selected = i;
	}
	void Deletei(int i)
	{
		Gear *G = g[i];
		g.erase(g.begin() + i);
		k--;
		delete G;
		for (int i = 0; i < k; i++) g[i]->UnConnect();
		for (int i = 0; i < k; i++)
			for (int j = 0; j < k; j++)
				if (i != j)
				{
					double S = rast(g[j]->x, g[j]->y, g[i]->x, g[i]->y);
					if (S < (g[j]->r + g[i]->r + d2))
					{
						g[j]->Connect(g[i]);
					}
				}
	}
	void DeleteAll()
	{
		for (int i = 0; i < k; i++)
		{
			delete g[i];
		}
		g.clear();
		k = 0;
	}
	void Save(string  file)
	{
		fout.open(file, ios_base::out);
		fout << k << endl;
		for (int j = 0; j < k; j++)
		{
			g[j]->Save();
		}
		fout.close();
	}
	void Load(string  file)
	{
		DeleteAll();
		fin.open(file, ios_base::in);
		fin >> k;
		for (int i = 0; i < k; i++)
		{
			Gear* tmp;
			tmp = new Gear();
			tmp->Load();
			g.push_back(tmp);
			for (int j = 0; j < i; j++)
			{
				double S = rast(g[i]->x, g[i]->y, g[j]->x, g[j]->y);
				if (S < (g[j]->r + g[i]->r + d2))
				{
					g[i]->Connect(g[j]);
				}
			}
		}

		fin.close();
	}
};

