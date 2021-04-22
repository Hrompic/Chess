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
	void move(int , int, int, int);
	void replase(int , int, int, int);
	bool ifWhite(int ,int);
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
		static int x1, y1, x2, y2;
		Vector2i pos = Mouse::getPosition(*wnd);
		if(pos.x<20||pos.x>H-20||pos.y<20||pos.y>H-20) return;
		if(!inMove)
		{
			x1 = (pos.x-BDR)/80;
			y1 = (pos.y-BDR)/80;
			setPosition((pos.x-BDR)/80, (pos.y-BDR)/80);
//			cout <<pos.x <<" -- " <<pos.y <<endl;
			inMove = 1;
			sleep(milliseconds(150));
		}
		else
		{
			x2 = (pos.x-BDR)/80;
			y2 = (pos.y-BDR)/80;
			if(!((x1==x2) && (y1==y2)))
				move(x1, y1, x2, y2);
			inMove=0;
			changed=1;
		}
	}

}

bool Board::setPosition(int x, int y)
{
//	cout <<x <<" -- " <<y <<endl;
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

void Board::move(int x1, int y1, int x2, int y2)
{
	if(brd[x1][y1] == Piece::PawnW)
	{
		if(brd[x2][y2]==Piece::Free)
		{
			if(y2==0)
			{
				brd[x2][y2]=Piece::BishopW;
				brd[x1][y1]=Piece::Free;
			}
			else if(y1==y2 && ((x1==x2+1)||(x1==x2-1)))
				replase(x1, y1, x2, y2);
			else if(x1==x2 && ((y1==y2+1)||(y1==y2+2)) && (y1==6))
				replase(x1, y1, x2, y2);
			else if(x1==x2 && (y1==y2+1))
				replase(x1, y1, x2, y2);
		}
		else
		{
			if(((x1 == x2-1)||(x1 == x2+1)) && (y1 ==y2+1)&& !ifWhite(x2, y2))
			{
				if(y2==0&&brd[x2][y2]!=Piece::Free)
				{
					brd[x2][y2]=Piece::BishopW;
					brd[x1][y1]=Piece::Free;
				}
				else
					replase(x1, y1, x2, y2);
			}
		}
	}
	else if (brd[x1][y1] == Piece::PawnB) //Implemet fook and replace
	{
		if(brd[x2][y2]==Piece::Free)
		{
			if(y2==7)
			{
				brd[x2][y2]=Piece::BishopB;
				brd[x1][y1]=Piece::Free;
			}
			else if(y1==y2 && ((x1==x2-1)||(x1==x2+1))) //x move
				replase(x1, y1, x2, y2);
			else if(x1==x2 && ((y1==y2-1)||(y1==y2-2)) && (y1==1)) //first y move
				replase(x1, y1, x2, y2);
			else if(x1==x2 && (y1==y2-1)) //y move
				replase(x1, y1, x2, y2);
		}
		else
		{
			if(((x1 == x2+1)||(x1 == x2-1)) && (y1 ==y2-1) && ifWhite(x2, y2))
			{
				if(y2==7&&brd[x2][y2]!=Piece::Free) //last move
				{
					brd[x2][y2]=Piece::BishopB;
					brd[x1][y1]=Piece::Free;
				}
				else
					replase(x1, y1, x2, y2);
			}
		}
	}
	else if (brd[x1][y1] == Piece::KnightW)
	{
		if (((abs(x1-x2)==2 && abs(y1-y2)==1)||(abs(x1-x2)==1 && abs(y1-y2)==2))&&
				(brd[x2][y2]==Piece::Free ||!ifWhite(x2, y2)))
			replase(x1, y1, x2, y2);
	}
	else if (brd[x1][y1] == Piece::KnightB)
	{
		if (((abs(x1-x2)==2 && abs(y1-y2)==1)||(abs(x1-x2)==1 && abs(y1-y2)==2))&&
				(brd[x2][y2]==Piece::Free || ifWhite(x2, y2)))
			replase(x1, y1, x2, y2);
	}
	else if (brd[x1][y1] == Piece::BishopW)
	{
		if (abs(x1 - x2) == abs(y1 - y2))
		{
			int xI = (x2-x1) / (abs(x2-x1));
			int yI = (y2-y1) / (abs(y2-y1));
			cout <<xI <<"\t--\t" <<yI <<" " <<abs(x1 - x2) <<"\t--\t" <<abs(y1 - y2) <<endl;
			for (int i = 1; i <= abs(x1 - x2); i++)
			{

				if (brd[x1 + xI*i][y1 + yI*i]!=Piece::Free) break;
				if (brd[x1 + xI*i][y1 + yI*i]==Piece::Free && i==abs(x1-x2)){replase(x1, y1, x2, y2); return;} //free space
			}
//			if (brd[x2][y2] == Piece::Free || !ifWhite(x2, y2))	{replase(x1, y1, x2, y2); return;}
		}
	}
	else if (brd[x1][y1] == Piece::RookW)
	{
		if (x1!=x2 || y1!=y2)
		{

			if (x1 == x2)
			{
				int yI = (y2-y1) / (abs(y2-y1));
				for (int i = y1+yI; i!=y2; i+=yI)
				{

					if (brd[x2][i] != Piece::Free)
						return ;

				}
				if(!ifWhite(x2,y2)) replase(x1, y1, x2, y2);
			}
			else
				if (y1 == y2)
				{

					int xI = (x2-x1) / (abs(x2-x1));
					for (int i = x1+xI; i!=x2; i+=xI)
					{
						if (brd[i][y2] != Piece::Free)
							return;
					}
					if(!ifWhite(x2,y2)) replase(x1, y1, x2, y2);
				}
		}
	}
	else if (brd[x1][y1] == Piece::RookB)
	{
		if (x1!=x2 || y1!=y2)
		{

			if (x1 == x2)
			{
				int yI = (y2-y1) / (abs(y2-y1));
				cout <<yI <<endl;
				for (int i = y1+yI; i!=y2; i+=yI)
				{

					if (brd[x2][i] != Piece::Free)
						return ;

				}
				if(ifWhite(x2, y2)||brd[x2][y2] == Piece::Free) replase(x1, y1, x2, y2);
			}
			else
				if (y1 == y2)
				{

					int xI = (x2-x1) / (abs(x2-x1));
					for (int i = x1+xI; i!=x2; i+=xI)
					{
						if (brd[i][y2] != Piece::Free)
							return;
					}
					if(ifWhite(x2, y2)||brd[x2][y2] == Piece::Free) replase(x1, y1, x2, y2);
				}
		}
	}
	cout <<"zzzzzzzzz:\t" <<x1 <<" -- " <<y1 <<"\t" <<x2 <<" -- " <<y2 <<endl;
}

void Board::replase(int x1, int y1, int x2, int y2)
{
	brd[x2][y2]=brd[x1][y1];
	brd[x1][y1]=Piece::Free;
	changed = true;
}

bool Board::ifWhite(int x, int y)
{
	return	brd[x][y] == Piece::PawnW ||
			brd[x][y] == Piece::BishopW||
			brd[x][y] == Piece::QueenW||
			brd[x][y] == Piece::KnightW||
			brd[x][y] == Piece::KingW||
			brd[x][y] == Piece::RookW;
}
