#pragma once
#include "piece.h"

int GetMoX(System::EventArgs^  e);
int GetMoY(System::EventArgs^  e);

// 1 - white 2 - black

int turn;

int take_color;

bool take;

int take_num;

std::string Promotions[4];

int PawnBeingPromoted;

int ChosenPromotion;

int PawnBeingPromotedColor;

bool GameEnd;

bool check;

bool paused;

void MoveBishop(System::Windows::Forms::PictureBox^ Bishop, int GetMoX, int GetMoY, ChessPiece& bishop, int color);

void MovePawn(System::Windows::Forms::PictureBox^ Pawn, int GetMoX, int GetMoY, ChessPiece& pawn, int color, int number, System::Windows::Forms::PictureBox^ C_Queen, System::Windows::Forms::PictureBox^ C_Bishop, System::Windows::Forms::PictureBox^ C_Knight, System::Windows::Forms::PictureBox^ C_Rook);

void MoveKnight(System::Windows::Forms::PictureBox^ Knight, int GetMoX, int GetMoY, ChessPiece& knight, int color);

void MoveQueen(System::Windows::Forms::PictureBox^ Queen, int GetMoX, int GetMoY, ChessPiece& queen, int color);

void MoveRook(System::Windows::Forms::PictureBox^ Rook, int GetMoX, int GetMoY, ChessPiece& rook, int color);

void MoveKing(System::Windows::Forms::PictureBox^ King, int GetMoX, int GetMoy, ChessPiece& king, int color);

int CheckKing(ChessPiece& king, int color);

void ChangeTurn();

int CheckIfItsPosibleToMove(int x, int y, int color);

int CheckIfPosibleToKill(int x, int y, int disx, int disy, int color, int num);

ChessPiece W_knight1(490, 570);

ChessPiece W_knight2(90, 570);

ChessPiece W_bishop1(170, 570);

ChessPiece W_bishop2(410, 570);

ChessPiece W_pawn1(10, 490);

ChessPiece W_pawn2(90, 490);

ChessPiece W_pawn3(170, 490);

ChessPiece W_pawn4(250, 490);

ChessPiece W_pawn5(330, 490);

ChessPiece W_pawn6(410, 490);

ChessPiece W_pawn7(490, 490);

ChessPiece W_pawn8(570, 490);

ChessPiece W_queen(330, 570);

ChessPiece W_rook1(570, 570);

ChessPiece W_rook2(10, 570);

ChessPiece W_king(250, 570);

ChessPiece B_knight1(90, 10);

ChessPiece B_knight2(490, 10);

ChessPiece B_bishop1(170, 10);

ChessPiece B_bishop2(410, 10);

ChessPiece B_king(250, 10);

ChessPiece B_queen(330, 10);

ChessPiece B_rook1(10, 10);

ChessPiece B_rook2(570, 10);

ChessPiece B_pawn1(10, 90);

ChessPiece B_pawn2(90, 90);

ChessPiece B_pawn3(170, 90);

ChessPiece B_pawn4(250, 90);

ChessPiece B_pawn5(330, 90);

ChessPiece B_pawn6(410, 90);

ChessPiece B_pawn7(490, 90);

ChessPiece B_pawn8(570, 90);

ChessPiece* White[16] = { &W_pawn1, &W_pawn2, &W_pawn3, &W_pawn4, &W_pawn5, &W_pawn6, &W_pawn7, &W_pawn8, &W_bishop1, &W_bishop2, &W_rook1, &W_rook2, &W_king, &W_queen, &W_knight1, &W_knight2 };

ChessPiece* Black[16] = { &B_pawn1, &B_pawn2, &B_pawn3, &B_pawn4, &B_pawn5, &B_pawn6, &B_pawn7, &B_pawn8, &B_bishop1, &B_bishop2, &B_rook1, &B_rook2, &B_king, &B_queen, &B_knight1, &B_knight2 };

namespace Project2 {

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
		MyForm(void)
		{
			InitializeComponent();
			W_pawn1.type = "pawn";
			W_pawn2.type = "pawn";
			W_pawn3.type = "pawn";
			W_pawn4.type = "pawn";
			W_pawn5.type = "pawn";
			W_pawn6.type = "pawn";
			W_pawn7.type = "pawn";
			W_pawn8.type = "pawn";
			/////////////////////////
			B_pawn1.type = "pawn";
			B_pawn2.type = "pawn";
			B_pawn3.type = "pawn";
			B_pawn4.type = "pawn";
			B_pawn5.type = "pawn";
			B_pawn6.type = "pawn";
			B_pawn7.type = "pawn";
			B_pawn8.type = "pawn";
			//
			//TODO: Add the constructor code here
			//
		}

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

	protected:





