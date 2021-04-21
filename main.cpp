//Hrompic 2021
#include <iostream>
#include <cstring>
#include <SFML/Graphics.hpp>
#define W 920
#define H 680
#define BDR 20
#define name(a) #a
#define sPos(a, x, y) (##a.setPosition(x, y))
using namespace std;
using namespace sf;

enum Piece {Free,
			PawnW, RookW, BishopW, KingW, KnightW, QueenW,
			PawnB, RookB, BishopB, KingB, KnightB, QueenB };

class Board
{
	Piece brd[8][8];
	RenderWindow *wnd;
	Sprite board, PawnW, RookW, BishopW, KingW, KnightW, QueenW,
	PawnB, RookB, BishopB, KingB, KnightB, QueenB;
	Texture _board, _PawnW, _RookW, _BishopW, _KingW, _KnightW, _QueenW,
	_PawnB, _RookB, _BishopB, _KingB, _KnightB, _QueenB;
	bool setPosition(int, int);
	int changed;
public:
	Board(RenderWindow *);
	~Board();
	void draw();
	void init();
	void event();


};
int main()
{
	ContextSettings ctx;
	ctx.antialiasingLevel = 16;
	RenderWindow app(VideoMode(W, H), "Chess", Style::Close, ctx);
	app.setFramerateLimit(60);


	Board brd(&app);
	while(app.isOpen())
	{
		Event event;
		while(app.pollEvent(event))
		{
			if(event.type == Event::Closed)
				app.close();
			if(event.type == Event::KeyPressed)
				if(event.key.code == Keyboard::Q)
					app.close();
		}
		//app.clear(Color::Black);

		brd.draw();
		brd.event();

		app.display();
	}
	cout <<name(BishopW);
	return 0;
}


Board::Board(RenderWindow *_wnd):
	wnd(_wnd),
	changed(true)
{

	_board.loadFromFile("images/Chess_Board_Stone.png");
	_PawnB.loadFromFile("images/PawnB.png");
	_PawnW.loadFromFile("images/PawnW.png");

	_BishopB.loadFromFile("images/BishopB.png");
	_BishopW.loadFromFile("images/BishopW.png");

	_PawnW.loadFromFile("images/PawnW.png");
	_PawnW.loadFromFile("images/PawnW.png");

	_KingB.loadFromFile("images/KingB.png");
	_KingW.loadFromFile("images/KingW.png");

	_KnightB.loadFromFile("images/KnightB.png");
	_KnightW.loadFromFile("images/KnightW.png");

	_QueenB.loadFromFile("images/QueenB.png");
	_QueenW.loadFromFile("images/QueenW.png");

	_RookB.loadFromFile("images/RookB.png");
	_RookW.loadFromFile("images/RookW.png");


	board.setTexture( _board);

	PawnB.setTexture( _PawnB);
	PawnW.setTexture( _PawnW);

	BishopB.setTexture( _BishopB);
	BishopW.setTexture( _BishopW);

	KingB.setTexture( _KingB);
	KingW.setTexture( _KingW);

	KnightB.setTexture( _KnightB);
	KnightW.setTexture( _KnightW);

	QueenB.setTexture( _QueenB);
	QueenW.setTexture( _QueenW);

	RookW.setTexture( _RookW);
	RookB.setTexture( _RookB);
	wnd->draw(board);
	init();

}

Board::~Board()
{

}

void Board::draw()
{
	if(changed)
	{
		wnd->clear(Color::Black);
		wnd->draw(board);
		for(int i=0; i<8; i++)
			for(int j=0; j<8; j++)
			switch (brd[i][j])
			{
			case Piece::Free:
				break;
			case Piece::QueenB:
				QueenB.setPosition(i*80+BDR, j*80+BDR-4);
				wnd->draw(QueenB);
				break;
			case Piece::QueenW:
				QueenW.setPosition(i*80+BDR, j*80+BDR-4);
				wnd->draw(QueenW);
				break;
			case Piece::KingB:
				KingB.setPosition(i*80+BDR, j*80+BDR-4);
				wnd->draw(KingB);
				break;
			case Piece::KnightB:
				KnightB.setPosition(i*80+BDR, j*80+BDR-4);
				wnd->draw(KnightB);
				break;
			case Piece::KnightW:
				KnightW.setPosition(i*80+BDR, j*80+BDR-4);
				wnd->draw(KnightW);
				break;
			case Piece::KingW:
				KingW.setPosition(i*80+BDR, j*80+BDR-4);
				wnd->draw(KingW);
				break;
			case Piece::RookB:
				RookB.setPosition(i*80+BDR, j*80+BDR-4);
				wnd->draw(RookB);
				break;
			case Piece::RookW:
				RookW.setPosition(i*80+BDR, j*80+BDR-4);
				wnd->draw(RookW);
				break;
			case Piece::BishopB:
				BishopB.setPosition(i*80+BDR, j*80+BDR-4);
				wnd->draw(BishopB);
				break;
			case Piece::BishopW:
				BishopW.setPosition(i*80+BDR, j*80+BDR-4);
				wnd->draw(BishopW);
				break;
			case Piece::PawnB:
				PawnB.setPosition(i*80+BDR, j*80+BDR-4);
				wnd->draw(PawnB);
				break;
			case Piece::PawnW:
				PawnW.setPosition(i*80+BDR, j*80+BDR-4);
				wnd->draw(PawnW);
				break;
			}
		changed = false;
	}
}

void Board::init()
{
	memset(brd, 0, sizeof(brd));
	for(int i=0; i<8; i++)
	{
		brd[i][1] = Piece::PawnB;
	}
	for(int i=0; i<8; i++)
	{
		brd[i][6] = Piece::PawnW;
	}
	brd[0][0]=brd[7][0]=Piece::RookB;
	brd[0][7]=brd[7][7]=Piece::RookW;
	brd[1][0]=brd[6][0]=Piece::BishopB;
	brd[1][7]=brd[6][7]=Piece::BishopW;
	brd[2][0]=brd[5][0]=Piece::KnightB;
	brd[2][7]=brd[5][7]=Piece::KnightW;
	brd[4][0]=Piece::KingB;
	brd[3][0]=Piece::QueenB;
	brd[4][7]=Piece::KingW;
	brd[3][7]=Piece::QueenW;
}

void Board::event()
{
	if(Mouse::isButtonPressed(Mouse::Left))
	{
		static bool inMove = 0;
		Vector2i pos = Mouse::getPosition(*wnd);
		if(pos.x<20||pos.x>H-20||pos.y<20||pos.y>H-20) return;
		if(!inMove)
		{

			setPosition((pos.x-BDR)/80, (pos.y-BDR)/80);
			cout <<pos.x <<" -- " <<pos.y <<endl;
			inMove = 1;
			sleep(milliseconds(150));
		}
		else
		{
			inMove=0;
			changed=1;
		}
	}

}

bool Board::setPosition(int x, int y)
{
	cout <<x <<" -- " <<y <<endl;
	if(brd[x][y] == Piece::Free)
		return false;

	else
	{
		RectangleShape rect(Vector2f(80., 80.));
		rect.setPosition(x*80+BDR, y*80+BDR+2);
		rect.setOutlineThickness(3.);
		rect.setFillColor(Color::Transparent);
		rect.setOutlineColor(Color::Yellow);
		wnd->draw(rect);
	}
	return false;
}
