#pragma once
#include<cmath>
#include"Classes.h"
#include <sstream>
#define PI 3.14159265358979323846

namespace РГР {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		Gears* G=new Gears();
		Color def = Color::Black;
		Color ch = Color::Red;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Button^  button4;

	public:
		int R = 10;
	private: System::Windows::Forms::Button^  button5;
	public:
	private: System::Windows::Forms::Button^  button6;
	private: System::Windows::Forms::Timer^  timer1;
	private: System::Windows::Forms::TreeView^  treeView1;

			 int k = 1;
	private: System::Windows::Forms::Button^  button8;
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  файлToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  открытьToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  открытьToolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^  сохранитьToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  выходToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  справкаToolStripMenuItem;
	private: System::Windows::Forms::NumericUpDown^  numericUpDown2;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::ToolStripMenuItem^  оПрограммеToolStripMenuItem;

			 int si = 0;
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			DoubleBuffered = true;
			timer1->Enabled = false;
			timer1->Interval = 20;
		}
		Bitmap^ myBitmap;
		Graphics^ gr;
	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::NumericUpDown^  numericUpDown1;
	private: System::ComponentModel::IContainer^  components;
	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->numericUpDown1 = (gcnew System::Windows::Forms::NumericUpDown());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->treeView1 = (gcnew System::Windows::Forms::TreeView());
			this->button8 = (gcnew System::Windows::Forms::Button());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->файлToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->открытьToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->открытьToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->сохранитьToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->выходToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->справкаToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->оПрограммеToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->numericUpDown2 = (gcnew System::Windows::Forms::NumericUpDown());
			this->label2 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->BeginInit();
			this->menuStrip1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown2))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pictureBox1->Location = System::Drawing::Point(12, 27);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(596, 371);
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Click += gcnew System::EventHandler(this, &MyForm::pictureBox1_Click);
			this->pictureBox1->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::pictureBox1_MouseClick);
			// 
			// numericUpDown1
			// 
			this->numericUpDown1->Location = System::Drawing::Point(724, 44);
			this->numericUpDown1->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 6, 0, 0, 0 });
			this->numericUpDown1->Name = L"numericUpDown1";
			this->numericUpDown1->Size = System::Drawing::Size(42, 20);
			this->numericUpDown1->TabIndex = 1;
			this->numericUpDown1->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10, 0, 0, 0 });
			this->numericUpDown1->ValueChanged += gcnew System::EventHandler(this, &MyForm::numericUpDown1_ValueChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(614, 51);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(104, 13);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Количество зубьев";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(739, 129);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(26, 23);
			this->button1->TabIndex = 3;
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(706, 157);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(27, 23);
			this->button2->TabIndex = 4;
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(738, 157);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(27, 23);
			this->button3->TabIndex = 5;
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(771, 157);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(26, 23);
			this->button4->TabIndex = 6;
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &MyForm::button4_Click);
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(614, 158);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(75, 23);
			this->button5->TabIndex = 8;
			this->button5->Text = L"Пуск";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &MyForm::button5_Click);
			// 
			// button6
			// 
			this->button6->Location = System::Drawing::Point(614, 188);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(75, 23);
			this->button6->TabIndex = 9;
			this->button6->Text = L"Стоп";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &MyForm::button6_Click);
			// 
			// timer1
			// 
			this->timer1->Interval = 50;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// treeView1
			// 
			this->treeView1->Location = System::Drawing::Point(614, 216);
			this->treeView1->Name = L"treeView1";
			this->treeView1->Size = System::Drawing::Size(104, 182);
			this->treeView1->TabIndex = 10;
			this->treeView1->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::treeView1_KeyDown);
			this->treeView1->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::treeView1_MouseDown);
			// 
			// button8
			// 
			this->button8->Location = System::Drawing::Point(614, 129);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(75, 23);
			this->button8->TabIndex = 12;
			this->button8->Text = L"Удалить";
			this->button8->UseVisualStyleBackColor = true;
			this->button8->Click += gcnew System::EventHandler(this, &MyForm::button8_Click);
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->файлToolStripMenuItem,
					this->справкаToolStripMenuItem, this->оПрограммеToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(809, 24);
			this->menuStrip1->TabIndex = 13;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// файлToolStripMenuItem
			// 
			this->файлToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->открытьToolStripMenuItem,
					this->открытьToolStripMenuItem1, this->сохранитьToolStripMenuItem, this->выходToolStripMenuItem
			});
			this->файлToolStripMenuItem->Name = L"файлToolStripMenuItem";
			this->файлToolStripMenuItem->Size = System::Drawing::Size(48, 20);
			this->файлToolStripMenuItem->Text = L"Файл";
			// 
			// открытьToolStripMenuItem
			// 
			this->открытьToolStripMenuItem->Name = L"открытьToolStripMenuItem";
			this->открытьToolStripMenuItem->Size = System::Drawing::Size(132, 22);
			this->открытьToolStripMenuItem->Text = L"Очистить";
			this->открытьToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::открытьToolStripMenuItem_Click);
			// 
			// открытьToolStripMenuItem1
			// 
			this->открытьToolStripMenuItem1->Name = L"открытьToolStripMenuItem1";
			this->открытьToolStripMenuItem1->Size = System::Drawing::Size(132, 22);
			this->открытьToolStripMenuItem1->Text = L"Открыть";
			this->открытьToolStripMenuItem1->Click += gcnew System::EventHandler(this, &MyForm::открытьToolStripMenuItem1_Click);
			// 
			// сохранитьToolStripMenuItem
			// 
			this->сохранитьToolStripMenuItem->Name = L"сохранитьToolStripMenuItem";
			this->сохранитьToolStripMenuItem->Size = System::Drawing::Size(132, 22);
			this->сохранитьToolStripMenuItem->Text = L"Сохранить";
			this->сохранитьToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::сохранитьToolStripMenuItem_Click);
			// 
			// выходToolStripMenuItem
			// 
			this->выходToolStripMenuItem->Name = L"выходToolStripMenuItem";
			this->выходToolStripMenuItem->Size = System::Drawing::Size(132, 22);
			this->выходToolStripMenuItem->Text = L"Выход";
			this->выходToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::выходToolStripMenuItem_Click);
			// 
			// справкаToolStripMenuItem
			// 
			this->справкаToolStripMenuItem->Name = L"справкаToolStripMenuItem";
			this->справкаToolStripMenuItem->Size = System::Drawing::Size(65, 20);
			this->справкаToolStripMenuItem->Text = L"Справка";
			this->справкаToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::справкаToolStripMenuItem_Click);
			// 
			// оПрограммеToolStripMenuItem
			// 
			this->оПрограммеToolStripMenuItem->Name = L"оПрограммеToolStripMenuItem";
			this->оПрограммеToolStripMenuItem->Size = System::Drawing::Size(94, 20);
			this->оПрограммеToolStripMenuItem->Text = L"О программе";
			this->оПрограммеToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::оПрограммеToolStripMenuItem_Click);
			// 
			// numericUpDown2
			// 
			this->numericUpDown2->Location = System::Drawing::Point(725, 75);
			this->numericUpDown2->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 5, 0, 0, 0 });
			this->numericUpDown2->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->numericUpDown2->Name = L"numericUpDown2";
			this->numericUpDown2->Size = System::Drawing::Size(40, 20);
			this->numericUpDown2->TabIndex = 14;
			this->numericUpDown2->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 2, 0, 0, 0 });
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(614, 77);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(55, 13);
			this->label2->TabIndex = 15;
			this->label2->Text = L"Скорость";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(809, 422);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->numericUpDown2);
			this->Controls->Add(this->button8);
			this->Controls->Add(this->treeView1);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->numericUpDown1);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"MyForm";
			this->Text = L"Редактор шестеренок";
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyDown);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->EndInit();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown2))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		Bitmap^ myB;
		void Paint()
		{
			myBitmap = gcnew Bitmap(pictureBox1->Width, pictureBox1->Height);
			gr = Graphics::FromImage(myBitmap);
			gr->SmoothingMode = Drawing2D::SmoothingMode::HighQuality;
			G->Draw(def, gr);
			pictureBox1->Image = myBitmap;
			if(timer1->Enabled==false)refresh();
		}
		void refresh()
		{
			treeView1->Nodes->Clear();
			TreeNode^ node = treeView1->Nodes->Add("Gears");
			if (G->Getk() > 0)
				for (int i = 0; i < G->Getk(); i++)
				{
					string str = G->Geti(i)->GetName();
					node->Nodes->Add(%String(str.c_str())), G->Geti(i);
				}
			treeView1->ExpandAll();
		}
	private: System::Void pictureBox1_Click(System::Object^  sender, System::EventArgs^  e) {
		
	}
			 void DrawGear(int X,int Y, int Rad,float A,float n,Color c)
			 {
				 float a =X;
				 float b = Y;
				 float r = Rad;
				 Pen^ myPen = gcnew Pen(c, 4);
				 Brush^ B = gcnew SolidBrush(c);
				 gr->FillEllipse(B, a - r, b - r, r * 2, r * 2);
				 r += 8;
				 float X1, Y1;
				 float angle = A;
				 for (int i = 0; i < n;i++)
				 {
					 X1 = a + r*cos(angle*(PI / 180));
					 Y1 = b + r*sin(angle*(PI / 180));
					 gr->DrawLine(myPen, a, b, X1, Y1);
					 angle = angle + 360 / n;
				 }
				 delete myPen;
			 }
	private: System::Void pictureBox1_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
		int x = e->X;
		int y = e->Y;
		int r= (10 * R) / (2 * PI)+8;
		if((x-r>0)&&(x+r<pictureBox1->Width)&& (y - r>0) && (y + r<pictureBox1->Height))
			G->Add(x, y, R);
		Paint();
	}
	private: System::Void numericUpDown1_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
		R = (int)numericUpDown1->Value;
	}
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {

	G->Move(si, 0, -1, pictureBox1->Width, pictureBox1->Height);
	Paint();
}
private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
	G->Move(si, 0,1, pictureBox1->Width, pictureBox1->Height);
	Paint();
}
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
	G->Move(si, -1, 0, pictureBox1->Width, pictureBox1->Height);
	Paint();
}
private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {
	G->Move(si, 1, 0, pictureBox1->Width, pictureBox1->Height);
	Paint();
}
private: System::Void listBox1_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
	Paint();
}
private: System::Void button5_Click(System::Object^  sender, System::EventArgs^  e) {
	timer1->Enabled = true;
}
private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
	G->Connect(si, (int)numericUpDown2->Value);
	G->Go();
	Paint();
}

