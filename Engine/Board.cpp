#include "Board.h"
#include <Assert.h>

Board::Board(Graphics& gfx)
	:
	gfx(gfx)
{
}

void Board::DrawCell(const Location & loc, Color c)
{
	assert(loc.x >= 0);
	assert(loc.x < width);
	assert(loc.y >= 0);
	assert(loc.y < height);
	const int off_x = x + borderThickness + loc.x * cellPadding;
	const int off_y = y + borderThickness + loc.y * cellPadding;
	gfx.DrawRectDim(off_x + loc.x * dimension, off_y + loc.y * dimension, dimension, dimension, c);
}

void Board::DrawBorder()
{
	const int top = y;
	const int left = x;
	const int bottom = top + borderThickness * 2 + height * (dimension + cellPadding);
	const int right = left + borderThickness * 2 + width * (dimension + cellPadding);

	gfx.DrawRect(left, top, right, top + borderThickness, borderColor);
	gfx.DrawRect(left, bottom - borderThickness, right, bottom, borderColor);
	gfx.DrawRect(left, top + borderThickness, left + borderThickness, bottom - borderThickness, borderColor);
	gfx.DrawRect(right - borderThickness, top + borderThickness, right, bottom - borderThickness, borderColor);
}

int Board::GetGridWidth() const
{
	return width;
}

int Board::GetGridHeight() const
{
	return height;
}

bool Board::IsInsideBoard(const Location & loc) const
{
	return loc.x >= 0 && loc.x < width &&
		loc.y >= 0 && loc.y < height;
}
