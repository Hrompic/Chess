#include <iostream>
#include <SFML/Graphics.hpp>
#define W 920
#define H 680
#define BDR 20
using namespace std;
using namespace sf;

class Board
{
	RenderWindow *wnd;
	Sprite board, PawnW, RookW, BishopW, KingW, KnightW, QueenW,
	PawnB, RookB, BishopB, KingB, KnightB, QueenB;
	Texture _board, _PawnW, _RookW, _BishopW, _KingW, _KnightW, _QueenW,
	_PawnB, _RookB, _BishopB, _KingB, _KnightB, _QueenB;
public:
	Board(RenderWindow *);
	~Board();
	void draw();
	void init();

};
int main()
{
	ContextSettings ctx;
	ctx.antialiasingLevel = 16;
	RenderWindow app(VideoMode(W, H), "Chess", Style::Default, ctx);
	app.setFramerateLimit(70);


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
		app.clear(Color::Black);
		brd.draw();

		app.display();
	}
	return 0;
}

Board::Board(RenderWindow *_wnd):
	wnd(_wnd)
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
	PawnB.setTexture( _PawnB);

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

}

Board::~Board()
{

}

void Board::draw()
{
	wnd->draw(board);
	wnd->draw(PawnB);
	wnd->draw(PawnW);
}

void Board::init()
{

}