	private: System::Windows::Forms::PictureBox^  W_Pawn_1;
	private: System::Windows::Forms::PictureBox^  W_Bishop_1;
	private: System::Windows::Forms::PictureBox^  W_Knight_1;
	private: System::Windows::Forms::PictureBox^  W_Queen;
	private: System::Windows::Forms::PictureBox^  W_Rook_1;
	private: System::Windows::Forms::PictureBox^  W_King;
	private: System::Windows::Forms::PictureBox^  W_Bishop_2;
	private: System::Windows::Forms::PictureBox^  W_Knight_2;
	private: System::Windows::Forms::PictureBox^  W_Rook_2;
	private: System::Windows::Forms::PictureBox^  W_Pawn_2;
	private: System::Windows::Forms::PictureBox^  W_Pawn_3;
	private: System::Windows::Forms::PictureBox^  W_Pawn_6;
	private: System::Windows::Forms::PictureBox^  W_Pawn_8;
	private: System::Windows::Forms::PictureBox^  W_Pawn_5;
	private: System::Windows::Forms::PictureBox^  W_Pawn_4;
	private: System::Windows::Forms::PictureBox^  W_Pawn_7;
	private: System::Windows::Forms::PictureBox^  B_Rook_1;
	private: System::Windows::Forms::PictureBox^  B_Knight_1;
	private: System::Windows::Forms::PictureBox^  B_Bishop_1;
	private: System::Windows::Forms::PictureBox^  B_King;
	private: System::Windows::Forms::PictureBox^  B_Queen;
	private: System::Windows::Forms::PictureBox^  B_Bishop_2;
	private: System::Windows::Forms::PictureBox^  B_Knight_2;
	private: System::Windows::Forms::PictureBox^  B_Rook_2;
	private: System::Windows::Forms::PictureBox^  B_Pawn_1;
	private: System::Windows::Forms::PictureBox^  B_Pawn_2;
	private: System::Windows::Forms::PictureBox^  B_Pawn_3;
	private: System::Windows::Forms::PictureBox^  B_Pawn_4;
	private: System::Windows::Forms::PictureBox^  B_Pawn_5;
	private: System::Windows::Forms::PictureBox^  B_Pawn_6;
	private: System::Windows::Forms::PictureBox^  B_Pawn_7;
	private: System::Windows::Forms::PictureBox^  B_Pawn_8;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::PictureBox^  C_Queen;
	private: System::Windows::Forms::PictureBox^  C_Bishop;
	private: System::Windows::Forms::PictureBox^  C_Knight;
	private: System::Windows::Forms::PictureBox^  C_Rook;











	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->W_Pawn_1 = (gcnew System::Windows::Forms::PictureBox());
			this->W_Bishop_1 = (gcnew System::Windows::Forms::PictureBox());
			this->W_Knight_1 = (gcnew System::Windows::Forms::PictureBox());
			this->W_Queen = (gcnew System::Windows::Forms::PictureBox());
			this->W_Rook_1 = (gcnew System::Windows::Forms::PictureBox());
			this->W_King = (gcnew System::Windows::Forms::PictureBox());
			this->W_Bishop_2 = (gcnew System::Windows::Forms::PictureBox());
			this->W_Knight_2 = (gcnew System::Windows::Forms::PictureBox());
			this->W_Rook_2 = (gcnew System::Windows::Forms::PictureBox());
			this->W_Pawn_2 = (gcnew System::Windows::Forms::PictureBox());
			this->W_Pawn_3 = (gcnew System::Windows::Forms::PictureBox());
			this->W_Pawn_6 = (gcnew System::Windows::Forms::PictureBox());
			this->W_Pawn_8 = (gcnew System::Windows::Forms::PictureBox());
			this->W_Pawn_5 = (gcnew System::Windows::Forms::PictureBox());
			this->W_Pawn_4 = (gcnew System::Windows::Forms::PictureBox());
			this->W_Pawn_7 = (gcnew System::Windows::Forms::PictureBox());
			this->B_Rook_1 = (gcnew System::Windows::Forms::PictureBox());
			this->B_Knight_1 = (gcnew System::Windows::Forms::PictureBox());
			this->B_Bishop_1 = (gcnew System::Windows::Forms::PictureBox());
			this->B_King = (gcnew System::Windows::Forms::PictureBox());
			this->B_Queen = (gcnew System::Windows::Forms::PictureBox());
			this->B_Bishop_2 = (gcnew System::Windows::Forms::PictureBox());
			this->B_Knight_2 = (gcnew System::Windows::Forms::PictureBox());
			this->B_Rook_2 = (gcnew System::Windows::Forms::PictureBox());
			this->B_Pawn_1 = (gcnew System::Windows::Forms::PictureBox());
			this->B_Pawn_2 = (gcnew System::Windows::Forms::PictureBox());
			this->B_Pawn_3 = (gcnew System::Windows::Forms::PictureBox());
			this->B_Pawn_4 = (gcnew System::Windows::Forms::PictureBox());
			this->B_Pawn_5 = (gcnew System::Windows::Forms::PictureBox());
			this->B_Pawn_6 = (gcnew System::Windows::Forms::PictureBox());
			this->B_Pawn_7 = (gcnew System::Windows::Forms::PictureBox());
			this->B_Pawn_8 = (gcnew System::Windows::Forms::PictureBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->C_Queen = (gcnew System::Windows::Forms::PictureBox());
			this->C_Bishop = (gcnew System::Windows::Forms::PictureBox());
			this->C_Knight = (gcnew System::Windows::Forms::PictureBox());
			this->C_Rook = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->W_Pawn_1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->W_Bishop_1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->W_Knight_1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->W_Queen))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->W_Rook_1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->W_King))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->W_Bishop_2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->W_Knight_2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->W_Rook_2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->W_Pawn_2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->W_Pawn_3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->W_Pawn_6))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->W_Pawn_8))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->W_Pawn_5))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->W_Pawn_4))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->W_Pawn_7))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->B_Rook_1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->B_Knight_1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->B_Bishop_1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->B_King))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->B_Queen))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->B_Bishop_2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->B_Knight_2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->B_Rook_2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->B_Pawn_1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->B_Pawn_2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->B_Pawn_3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->B_Pawn_4))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->B_Pawn_5))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->B_Pawn_6))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->B_Pawn_7))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->B_Pawn_8))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->C_Queen))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->C_Bishop))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->C_Knight))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->C_Rook))->BeginInit();
			this->SuspendLayout();
			// 
			// W_Pawn_1
			// 
			this->W_Pawn_1->BackColor = System::Drawing::Color::Transparent;
			this->W_Pawn_1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"W_Pawn_1.Image")));
			this->W_Pawn_1->Location = System::Drawing::Point(10, 490);
			this->W_Pawn_1->Name = L"W_Pawn_1";
			this->W_Pawn_1->Size = System::Drawing::Size(50, 50);
			this->W_Pawn_1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::CenterImage;
			this->W_Pawn_1->TabIndex = 5;
			this->W_Pawn_1->TabStop = false;
			this->W_Pawn_1->Click += gcnew System::EventHandler(this, &MyForm::pictureBox1_Click);
			// 
			// W_Bishop_1
			// 
			this->W_Bishop_1->BackColor = System::Drawing::Color::Transparent;
			this->W_Bishop_1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"W_Bishop_1.Image")));
			this->W_Bishop_1->Location = System::Drawing::Point(170, 570);
			this->W_Bishop_1->Name = L"W_Bishop_1";
			this->W_Bishop_1->Size = System::Drawing::Size(50, 50);
			this->W_Bishop_1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::CenterImage;
			this->W_Bishop_1->TabIndex = 6;
			this->W_Bishop_1->TabStop = false;
			this->W_Bishop_1->Click += gcnew System::EventHandler(this, &MyForm::W_Bishop_1_Click);
			// 
			// W_Knight_1
			// 
			this->W_Knight_1->BackColor = System::Drawing::Color::Transparent;
			this->W_Knight_1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"W_Knight_1.Image")));
			this->W_Knight_1->Location = System::Drawing::Point(490, 570);
			this->W_Knight_1->Name = L"W_Knight_1";
			this->W_Knight_1->Size = System::Drawing::Size(50, 50);
			this->W_Knight_1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::CenterImage;
			this->W_Knight_1->TabIndex = 7;
			this->W_Knight_1->TabStop = false;
			this->W_Knight_1->Click += gcnew System::EventHandler(this, &MyForm::W_Knight_1_Click);
			// 
			// W_Queen
			// 
			this->W_Queen->BackColor = System::Drawing::Color::Transparent;
			this->W_Queen->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"W_Queen.Image")));
			this->W_Queen->Location = System::Drawing::Point(330, 570);
			this->W_Queen->Name = L"W_Queen";
			this->W_Queen->Size = System::Drawing::Size(50, 50);
			this->W_Queen->SizeMode = System::Windows::Forms::PictureBoxSizeMode::CenterImage;
			this->W_Queen->TabIndex = 8;
			this->W_Queen->TabStop = false;
			this->W_Queen->Click += gcnew System::EventHandler(this, &MyForm::W_Queen_Click);
			// 
			// W_Rook_1
			// 
			this->W_Rook_1->BackColor = System::Drawing::Color::Transparent;
			this->W_Rook_1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"W_Rook_1.Image")));
			this->W_Rook_1->Location = System::Drawing::Point(570, 570);
			this->W_Rook_1->Name = L"W_Rook_1";
			this->W_Rook_1->Size = System::Drawing::Size(50, 50);
			this->W_Rook_1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::CenterImage;
			this->W_Rook_1->TabIndex = 9;
			this->W_Rook_1->TabStop = false;
			this->W_Rook_1->Click += gcnew System::EventHandler(this, &MyForm::W_Rook_1_Click);
			// 
			// W_King
			// 
			this->W_King->BackColor = System::Drawing::Color::Transparent;
			this->W_King->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"W_King.Image")));
			this->W_King->Location = System::Drawing::Point(250, 570);
			this->W_King->Name = L"W_King";
			this->W_King->Size = System::Drawing::Size(50, 50);
			this->W_King->SizeMode = System::Windows::Forms::PictureBoxSizeMode::CenterImage;
			this->W_King->TabIndex = 10;
			this->W_King->TabStop = false;
			this->W_King->Click += gcnew System::EventHandler(this, &MyForm::W_King_Click);
			// 
			// W_Bishop_2
			// 
			this->W_Bishop_2->BackColor = System::Drawing::Color::Transparent;
			this->W_Bishop_2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"W_Bishop_2.Image")));
			this->W_Bishop_2->Location = System::Drawing::Point(410, 570);
			this->W_Bishop_2->Name = L"W_Bishop_2";
			this->W_Bishop_2->Size = System::Drawing::Size(50, 50);
			this->W_Bishop_2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::CenterImage;
			this->W_Bishop_2->TabIndex = 11;
			this->W_Bishop_2->TabStop = false;
			this->W_Bishop_2->Click += gcnew System::EventHandler(this, &MyForm::W_Bishop_2_Click);
			// 
			// W_Knight_2
			// 
			this->W_Knight_2->BackColor = System::Drawing::Color::Transparent;
			this->W_Knight_2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"W_Knight_2.Image")));
			this->W_Knight_2->Location = System::Drawing::Point(90, 570);
			this->W_Knight_2->Name = L"W_Knight_2";
			this->W_Knight_2->Size = System::Drawing::Size(50, 50);
			this->W_Knight_2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::CenterImage;
			this->W_Knight_2->TabIndex = 12;
			this->W_Knight_2->TabStop = false;
			this->W_Knight_2->Click += gcnew System::EventHandler(this, &MyForm::W_Knight_2_Click);
			// 
			// W_Rook_2
			// 
			this->W_Rook_2->BackColor = System::Drawing::Color::Transparent;
			this->W_Rook_2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"W_Rook_2.Image")));
			this->W_Rook_2->Location = System::Drawing::Point(10, 570);
			this->W_Rook_2->Name = L"W_Rook_2";
			this->W_Rook_2->Size = System::Drawing::Size(50, 50);
			this->W_Rook_2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::CenterImage;
			this->W_Rook_2->TabIndex = 13;
			this->W_Rook_2->TabStop = false;
			this->W_Rook_2->Click += gcnew System::EventHandler(this, &MyForm::W_Rook_2_Click);
			// 
			// W_Pawn_2
			// 
			this->W_Pawn_2->BackColor = System::Drawing::Color::Transparent;
			this->W_Pawn_2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"W_Pawn_2.Image")));
			this->W_Pawn_2->Location = System::Drawing::Point(90, 490);
			this->W_Pawn_2->Name = L"W_Pawn_2";
			this->W_Pawn_2->Size = System::Drawing::Size(50, 50);
			this->W_Pawn_2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::CenterImage;
			this->W_Pawn_2->TabIndex = 14;
			this->W_Pawn_2->TabStop = false;
			this->W_Pawn_2->Click += gcnew System::EventHandler(this, &MyForm::W_Pawn_2_Click);
			// 
			// W_Pawn_3
			// 
			this->W_Pawn_3->BackColor = System::Drawing::Color::Transparent;
			this->W_Pawn_3->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"W_Pawn_3.Image")));
			this->W_Pawn_3->Location = System::Drawing::Point(170, 490);
			this->W_Pawn_3->Name = L"W_Pawn_3";
			this->W_Pawn_3->Size = System::Drawing::Size(50, 50);
			this->W_Pawn_3->SizeMode = System::Windows::Forms::PictureBoxSizeMode::CenterImage;
			this->W_Pawn_3->TabIndex = 15;
			this->W_Pawn_3->TabStop = false;
			this->W_Pawn_3->Click += gcnew System::EventHandler(this, &MyForm::W_Pawn_3_Click);
			// 
			// W_Pawn_6
			// 
			this->W_Pawn_6->BackColor = System::Drawing::Color::Transparent;
			this->W_Pawn_6->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"W_Pawn_6.Image")));
			this->W_Pawn_6->Location = System::Drawing::Point(410, 490);
			this->W_Pawn_6->Name = L"W_Pawn_6";
			this->W_Pawn_6->Size = System::Drawing::Size(50, 50);
			this->W_Pawn_6->SizeMode = System::Windows::Forms::PictureBoxSizeMode::CenterImage;
			this->W_Pawn_6->TabIndex = 16;
			this->W_Pawn_6->TabStop = false;
			this->W_Pawn_6->Click += gcnew System::EventHandler(this, &MyForm::W_Pawn_6_Click);
			// 
			// W_Pawn_8
			// 
			this->W_Pawn_8->BackColor = System::Drawing::Color::Transparent;
			this->W_Pawn_8->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"W_Pawn_8.Image")));
			this->W_Pawn_8->Location = System::Drawing::Point(570, 490);
			this->W_Pawn_8->Name = L"W_Pawn_8";
			this->W_Pawn_8->Size = System::Drawing::Size(50, 50);
			this->W_Pawn_8->SizeMode = System::Windows::Forms::PictureBoxSizeMode::CenterImage;
			this->W_Pawn_8->TabIndex = 17;
			this->W_Pawn_8->TabStop = false;
			this->W_Pawn_8->Click += gcnew System::EventHandler(this, &MyForm::W_Pawn_8_Click);
			// 
			// W_Pawn_5
			// 
			this->W_Pawn_5->BackColor = System::Drawing::Color::Transparent;
			this->W_Pawn_5->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"W_Pawn_5.Image")));
			this->W_Pawn_5->Location = System::Drawing::Point(330, 490);
			this->W_Pawn_5->Name = L"W_Pawn_5";
			this->W_Pawn_5->Size = System::Drawing::Size(50, 50);
			this->W_Pawn_5->SizeMode = System::Windows::Forms::PictureBoxSizeMode::CenterImage;
			this->W_Pawn_5->TabIndex = 18;
			this->W_Pawn_5->TabStop = false;
			this->W_Pawn_5->Click += gcnew System::EventHandler(this, &MyForm::W_Pawn_5_Click);
			// 
			// W_Pawn_4
			// 
			this->W_Pawn_4->BackColor = System::Drawing::Color::Transparent;
			this->W_Pawn_4->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"W_Pawn_4.Image")));
			this->W_Pawn_4->Location = System::Drawing::Point(250, 490);
			this->W_Pawn_4->Name = L"W_Pawn_4";
			this->W_Pawn_4->Size = System::Drawing::Size(50, 50);
			this->W_Pawn_4->SizeMode = System::Windows::Forms::PictureBoxSizeMode::CenterImage;
			this->W_Pawn_4->TabIndex = 19;
			this->W_Pawn_4->TabStop = false;
			this->W_Pawn_4->Click += gcnew System::EventHandler(this, &MyForm::W_Pawn_4_Click);
			// 
			// W_Pawn_7
			// 
			this->W_Pawn_7->BackColor = System::Drawing::Color::Transparent;
			this->W_Pawn_7->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"W_Pawn_7.Image")));
			this->W_Pawn_7->Location = System::Drawing::Point(490, 490);
			this->W_Pawn_7->Name = L"W_Pawn_7";
			this->W_Pawn_7->Size = System::Drawing::Size(50, 50);
			this->W_Pawn_7->SizeMode = System::Windows::Forms::PictureBoxSizeMode::CenterImage;
			this->W_Pawn_7->TabIndex = 20;
			this->W_Pawn_7->TabStop = false;
			this->W_Pawn_7->Click += gcnew System::EventHandler(this, &MyForm::W_Pawn_7_Click);
			// 
			// B_Rook_1
			// 
			this->B_Rook_1->BackColor = System::Drawing::Color::Transparent;
			this->B_Rook_1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"B_Rook_1.Image")));
			this->B_Rook_1->Location = System::Drawing::Point(10, 10);
			this->B_Rook_1->Name = L"B_Rook_1";
			this->B_Rook_1->Size = System::Drawing::Size(50, 50);
			this->B_Rook_1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::CenterImage;
			this->B_Rook_1->TabIndex = 21;
			this->B_Rook_1->TabStop = false;
			this->B_Rook_1->Click += gcnew System::EventHandler(this, &MyForm::B_Rook_1_Click);
			// 
			// B_Knight_1
			// 
			this->B_Knight_1->BackColor = System::Drawing::Color::Transparent;
			this->B_Knight_1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"B_Knight_1.Image")));
			this->B_Knight_1->Location = System::Drawing::Point(90, 10);
			this->B_Knight_1->Name = L"B_Knight_1";
			this->B_Knight_1->Size = System::Drawing::Size(50, 50);
			this->B_Knight_1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::CenterImage;
			this->B_Knight_1->TabIndex = 22;
			this->B_Knight_1->TabStop = false;
			this->B_Knight_1->Click += gcnew System::EventHandler(this, &MyForm::B_Knight_1_Click);
			// 
			// B_Bishop_1
			// 
			this->B_Bishop_1->BackColor = System::Drawing::Color::Transparent;
			this->B_Bishop_1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"B_Bishop_1.Image")));
			this->B_Bishop_1->Location = System::Drawing::Point(170, 10);
			this->B_Bishop_1->Name = L"B_Bishop_1";
			this->B_Bishop_1->Size = System::Drawing::Size(50, 50);
			this->B_Bishop_1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::CenterImage;
			this->B_Bishop_1->TabIndex = 23;
			this->B_Bishop_1->TabStop = false;
			this->B_Bishop_1->Click += gcnew System::EventHandler(this, &MyForm::B_Bishop_1_Click);
			// 
			// B_King
			// 
			this->B_King->BackColor = System::Drawing::Color::Transparent;
			this->B_King->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"B_King.Image")));
			this->B_King->Location = System::Drawing::Point(250, 10);
			this->B_King->Name = L"B_King";
			this->B_King->Size = System::Drawing::Size(50, 50);
			this->B_King->SizeMode = System::Windows::Forms::PictureBoxSizeMode::CenterImage;
			this->B_King->TabIndex = 24;
			this->B_King->TabStop = false;
			this->B_King->Click += gcnew System::EventHandler(this, &MyForm::B_King_Click);
			// 
			// B_Queen
			// 
			this->B_Queen->BackColor = System::Drawing::Color::Transparent;
			this->B_Queen->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"B_Queen.Image")));
			this->B_Queen->Location = System::Drawing::Point(330, 10);
			this->B_Queen->Name = L"B_Queen";
			this->B_Queen->Size = System::Drawing::Size(50, 50);
			this->B_Queen->SizeMode = System::Windows::Forms::PictureBoxSizeMode::CenterImage;
			this->B_Queen->TabIndex = 25;
			this->B_Queen->TabStop = false;
			this->B_Queen->Click += gcnew System::EventHandler(this, &MyForm::B_Queen_Click);
			// 
			// B_Bishop_2
			// 
			this->B_Bishop_2->BackColor = System::Drawing::Color::Transparent;
			this->B_Bishop_2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"B_Bishop_2.Image")));
			this->B_Bishop_2->Location = System::Drawing::Point(410, 10);
			this->B_Bishop_2->Name = L"B_Bishop_2";
			this->B_Bishop_2->Size = System::Drawing::Size(50, 50);
			this->B_Bishop_2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::CenterImage;
			this->B_Bishop_2->TabIndex = 26;
			this->B_Bishop_2->TabStop = false;
			this->B_Bishop_2->Click += gcnew System::EventHandler(this, &MyForm::B_Bishop_2_Click);
			// 
			// B_Knight_2
			// 
			this->B_Knight_2->BackColor = System::Drawing::Color::Transparent;
			this->B_Knight_2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"B_Knight_2.Image")));
			this->B_Knight_2->Location = System::Drawing::Point(490, 10);
			this->B_Knight_2->Name = L"B_Knight_2";
			this->B_Knight_2->Size = System::Drawing::Size(50, 50);
			this->B_Knight_2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::CenterImage;
			this->B_Knight_2->TabIndex = 27;
			this->B_Knight_2->TabStop = false;
			this->B_Knight_2->Click += gcnew System::EventHandler(this, &MyForm::B_Knight_2_Click);
			// 
			// B_Rook_2
			// 
			this->B_Rook_2->BackColor = System::Drawing::Color::Transparent;
			this->B_Rook_2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"B_Rook_2.Image")));
			this->B_Rook_2->Location = System::Drawing::Point(570, 10);
			this->B_Rook_2->Name = L"B_Rook_2";
			this->B_Rook_2->Size = System::Drawing::Size(50, 50);
			this->B_Rook_2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::CenterImage;
			this->B_Rook_2->TabIndex = 28;
			this->B_Rook_2->TabStop = false;
			this->B_Rook_2->Click += gcnew System::EventHandler(this, &MyForm::B_Rook_2_Click);
			// 
			// B_Pawn_1
			// 
			this->B_Pawn_1->BackColor = System::Drawing::Color::Transparent;
			this->B_Pawn_1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"B_Pawn_1.Image")));
			this->B_Pawn_1->Location = System::Drawing::Point(10, 90);
			this->B_Pawn_1->Name = L"B_Pawn_1";
			this->B_Pawn_1->Size = System::Drawing::Size(50, 50);
			this->B_Pawn_1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::CenterImage;
			this->B_Pawn_1->TabIndex = 29;
			this->B_Pawn_1->TabStop = false;
			this->B_Pawn_1->Click += gcnew System::EventHandler(this, &MyForm::B_Pawn_1_Click);
			// 
			// B_Pawn_2
			// 
			this->B_Pawn_2->BackColor = System::Drawing::Color::Transparent;
			this->B_Pawn_2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"B_Pawn_2.Image")));
			this->B_Pawn_2->Location = System::Drawing::Point(90, 90);
			this->B_Pawn_2->Name = L"B_Pawn_2";
			this->B_Pawn_2->Size = System::Drawing::Size(50, 50);
			this->B_Pawn_2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::CenterImage;
			this->B_Pawn_2->TabIndex = 30;
			this->B_Pawn_2->TabStop = false;
			this->B_Pawn_2->Click += gcnew System::EventHandler(this, &MyForm::B_Pawn_2_Click);
			// 
			// B_Pawn_3
			// 
			this->B_Pawn_3->BackColor = System::Drawing::Color::Transparent;
			this->B_Pawn_3->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"B_Pawn_3.Image")));
			this->B_Pawn_3->Location = System::Drawing::Point(170, 90);
			this->B_Pawn_3->Name = L"B_Pawn_3";
			this->B_Pawn_3->Size = System::Drawing::Size(50, 50);
			this->B_Pawn_3->SizeMode = System::Windows::Forms::PictureBoxSizeMode::CenterImage;
			this->B_Pawn_3->TabIndex = 31;
			this->B_Pawn_3->TabStop = false;
			this->B_Pawn_3->Click += gcnew System::EventHandler(this, &MyForm::B_Pawn_3_Click);
			// 
			// B_Pawn_4
			// 
			this->B_Pawn_4->BackColor = System::Drawing::Color::Transparent;
			this->B_Pawn_4->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"B_Pawn_4.Image")));
			this->B_Pawn_4->Location = System::Drawing::Point(250, 90);
			this->B_Pawn_4->Name = L"B_Pawn_4";
			this->B_Pawn_4->Size = System::Drawing::Size(50, 50);
			this->B_Pawn_4->SizeMode = System::Windows::Forms::PictureBoxSizeMode::CenterImage;
			this->B_Pawn_4->TabIndex = 32;
			this->B_Pawn_4->TabStop = false;
			this->B_Pawn_4->Click += gcnew System::EventHandler(this, &MyForm::B_Pawn_4_Click);
			// 
			// B_Pawn_5
			// 
			this->B_Pawn_5->BackColor = System::Drawing::Color::Transparent;
			this->B_Pawn_5->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"B_Pawn_5.Image")));
			this->B_Pawn_5->Location = System::Drawing::Point(330, 90);
			this->B_Pawn_5->Name = L"B_Pawn_5";
			this->B_Pawn_5->Size = System::Drawing::Size(50, 50);
			this->B_Pawn_5->SizeMode = System::Windows::Forms::PictureBoxSizeMode::CenterImage;
			this->B_Pawn_5->TabIndex = 33;
			this->B_Pawn_5->TabStop = false;
			this->B_Pawn_5->Click += gcnew System::EventHandler(this, &MyForm::B_Pawn_5_Click);
			// 
			// B_Pawn_6
			// 
			this->B_Pawn_6->BackColor = System::Drawing::Color::Transparent;
			this->B_Pawn_6->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"B_Pawn_6.Image")));
			this->B_Pawn_6->Location = System::Drawing::Point(410, 90);
			this->B_Pawn_6->Name = L"B_Pawn_6";
			this->B_Pawn_6->Size = System::Drawing::Size(50, 50);
			this->B_Pawn_6->SizeMode = System::Windows::Forms::PictureBoxSizeMode::CenterImage;
			this->B_Pawn_6->TabIndex = 34;
			this->B_Pawn_6->TabStop = false;
			this->B_Pawn_6->Click += gcnew System::EventHandler(this, &MyForm::B_Pawn_6_Click);
			// 
			// B_Pawn_7
			// 
			this->B_Pawn_7->BackColor = System::Drawing::Color::Transparent;
			this->B_Pawn_7->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"B_Pawn_7.Image")));
			this->B_Pawn_7->Location = System::Drawing::Point(490, 90);
			this->B_Pawn_7->Name = L"B_Pawn_7";
			this->B_Pawn_7->Size = System::Drawing::Size(50, 50);
			this->B_Pawn_7->SizeMode = System::Windows::Forms::PictureBoxSizeMode::CenterImage;
			this->B_Pawn_7->TabIndex = 35;
			this->B_Pawn_7->TabStop = false;
			this->B_Pawn_7->Click += gcnew System::EventHandler(this, &MyForm::B_Pawn_7_Click);
			// 
			// B_Pawn_8
			// 
			this->B_Pawn_8->BackColor = System::Drawing::Color::Transparent;
			this->B_Pawn_8->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"B_Pawn_8.Image")));
			this->B_Pawn_8->Location = System::Drawing::Point(570, 90);
			this->B_Pawn_8->Name = L"B_Pawn_8";
			this->B_Pawn_8->Size = System::Drawing::Size(50, 50);
			this->B_Pawn_8->SizeMode = System::Windows::Forms::PictureBoxSizeMode::CenterImage;
			this->B_Pawn_8->TabIndex = 36;
			this->B_Pawn_8->TabStop = false;
			this->B_Pawn_8->Click += gcnew System::EventHandler(this, &MyForm::B_Pawn_8_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 36, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::SystemColors::ControlText;
			this->label1->Location = System::Drawing::Point(1000, 1000);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(0, 55);
			this->label1->TabIndex = 37;
			// 
			// C_Queen
			// 
			this->C_Queen->BackColor = System::Drawing::Color::Transparent;
			this->C_Queen->Location = System::Drawing::Point(1000, 1000);
			this->C_Queen->Name = L"C_Queen";
			this->C_Queen->Size = System::Drawing::Size(50, 50);
			this->C_Queen->SizeMode = System::Windows::Forms::PictureBoxSizeMode::CenterImage;
			this->C_Queen->TabIndex = 38;
			this->C_Queen->TabStop = false;
			this->C_Queen->Click += gcnew System::EventHandler(this, &MyForm::C_Queen_Click);
			// 
			// C_Bishop
			// 
			this->C_Bishop->BackColor = System::Drawing::Color::Transparent;
			this->C_Bishop->Location = System::Drawing::Point(1000, 1000);
			this->C_Bishop->Name = L"C_Bishop";
			this->C_Bishop->Size = System::Drawing::Size(50, 50);
			this->C_Bishop->SizeMode = System::Windows::Forms::PictureBoxSizeMode::CenterImage;
			this->C_Bishop->TabIndex = 39;
			this->C_Bishop->TabStop = false;
			this->C_Bishop->Click += gcnew System::EventHandler(this, &MyForm::C_Bishop_Click);
			// 
			// C_Knight
			// 
			this->C_Knight->BackColor = System::Drawing::Color::Transparent;
			this->C_Knight->Location = System::Drawing::Point(1000, 1000);
			this->C_Knight->Name = L"C_Knight";
			this->C_Knight->Size = System::Drawing::Size(50, 50);
			this->C_Knight->SizeMode = System::Windows::Forms::PictureBoxSizeMode::CenterImage;
			this->C_Knight->TabIndex = 40;
			this->C_Knight->TabStop = false;
			this->C_Knight->Click += gcnew System::EventHandler(this, &MyForm::C_Knight_Click);
			// 
			// C_Rook
			// 
			this->C_Rook->BackColor = System::Drawing::Color::Transparent;
			this->C_Rook->Location = System::Drawing::Point(1000, 1000);
			this->C_Rook->Name = L"C_Rook";
			this->C_Rook->Size = System::Drawing::Size(50, 50);
			this->C_Rook->SizeMode = System::Windows::Forms::PictureBoxSizeMode::CenterImage;
			this->C_Rook->TabIndex = 41;
			this->C_Rook->TabStop = false;
			this->C_Rook->Click += gcnew System::EventHandler(this, &MyForm::pictureBox1_Click_1);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoValidate = System::Windows::Forms::AutoValidate::EnablePreventFocusChange;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(631, 632);
			this->Controls->Add(this->C_Rook);
			this->Controls->Add(this->C_Knight);
			this->Controls->Add(this->C_Bishop);
			this->Controls->Add(this->C_Queen);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->B_Pawn_8);
			this->Controls->Add(this->B_Pawn_7);
			this->Controls->Add(this->B_Pawn_6);
			this->Controls->Add(this->B_Pawn_5);
			this->Controls->Add(this->B_Pawn_4);
			this->Controls->Add(this->B_Pawn_3);
			this->Controls->Add(this->B_Pawn_2);
			this->Controls->Add(this->B_Pawn_1);
			this->Controls->Add(this->B_Rook_2);
			this->Controls->Add(this->B_Knight_2);
			this->Controls->Add(this->B_Bishop_2);
			this->Controls->Add(this->B_Queen);
			this->Controls->Add(this->B_King);
			this->Controls->Add(this->B_Bishop_1);
			this->Controls->Add(this->B_Knight_1);
			this->Controls->Add(this->B_Rook_1);
			this->Controls->Add(this->W_Pawn_7);
			this->Controls->Add(this->W_Pawn_4);
			this->Controls->Add(this->W_Pawn_5);
			this->Controls->Add(this->W_Pawn_8);
			this->Controls->Add(this->W_Pawn_6);
			this->Controls->Add(this->W_Pawn_3);
			this->Controls->Add(this->W_Pawn_2);
			this->Controls->Add(this->W_Rook_2);
			this->Controls->Add(this->W_Knight_2);
			this->Controls->Add(this->W_Bishop_2);
			this->Controls->Add(this->W_King);
			this->Controls->Add(this->W_Rook_1);
			this->Controls->Add(this->W_Queen);
			this->Controls->Add(this->W_Knight_1);
			this->Controls->Add(this->W_Bishop_1);
			this->Controls->Add(this->W_Pawn_1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Chess.kom";
			this->Click += gcnew System::EventHandler(this, &MyForm::MyForm_Click);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->W_Pawn_1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->W_Bishop_1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->W_Knight_1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->W_Queen))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->W_Rook_1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->W_King))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->W_Bishop_2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->W_Knight_2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->W_Rook_2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->W_Pawn_2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->W_Pawn_3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->W_Pawn_6))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->W_Pawn_8))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->W_Pawn_5))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->W_Pawn_4))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->W_Pawn_7))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->B_Rook_1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->B_Knight_1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->B_Bishop_1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->B_King))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->B_Queen))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->B_Bishop_2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->B_Knight_2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->B_Rook_2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->B_Pawn_1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->B_Pawn_2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->B_Pawn_3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->B_Pawn_4))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->B_Pawn_5))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->B_Pawn_6))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->B_Pawn_7))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->B_Pawn_8))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->C_Queen))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->C_Bishop))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->C_Knight))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->C_Rook))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}