private: System::Void treeView1_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	TreeNode^ node;
	if (treeView1->GetNodeAt(e->X, e->Y))
	{
		node = treeView1->GetNodeAt(e->X, e->Y);
		si = node->Index;
		G->SetSelected(si);
	}
	
	Paint();
}
private: System::Void button6_Click(System::Object^  sender, System::EventArgs^  e) {
	timer1->Enabled = false;
}
private: System::Void button7_Click(System::Object^  sender, System::EventArgs^  e) {
	
}
private: System::Void button8_Click(System::Object^  sender, System::EventArgs^  e) {
	G->Deletei(si);
	Paint();
}
private: System::Void открытьToolStripMenuItem1_Click(System::Object^  sender, System::EventArgs^  e) {
	OpenFileDialog  ^openFileDialog1 = gcnew OpenFileDialog();
	openFileDialog1->Filter = "txt files(*.txt) | *.txt";
	if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
	{
		if (openFileDialog1->FileName != "") {
			string file = and_SysStringToChar(openFileDialog1->FileName);
			G->Load(file);
		}
	}
	Paint();

}
private: System::Void сохранитьToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	SaveFileDialog ^ saveFileDialog1 = gcnew SaveFileDialog();
	saveFileDialog1->Filter = "txt files(*.txt) | *.txt";
	if (saveFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
	{
		if (saveFileDialog1->FileName != "") {
			string file = and_SysStringToChar(saveFileDialog1->FileName);
			G->Save(file);
		}
	}
}
private: System::Void открытьToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	G->DeleteAll();
	Paint();
}
private: System::Void выходToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	this->Close();
}
private: System::Void справкаToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	MessageBox::Show("Шестеренки помещаются на рабочую область с помощью клика мышки. Параметры создания размещены справа. Шестеренки выделются кликом по дереву. Выделенную шестеренку можно двигать с помощью кнопок или цифр 2,4,6,8 NumPad, предварительно выбрав нужную шестеренку на дереве.");
}
private: System::Void оПрограммеToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	MessageBox::Show("Редактор шестеренок. Программу выполнил студент группы ПРО-211: Елисеев М.А. \n 2016");
}
private: System::Void MyForm_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
	
}
private: System::Void treeView1_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
	if (e->KeyCode == Keys::NumPad4)  button2_Click(button2, e);
	if (e->KeyCode == Keys::NumPad6)  button4_Click(button4, e);
	if (e->KeyCode == Keys::NumPad8)  button1_Click(button1, e);
	if (e->KeyCode == Keys::NumPad2)  button3_Click(button3, e);
}
};
}