#pragma endregion
	private: System::Void MyForm_Click(System::Object^  sender, System::EventArgs^  e) {

		MovePiece(GetMoX(e), GetMoY(e));

	}

	private: System::Void pictureBox1_Click(System::Object^  sender, System::EventArgs^  e) {
		Select(W_Pawn_1, W_pawn1, 1);
		if (turn == 2)
			MovePiece(W_pawn1.x, W_pawn1.y);
	}

	private: System::Void W_Bishop_1_Click(System::Object^  sender, System::EventArgs^  e) {
		Select(W_Bishop_1, W_bishop1, 1);
		if (turn == 2)
			MovePiece(W_bishop1.x, W_bishop1.y);
	}


	public: System::Void W_Knight_1_Click(System::Object^  sender, System::EventArgs^  e) {
		Select(W_Knight_1, W_knight1, 1);
		if (turn == 2)
			MovePiece(W_knight1.x, W_knight1.y);
	}

	private: System::Void W_Queen_Click(System::Object^  sender, System::EventArgs^  e) {
		Select(W_Queen, W_queen, 1);
		if (turn == 2)
			MovePiece(W_queen.x, W_queen.y);
	}

	private: System::Void W_Rook_1_Click(System::Object^  sender, System::EventArgs^  e) {
		Select(W_Rook_1, W_rook1, 1);
		if (turn == 2)
			MovePiece(W_rook1.x, W_rook1.y);
	}

	private: System::Void W_King_Click(System::Object^  sender, System::EventArgs^  e) {
		Select(W_King, W_king, 1);
		if (turn == 2)
			MovePiece(W_king.x, W_king.y);
	}

	private: System::Void W_Bishop_2_Click(System::Object^  sender, System::EventArgs^  e) {
		Select(W_Bishop_2, W_bishop2, 1);
		if (turn == 2)
			MovePiece(W_bishop2.x, W_bishop2.y);
	}

	private: System::Void W_Knight_2_Click(System::Object^  sender, System::EventArgs^  e) {
		Select(W_Knight_2, W_knight2, 1);
		if (turn == 2)
			MovePiece(W_knight2.x, W_knight2.y);
	}

	private: System::Void W_Rook_2_Click(System::Object^  sender, System::EventArgs^  e) {
		Select(W_Rook_2, W_rook2, 1);
		if (turn == 2)
			MovePiece(W_rook2.x, W_rook2.y);
	}

	private: System::Void W_Pawn_2_Click(System::Object^  sender, System::EventArgs^  e) {
		Select(W_Pawn_2, W_pawn2, 1);
		if (turn == 2)
			MovePiece(W_pawn2.x, W_pawn2.y);
	}

	private: System::Void W_Pawn_3_Click(System::Object^  sender, System::EventArgs^  e) {
		Select(W_Pawn_3, W_pawn3, 1);
		if (turn == 2)
			MovePiece(W_pawn3.x, W_pawn3.y);
	}

	private: System::Void W_Pawn_4_Click(System::Object^  sender, System::EventArgs^  e) {
		Select(W_Pawn_4, W_pawn4, 1);
		if (turn == 2)
			MovePiece(W_pawn4.x, W_pawn4.y);
	}

	private: System::Void W_Pawn_5_Click(System::Object^  sender, System::EventArgs^  e) {
		Select(W_Pawn_5, W_pawn5, 1);
		if (turn == 2)
			MovePiece(W_pawn5.x, W_pawn5.y);
	}

	private: System::Void W_Pawn_6_Click(System::Object^  sender, System::EventArgs^  e) {
		Select(W_Pawn_6, W_pawn6, 1);
		if (turn == 2)
			MovePiece(W_pawn6.x, W_pawn6.y);
	}

	private: System::Void W_Pawn_7_Click(System::Object^  sender, System::EventArgs^  e) {
		Select(W_Pawn_7, W_pawn7, 1);
		if (turn == 2)
			MovePiece(W_pawn7.x, W_pawn7.y);
	}

	private: System::Void W_Pawn_8_Click(System::Object^  sender, System::EventArgs^  e) {
		Select(W_Pawn_8, W_pawn8, 1);
		if (turn == 2)
			MovePiece(W_pawn8.x, W_pawn8.y);
	}

	//////////////////////////////////////////////

	private: System::Void B_Rook_1_Click(System::Object^  sender, System::EventArgs^  e) {
		Select(B_Rook_1, B_rook1, 2);
		if (turn == 1)
			MovePiece(B_rook1.x, B_rook1.y);
	}

	private: System::Void B_Knight_1_Click(System::Object^  sender, System::EventArgs^  e) {
		Select(B_Knight_1, B_knight1, 2);
		if (turn == 1)
			MovePiece(B_knight1.x, B_knight1.y);
	}

	private: System::Void B_Bishop_1_Click(System::Object^  sender, System::EventArgs^  e) {
		Select(B_Bishop_1, B_bishop1, 2);
		if (turn == 1)
			MovePiece(B_bishop1.x, B_bishop1.y);
	}

	private: System::Void B_King_Click(System::Object^  sender, System::EventArgs^  e) {
		Select(B_King, B_king, 2);
		if (turn == 1)
			MovePiece(B_king.x, B_king.y);
	}

	private: System::Void B_Queen_Click(System::Object^  sender, System::EventArgs^  e) {
		Select(B_Queen, B_queen, 2);
		if (turn == 1)
			MovePiece(B_queen.x, B_queen.y);
	}

	private: System::Void B_Bishop_2_Click(System::Object^  sender, System::EventArgs^  e) {
		Select(B_Bishop_2, B_bishop2, 2);
		if (turn == 1)
			MovePiece(B_bishop2.x, B_bishop2.y);
	}

	private: System::Void B_Knight_2_Click(System::Object^  sender, System::EventArgs^  e) {
		Select(B_Knight_2, B_knight2, 2);
		if (turn == 1)
			MovePiece(B_knight2.x, B_knight2.y);
	}

	private: System::Void B_Rook_2_Click(System::Object^  sender, System::EventArgs^  e) {
		Select(B_Rook_2, B_rook2, 2);
		if (turn == 1)
			MovePiece(B_rook2.x, B_rook2.y);
	}

	private: System::Void B_Pawn_1_Click(System::Object^  sender, System::EventArgs^  e) {
		Select(B_Pawn_1, B_pawn1, 2);
		if (turn == 1)
			MovePiece(B_pawn1.x, B_pawn1.y);
	}

	private: System::Void B_Pawn_2_Click(System::Object^  sender, System::EventArgs^  e) {
		Select(B_Pawn_2, B_pawn2, 2);
		if (turn == 1)
			MovePiece(B_pawn2.x, B_pawn2.y);
	}

	private: System::Void B_Pawn_3_Click(System::Object^  sender, System::EventArgs^  e) {
		Select(B_Pawn_3, B_pawn3, 2);
		if (turn == 1)
			MovePiece(B_pawn3.x, B_pawn3.y);
	}

	private: System::Void B_Pawn_4_Click(System::Object^  sender, System::EventArgs^  e) {
		Select(B_Pawn_4, B_pawn4, 2);
		if (turn == 1)
			MovePiece(B_pawn4.x, B_pawn4.y);
	}

	private: System::Void B_Pawn_5_Click(System::Object^  sender, System::EventArgs^  e) {
		Select(B_Pawn_5, B_pawn5, 2);
		if (turn == 1)
			MovePiece(B_pawn5.x, B_pawn5.y);
	}

	private: System::Void B_Pawn_6_Click(System::Object^  sender, System::EventArgs^  e) {
		Select(B_Pawn_6, B_pawn6, 2);
		if (turn == 1)
			MovePiece(B_pawn6.x, B_pawn6.y);
	}

	private: System::Void B_Pawn_7_Click(System::Object^  sender, System::EventArgs^  e) {
		Select(B_Pawn_7, B_pawn7, 2);
		if (turn == 1)
			MovePiece(B_pawn7.x, B_pawn7.y);
	}

	private: System::Void B_Pawn_8_Click(System::Object^  sender, System::EventArgs^  e) {
		Select(B_Pawn_8, B_pawn8, 2);
		if (turn == 1)
			MovePiece(B_pawn8.x, B_pawn8.y);
	}

	private: System::Void C_Queen_Click(System::Object^  sender, System::EventArgs^  e) {

		Promote(PawnBeingPromotedColor, PawnBeingPromoted, 0);

		C_Queen->Location = System::Drawing::Point(1000, 1000);

		C_Bishop->Location = System::Drawing::Point(1000, 1000);

		C_Knight->Location = System::Drawing::Point(1000, 1000);

		C_Rook->Location = System::Drawing::Point(1000, 1000);

		paused = false;

	}

	private: System::Void C_Bishop_Click(System::Object^  sender, System::EventArgs^  e) {

		Promote(PawnBeingPromotedColor, PawnBeingPromoted, 1);

		C_Queen->Location = System::Drawing::Point(1000, 1000);

		C_Bishop->Location = System::Drawing::Point(1000, 1000);

		C_Knight->Location = System::Drawing::Point(1000, 1000);

		C_Rook->Location = System::Drawing::Point(1000, 1000);

		paused = false;
	}

	private: System::Void C_Knight_Click(System::Object^  sender, System::EventArgs^  e) {

		Promote(PawnBeingPromotedColor, PawnBeingPromoted, 2);

		C_Queen->Location = System::Drawing::Point(1000, 1000);

		C_Bishop->Location = System::Drawing::Point(1000, 1000);

		C_Knight->Location = System::Drawing::Point(1000, 1000);

		C_Rook->Location = System::Drawing::Point(1000, 1000);

		paused = false;
	}

	private: System::Void pictureBox1_Click_1(System::Object^  sender, System::EventArgs^  e) {

		Promote(PawnBeingPromotedColor, PawnBeingPromoted, 3);

		C_Queen->Location = System::Drawing::Point(1000, 1000);

		C_Bishop->Location = System::Drawing::Point(1000, 1000);

		C_Knight->Location = System::Drawing::Point(1000, 1000);

		C_Rook->Location = System::Drawing::Point(1000, 1000);

		paused = false;
	}

	void Hide(int color, int update_num, bool take)
	{
		if (color == 1 && take)
		{
			switch (update_num)
			{
				case 0:
					B_pawn1.dead = true;
					B_Pawn_1->Location = System::Drawing::Point(1000, 1000);
					break;
				case 1:
					B_pawn2.dead = true;
					B_Pawn_2->Location = System::Drawing::Point(1000, 1000);
					break;
				case 2:
					B_pawn3.dead = true;
					B_Pawn_3->Location = System::Drawing::Point(1000, 1000);
					break;
				case 3:
					B_pawn4.dead = true;
					B_Pawn_4->Location = System::Drawing::Point(1000, 1000);
					break;
				case 4:
					B_pawn5.dead = true;
					B_Pawn_5->Location = System::Drawing::Point(1000, 1000);
					break;
				case 5:
					B_pawn6.dead = true;
					B_Pawn_6->Location = System::Drawing::Point(1000, 1000);
					break;
				case 6:
					B_pawn7.dead = true;
					B_Pawn_7->Location = System::Drawing::Point(1000, 1000);
					break;
				case 7:
					B_pawn8.dead = true;
					B_Pawn_8->Location = System::Drawing::Point(1000, 1000);
					break;
				case 8:
					B_bishop1.dead = true;
					B_Bishop_1->Location = System::Drawing::Point(1000, 1000);
					break;
				case 9:
					B_bishop2.dead = true;
					B_Bishop_2->Location = System::Drawing::Point(1000, 1000);
					break;
				case 10:
					B_rook1.dead = true;
					B_Rook_1->Location = System::Drawing::Point(1000, 1000);
					break;
				case 11:
					B_pawn2.dead = true;
					B_Rook_2->Location = System::Drawing::Point(1000, 1000);
					break;
				case 12:
					B_king.dead = true;
					GameEnd = true;
					label1->Text = "White Won";
					label1->Location = System::Drawing::Point(160, 275);
					B_King->Location = System::Drawing::Point(1000, 1000);
					break;
				case 13:
					B_queen.dead = true;
					B_Queen->Location = System::Drawing::Point(1000, 1000);
					break;
				case 14:
					B_knight1.dead = true;
					B_Knight_1->Location = System::Drawing::Point(1000, 1000);
					break;
				case 15:
					B_knight2.dead = true;
					B_Knight_2->Location = System::Drawing::Point(1000, 1000);
					break;
			}
		}
		else if (color == 2 && take)
		{
			switch (update_num)
			{
				case 0:
					W_pawn1.dead = true;
					W_Pawn_1->Location = System::Drawing::Point(1000, 1000);
					break;
				case 1:
					W_pawn2.dead = true;
					W_Pawn_2->Location = System::Drawing::Point(1000, 1000);
					break;
				case 2:
					W_pawn3.dead = true;
					W_Pawn_3->Location = System::Drawing::Point(1000, 1000);
					break;
				case 3:
					W_pawn4.dead = true;
					W_Pawn_4->Location = System::Drawing::Point(1000, 1000);
					break;
				case 4:
					W_pawn5.dead = true;
					W_Pawn_5->Location = System::Drawing::Point(1000, 1000);
					break;
				case 5:
					W_pawn6.dead = true;
					W_Pawn_6->Location = System::Drawing::Point(1000, 1000);
					break;
				case 6:
					W_pawn7.dead = true;
					W_Pawn_7->Location = System::Drawing::Point(1000, 1000);
					break;
				case 7:
					W_pawn8.dead = true;
					W_Pawn_8->Location = System::Drawing::Point(1000, 1000);
					break;
				case 8:
					W_bishop1.dead = true;
					W_Bishop_1->Location = System::Drawing::Point(1000, 1000);
					break;
				case 9:
					W_bishop2.dead = true;
					W_Bishop_2->Location = System::Drawing::Point(1000, 1000);
					break;
				case 10:
					W_rook1.dead = true;
					W_Rook_1->Location = System::Drawing::Point(1000, 1000);
					break;
				case 11:
					W_rook2.dead = true;
					W_Rook_2->Location = System::Drawing::Point(1000, 1000);
					break;
				case 12:
					W_king.dead = true;
					GameEnd = true;
					label1->Text = "Black Won";
					label1->Location = System::Drawing::Point(160, 275);
					W_King->Location = System::Drawing::Point(1000, 1000);
					break;
				case 13:
					W_queen.dead = true;
					W_Queen->Location = System::Drawing::Point(1000, 1000);
					break;
				case 14:
					W_knight1.dead = true;
					W_Knight_1->Location = System::Drawing::Point(1000, 1000);
					break;
				case 15:
					W_knight2.dead = true;
					W_Knight_2->Location = System::Drawing::Point(1000, 1000);
					break;
			}
		}
	}
	
	void Select(System::Windows::Forms::PictureBox^ Piece, ChessPiece& piece, int color) 
	{	
		if (!GameEnd && !paused)
		{
			if (piece.selected)
			{
				Piece->BorderStyle = BorderStyle::None;
				piece.selected = false;
			}
			else
			{
				if (turn == 1 && color == 1)
				{
					W_bishop1.selected = false;

					W_knight1.selected = false;

					W_queen.selected = false;

					W_rook1.selected = false;

					W_pawn1.selected = false;

					W_bishop2.selected = false;

					W_knight2.selected = false;

					W_rook2.selected = false;

					W_pawn2.selected = false;

					W_pawn3.selected = false;

					W_pawn4.selected = false;

					W_pawn5.selected = false;

					W_pawn6.selected = false;

					W_pawn7.selected = false;

					W_pawn8.selected = false;

					W_Pawn_8->BorderStyle = BorderStyle::None;

					W_Pawn_7->BorderStyle = BorderStyle::None;

					W_Pawn_6->BorderStyle = BorderStyle::None;

					W_Pawn_5->BorderStyle = BorderStyle::None;

					W_Pawn_4->BorderStyle = BorderStyle::None;

					W_Pawn_3->BorderStyle = BorderStyle::None;

					W_Pawn_2->BorderStyle = BorderStyle::None;

					W_Rook_2->BorderStyle = BorderStyle::None;

					W_Knight_2->BorderStyle = BorderStyle::None;

					W_Bishop_2->BorderStyle = BorderStyle::None;

					W_Pawn_1->BorderStyle = BorderStyle::None;

					W_Knight_1->BorderStyle = BorderStyle::None;

					W_Bishop_1->BorderStyle = BorderStyle::None;

					W_Queen->BorderStyle = BorderStyle::None;

					W_Rook_1->BorderStyle = BorderStyle::None;

					if (W_king.NotInDanger)
					{
						W_King->BorderStyle = BorderStyle::None;

						W_king.selected = false;
					}

					Piece->BorderStyle = BorderStyle::FixedSingle;

					piece.selected = true;

				}
				///////////////////////////////////////////////
				if (turn == 2 && color == 2)
				{
					B_bishop1.selected = false;

					B_knight1.selected = false;

					B_queen.selected = false;

					B_rook1.selected = false;

					B_pawn1.selected = false;

					B_bishop2.selected = false;

					B_knight2.selected = false;

					B_rook2.selected = false;

					B_pawn2.selected = false;

					B_pawn3.selected = false;

					B_pawn4.selected = false;

					B_pawn5.selected = false;

					B_pawn6.selected = false;

					B_pawn7.selected = false;

					B_pawn8.selected = false;

					B_Pawn_8->BorderStyle = BorderStyle::None;

					B_Pawn_7->BorderStyle = BorderStyle::None;

					B_Pawn_6->BorderStyle = BorderStyle::None;

					B_Pawn_5->BorderStyle = BorderStyle::None;

					B_Pawn_4->BorderStyle = BorderStyle::None;

					B_Pawn_3->BorderStyle = BorderStyle::None;

					B_Pawn_2->BorderStyle = BorderStyle::None;

					B_Rook_2->BorderStyle = BorderStyle::None;

					B_Knight_2->BorderStyle = BorderStyle::None;

					B_Bishop_2->BorderStyle = BorderStyle::None;

					B_Pawn_1->BorderStyle = BorderStyle::None;

					B_Knight_1->BorderStyle = BorderStyle::None;

					B_Bishop_1->BorderStyle = BorderStyle::None;

					B_Queen->BorderStyle = BorderStyle::None;

					B_Rook_1->BorderStyle = BorderStyle::None;

					if (B_king.NotInDanger)
					{
						B_King->BorderStyle = BorderStyle::None;

						B_king.selected = false;
					}

					Piece->BorderStyle = BorderStyle::FixedSingle;

					piece.selected = true;

				}
			}
		}

	
	}

	void MovePiece(int X, int Y)
	{
		if (turn == 1)
		{
			MoveBishop(W_Bishop_1, X, Y, W_bishop1, 1);

			MovePawn(W_Pawn_1, X, Y, W_pawn1, 1, 1, C_Queen, C_Bishop, C_Knight, C_Rook);

			MoveKnight(W_Knight_1, X, Y, W_knight1, 1);

			MoveQueen(W_Queen, X, Y, W_queen, 1);

			MoveRook(W_Rook_1, X, Y, W_rook1, 1);

			MoveKnight(W_Knight_2, X, Y, W_knight2, 1);

			MoveBishop(W_Bishop_2, X, Y, W_bishop2, 1);

			MoveRook(W_Rook_2, X, Y, W_rook2, 1);

			MovePawn(W_Pawn_2, X, Y, W_pawn2, 1, 2, C_Queen, C_Bishop, C_Knight, C_Rook);

			MovePawn(W_Pawn_3, X, Y, W_pawn3, 1, 3, C_Queen, C_Bishop, C_Knight, C_Rook);

			MovePawn(W_Pawn_4, X, Y, W_pawn4, 1, 4, C_Queen, C_Bishop, C_Knight, C_Rook);

			MovePawn(W_Pawn_5, X, Y, W_pawn5, 1, 5, C_Queen, C_Bishop, C_Knight, C_Rook);

			MovePawn(W_Pawn_6, X, Y, W_pawn6, 1, 6, C_Queen, C_Bishop, C_Knight, C_Rook);

			MovePawn(W_Pawn_7, X, Y, W_pawn7, 1, 7, C_Queen, C_Bishop, C_Knight, C_Rook);

			MovePawn(W_Pawn_8, X, Y, W_pawn8, 1, 8, C_Queen, C_Bishop, C_Knight, C_Rook);

			MoveKing(W_King, X, Y, W_king, 1);

		}

		//////////////////////////////////////////////
		else if (turn == 2)
		{
			MoveBishop(B_Bishop_1, X, Y, B_bishop1, 2);

			MovePawn(B_Pawn_1, X, Y, B_pawn1, 2, 1, C_Queen, C_Bishop, C_Knight, C_Rook);

			MoveKnight(B_Knight_1, X, Y, B_knight1, 2);

			MoveQueen(B_Queen, X, Y, B_queen, 2);

			MoveRook(B_Rook_1, X, Y, B_rook1, 2);

			MoveKnight(B_Knight_2, X, Y, B_knight2, 2);

			MoveBishop(B_Bishop_2, X, Y, B_bishop2, 2);

			MoveRook(B_Rook_2, X, Y, B_rook2, 2);

			MovePawn(B_Pawn_2, X, Y, B_pawn2, 2, 2, C_Queen, C_Bishop, C_Knight, C_Rook);

			MovePawn(B_Pawn_3, X, Y, B_pawn3, 2, 3, C_Queen, C_Bishop, C_Knight, C_Rook);

			MovePawn(B_Pawn_4, X, Y, B_pawn4, 2, 4, C_Queen, C_Bishop, C_Knight, C_Rook);

			MovePawn(B_Pawn_5, X, Y, B_pawn5, 2, 5, C_Queen, C_Bishop, C_Knight, C_Rook);

			MovePawn(B_Pawn_6, X, Y, B_pawn6, 2, 6, C_Queen, C_Bishop, C_Knight, C_Rook);

			MovePawn(B_Pawn_7, X, Y, B_pawn7, 2, 7, C_Queen, C_Bishop, C_Knight, C_Rook);

			MovePawn(B_Pawn_8, X, Y, B_pawn8, 2, 8, C_Queen, C_Bishop, C_Knight, C_Rook);

			MoveKing(B_King, X, Y, B_king, 2);

		}

		////////
		Hide(take_color, take_num, take);
		////////
		
		if (CheckKing(W_king, 1) == 1)
		{
			W_King->BorderStyle = BorderStyle::FixedSingle;
			W_king.NotInDanger = false;
		}
		else
		{
			W_King->BorderStyle = BorderStyle::None;
			W_king.NotInDanger = true;
		}

		if (CheckKing(B_king, 2) == 1)
		{
			B_King->BorderStyle = BorderStyle::FixedSingle;
			B_king.NotInDanger = false;
		}
		else
		{
			B_King->BorderStyle = BorderStyle::None;
			B_king.NotInDanger = true;
		}
		
		take_color = 0;

		take = false;

		take_num = -1;

		//check = false;
	}

	void ChangePawnsImage(System::Windows::Forms::PictureBox^ Pawn, int PawnBeingPromotedColor, int ChosenPromotion)
	{
		if (PawnBeingPromotedColor == 1)
		{
			switch (ChosenPromotion)
			{
			case 0:
				Pawn->Image = System::Drawing::Image::FromFile("img/Chess_qlt60.png");
				break;
			case 1:
				Pawn->Image = System::Drawing::Image::FromFile("img/Chess_blt60.png");
				break;
			case 2:
				Pawn->Image = System::Drawing::Image::FromFile("img/Chess_nlt60.png");
				break;
			case 3:
				Pawn->Image = System::Drawing::Image::FromFile("img/Chess_rlt60.png");
				break;
			}
		}
		if (PawnBeingPromotedColor == 2)
		{
			switch (ChosenPromotion)
			{
			case 0:
				Pawn->Image = System::Drawing::Image::FromFile("img/Chess_qdt60.png");
				break;
			case 1:
				Pawn->Image = System::Drawing::Image::FromFile("img/Chess_bdt60.png");
				break;
			case 2:
				Pawn->Image = System::Drawing::Image::FromFile("img/Chess_ndt60.png");
				break;
			case 3:
				Pawn->Image = System::Drawing::Image::FromFile("img/Chess_rdt60.png");
				break;
			}
		}
	}

	void Promote(int PawnBeingPromotedColor, int PawnBeingPromoted, int ChosenPromotion)
	{
		if (PawnBeingPromotedColor == 1) {
			switch (PawnBeingPromoted)
			{
			case 1:
				W_pawn1.type = Promotions[ChosenPromotion];
				ChangePawnsImage(W_Pawn_1, PawnBeingPromotedColor, ChosenPromotion);
				break;
			case 2:
				W_pawn2.type = Promotions[ChosenPromotion];
				ChangePawnsImage(W_Pawn_2, PawnBeingPromotedColor, ChosenPromotion);
				break;
			case 3:
				W_pawn3.type = Promotions[ChosenPromotion];
				ChangePawnsImage(W_Pawn_3, PawnBeingPromotedColor, ChosenPromotion);
				break;
			case 4:
				W_pawn4.type = Promotions[ChosenPromotion];
				ChangePawnsImage(W_Pawn_4, PawnBeingPromotedColor, ChosenPromotion);
				break;
			case 5:
				W_pawn5.type = Promotions[ChosenPromotion];
				ChangePawnsImage(W_Pawn_5, PawnBeingPromotedColor, ChosenPromotion);
				break;
			case 6:
				W_pawn6.type = Promotions[ChosenPromotion];
				ChangePawnsImage(W_Pawn_6, PawnBeingPromotedColor, ChosenPromotion);
				break;
			case 7:
				W_pawn7.type = Promotions[ChosenPromotion];
				ChangePawnsImage(W_Pawn_7, PawnBeingPromotedColor, ChosenPromotion);
				break;
			case 8:
				W_pawn8.type = Promotions[ChosenPromotion];
				ChangePawnsImage(W_Pawn_8, PawnBeingPromotedColor, ChosenPromotion);
				break;
			}
		}
		else if (PawnBeingPromotedColor == 2) {
			switch (PawnBeingPromoted)
			{
			case 1:
				B_pawn1.type = Promotions[ChosenPromotion];
				ChangePawnsImage(B_Pawn_1, PawnBeingPromotedColor, ChosenPromotion);
				break;
			case 2:
				B_pawn2.type = Promotions[ChosenPromotion];
				ChangePawnsImage(B_Pawn_2, PawnBeingPromotedColor, ChosenPromotion);
				break;
			case 3:
				B_pawn3.type = Promotions[ChosenPromotion];
				ChangePawnsImage(B_Pawn_3, PawnBeingPromotedColor, ChosenPromotion);
				break;
			case 4:
				B_pawn4.type = Promotions[ChosenPromotion];
				ChangePawnsImage(B_Pawn_4, PawnBeingPromotedColor, ChosenPromotion);
				break;
			case 5:
				B_pawn5.type = Promotions[ChosenPromotion];
				ChangePawnsImage(B_Pawn_5, PawnBeingPromotedColor, ChosenPromotion);
				break;
			case 6:
				B_pawn6.type = Promotions[ChosenPromotion];
				ChangePawnsImage(B_Pawn_6, PawnBeingPromotedColor, ChosenPromotion);
				break;
			case 7:
				B_pawn7.type = Promotions[ChosenPromotion];
				ChangePawnsImage(B_Pawn_7, PawnBeingPromotedColor, ChosenPromotion);
				break;
			case 8:
				B_pawn8.type = Promotions[ChosenPromotion];
				ChangePawnsImage(B_Pawn_8, PawnBeingPromotedColor, ChosenPromotion);
				break;


			}
		}
	}


};
}

